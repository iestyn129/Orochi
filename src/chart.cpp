#include "chart.h"

const u32 initSceneID = SCENE_GERM_AEROBICS;


void chartMain(StageRemix20* stage, SeqThread* thread) {
    rest(358);

    stage->FUN_7100138CD0();

    stage->fadeScreen(1 * 480, 0.0);
    rest(1);

    stage->FUN_7100138FC0();
    rest(1);

    stage->FUN_7100137140();
}


void chartControl(StageRemix20* stage, SeqThread* thread) {
    stage->FUN_71004da400(SCENE_GERM_AEROBICS, 1);
    rest(36);
    stage->FUN_71004da400(SCENE_GERM_AEROBICS, 2);

    change_scene_fade_2_beat(SCENE_HOOP_TRUNDLING);
    stage->FUN_71004da400(SCENE_HOOP_TRUNDLING, 1);
    rest(6.75); // -0.25

    change_scene_instant(SCENE_SNEEZY_MOON);
    stage->FUN_71004da400(SCENE_SNEEZY_MOON, 1);
    rest(4);

    change_scene_instant(SCENE_HOOP_TRUNDLING);
    rest(3);

    change_scene_instant(SCENE_HIGH_FIVE_FEVER);
    stage->FUN_71004da400(SCENE_HIGH_FIVE_FEVER, 1);
    stage->FUN_71004da400(SCENE_GERM_AEROBICS, 3);
    rest(4);

    change_scene_instant(SCENE_HOOP_TRUNDLING);
    rest(3.25); // +0.25

    change_scene_instant(SCENE_GERM_AEROBICS);
    rest(5);
}


void chartAnim(StageRemix20* stage, SeqThread* thread) {

}


void chartCues00(StageRemix20* stage, SeqThread* thread) {
    stage->setComment("basic");

    stage->bacteria->startAerobics(thread, 9, true);
    rest(9);
    stage->bacteria->tripleAerobics(thread);
    rest(2);
    stage->bacteria->startAerobics(thread, 2, false);
    rest(2);
    stage->bacteria->stopAerobics(thread, 0);

    rest(3);

    stage->bacteria->startAerobics(thread, 9, true);
    rest(9);
    stage->bacteria->tripleAerobics(thread);
    rest(2);
    stage->bacteria->startAerobics(thread, 3, false);
    rest(3);
    stage->bacteria->stopAerobics(thread, 0);

    rest(25);

    stage->bacteria->tripleAerobics(thread);

    rest(43);

    stage->bacteria->tripleAerobics(thread);

    rest(32);

    stage->bacteria->startAerobics(thread, 7, true);
    rest(7);
    stage->bacteria->tripleAerobics(thread);
    rest(2);
    stage->bacteria->startAerobics(thread, 2, false);
    rest(2);
    stage->bacteria->stopAerobics(thread, 0);
    rest(5);

    stage->bacteria->startAerobics(thread, 7, true);
    rest(7);
    stage->bacteria->tripleAerobics(thread);
    rest(2);
    stage->bacteria->startAerobics(thread, 3, false);
    rest(3);
    stage->bacteria->stopAerobics(thread, 0);

    rest(162);

    stage->bacteria->startAerobics(thread, 9, true);
    rest(9);
    stage->bacteria->tripleAerobics(thread);
    rest(2);
    stage->bacteria->startAerobics(thread, 5, false);
    rest(5);
    stage->bacteria->startSlowAerobics(thread, 10, true);
    rest(10);
    stage->bacteria->startAerobics(thread, 4, true);
    rest(4);
    stage->bacteria->stopAerobics(thread, 0);
}


void chartCues01(StageRemix20* stage, SeqThread* thread) {

}


void chartCues02(StageRemix20* stage, SeqThread* thread) {

}


void chartCues03(StageRemix20* stage, SeqThread* thread) {

}


void chartCues04(StageRemix20* stage, SeqThread* thread) {

}


void chartCues05(StageRemix20* stage, SeqThread* thread) {

}


void chartCues06(StageRemix20* stage, SeqThread* thread) {

}


void chartCues07(StageRemix20* stage, SeqThread* thread) {

}
