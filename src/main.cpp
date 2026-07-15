#include "hk/hook/Trampoline.h"
#include "nn/fs.h"
#include "aloha.h"
#include "global.h"
#include "log.h"
#include "scripting.h"

#define check_thread(a2) \
    if (is_thread_stopping(a2)) \
        return;

#define check_threadc(a2) \
    if (is_thread_stopping(a2)) \
        return sub_7100514FD0(a2);;

#define restb(beats) rest_ticks(a2, 480 * beats); \
    check_thread(a2);

#define restbc(beats) rest_ticks(a2, 480 * beats); \
    check_threadc(a2);

#define scene_change_r(scene) \
    do { \
        v1 = sub_7100514FB0(a2); \
        change_scene(a1 + 28168, a2, scene); \
        unk_thread_check(a2, v1); \
        check_thread(a2); \
    } while (0);

#define scene_change_f(scene) \
    do { \
        v1 = sub_7100514FB0(a2); \
        change_scene_fade(a1 + 28168, a2, scene, 2); \
        unk_thread_check(a2, v1); \
        check_thread(a2); \
    } while (0);

#define scene_change_sf(scene) \
    do { \
        v1 = sub_7100514FB0(a2); \
        change_scene_slow_fade(a1 + 28168, a2, scene, 2); \
        unk_thread_check(a2, v1); \
        check_thread(a2); \
    } while (0);

#define cue_scene_change(scene) \
    do { \
        v1 = sub_7100514FB0(a2); \
        change_cue_scene(a1, a2, scene); \
        unk_thread_check(a2, v1); \
        check_threadc(a2); \
    } while (0);

#define set_criteria(criteria) \
    set_marking_criteria(a1, const_cast<char*>(criteria))

#define parasol_cue(ticks, a4, a5, a6) \
    spawn_parasol_cue(reinterpret_cast<s64*>(a1)[7313], a2, ticks, a4, a5, a6)

#define birds_cue(cue) \
    spawn_birds_cue(reinterpret_cast<s64*>(a1)[7265], a2, const_cast<char*>(cue))

#define talk_cue00() \
    spawn_talk_cue00(reinterpret_cast<s64*>(a1)[7340])

#define talk_cue01() \
    spawn_talk_cue01(reinterpret_cast<s64*>(a1)[7340])

#define talk_cue02() \
    spawn_talk_cue02(reinterpret_cast<s64*>(a1)[7340])

#define wiper_cue_RS(a3) \
    spawn_wiper_cue_RS(reinterpret_cast<s64*>(a1)[7349], a2, a3)

#define wiper_cue_LS(a3) \
    spawn_wiper_cue_LS(reinterpret_cast<s64*>(a1)[7349], a2, a3)

#define wiper_cue_BS() \
    spawn_wiper_cue_BS(reinterpret_cast<s64*>(a1)[7349])

#define wiper_cue_RQ() \
    spawn_wiper_cue_RQ(reinterpret_cast<s64*>(a1)[7349])

#define wiper_cue_LQ() \
    spawn_wiper_cue_LQ(reinterpret_cast<s64*>(a1)[7349])

#define wiper_cue_BQ() \
    spawn_wiper_cue_BQ(reinterpret_cast<s64*>(a1)[7349])

#define flydisc_cue(a3, ticks, a5, a6) \
    spawn_flydisc_cue(reinterpret_cast<s64*>(a1)[7286], a2, a3, ticks, a5, a6)

#define rope_cue00(ticks, a4) \
    spawn_rope_cue00(reinterpret_cast<s64*>(a1)[7328], a2, ticks, a4)

#define rope_cue01(ticks, a4, a5) \
    spawn_rope_cue01(reinterpret_cast<s64*>(a1)[7328], a2, ticks, a4, a5)

#define crab_cue00(a3, a4, a5) \
    spawn_crab_cue00(reinterpret_cast<s64*>(a1)[7280], a2, a3, a4, a5)

#define crab_cue02(a3, a4, a5) \
    spawn_crab_cue02(reinterpret_cast<s64*>(a1)[7280], a2, a3, a4, a5)

