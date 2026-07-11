#include "hk/hook/Trampoline.h"
#include "nn/fs.h"
#include "arm_neon.h"
#include "aloha.h"
#include "global.h"
#include "log.h"
#include "scripting.h"


HkTrampoline initHook = [](TrampolineStatic(), u64* a1) -> void {
    nn::fs::MountSdCard(SD_DRIVE);
    nn::fs::CreateDirectory(ROOT_FOLDER);

    initLog();

    orig(a1);
};


HkTrampoline mainLoopHook = [](TrampolineStatic(), s32 a1) -> void {
    orig(a1);
};


HkTrampoline remix20AnimHook = [](TrampolineStatic(), s64 a1, u32* a2) -> s64 {
    a2[4] -= sub_7100137990();

    //rest_ticks(a2, 480 * 18);
    //anim_unk_sub_71001379A0(a1, (s64)a2, 0, 480, 0);
    //rest_ticks(a2, 480 * 153);
    //sub_7100137A80(a1);
    //rest_ticks(a2, 480 * 7);
    //anim_unk_sub_71001379A0(a1, (s64)a2, 0, 480, 0);
    //rest_ticks(a2, 480 * 349);
    //sub_7100137A80(a1);
    //rest_ticks(a2, 480 * 3);
    //anim_unk_sub_71001379A0(a1, (s64)a2, 0, 480, 0);
    //rest_ticks(a2, 480 * 32);
    //sub_7100137A80(a1);
    //rest_ticks(a2, 480 * 4);
    //anim_unk_sub_71001379A0(a1, (s64)a2, 0, 480, 0);
    //rest_ticks(a2, 480 * 12);
    //sub_7100137A80(a1);
    //rest_ticks(a2, 480 * 4);

    return sub_7100514FD0((s64)a2);
};


void remix20Main(s64 a1, u32* a2) {
    rest_ticks(a2, 480 * 4);

    sub_7100138CD0(a1);
    sub_71001366E0(a1);

    rest_ticks(a2, 480);

    sub_7100138FC0(a1);

    rest_ticks(a2, 480 * 15);

    sub_7100137140(a1);
}


void remix20Control(s64 a1, u32* a2) {
    log("remix20Control - start");

    rest_ticks(a2, 480 * 17);

    s64 v1 = sub_7100514FB0((s64)a2);
    change_scene_fade(a1 + 28168, (s64)a2, 1, 2);
    unk_thread_check((s64)a2, v1);
    sub_71004F8260(*(s64*)(((s64*)a1)[7265] + 15208LL), (char*)"SetupCloud");

    log("remix20Control - end");
}


HkTrampoline remix20Cues00Hook = [](TrampolineStatic(), s64 a1, u32* a2) -> s64 {
    return sub_7100514FD0((s64)a2);
};


HkTrampoline remix20Cues01Hook = [](TrampolineStatic(), s64 a1, u32* a2) -> s64 {
    return sub_7100514FD0((s64)a2);
};


HkTrampoline remix20Cues02Hook = [](TrampolineStatic(), s64 a1, u32* a2) -> s64 {
    return sub_7100514FD0((s64)a2);
};


HkTrampoline remix20Cues03Hook = [](TrampolineStatic(), s64 a1, u32* a2) -> s64 {
    return sub_7100514FD0((s64)a2);
};


HkTrampoline remix20Cues04Hook = [](TrampolineStatic(), s64 a1, u32* a2) -> s64 {
    return sub_7100514FD0((s64)a2);
};


HkTrampoline remix20Cues05Hook = [](TrampolineStatic(), s64 a1, u32* a2) -> s64 {
    return sub_7100514FD0((s64)a2);
};


HkTrampoline remix20Cues06Hook = [](TrampolineStatic(), s64 a1, u32* a2) -> s64 {
    //rest_ticks(a2, 480 * 58);

    //sub_7100514FB0((s64)a2);
    //change_cue_scene(a1, (s64)a2, 10);

    //set_marking_criteria(a1, (char*)"basic");
    //spawn_guardian_cue02(*(s64*)(a1 + 58336), (s64)a2, 0, 0);

    //rest_ticks(a2, 480 * 8);

    //set_marking_criteria(a1, (char*)"basic");
    //spawn_guardian_cue02(*(s64*)(a1 + 58336), (s64)a2, 0, 0);

    //rest_ticks(a2, 480 * 504);

    return sub_7100514FD0((s64)a2);
};


HkTrampoline remix20Cues07Hook = [](TrampolineStatic(), s64 a1, u32* a2) -> s64 {
    return sub_7100514FD0((s64)a2);
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
