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


s64 remix20Control(s64 a1, u32* a2) {
    /*
    // s64 qword_7100D9C638 = *(s64*)(hk::ro::getMainModule()->range().start() + 0xD9C638);
    // s64 qword_7100D9C640 = *(s64*)(hk::ro::getMainModule()->range().start() + 0xD9C640);
    // s64 qword_7100D9C6A8 = *(s64*)(hk::ro::getMainModule()->range().start() + 0xD9C6A8);

    // u64* v4 = a1 + 1705;
    // s64* v5 = (s64*)operator new(664LL);
    // s64 v6 = a1[1706];
    // s32 v7 = *(a1 + 3416);
    // s64* v8 = v5;
    // s64 v9 = qword_7100D9C638 + 16;
    // s64 v10 = qword_7100D9C638 + 64;
    // *v5 = qword_7100D9C638 + 16;
    // v5[3] = v10;
    // sub_7100514A90((s64)v5, v6, v7, qword_7100D9C640, (s64)(v5 + 80), (s64)a2);
    // *v8 = v9;
    // v8[3] = v10;
    // v8[80] = (s64)v4;
    // s64 v11 = qword_7100D9C6A8;
    // s64 v12 = a1[1706];
    // v8[82] = 0LL;
    // v8[81] = v11;
    // sub_71005153A0(v12, (s64)v8);
    // sub_71004DA420((u32*)a1, 3);
    // sub_71004D9E10((u32*)a1, 960);
    
    rest_ticks(a2, 960);

    rest_ticks(a2, 480 * 16);

    rest_ticks(a2, 480 * 16);

    rest_ticks(a2, 3 * 480 * 4);

    rest_ticks(a2, 480);

    rest_ticks(a2, 480);

    rest_ticks(a2, 480);

    // sub_7100514FB0((s64)a2);
    // sub_71003B86F0((s64)(a1 + 3521), (s64)a2, 1u, 2u);

    // sub_71004F8260(*(s64*)(a1[7265] + 15208LL), (char*)"SetupCloud");
    rest_ticks(a2, 480);

    rest_ticks(a2, 480 * 16);

    sub_71004DA400((s64)a1, 1, 1);
    sub_7100514FB0((s64)a2);
    change_scene((s64)(a1 + 3521), (s64)a2, 10);

    rest_ticks(a2, 480 * 16);

    // sub_7100514FB0((s64)a2);
    // change_scene((s64)(a1 + 3521), (s64)a2, 0xEu);

    rest_ticks(a2, 480 * 16);

    // sub_7100514FB0((s64)a2);
    // change_scene((s64)(a1 + 3521), (s64)a2, 6u);

    rest_ticks(a2, 480 * 12);

    rest_ticks(a2, 480);

    rest_ticks(a2, 480);

    // sub_7100514FB0((s64)a2);
    // sub_71003B86F0((s64)(a1 + 3521), (s64)a2, 0, 2u);

    rest_ticks(a2, 480);

    rest_ticks(a2, 480);

    rest_ticks(a2, 480 * 12);

    // sub_7100514FB0((s64)a2);
    // sub_71003B8770((s64)(a1 + 3521), (s64)a2, 4u, 2u);

    rest_ticks(a2, 480);

    rest_ticks(a2, 480);

    rest_ticks(a2, 480);

    rest_ticks(a2, 480);

    // sub_7100514FB0((s64)a2);
    // change_scene((s64)(a1 + 3521), (s64)a2, 4u);

    //s64 v16 = a1[7274];
    //s64 v17 = (loc_71004EFE80)(a1 + 7353, "s00_m_tv_00", 0LL);
    //sub_7100162DE0(v16, v17);
    rest_ticks(a2, 480 * 16);

    // sub_7100514FB0((s64)a2);
    // change_scene((s64)(a1 + 3521), (s64)a2, 0x1Au);

    rest_ticks(a2, 480 * 16);

    // sub_7100514FB0((s64)a2);
    // change_scene((s64)(a1 + 3521), (s64)a2, 8u);

    // sub_710018C730(a1[7286], (char*)"BG_IMG_B");
    rest_ticks(a2, 480 * 12);

    rest_ticks(a2, 480);

    rest_ticks(a2, 480);

    rest_ticks(a2, 480);

    // sub_7100514FB0((s64)a2);
    // sub_71003B86F0((s64)(a1 + 3521), (s64)a2, 0x16u, 2u);

    rest_ticks(a2, 480);

    rest_ticks(a2, 480 * 16);

    // sub_7100514FB0((s64)a2);
    // change_scene((s64)(a1 + 3521), (s64)a2, 0x1Du);

    // sub_71002A8E10((s64)a1[7349]);
    rest_ticks(a2, 480 * 16);

    // sub_7100514FB0((s64)a2);
    // change_scene((s64)(a1 + 3521), (s64)a2, 0xCu);

    rest_ticks(a2, 480 * 16);

    // sub_7100514FB0((s64)a2);
    // change_scene((s64)(a1 + 3521), (s64)a2, 0x18u);

    rest_ticks(a2, 480 * 16);

    // sub_7100514FB0((s64)a2);
    // change_scene((s64)(a1 + 3521), (s64)a2, 0x13u);

    rest_ticks(a2, 480 * 16);

    // sub_7100514FB0((s64)a2);
    // sub_71003B86F0((s64)(a1 + 3521), (s64)a2, 0xFu, 2u);

    rest_ticks(a2, 480 * 12);

    rest_ticks(a2, 480);

    // sub_7100514FB0((s64)a2);
    // sub_71003B86F0((s64)(a1 + 3521), (s64)a2, 0x15u, 2u);

    rest_ticks(a2, 480);

    rest_ticks(a2, 480);

    rest_ticks(a2, 480);

    rest_ticks(a2, 480 * 16);

    // sub_7100514FB0((s64)a2);
    // change_scene((s64)(a1 + 3521), (s64)a2, 2u);

    // sub_71004F8260(*(s64*)(a1[7268] + 16576LL), (char*)"FinishSceneChange");
    // s64 v18 = sub_71004FBA20(*(s64*)(a1[7268] + 16568LL), (char*)"you", 1);
    // sub_71004F7A80(v18, (char*)"YOU_B", 0);
    rest_ticks(a2, 480 * 16);

    // sub_7100514FB0((s64)a2);
    // change_scene((s64)(a1 + 3521), (s64)a2, 0x14u);

    rest_ticks(a2, 480 * 16);

    // sub_7100514FB0((s64)a2);
    // change_scene((s64)(a1 + 3521), (s64)a2, 0x1Eu);

    rest_ticks(a2, 480 * 12);

    rest_ticks(a2, 480);

    rest_ticks(a2, 480);

    rest_ticks(a2, 480);

    // sub_7100514FB0((s64)a2);
    // sub_71003B86F0((s64)(a1 + 3521), (s64)a2, 0x12u, 2u);

    rest_ticks(a2, 480);

    rest_ticks(a2, 480 * 12);

    rest_ticks(a2, 480);

    rest_ticks(a2, 480);

    rest_ticks(a2, 480);

    rest_ticks(a2, 480);

    // sub_7100514FB0((s64)a2);
    // sub_71003B86F0((s64)(a1 + 3521), (s64)a2, 0x1Bu, 2u);

    rest_ticks(a2, 480 * 12);

    rest_ticks(a2, 480);

    rest_ticks(a2, 480);

    rest_ticks(a2, 480);

    rest_ticks(a2, 240);

    // sub_7100514FB0((s64)a2);
    // sub_71003B86F0((s64)(a1 + 3521), (s64)a2, 5u, 2u);

    rest_ticks(a2, 240);

    // sub_71001792D0(a1[7277], (s64)a2, 0);
    rest_ticks(a2, 480 * 16);

    // sub_7100137B50((s64)a1, 240);
    // sub_7100137B60((s64)a1, 100);
    // sub_7100514FB0((s64)a2);
    // change_scene((s64)(a1 + 3521), (s64)a2, 0x1Cu);

    rest_ticks(a2, 480 * 16);

    // sub_7100137B50((s64)a1, 120);
    // sub_7100137B60((s64)a1, 0);
    // sub_7100514FB0((s64)a2);
    // change_scene((s64)(a1 + 3521), (s64)a2, 0x10u);

    rest_ticks(a2, 480 * 16);

    // sub_7100514FB0((s64)a2);
    // change_scene((s64)(a1 + 3521), (s64)a2, 9u);

    rest_ticks(a2, 480 * 12);

    rest_ticks(a2, 480);

    rest_ticks(a2, 480);

    rest_ticks(a2, 480);

    rest_ticks(a2, 120);

    rest_ticks(a2, 120);

    rest_ticks(a2, 120);

    // sub_7100514FB0((s64)a2);
    // sub_71003B86F0((s64)(a1 + 3521), (s64)a2, 0x19u, 2u);

    rest_ticks(a2, 120);

    rest_ticks(a2, 480 * 16);

    // sub_7100514FB0((s64)a2);
    // sub_71003B86F0((s64)(a1 + 3521), (s64)a2, 0xBu, 2u);

    rest_ticks(a2, 480 * 16);

    // sub_7100514FB0((s64)a2);
    // change_scene((s64)(a1 + 3521), (s64)a2, 3u);

    rest_ticks(a2, 480 * 16);

    // sub_7100514FB0((s64)a2);
    // sub_71003B8770((s64)(a1 + 3521), (s64)a2, 0x17u, 2u);

    // *(s64*)(a1[7331] + 15980LL) = 1;
    rest_ticks(a2, 480 * 16);

    // sub_7100514FB0((s64)a2);
    // change_scene((s64)(a1 + 3521), (s64)a2, 0xDu);

    // sub_71001B24D0(a1[7301]);
    rest_ticks(a2, 480 * 16);

    // sub_7100514FB0((s64)a2);
    // change_scene((s64)(a1 + 3521), (s64)a2, 7u);

    rest_ticks(a2, 480 * 12);

    // sub_7100514FB0((s64)a2);
    // sub_71003BE7D0((s64)(a1 + 3521), (s64)a2, 0x11u, 2u);

    rest_ticks(a2, 480);

    rest_ticks(a2, 480);

    rest_ticks(a2, 480);

    rest_ticks(a2, 480);

    rest_ticks(a2, 5 * 480 * 4);

    rest_ticks(a2, 480 * 4);

    rest_ticks(a2, 480 * 4);

    rest_ticks(a2, 480);

    rest_ticks(a2, 480);

    // *(s64*)(a1[7313] + 15912LL) = 1;
    // *(s64*)(a1[7313] + 15916LL) = 0;
    rest_ticks(a2, 480);

    rest_ticks(a2, 480);

    rest_ticks(a2, 480 * 4);

    // sub_71004F4610(a1[7313] + 14496LL, (char*)"PR_RAIN_FADER", (char*)"RainFadeOut", 1, 0);
    // sub_71004F8260(*(s64*)(a1[7313] + 15536LL), (char*)"SetSunnyBG");
    // *(s64*)(a1[7313] + 15912LL) = 0;
    rest_ticks(a2, 480 * 4);

    rest_ticks(a2, 480 * 4);

    rest_ticks(a2, 480);

    rest_ticks(a2, 480);

    // *(s64*)(a1[7313] + 15912LL) = 1;
    // *(s64*)(a1[7313] + 15916LL) = 1;
    rest_ticks(a2, 480);

    rest_ticks(a2, 240);

    // sub_71004F8260(*(s64*)(a1[7313] + 15536LL), (char*)"SetShineBG");
    rest_ticks(a2, 240);

    rest_ticks(a2, 480 * 4);
    */

    rest_ticks(a2, 480 * 17);

    s64 v1 = sub_7100514FB0((s64)a2);
    change_scene(a1 + 28168, (s64)a2, 1);
    unk_thread_check((s64)a2, v1);
    sub_71004F8260(*(s64*)(((s64*)a1)[7265] + 15208LL), (char*)"SetupCloud");

    return sub_7100514FD0((s64)a2);
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
    initHook.installAtMainOffset(0x50CBA0);
    mainLoopHook.installAtMainOffset(0x509E10);

    //remix20MainHook.installAtMainOffset(0x417060);
    remix20AnimHook.installAtMainOffset(0x4179C0);

    hk::hook::a64::assemble<"mov x0, x21">().installAtMainOffset(0x41F198);
    hk::hook::a64::assemble<"mov x1, x19">().installAtMainOffset(0x41F19C);
    hk::hook::writeBranchAtMainOffset(0x41F1A0, &remix20Control);

    remix20Cues00Hook.installAtMainOffset(0x418AE0);
    remix20Cues01Hook.installAtMainOffset(0x4194D0);
    remix20Cues02Hook.installAtMainOffset(0x41A020);
    remix20Cues03Hook.installAtMainOffset(0x41B8F0);
    remix20Cues04Hook.installAtMainOffset(0x41DCE0);
    remix20Cues05Hook.installAtMainOffset(0x41E770);
    remix20Cues06Hook.installAtMainOffset(0x418020);
    remix20Cues07Hook.installAtMainOffset(0x418500);
}