#define clap_123() \
    spawn_clap_123(reinterpret_cast<s64*>(a1)[7274])

#define clap_321() \
    spawn_clap_321(reinterpret_cast<s64*>(a1)[7274])

#define clap_cue00(a3) \
    spawn_clap_cue00(reinterpret_cast<s64*>(a1)[7274], a2, a3)

#define clap_cue01() \
    spawn_clap_cue01(reinterpret_cast<s64*>(a1)[7274], a2)

#define clap_cue02() \
    spawn_clap_cue02(reinterpret_cast<s64*>(a1)[7274])

#define clap_cue03() \
    spawn_clap_cue03(reinterpret_cast<s64*>(a1)[7274], a2)

#define clap_cue04() \
    spawn_clap_cue04(reinterpret_cast<s64*>(a1)[7274])

#define bacteria_cue00(beats, a4) \
    spawn_bacteria_cue00(reinterpret_cast<s64*>(a1)[7262], a2, beats, a4)

#define bacteria_cue01(a3) \
    spawn_bacteria_cue01(reinterpret_cast<s64*>(a1)[7262], a2, a3)

#define bacteria_cue03() \
    spawn_bacteria_cue03(reinterpret_cast<s64*>(a1)[7262])

#define insect_cue01(ticks, alsoTicks, a5) \
    spawn_insect_cue01(reinterpret_cast<s64*>(a1)[7304], a2, ticks, alsoTicks, a5)

#define insect_cue02(ticks, alsoTicks, a5) \
    spawn_insect_cue02(reinterpret_cast<s64*>(a1)[7304], a2, ticks, alsoTicks, a5)

#define hungry_cue(a3) \
    spawn_hungry_cue(reinterpret_cast<s64*>(a1)[7298], a2, a3)

#define guardian_cue00(a3, a4) \
    spawn_guardian_cue00(reinterpret_cast<s64*>(a1)[7292], a2, a3, a4)

#define guardian_cue01(a3, a4) \
    spawn_guardian_cue01(reinterpret_cast<s64*>(a1)[7292], a2, a3, a4)

#define guardian_cue02(a3, a4) \
    spawn_guardian_cue02(reinterpret_cast<s64*>(a1)[7292], a2, a3, a4)


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

    restb(462);

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

    restb(33.5);

    sub_71004DA400(a1, 17, 1);

    scene_change_r(1);
    sub_71004DA400(a1, 1, 1);
    // if you're wondering about why I have horrid pointer math like this,
    // it's because sometimes when I do it nicely it seg faults
    sub_71004F8260(*(s64*)(((s64*)a1)[7265] + 15208), const_cast<char*>("SetupCloud"));
    restb(8);

    scene_change_f(26);
    sub_71004DA400(a1, 26, 1);
    restb(8);

    scene_change_r(29);
    sub_71004DA400(a1, 29, 1);
    restb(8);

    scene_change_f(8);
    sub_71004DA400(a1, 8, 1);
    sub_710018C730(((s64*)a1)[7286], const_cast<char*>("BG_IMG_B"));
    restb(7.25); // -0.75

    scene_change_f(22);
    sub_71004DA400(a1, 22, 1);
    restb(32.75); // +0.75

    scene_change_sf(6);
    sub_71004DA400(a1, 6, 1);
    restb(16);

    scene_change_f(4);
    sub_71004DA400(a1, 4, 1);
    // crashes on hardware
    //sub_7100162DE0(((s64*)a1)[7274], sub_71004EFE80(((s64*)a1)[7353], const_cast<char*>("s00_m_tv_00"), 0));
    restb(20.5); // -2.0 -1.5

    scene_change_sf(0);
    sub_71004DA400(a1, 0, 1);
    restb(36);

    scene_change_f(14);
    sub_71004DA400(a1, 14, 1);
    restb(27.75); // -0.25

    scene_change_r(12);
    sub_71004DA400(a1, 12, 1);
    restb(16.25); // +0.25

    scene_change_f(10);
    sub_71004DA400(a1, 10, 1);
    restb(14.5); // -1.5

    scene_change_f(22);
    restb(33.5); // +1.5

    scene_change_sf(6);
    restb(15.5); // -0.5

    scene_change_f(4);
    restb(17); // -0.5 +0.5

    scene_change_sf(0);
    restb(7); // +0.5 -1.0

    scene_change_r(29);
    restb(8); // +1.0 -1.0s

    scene_change_f(1);
    restb(15); // -1.0

    scene_change_f(12);
    restb(9); // +1.0

    scene_change_r(17);
    restb(8);

    scene_change_f(8);
    restb(8);

    scene_change_f(14);
    restb(8);

    scene_change_f(26);
    restb(8);

    scene_change_r(1);
    restb(8);

    scene_change_r(29);
    restb(16);

    scene_change_r(4);
    restb(16);

    scene_change_r(17);
    restb(8);

    scene_change_f(14);
    restb(8);

    scene_change_r(22);
    restb(20);

    scene_change_r(12);
    restb(12);

    scene_change_f(8);
    restb(8);
}


