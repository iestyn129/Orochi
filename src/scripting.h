#pragma once

#include "hk/prim/traits/Integer.h"
#include "lua.hpp"
#include "global.h"

extern lua_State* initLua();
extern void runLua(lua_State* L, const char* script);
extern void runLuaScript(lua_State* L, const char* scriptPath);
extern "C" s32 lua_print(lua_State* L);
