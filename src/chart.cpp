#include "chart.h"
#include "log.h"

const u32 initSceneID = SCENE_SWEEPER_STAR;
const s32 initRingBubbleState = ring_bubble_mask(true, true, true, true);


void evilThread(StageRemix20* stage, SeqThread* thread) {
    log("hello from the start of this thread");
    rest(4);
    log("hello from 4 beats later");
    //stage->shinkai->spawnSugarCubes(thread, 0, 0);
}


void chartMain(StageRemix20* stage, SeqThread* thread) {
    stage->FUN_7100137050(false);
    stage->setUnk3535(false);
    stage->setRingBubbleState(initRingBubbleState);
    stage->initSubScene(initSceneID, -1, true);
    wait_until_scene_ready(initSceneID, false);
    change_scene_instant(initSceneID);
    stage->fadeScreen(480, 1.0);
    unk_7100139250(-1, 0);
    rest(1);

    stage->FUN_7100138f80();
    stage->FUN_7100137b50(120);
    stage->FUN_7100137b60(0);
    startup_bgm(0x80, 960, 0, 1.0, 1.0);

    stage->runner->appendThread(new SeqThread(
        stage->runner, stage->seqThreadIndex,
        reinterpret_cast<void*>(&StageRemix20::invokeSeqCallback),
        new SeqCallback(
            &stage->seqCallbackContext,
            reinterpret_cast<void*>(&chartControl),
            0
        ),
        thread
    ));

    stage->FUN_7100138d20();
    stage->FUN_7100138ce0();
    rest(8);

    stage->FUN_7100138CD0();
    stage->fadeScreen(1 * 480, 0.0);
    rest(1);
    stage->FUN_7100138FC0();
    rest(1);
    stage->FUN_7100137140();
}


void chartControl(StageRemix20* stage, SeqThread* thread) {
    log("chartControl");
    //stage->shinkai->initUFO();
    //stage->shinkai->FUN_710023c9f0(50, 100);
    //stage->shinkai->initGround(thread, 6, 10, 1);

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
    log("chartAnim");
}


void chartInitSubScenes(StageRemix20* stage, SeqThread* thread) {
    log("chartInitSubScenes");
}


void chartCues00(StageRemix20* stage, SeqThread* thread) {
    log("chartCues00");
    return;
    rest(4);

    //stage->shinkai->spawnSugarCubes(thread, 0, 0);
    rest(8);
    //stage->shinkai->spawnEgg(thread, 0, 0);
    rest(8);
    //stage->shinkai->spawnCookieTower(thread, 0, 0);
    rest(8);

    //stage->shinkai->spawnSugarCubes(thread, 0, 0);
    rest(8);
    //stage->shinkai->spawnEgg(thread, 0, 0);
    rest(8);
    //stage->shinkai->spawnCookieTower(thread, 0, 0);
    rest(8);

    //stage->shinkai->spawnSugarCubes(thread, 0, 0);
    rest(8);
    //stage->shinkai->spawnEgg(thread, 0, 0);
    rest(8);
    //stage->shinkai->spawnCookieTower(thread, 0, 0);
    rest(8);
}


void chartCues01(StageRemix20* stage, SeqThread* thread) {
    log("chartCues01");
}


void chartCues02(StageRemix20* stage, SeqThread* thread) {
    log("chartCues02");
}


void chartCues03(StageRemix20* stage, SeqThread* thread) {
    log("chartCues03");
}


void chartCues04(StageRemix20* stage, SeqThread* thread) {
    log("chartCues04");
}


void chartCues05(StageRemix20* stage, SeqThread* thread) {
    log("chartCues05");
}


void chartCues06(StageRemix20* stage, SeqThread* thread) {
    log("chartCues06");
}


void chartCues07(StageRemix20* stage, SeqThread* thread) {
    log("chartCues07");
}