void remix20Anim(s64 a1, s64 a2) {
    //runLuaChart(a1, a2, ANIM_SCRIPT);
    restb(32);

    set_anim(a1, a2, 0, 192, 0);
    restb(2);
    set_anim(a1, a2, 0, 480, 0);
    restb(25);

    stop_anim(a1);
    restb(5);

    set_anim(a1, a2, 0, 480, 0);
    restb(279);

    stop_anim(a1);
    restb(5);

    set_anim(a1, a2, 0, 480, 0);
    restb(107);

    stop_anim(a1);
}


HkTrampoline remix20Cues00Hook = [](TrampolineStatic(), s64 a1, s64 a2) -> s64 {
    //runLuaChart(a1, a2, CUES00_SCRIPT);
    s64 v1;

    restbc(14);

    cue_scene_change(17);
    set_criteria("basic");
    restbc(1);

    parasol_cue(480, 1, 0, 0);
    restbc(8);
    parasol_cue(480, 0, 0, 0);
    restbc(8);

    restbc(100);

    cue_scene_change(4);
    set_criteria("basic");
    restbc(1);

    restbc(1);

    bacteria_cue00(13, 1);
    restbc(13);
    bacteria_cue03();
    restbc(2);
    bacteria_cue00(14, 0);
    restbc(14);
    bacteria_cue03();
    restbc(2);
    bacteria_cue01(0);

    restbc(128); // +4

    cue_scene_change(4);
    set_criteria("basic");
    restbc(1);

    bacteria_cue00(4, 1);

    restbc(37);

    cue_scene_change(17);
    set_criteria("basic");
    restbc(1);

    parasol_cue(480, 1, 0, 0);
    restbc(4);
    set_criteria("tech");
    parasol_cue(240, 0, 0, 0);
    restbc(2);
    parasol_cue(240, 1, 0, 0);
    restbc(2);

    restbc(63);

    cue_scene_change(17);
    set_criteria("tech");
    restbc(1);

    parasol_cue(480, 0, 0, 0);
    restbc(0.5);
    parasol_cue(480, 1, 0, 0);
    restbc(3.5);
    parasol_cue(480, 0, 0, 0);
    restbc(0.5);
    parasol_cue(480, 1, 0, 0);
    restbc(3.5);

    //restbc(); // -4

    return sub_7100514FD0(a2);
};


