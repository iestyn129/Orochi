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

    *static_cast<ChartContext**>(lua_getextraspace(L)) = new ChartContext{};

    return L;
}


void destroyLua(lua_State* L) {
    if (!L) {
        return;
    }

    if (auto** ctx = static_cast<ChartContext**>(lua_getextraspace(L)); *ctx) {
        delete *ctx;
        *ctx = nullptr;
    }

    lua_close(L);
}


ChartContext* getChartContext(lua_State* L) {
    return *static_cast<ChartContext**>(lua_getextraspace(L));
}


void runLua(lua_State* L, const char* script, const char* scriptName) {
    if (luaL_loadbuffer(L, script, strlen(script), scriptName) != LUA_OK) {
        log("Lua load error: %s", lua_tostring(L, -1));
        lua_pop(L, 1);
        return;
    }

    if (lua_pcall(L, 0, 0, 0) != LUA_OK) {
        log("Lua error: %s", lua_tostring(L, -1));
        lua_pop(L, 1);
    }
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

        runLua(L, buffer.data(), scriptPath);

        break;
    }

    nn::fs::CloseFile(file);
}


void runLuaChart(s64 a1, s64 a2, const char* scriptPath) {
    lua_State* L = initLua();

    const ChartContext* ctx = getChartContext(L);
    ctx->a1 = a1;
    ctx->a2 = a2;

    runLuaScript(L, scriptPath);
    destroyLua(L);
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
