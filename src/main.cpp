#include <hk/hook/Trampoline.h>
#include <nn/fs.h>
#include <string>
#include "global.h"
#include "chart.h"
#include "log.h"
#include "script.h"

static const char* graphBacteria[] = {
    "graph/scene/bacteria/type_lpr/main",
    "graph/scene/bacteria/type_lpr/bg",
    "graph/scene/bacteria/type_00/lesson_mark"
};

static_assert(sizeof(graphBacteria) == sizeof(char*) * 3);

static const char* graphBrush[] = {
    "graph/scene/brush/type_00/main",
    "graph/scene/brush/type_lpr/stage_000",
    "graph/scene/brush/type_lpr/actor_00",
    "graph/scene/brush/type_lpr/actor_01",
    "graph/scene/brush/type_lpr/actor_02",
    "graph/scene/brush/type_lpr/actor_03"
};

static_assert(sizeof(graphBrush) == sizeof(char*) * 6);

static const char* graphClap[] = {
    "graph/scene/clap/type_lpr/high_mip/main",
    "graph/scene/clap/type_lpr/high_mip/view_frame_00",
    "graph/scene/clap/type_lpr/view_tutorial",
    "graph/scene/clap/type_00/view_hand_00"
};

static_assert(sizeof(graphClap) == sizeof(char*) * 4);

static const char* graphHammer[] = {
    "graph/scene/hammer/type_lpr/main",
    "graph/scene/hammer/type_lpr/bg"
};

static_assert(sizeof(graphHammer) == sizeof(char*) * 2);

static const char* graphMoon[] = {
    "graph/scene/moon/type_lpr/main",
    "graph/scene/moon/type_lpr/bg",
    "graph/scene/moon/type_lpr/bg_obj_00",
    "graph/scene/moon/type_lpr/actor_00"
};

static_assert(sizeof(graphMoon) == sizeof(char*) * 4);

static const char* graphRing[] = {
    "graph/scene/ring/type_lpr/main",
    "graph/scene/ring/type_00/bg"
};

static_assert(sizeof(graphRing) == sizeof(char*) * 2);

static const char* graphRope[] = {
    "graph/scene/rope/type_lpr/main",
    "graph/scene/rope/type_lpr/bg_back",
    "graph/scene/rope/type_00/bg_middle",
    "graph/scene/rope/type_lpr/bg_front"
};

static_assert(sizeof(graphRope) == sizeof(char*) * 4);

bool isRemix20 = false;


HkTrampoline initHook = [](TrampolineStatic(), u64* a1) -> void {
    nn::fs::MountSdCard(SD_DRIVE);
    nn::fs::CreateDirectory(ROOT_FOLDER);

    initLog();

    log("=== Orochi Initialised! ===");
    orig(a1);
};


HkTrampoline mainLoopHook = [](TrampolineStatic(), s32 a1) -> void {
    orig(a1);
};


HkTrampoline stageFactoryCreateHook = [](TrampolineStatic(), u32 stageID, u64 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7) -> Stage* {
    log("creating stage: %d", stageID);

    isRemix20 = stageID == 107;

    return orig(stageID, a2, a3, a4, a5, a6, a7);
};


HkTrampoline getTextHook = [](TrampolineStatic(), void* a1, const char* a2, void* a3) -> const char* {
    const auto key = std::string(a2);
    const char* result = orig(a1, a2, a3);

    //if (key.ends_with("cold_open_title")) {
    //    result = "♪ Cold Open\nVocal：Rin Penrose";
    //}

    return result;
};


HkTrampoline getGraphBacteriaHook = [](TrampolineStatic(), int version) -> const char** {
    return isRemix20 ? graphBacteria : orig(version);
};


HkTrampoline getGraphBrushHook = [](TrampolineStatic(), int version) -> const char** {
    return isRemix20 ? graphBrush : orig(version);
};


HkTrampoline getGraphClapHook = [](TrampolineStatic(), int version) -> const char** {
    return isRemix20 ? graphClap : orig(version);
};


HkTrampoline getGraphHammerHook = [](TrampolineStatic(), int version) -> const char** {
    return isRemix20 ? graphHammer : orig(version);
};


HkTrampoline getGraphMoonHook = [](TrampolineStatic(), int version) -> const char** {
    return isRemix20 ? graphMoon : orig(version);
};


HkTrampoline getGraphRingHook = [](TrampolineStatic(), int version) -> const char** {
    return isRemix20 ? graphRing : orig(version);
};


HkTrampoline getGraphRopeHook = [](TrampolineStatic(), int version) -> const char** {
    return isRemix20 ? graphRope : orig(version);
};

HkTrampoline remix20EntryHook = [](TrampolineStatic(), StageRemix20* stage, SeqThread* thread) -> void {
    sol::state lua = init_state();

    auto result = run_script(lua, CHART_FILE);

    chartEntry(result.get<Chart>(), stage, thread);

    thread->popUnk270();
};


extern "C" void hkMain() {
    //const ptr mainBase = hk::ro::getMainModule()->range().start();

    initHook.installAtMainOffset(0x50CBA0);
    mainLoopHook.installAtMainOffset(0x509E10);
    stageFactoryCreateHook.installAtSym<"_ZN12StageFactory6createEjyjjjjj">();
    getTextHook.installAtMainOffset(0x4EFE80);

    remix20EntryHook.installAtMainOffset(0x416220);

    //getGraphBacteriaHook.installAtMainOffset(0x1434E0);
    //getGraphBrushHook.installAtMainOffset(0x158A00);
    //getGraphClapHook.installAtMainOffset(0x161D40);
    //getGraphHammerHook.installAtMainOffset(0x1A9920);
    //getGraphMoonHook.installAtMainOffset(0x1D8B60);
    //getGraphRingHook.installAtMainOffset(0x216530);
    //getGraphRopeHook.installAtMainOffset(0x224790);

    // over germ aerobics
    //hk::hook::writeBranchLinkAtMainOffset(0x4169C0, &makeSceneOnion);
    // over deep sea
    //hk::hook::writeBranchLinkAtMainOffset(0x416DF4, &makeSceneSkater);
}