HkTrampoline remix20Cues01Hook = [](TrampolineStatic(), s64 a1, s64 a2) -> s64 {
    //runLuaChart(a1, a2, CUES01_SCRIPT);
    s64 v1;

    restbc(32);

    cue_scene_change(1);
    set_criteria("basic");
    restbc(1);

    birds_cue("D...U...D...U?..");
    restbc(8);

    restbc(122);

    cue_scene_change(14);
    set_criteria("basic");
    restbc(1);

    restbc(4);

    insect_cue01(240, 480 * 4, 0);
    restbc(4);
    insect_cue01(240, 480 * 4, 0);
    restbc(4);

    insect_cue01(240, 480 * 4, 0);
    restbc(2);
    insect_cue01(240, 480 * 4, 0);
    restbc(2);
    insect_cue01(240, 480 * 4, 0);
    restbc(4);

    set_criteria("tech");
    insect_cue02(480, 480 * 4, 0);
    restbc(5);
    insect_cue02(480, 480 * 4, 0);
    restbc(3);

    restbc(116);

    cue_scene_change(1);
    set_criteria("tech");
    restbc(1);

    birds_cue("D...U...D.U.D.U?");
    restbc(8);

    set_criteria("basic");
    birds_cue("D...U...D...U?..");
    restbc(8);

    restbc(20);

    cue_scene_change(14);
    set_criteria("basic");
    restbc(1);

    insect_cue01(240, 480 * 4, 0);
    restbc(2);
    insect_cue01(240, 480 * 4, 0);
    restbc(2);
    set_criteria("tech");
    insect_cue02(480, 480 * 4, 0);
    insect_cue01(240, 480 * 4, 0);
    restbc(4);

    restbc(10);

    cue_scene_change(1);
    set_criteria("basic");
    restbc(1);

    birds_cue("D...U...D...U?..");
    restbc(8);

    restbc(36);

    cue_scene_change(14);
    set_criteria("tech");
    restbc(1);

    insect_cue01(240, 480 * 4, 0);
    insect_cue02(480, 480 * 4, 0);
    restbc(2);
    insect_cue02(480, 480 * 4, 0);
    restbc(2);
    insect_cue02(480, 480 * 4, 0);
    restbc(2);

    return sub_7100514FD0(a2);
};


HkTrampoline remix20Cues02Hook = [](TrampolineStatic(), s64 a1, s64 a2) -> s64 {
    //runLuaChart(a1, a2, CUES02_SCRIPT);
    s64 v1;

    restbc(40);

    cue_scene_change(26);
    set_criteria("basic");
    restbc(1);

    talk_cue01();
    restbc(4);
    talk_cue01();
    restbc(4);

    restbc(140); // -2.0

    cue_scene_change(12);
    set_criteria("basic");
    restbc(1);

    hungry_cue(0);
    restbc(1);
    hungry_cue(0);
    restbc(1);
    hungry_cue(1);
    restbc(2);

    restbc(3);
    hungry_cue(1);
    restbc(1);

    hungry_cue(0);
    restbc(1);
    hungry_cue(1);
    restbc(2);
    hungry_cue(1);
    restbc(1);

    restbc(111); // +2.0

    cue_scene_change(12);
    set_criteria("tech");
    restbc(1);

    hungry_cue(1);
    restbc(1);
    hungry_cue(1);
    restbc(1);
    hungry_cue(1);
    restbc(1);
    hungry_cue(1);
    restbc(4); // +3.0

    set_criteria("basic");
    hungry_cue(0);
    restbc(2);
    hungry_cue(0);
    restbc(2);

    restbc(31);

    cue_scene_change(26);
    set_criteria("tech");
    restbc(1);

    talk_cue02();
    restbc(4);
    talk_cue00();
    restbc(4);

    restbc(67);

    cue_scene_change(12);
    set_criteria("tech");
    restbc(1);

    hungry_cue(1);
    restbc(5);

    hungry_cue(0);
    restbc(1.5);

    hungry_cue(0);
    restbc(1);
    hungry_cue(0);
    restbc(1.5);

    hungry_cue(0);
    restbc(1);
    hungry_cue(0);
    restbc(1);

    return sub_7100514FD0(a2);
};


HkTrampoline remix20Cues03Hook = [](TrampolineStatic(), s64 a1, s64 a2) -> s64 {
    //runLuaChart(a1, a2, CUES03_SCRIPT);
    s64 v1;

    restbc(48);

    cue_scene_change(29);
    set_criteria("basic");
    restbc(1);

    wiper_cue_LQ();
    restbc(4);
    wiper_cue_BQ();
    restbc(4);

    restbc(144); // -10.0

    cue_scene_change(10);
    set_criteria("basic");
    restbc(1);

    set_criteria("basic");
    guardian_cue00(0, 0);
    restbc(4);
    set_criteria("must");
    guardian_cue01(0, 0);
    restbc(4);

    set_criteria("basic");
    guardian_cue00(0, 0);
    restbc(4);
    set_criteria("must");
    guardian_cue02(0, 0);
    restbc(4);

    restbc(78); // +10.0 -5.0

    cue_scene_change(29);
    set_criteria("basic");
    restbc(1);

    wiper_cue_RS(1);
    restbc(1);
    wiper_cue_LS(1);
    restbc(4); // +1.0

    wiper_cue_BS();
    restbc(8);

    restbc(62); // +4.0

    cue_scene_change(29);
    set_criteria("basic");
    restbc(1);

    wiper_cue_LQ();
    restbc(4);
    wiper_cue_RQ();
    restbc(4);
    wiper_cue_BQ();
    wiper_cue_LS(1);
    restbc(1);
    wiper_cue_RS(1);
    restbc(7);

    return sub_7100514FD0(a2);
};


