#pragma once

#include "global.h"
#include <magic_enum/magic_enum.hpp>
#include <sol/sol.hpp>
#include "aloha/Stage.h"
#include "chart.h"

#define check_threadL() \
    if (thread->stopRequested()) \
        return false;

#define restL(beats) \
    thread->wait((beats) * 480); \
    check_threadL()

struct LuaStage {
    StageRemix20* stage;
    SeqThread* thread;

    [[nodiscard]] bool restb(f32 beats) const;
};

struct LuaStageCallback {
    StageRemix20* stage;
    sol::protected_function func;
};

void invokeLuaStageCallback(SeqThread* thread, LuaStageCallback* callback);

template <typename E> E get_enum_or(sol::table& tbl, const char* name, E fallback) {
    auto value = tbl.get<std::underlying_type_t<E>>(name);

    if (!magic_enum::enum_contains<E>(value))
        return fallback;

    return static_cast<E>(value);
}

namespace sol {
    inline Chart sol_lua_get(types<Chart>, lua_State* L, int index, stack::record& tracking) {
        auto tbl = sol::stack::get<table>(L, index);

        auto wavmark = get_enum_or<WavMarkId>(tbl, "wavmark", wavmark_invalid);
        auto init_scene = get_enum_or<Remix20SceneID>(tbl, "init_scene", SCENE_INVALID);
        auto length = tbl.get<f32>("length");
        std::vector<protected_function> threads;

        if (auto thread_table = tbl["threads"].get<optional<table>>()) {
            for (auto& pair : *thread_table) {
                object value = pair.second;
                if (value.is<protected_function>()) {
                    threads.emplace_back(value.as<protected_function>());
                }
            }
        }

        tracking.use(1);

        return Chart(
            wavmark,
            init_scene,
            length,
            std::move(threads)
        );
    }
}

sol::state init_state();

sol::protected_function_result run_script(sol::state_view& state, const std::string& filename);
