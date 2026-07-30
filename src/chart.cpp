#include "chart.h"

const u32 initSceneID = SCENE_GERM_AEROBICS;


void chartMain(StageRemix* stage, SeqThread* thread) {
    rest(356);

    stage->FUN_7100138CD0();

    stage->fadeScreen(1 * 480, 0.0);
    rest(1);

    stage->FUN_7100138FC0();
    rest(1);

    stage->FUN_7100137140();
}


void chartControl(StageRemix* stage, SeqThread* thread) {

}


void chartAnim(StageRemix* stage, SeqThread* thread) {

}


void chartCues00(StageRemix* stage, SeqThread* thread) {
    stage->setComment("basic");

    stage->bacteria->startAerobics(thread, 9, true);
    rest(9);
    stage->bacteria->tripleAerobics(thread);
    rest(2);
    stage->bacteria->startAerobics(thread, 3, false);
    rest(3);
    stage->bacteria->stopAerobics(thread, 0);
    rest(2);

    stage->bacteria->startAerobics(thread, 9, true);
    rest(9);
    stage->bacteria->tripleAerobics(thread);
    rest(2);
    stage->bacteria->startAerobics(thread, 3, false);
    rest(3);
    stage->bacteria->stopAerobics(thread, 0);
    rest(2);
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