HkTrampoline remix20Cues04Hook = [](TrampolineStatic(), s64 a1, s64 a2) -> s64 {
    //runLuaChart(a1, a2, CUES04_SCRIPT);
    s64 v1;

    restbc(53);

    cue_scene_change(8);
    set_criteria("must");
    restbc(1);

    flydisc_cue(0, 7 * 480, -1, 0);
    restbc(11);

    restbc(272);

    cue_scene_change(8);
    set_criteria("must");
    restbc(1);

    flydisc_cue(0, 7 * 480, -1, 0);
    restbc(11);

    restbc(100);

    cue_scene_change(8);
    set_criteria("must");
    restbc(1);

    flydisc_cue(0, 7 * 480, -1, 0);
    restbc(11);

    return sub_7100514FD0(a2);
};


HkTrampoline remix20Cues05Hook = [](TrampolineStatic(), s64 a1, s64 a2) -> s64 {
    //runLuaChart(a1, a2, CUES05_SCRIPT);
    s64 v1;

    restbc(61);

    cue_scene_change(22);
    set_criteria("basic");
    restbc(1);

    for (s32 i = 0; i < 15; i++) {
        rope_cue00(480, 0);
        restbc(1);
    }

    set_criteria("tech");
    rope_cue01(480, 0, 0);
    restbc(1.5);

    set_criteria("basic");
    for (s32 i = 0; i < 10; i++) {
        rope_cue00(480, 0);
        restbc(1);
    }

    set_criteria("tech");
    rope_cue01(480, 0, 0);
    restbc(1.5);

    set_criteria("basic");
    for (s32 i = 0; i < 3; i++) {
        rope_cue00(480, 0);
        restbc(1);
    }

    rope_cue00(480, 1);
    restbc(1);

    restbc(131);

    cue_scene_change(22);
    set_criteria("basic");
    restbc(1);

    for (s32 i = 0; i < 7; i++) {
        rope_cue00(480, 0);
        restbc(1);
    }

    set_criteria("tech");
    rope_cue01(480, 0, 0);
    restbc(1.5);

    set_criteria("basic");
    for (s32 i = 0; i < 6; i++) {
        rope_cue00(480, 0);
        restbc(1);
    }

    set_criteria("tech");
    rope_cue01(480, 0, 0);
    restbc(1.5);

    set_criteria("basic");
    for (s32 i = 0; i < 4; i++) {
        rope_cue00(480, 0);
        restbc(1);
    }

    set_criteria("tech");
    rope_cue01(480, 0, 0);
    restbc(1.5);

    set_criteria("basic");
    for (s32 i = 0; i < 2; i++) {
        rope_cue00(480, 0);
        restbc(1);
    }

    set_criteria("tech");
    rope_cue01(480, 0, 0);
    restbc(1.5);

    set_criteria("basic");
    for (s32 i = 0; i < 2; i++) {
        rope_cue00(480, 0);
        restbc(1);
    }

    set_criteria("tech");
    rope_cue01(480, 0, 0);
    restbc(1.5);

    set_criteria("basic");
    for (s32 i = 0; i < 3; i++) {
        rope_cue00(480, 0);
        restbc(1);
    }

    rope_cue00(480, 1);
    restbc(1.5);

    restbc(158);

    cue_scene_change(22);
    set_criteria("basic");
    restbc(1);

    set_criteria("basic");
    for (s32 i = 0; i < 6; i++) {
        rope_cue00(480, 0);
        restbc(1);
    }

    rope_cue00(480, 1);
    restbc(3);

    set_criteria("basic");
    for (s32 i = 0; i < 2; i++) {
        rope_cue00(480, 0);
        restbc(1);
    }

    set_criteria("tech");
    rope_cue01(480, 0, 0);
    restbc(1.5);

    set_criteria("basic");
    for (s32 i = 0; i < 2; i++) {
        rope_cue00(480, 0);
        restbc(1);
    }

    set_criteria("tech");
    rope_cue01(480, 0, 0);
    restbc(1.5);

    set_criteria("basic");
    for (s32 i = 0; i < 3; i++) {
        rope_cue00(480, 0);
        restbc(1);
    }

    set_criteria("basic");
    rope_cue00(480, 1);

    return sub_7100514FD0(a2);
};


