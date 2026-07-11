#include "hk/hook/Trampoline.h"
#include "nn/fs.h"
#include "aloha.h"
#include "global.h"
#include "log.h"
#include "scripting.h"

#define check_thread(a2) \
    if (is_thread_stopping(a2)) \
        return;

#define restb(beats) rest_ticks(a2, 480 * beats); \
    check_thread(a2);

#define scene_change_r(scene) \
    do { \
        v1 = sub_7100514FB0(a2); \
        change_scene(a1 + 28168, a2, scene); \
        unk_thread_check(a2, v1); \
        check_thread(a2); \
    } while (0);

#define scene_change_f(a1, a2, scene) \
    do { \
        v1 = sub_7100514FB0(a2); \
        change_scene_fade(a1 + 28168, a2, scene, 2); \
        unk_thread_check(a2, v1); \
        check_thread(a2); \
    } while (0);


HkTrampoline initHook = [](TrampolineStatic(), u64* a1) -> void {
    nn::fs::MountSdCard(SD_DRIVE);
    nn::fs::CreateDirectory(ROOT_FOLDER);

    initLog();

    log("=== Pyrite Initialised! ===");
    orig(a1);
};


HkTrampoline mainLoopHook = [](TrampolineStatic(), s32 a1) -> void {
    orig(a1);
};


void remix20Main(s64 a1, s64 a2) {
    //runLuaChart(a1, a2, MAIN_SCRIPT);

    restb(464);

    sub_7100138CD0(a1);
    sub_71001366E0(a1);

    restb(1);

    sub_7100138FC0(a1);

    restb(3);

    sub_7100137140(a1);
}


void remix20Control(s64 a1, s64 a2) {
    //runLuaChart(a1, a2, CONTROL_SCRIPT);
    s64 v1;

    restb(35.5);

    scene_change_r(1);
    restb(8);

    scene_change_r(26);
    restb(8);

    scene_change_r(29);
    restb(8);

    scene_change_r(8);
    restb(8);

    scene_change_r(22);
    restb(8);
}


void remix20Anim(s64 a1, s64 a2) {
    // runLuaChart(a1, a2, ANIM_SCRIPT);
    restb(20);

    set_anim(a1, a2, 0, 480, 0);
}


HkTrampoline remix20Cues00Hook = [](TrampolineStatic(), s64 a1, s64 a2) -> s64 {
    runLuaChart(a1, a2, CUES00_SCRIPT);

    return sub_7100514FD0(a2);
};


HkTrampoline remix20Cues01Hook = [](TrampolineStatic(), s64 a1, s64 a2) -> s64 {
    runLuaChart(a1, a2, CUES01_SCRIPT);

    return sub_7100514FD0(a2);
};


HkTrampoline remix20Cues02Hook = [](TrampolineStatic(), s64 a1, s64 a2) -> s64 {
    runLuaChart(a1, a2, CUES02_SCRIPT);

    return sub_7100514FD0(a2);
};


HkTrampoline remix20Cues03Hook = [](TrampolineStatic(), s64 a1, s64 a2) -> s64 {
    runLuaChart(a1, a2, CUES03_SCRIPT);

    return sub_7100514FD0(a2);
};


HkTrampoline remix20Cues04Hook = [](TrampolineStatic(), s64 a1, s64 a2) -> s64 {
    runLuaChart(a1, a2, CUES04_SCRIPT);

    return sub_7100514FD0(a2);
};


HkTrampoline remix20Cues05Hook = [](TrampolineStatic(), s64 a1, s64 a2) -> s64 {
    runLuaChart(a1, a2, CUES05_SCRIPT);

    return sub_7100514FD0(a2);
};


HkTrampoline remix20Cues06Hook = [](TrampolineStatic(), s64 a1, s64 a2) -> s64 {
    runLuaChart(a1, a2, CUES06_SCRIPT);

    //rest_ticks(a2, 480 * 58);

    //sub_7100514FB0(a2);
    //change_cue_scene(a1, a2, 10);

    //set_marking_criteria(a1, (char*)"basic");
    //spawn_guardian_cue02(*(s64*)(a1 + 58336), a2, 0, 0);

    //rest_ticks(a2, 480 * 8);

    //set_marking_criteria(a1, (char*)"basic");
    //spawn_guardian_cue02(*(s64*)(a1 + 58336), a2, 0, 0);

    //rest_ticks(a2, 480 * 504);

    return sub_7100514FD0(a2);
};


HkTrampoline remix20Cues07Hook = [](TrampolineStatic(), s64 a1, s64 a2) -> s64 {
    runLuaChart(a1, a2, CUES07_SCRIPT);

    return sub_7100514FD0(a2);
};

extern "C" void hkMain() {
    u64 mainBase = hk::ro::getMainModule()->range().start();

    initHook.installAtMainOffset(0x50CBA0);
    mainLoopHook.installAtMainOffset(0x509E10);

    constexpr u64 remix20MainOffset = 0x417574;
    hk::hook::a64::assemble<"mov x0, x20">().installAtMainOffset(remix20MainOffset);
    hk::hook::a64::assemble<"mov x1, x19">().installAtMainOffset(remix20MainOffset + 4);
    hk::hook::writeBranchLinkAtMainOffset(remix20MainOffset + 8, &remix20Main);
    hk::hook::writeBranchAtMainOffset(remix20MainOffset + 12, reinterpret_cast<void*>(mainBase + 0x41799C));

    constexpr u64 remix20ControlOffset = 0x41F198;
    hk::hook::a64::assemble<"mov x0, x21">().installAtMainOffset(remix20ControlOffset);
    hk::hook::a64::assemble<"mov x1, x19">().installAtMainOffset(remix20ControlOffset + 4);
    hk::hook::writeBranchLinkAtMainOffset(remix20ControlOffset + 8, &remix20Control);
    hk::hook::writeBranchAtMainOffset(remix20ControlOffset + 12, reinterpret_cast<void*>(mainBase + 0x42029C));

    constexpr u64 remix20AnimOffset = 0x4179F0;
    hk::hook::a64::assemble<"mov x0, x20">().installAtMainOffset(remix20AnimOffset);
    hk::hook::a64::assemble<"mov x1, x19">().installAtMainOffset(remix20AnimOffset + 4);
    hk::hook::writeBranchLinkAtMainOffset(remix20AnimOffset + 8, &remix20Anim);
    hk::hook::writeBranchAtMainOffset(remix20AnimOffset + 12, reinterpret_cast<void*>(mainBase + 0x41800C));

    remix20Cues00Hook.installAtMainOffset(0x418AE0);
    remix20Cues01Hook.installAtMainOffset(0x4194D0);
    remix20Cues02Hook.installAtMainOffset(0x41A020);
    remix20Cues03Hook.installAtMainOffset(0x41B8F0);
    remix20Cues04Hook.installAtMainOffset(0x41DCE0);
    remix20Cues05Hook.installAtMainOffset(0x41E770);
    remix20Cues06Hook.installAtMainOffset(0x418020);
    remix20Cues07Hook.installAtMainOffset(0x418500);
}
