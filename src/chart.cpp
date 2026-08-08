#include "chart.h"
#include "log.h"

const u32 initSceneID = SCENE_DEEP_SEA;
const s32 initRingBubbleState = ring_bubble_mask(true, true, true, true);


void evilThread(StageRemix20* stage, SeqThread* thread) {
    log("hello from the start of this thread");
    rest(4);
    log("hello from 4 beats later");
    stage->shinkai->spawnSugarCubes(thread, 0, 0);
}


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
    stage->shinkai->initUFO();
    stage->shinkai->FUN_710023c9f0(50, 100);
    stage->shinkai->initGround(thread, 6, 10, 1);

    stage->runner->appendThread(new SeqThread(
        stage->runner, stage->seqThreadIndex,
        reinterpret_cast<void*>(&StageRemix20::invokeSeqCallback),
        new SeqCallback(
            &stage->seqCallbackContext,
            reinterpret_cast<void*>(&evilThread),
            0
        ),
        thread
    ));
}


void chartAnim(StageRemix20* stage, SeqThread* thread) {

}


void chartInitSubScenes(StageRemix20* stage, SeqThread* thread) {

}


void chartCues00(StageRemix20* stage, SeqThread* thread) {
    return;
    rest(4);

    stage->shinkai->spawnSugarCubes(thread, 0, 0);
    rest(8);
    stage->shinkai->spawnEgg(thread, 0, 0);
    rest(8);
    stage->shinkai->spawnCookieTower(thread, 0, 0);
    rest(8);

    stage->shinkai->spawnSugarCubes(thread, 0, 0);
    rest(8);
    stage->shinkai->spawnEgg(thread, 0, 0);
    rest(8);
    stage->shinkai->spawnCookieTower(thread, 0, 0);
    rest(8);

    stage->shinkai->spawnSugarCubes(thread, 0, 0);
    rest(8);
    stage->shinkai->spawnEgg(thread, 0, 0);
    rest(8);
    stage->shinkai->spawnCookieTower(thread, 0, 0);
    rest(8);
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