HkTrampoline remix20Cues06Hook = [](TrampolineStatic(), s64 a1, s64 a2) -> s64 {
    //runLuaChart(a1, a2, CUES06_SCRIPT);
    s64 v1;

    restbc(93);

    cue_scene_change(6);
    set_criteria("tech");
    restbc(1);

    restbc(3);
    crab_cue02(-1, -1, -1);
    restbc(8);
    crab_cue02(-1, -1, -1);
    restbc(5);

    restbc(147);

    cue_scene_change(6);
    set_criteria("tech");
    restbc(1);

    restbc(3);
    crab_cue02(-1, -1, -1);
    crab_cue00(-1, -1, -1);
    restbc(8);
    crab_cue02(-1, -1, -1);
    crab_cue00(-1, -1, -1);
    restbc(5);

    return sub_7100514FD0(a2);
};


HkTrampoline remix20Cues07Hook = [](TrampolineStatic(), s64 a1, s64 a2) -> s64 {
    //runLuaChart(a1, a2, CUES07_SCRIPT);
    s64 v1;

    restbc(107);

    cue_scene_change(4);
    set_criteria("basic");
    restbc(1);

    clap_123();
    restbc(3);

    clap_cue00(0);
    restbc(2);

    clap_cue01(); // check it out!
    restbc(2);
    //set_criteria("tech"); // why the hell does this seg fault
    clap_cue02(); // clap clap!
    restbc(2);

    //set_criteria("basic");
    clap_cue00(0);
    restbc(2);
    clap_cue00(0);
    restbc(2);
    clap_cue00(0);
    restbc(2);

    clap_cue03(); // show it go!
    restbc(2);
    //set_criteria("must"); // why the hell does this seg fault
    clap_cue04(); // cl-cl-clap!
    restbc(1);
    clap_321();
    restbc(1);

    //set_criteria("basic");
    clap_cue00(0);
    restbc(2);
    clap_cue00(0);
    restbc(2);

    restbc(140);

    cue_scene_change(4);
    set_criteria("basic");
    restbc(1);

    clap_123();
    restbc(3);

    clap_cue00(0);
    restbc(2);

    clap_cue01(); // check it out!
    restbc(2);
    clap_cue02(); // clap clap!
    restbc(2);

    clap_cue00(0);
    restbc(2);

    clap_cue03(); // show it go!
    restbc(2);
    clap_cue04(); // cl-cl-clap!
    restbc(2);

    clap_cue03(); // show it go!
    restbc(1);
    clap_321();
    restbc(1);
    clap_cue04(); // cl-cl-clap!
    restbc(2);

    clap_cue00(0);
    restbc(2);

    restbc(90);

    cue_scene_change(4);
    set_criteria("basic");
    restbc(1);

    clap_123();
    restbc(3);

    clap_cue00(0);
    restbc(2);

    clap_cue03(); // show it go!
    restbc(2);
    clap_cue04(); // cl-cl-clap!
    restbc(2);

    clap_cue01(); // check it out!
    restbc(2);
    clap_cue02(); // clap clap!
    restbc(2);

    clap_cue03(); // show it go!
    restbc(1);
    clap_321();
    restbc(1);
    clap_cue04(); // cl-cl-clap!
    restbc(2);

    clap_cue00(0);
    restbc(2);

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
