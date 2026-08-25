#include "script.h"

#include <nn/fs.h>
#include "log.h"

#define load_enum(_enum) \
    for (auto value : magic_enum::enum_values<_enum>()) { \
        auto name = magic_enum::enum_name(value); \
        lua[name.data()] = value; \
    } \

// this will cause a crash someday, but for the moment it links, so who cares
static FILE dummy_stdin{};
static FILE dummy_stdout{};
FILE* const stdin  = &dummy_stdin;
FILE* const stdout = &dummy_stdout;

sol::state init_state() {
    sol::state lua;
    lua.open_libraries(
        sol::lib::base,
        sol::lib::package,
        sol::lib::string,
        sol::lib::table
    );

    lua.set_function("print", [](const char* a) {
        log("LUA: %s", a);
    });

    load_enum(WavMarkId)
    load_enum(Remix20SceneID)
    load_enum(Remix20SceneIDAlias)
    load_enum(Remix20SceneIDAliasEU)

    return lua;
}

sol::protected_function_result run_script(sol::state_view& state, const std::string& filename) {
    sol::protected_function_result pfr;
    nn::fs::FileHandle file{};

    while (true) {
        if (nn::fs::OpenFile(&file, filename.c_str(), nn::fs::OpenMode_Read).IsFailure())
            break;

        s64 fileSize;
        if (nn::fs::GetFileSize(&fileSize, file).IsFailure())
            break;

        std::vector<char> buffer(fileSize + 1);

        u64 bytesRead;
        if (nn::fs::ReadFile(&bytesRead, file, 0, buffer.data(), fileSize).IsFailure())
            break;

        buffer[bytesRead] = '\0';

        pfr = state.safe_script(buffer.data());

        break;
    }

    nn::fs::CloseFile(file);

    return pfr;
}
