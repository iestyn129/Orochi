#include "scripting.h"

#include <cstdio>
#include <vector>
#include "log.h"
#include "nn/fs.h"

// this will cause a crash someday, but for the moment it links, so who cares
static FILE dummy_stdin{};
static FILE dummy_stdout{};
FILE* const stdin  = &dummy_stdin;
FILE* const stdout = &dummy_stdout;


lua_State* initLua() {
    lua_State* L = luaL_newstate();
    luaL_openlibs(L);

    lua_pushcfunction(L, lua_print);
    lua_setglobal(L, "print");

    return L;
}


void runLua(lua_State* L, const char* script) {
    luaL_loadbuffer(L, script, static_cast<s32>(strlen(script)), "runLua");
    lua_pcall(L, 0, 0, 0);
}


void runLuaScript(lua_State* L, const char* scriptPath) {
    nn::fs::FileHandle file{};

    while (true) {
        if (nn::fs::OpenFile(&file, scriptPath, nn::fs::OpenMode_Read).IsFailure())
            break;

        s64 fileSize;
        if (nn::fs::GetFileSize(&fileSize, file).IsFailure())
            break;

        std::vector<char> buffer(fileSize + 1);

        u64 bytesRead;
        if (nn::fs::ReadFile(&bytesRead, file, 0, buffer.data(), fileSize).IsFailure())
            break;

        buffer[bytesRead] = '\0';

        runLua(L, buffer.data());

        break;
    }

    nn::fs::CloseFile(file);
}


s32 lua_print(lua_State* L) {
    const s32 argc = lua_gettop(L);

    for (s32 i = 1; i <= argc; i++) {
        if (const char* str = lua_tostring(L, i); str != nullptr) {
            log("LUA: %s", str);
        }
    }

    return 0;
}
