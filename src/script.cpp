#include "script.h"

// this will cause a crash someday, but for the moment it links, so who cares
static FILE dummy_stdin{};
static FILE dummy_stdout{};
FILE* const stdin  = &dummy_stdin;
FILE* const stdout = &dummy_stdout;

void lua_test() {
    sol::state lua;

    int x = 0;
    lua.set_function("test", [&x]{ ++x; });

    lua.script("test()");
    log("%d", x);
    lua.script("test()");
    log("%d", x);
    lua.script("test()");
    log("%d", x);
    lua.script("test()");
    log("%d", x);
}
