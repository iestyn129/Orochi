#include "chart.h"
#include "log.h"

const WavMarkId chartWavMark = wavmark_stage_showtime_t_dancer;
const u32 initSceneID = SCENE_BACKUP_SPOTLIGHT;
const s32 initRingBubbleState = ring_bubble_mask(true, true, true, true);


void remix20ExtCtor(StageRemix20* stage) {

}


void remix20ExtDtor(StageRemix20* stage) {
    const auto old = stage->tea;
    stage->tea = nullptr;
    if (old != nullptr) {
        old->~Sub7100276330();
    }
}


void chartEntry(StageRemix20* stage, SeqThread* thread) {
    log("chartEntry");
    remix20ExtCtor(stage);
    stage->fadeScreen(0, 0.0);
    stage->initWavMark(chartWavMark, true);
    wait_until_unk(false, -1);
    stage->prepareWavMark(chartWavMark);
    thread->pushUnk270();
    chartMain(stage, thread);
    check_thread();
    stage->registerResults();
}


void chartMain(StageRemix20* stage, SeqThread* thread) {
    log("chartMain");
    stage->FUN_7100137050(false);
    stage->setUnk3535(false);
    stage->setInitRingBubbleState(initRingBubbleState);
    stage->initSubScene(initSceneID, -1, true);
    wait_until_scene_ready(initSceneID, false);
    change_scene_instant(initSceneID);
    stage->fadeScreen(480, 1.0);
    unk_7100139250(-1, 0);
    rest(1);

    stage->FUN_7100138f80();
    stage->FUN_7100137b50(120);
    stage->FUN_7100137b60(0);
    startup_bgm(chartWavMark, 960, 0, 1.0, 1.0);

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

    stage->runner->appendThread(new SeqThread(
        stage->runner, stage->seqThreadIndex,
        reinterpret_cast<void*>(&StageRemix20::invokeSeqCallback),
        new SeqCallback(
            &stage->seqCallbackContext,
            reinterpret_cast<void*>(&chartAnim),
            0
        ),
        thread
    ));

    stage->runner->appendThread(new SeqThread(
        stage->runner, stage->seqThreadIndex,
        reinterpret_cast<void*>(&StageRemix20::invokeSeqCallback),
        new SeqCallback(
            &stage->seqCallbackContext,
            reinterpret_cast<void*>(&chartCues00),
            0
        ),
        thread
    ));

    stage->FUN_7100138d20();
    stage->FUN_7100138ce0();
    rest(800);

    stage->FUN_7100138CD0();
    stage->fadeScreen(1 * 480, 0.0);
    rest(1);
    stage->FUN_7100138FC0();
    rest(1);
    stage->FUN_7100137140();
}


void chartControl(StageRemix20* stage, SeqThread* thread) {
    log("chartControl");

    stage->tea = new SceneTheA::Sub7100276330(
        stage->sceneTheA.scene,
        "graph/scene/the_a/type_00/tea_00"
    );

    stage->sceneDancer.scene->layout->playAction("SingerAppear");
}


void chartAnim(StageRemix20* stage, SeqThread* thread) {
    log("chartAnim");
}


void chartCues00(StageRemix20* stage, SeqThread* thread) {
    log("chartCues00");
    rest(4);
}
