#pragma once

#include "global.h"
#include <magic_enum/magic_enum.hpp>
#include <sol/sol.hpp>
#include "aloha/Stage.h"
#include "chart.h"

template <typename E> E get_enum_or(sol::table& tbl, const char* name, E fallback) {
    auto value = tbl.get<std::underlying_type_t<E>>(name);

    if (!magic_enum::enum_contains<E>(value))
        return fallback;

    return static_cast<E>(value);
}

namespace sol {
    inline Chart sol_lua_get(types<Chart>, lua_State* L, int index, stack::record& tracking) {
        auto tbl = sol::stack::get<table>(L, index);

        WavMarkId wavmark = get_enum_or<WavMarkId>(tbl, "wavmark", wavmark_invalid);
        Remix20SceneID init_scene = get_enum_or<Remix20SceneID>(tbl, "init_scene", SCENE_INVALID);
        f32 length = tbl.get<f32>("length");

        tracking.use(1);

        return Chart{
            .wavmark = wavmark,
            .init_scene = init_scene,
            .length = length
        };
    }
}

sol::state init_state();

sol::protected_function_result run_script(sol::state_view& state, const std::string& filename);
