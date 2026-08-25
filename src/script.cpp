#include "script.h"

#include "aloha/WavMark.h"
#include "magic_enum/magic_enum.hpp"
#include "log.h"

// this will cause a crash someday, but for the moment it links, so who cares
static FILE dummy_stdin{};
static FILE dummy_stdout{};
FILE* const stdin  = &dummy_stdin;
FILE* const stdout = &dummy_stdout;

template <> struct magic_enum::customize::enum_range<WavMarkId> {
    static constexpr int min = -1;
    static constexpr int max = 2200;
};

sol::state init_state() {
    sol::state lua;
    lua.open_libraries(
        sol::lib::base,
        sol::lib::package,
        sol::lib::string,
        sol::lib::table
    );

    lua.set_function("print", [](sol::this_state s, const char* a) {
        log("LUA: %s", a);
    });

    for (auto value : magic_enum::enum_values<WavMarkId>()) {
        auto name = magic_enum::enum_name(value);
        lua[name.data()] = value;
    }

    return lua;
}
