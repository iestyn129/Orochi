#include "chart.h"

const u32 initSceneID = SCENE_DEEP_SEA;
const s32 initRingBubbleState = ring_bubble_mask(true, true, true, true);


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
    stage->initSubScene(SCENE_DEEP_SEA, -1, false);
}


void chartAnim(StageRemix20* stage, SeqThread* thread) {

}


// high-five fever channel initialisation
void chartInitSubScenes(StageRemix20* stage, SeqThread* thread) {

}


// germ aerobics
void chartCues00(StageRemix20* stage, SeqThread* thread) {

}


// hoop trundling
void chartCues01(StageRemix20* stage, SeqThread* thread) {

}


// sneezy moon
void chartCues02(StageRemix20* stage, SeqThread* thread) {

}


// high-five fever
void chartCues03(StageRemix20* stage, SeqThread* thread) {

}


// soda hop
void chartCues04(StageRemix20* stage, SeqThread* thread) {

}


// sweeper star
void chartCues05(StageRemix20* stage, SeqThread* thread) {

}


// can do
void chartCues06(StageRemix20* stage, SeqThread* thread) {

}


void chartCues07(StageRemix20* stage, SeqThread* thread) {

}
