#include "hk/hook/Trampoline.h"
#include "nn/fs.h"
#include "aloha.h"
#include "global.h"
#include "log.h"
#include "scripting.h"


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
    runLuaChart(a1, a2, MAIN_SCRIPT);

    sub_7100138CD0(a1);
    sub_71001366E0(a1);

    rest_ticks(a2, 480);

    if (is_thread_stopping(a2)) {
        return;
    }

    sub_7100138FC0(a1);

    rest_ticks(a2, 480 * 3);

    if (is_thread_stopping(a2)) {
        return;
    }

    sub_7100137140(a1);
}


void remix20Control(s64 a1, s64 a2) {
    runLuaChart(a1, a2, CONTROL_SCRIPT);
}


HkTrampoline remix20AnimHook = [](TrampolineStatic(), s64 a1, s64 a2) -> s64 {
    reinterpret_cast<u32*>(a2)[4] -= sub_7100137990();

    runLuaChart(a1, a2, ANIM_SCRIPT);

    return sub_7100514FD0(a2);
};


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

    hk::hook::a64::assemble<"mov x0, x20">().installAtMainOffset(0x417574);
    hk::hook::a64::assemble<"mov x1, x19">().installAtMainOffset(0x417578);
    hk::hook::writeBranchLinkAtMainOffset(0x41757C, &remix20Main);
    hk::hook::writeBranchAtMainOffset(0x417580, reinterpret_cast<void*>(mainBase + 0x41799C));

    hk::hook::a64::assemble<"mov x0, x21">().installAtMainOffset(0x41F198);
    hk::hook::a64::assemble<"mov x1, x19">().installAtMainOffset(0x41F19C);
    hk::hook::writeBranchLinkAtMainOffset(0x41F1A0, &remix20Control);
    hk::hook::writeBranchAtMainOffset(0x41F1A4, reinterpret_cast<void*>(mainBase + 0x42029C));

    remix20AnimHook.installAtMainOffset(0x4179C0);
    remix20Cues00Hook.installAtMainOffset(0x418AE0);
    remix20Cues01Hook.installAtMainOffset(0x4194D0);
    remix20Cues02Hook.installAtMainOffset(0x41A020);
    remix20Cues03Hook.installAtMainOffset(0x41B8F0);
    remix20Cues04Hook.installAtMainOffset(0x41DCE0);
    remix20Cues05Hook.installAtMainOffset(0x41E770);
    remix20Cues06Hook.installAtMainOffset(0x418020);
    remix20Cues07Hook.installAtMainOffset(0x418500);
}
