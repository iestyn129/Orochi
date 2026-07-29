#include "chart.h"

const u32 initSceneID = SCENE_GERM_AEROBICS;


void chartMain(StageRemix* stage, SeqThread* thread) {
    rest(64);

    stage->FUN_7100138CD0();

    stage->fadeScreen(1 * 480, 0.0);
    rest(1);

    stage->FUN_7100138FC0();
    rest(1);

    stage->FUN_7100137140();
}


void chartControl(StageRemix* stage, SeqThread* thread) {
    rest(4);

    change_scene_instant(SCENE_HOOP_TRUNDLING);
    rest(4);

    change_scene_instant(SCENE_SNEEZY_MOON);
    rest(4);

    change_scene_instant(SCENE_HIGH_FIVE_FEVER);
    rest(4);

    change_scene_instant(SCENE_SODA_HOP);
    rest(4);

    change_scene_instant(SCENE_SWEEPER_STAR);
    rest(4);

    change_scene_instant(SCENE_CAN_DO);
    rest(4);
}


void chartAnim(StageRemix* stage, SeqThread* thread) {

}


void chartCues00(StageRemix* stage, SeqThread* thread) {

}


void chartCues01(StageRemix* stage, SeqThread* thread) {

}


void chartCues02(StageRemix* stage, SeqThread* thread) {

}


void chartCues03(StageRemix* stage, SeqThread* thread) {

}


void chartCues04(StageRemix* stage, SeqThread* thread) {

}


void chartCues05(StageRemix* stage, SeqThread* thread) {

}


void chartCues06(StageRemix* stage, SeqThread* thread) {

}


void chartCues07(StageRemix* stage, SeqThread* thread) {

}
