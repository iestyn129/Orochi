#pragma once

#include "hk/prim/traits/Integer.h"
#include "lua.hpp"
#include "global.h"

#define check_thread_stopping(ctx, L) \
    if (is_thread_stopping(ctx->a2)) \
        return luaL_error(L, "Thread stopping!")

struct ChartContext {
    mutable s64 a1;
    mutable s64 a2;
};

extern lua_State* initLua();
extern void destroyLua(lua_State* L);
extern ChartContext* getChartContext(lua_State* L);
extern void runLua(lua_State* L, const char* script, const char* scriptName);
extern void runLuaScript(lua_State* L, const char* scriptPath);
extern void runLuaChart(s64 a1, s64 a2, const char* scriptPath);
extern "C" s32 lua_print(lua_State* L);
extern "C" s32 lua_rest(lua_State* L);
extern "C" s32 lua_change_scene(lua_State* L);
extern "C" s32 lua_change_scene_fade(lua_State* L);
