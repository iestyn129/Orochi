#include "scripting.h"

#include <cstdio>
#include <vector>
#include "aloha.h"
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

    lua_pushcfunction(L, lua_rest);
    lua_setglobal(L, "rest");

    lua_pushcfunction(L, lua_change_cue_scene);
    lua_setglobal(L, "change_cue_scene");
    lua_pushcfunction(L, lua_set_marking_criteria);
    lua_setglobal(L, "set_marking_criteria");

    lua_pushcfunction(L, lua_spawn_parasol_cue);
    lua_setglobal(L, "spawn_parasol_cue");
    lua_pushcfunction(L, lua_spawn_birds_cue);
    lua_setglobal(L, "spawn_birds_cue");
    lua_pushcfunction(L, lua_spawn_talk_cue01);
    lua_setglobal(L, "spawn_talk_cue01");
    lua_pushcfunction(L, lua_spawn_wiper_cue01);
    lua_setglobal(L, "spawn_wiper_cue01");
    lua_pushcfunction(L, lua_spawn_wiper_cue02);
    lua_setglobal(L, "spawn_wiper_cue02");

    lua_pushcfunction(L, lua_set_anim);
    lua_setglobal(L, "set_anim");
    lua_pushcfunction(L, lua_stop_anim);
    lua_setglobal(L, "stop_anim");

    lua_pushcfunction(L, lua_change_scene);
    lua_setglobal(L, "change_scene");
    lua_pushcfunction(L, lua_change_scene_fade);
    lua_setglobal(L, "change_scene_fade");

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


s32 lua_rest(lua_State* L) {
    const auto ticks = static_cast<s32>(luaL_checkinteger(L, 1));
    const ChartContext* ctx = getChartContext(L);

    rest_ticks(ctx->a2, ticks);

    check_thread_stopping(ctx, L);

    return 0;
}


s32 lua_change_cue_scene(lua_State* L) {
    const auto scene = static_cast<s32>(luaL_checkinteger(L, 1));
    const ChartContext* ctx = getChartContext(L);

    log("changing cue scene to: %d", scene);

    const s64 v1 = sub_7100514FB0(ctx->a2);
    change_cue_scene(ctx->a1, ctx->a2, scene);
    unk_thread_check(ctx->a2, v1);

    check_thread_stopping(ctx, L);

    return 0;
}


s32 lua_set_marking_criteria(lua_State* L) {
    const char* criteria = luaL_checkstring(L, 1);
    const ChartContext* ctx = getChartContext(L);

    log("setting marking criteria to: %s", criteria);

    set_marking_criteria(ctx->a1, const_cast<char*>(criteria));

    return 0;
}


s32 lua_spawn_parasol_cue(lua_State* L) {
    const auto ticks = static_cast<u32>(luaL_checkinteger(L, 1));
    const auto a4 = static_cast<u32>(luaL_checkinteger(L, 2));
    const auto a5 = static_cast<u32>(luaL_checkinteger(L, 3));
    const auto a6 = static_cast<u32>(luaL_checkinteger(L, 3));
    const ChartContext* ctx = getChartContext(L);

    log("spawning parasol cue (ticks: %d, a4: %d, a5: %d, a6: %d)", ticks, a4, a5, a6);

    spawn_parasol_cue(reinterpret_cast<s64*>(ctx->a1)[7313], ctx->a2, ticks, a4, a5, a6);

    return 0;
}


s32 lua_spawn_birds_cue(lua_State* L) {
    const char* cue = luaL_checkstring(L, 1);
    const ChartContext* ctx = getChartContext(L);

    log("spawning birds cue: %s", cue);

    spawn_birds_cue(reinterpret_cast<s64*>(ctx->a1)[7265], ctx->a2, const_cast<char*>(cue));

    return 0;
}


s32 lua_spawn_talk_cue01(lua_State* L) {
    const ChartContext* ctx = getChartContext(L);

    log("spawning talk cue01");

    spawn_talk_cue01(reinterpret_cast<s64*>(ctx->a1)[7340]);

    return 0;
}


s32 lua_spawn_wiper_cue01(lua_State* L) {
    const ChartContext* ctx = getChartContext(L);

    log("spawning wiper cue01");

    spawn_wiper_cue_LQ(reinterpret_cast<s64*>(ctx->a1)[7349]);

    return 0;
}


s32 lua_spawn_wiper_cue02(lua_State* L) {
    const ChartContext* ctx = getChartContext(L);

    log("spawning wiper cue02");

    spawn_wiper_cue_BQ(reinterpret_cast<s64*>(ctx->a1)[7349]);

    return 0;
}


s32 lua_set_anim(lua_State* L) {
    const auto ticks = static_cast<s32>(luaL_checkinteger(L, 1));
    const auto alsoTicks = static_cast<s32>(luaL_checkinteger(L, 2));
    const auto maybeAnID = static_cast<s32>(luaL_checkinteger(L, 3));
    const ChartContext* ctx = getChartContext(L);

    set_anim(ctx->a1, ctx->a2, ticks, alsoTicks, maybeAnID);

    return 0;
}


s32 lua_stop_anim(lua_State* L) {
    const ChartContext* ctx = getChartContext(L);

    stop_anim(ctx->a1);

    return 0;
}


s32 lua_change_scene(lua_State* L) {
    const auto scene = static_cast<u32>(luaL_checkinteger(L, 1));
    const ChartContext* ctx = getChartContext(L);

    log("changing scene (regular) to: %d", scene);

    const s64 v1 = sub_7100514FB0(ctx->a2);
    change_scene(ctx->a1 + 28168, ctx->a2, scene);
    unk_thread_check(ctx->a2, v1);

    check_thread_stopping(ctx, L);

    return 0;
}


s32 lua_change_scene_fade(lua_State* L) {
    const auto scene = static_cast<u32>(luaL_checkinteger(L, 1));
    const ChartContext* ctx = getChartContext(L);

    log("changing scene (fade) to: %d", scene);

    const s64 v1 = sub_7100514FB0(ctx->a2);
    change_scene_fade(ctx->a1 + 28168, ctx->a2, scene, 2);
    unk_thread_check(ctx->a2, v1);

    check_thread_stopping(ctx, L);

    return 0;
}
