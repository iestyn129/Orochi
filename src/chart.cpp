#include "chart.h"
#include "aloha/Stage.h"
#include "log.h"

const WavMarkId chartWavMark = wavmark_stage_showtime_n_remix_03;
const u32 initSceneID = SCENE_SHINKAI;
const s32 initRingBubbleState = ring_bubble_mask(true, true, true, true);


void chartEntry(StageRemix20* stage, SeqThread* thread) {
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
    rest(1008);

    stage->FUN_7100138CD0();
    stage->fadeScreen(1 * 480, 0.0);
    rest(1);
    stage->FUN_7100138FC0();
    rest(1);
    stage->FUN_7100137140();
}


void chartControl(StageRemix20* stage, SeqThread* thread) {
    log("chartControl");
    stage->initSubScene(SCENE_BACTERIA, -1, false);
    stage->initSubScene(SCENE_BIRDS, -1, false);
    stage->initSubScene(SCENE_BRUSH, -1, false);
    stage->initSubScene(SCENE_CARS, -1, false);
    stage->initSubScene(SCENE_CLAP, -1, false);
    stage->initSubScene(SCENE_COOKING, -1, false);
    stage->initSubScene(SCENE_CRAB, -1, false);
    stage->initSubScene(SCENE_DANCER, -1, false);
    stage->initSubScene(SCENE_FLYDISC, -1, false);
    stage->initSubScene(SCENE_GRASP, -1, false);
    stage->initSubScene(SCENE_GUARDIAN, -1, false);
    stage->initSubScene(SCENE_HAMMER, -1, false);
    stage->initSubScene(SCENE_HUNGRY, -1, false);
    stage->initSubScene(SCENE_HURDLE, -1, false);
    stage->initSubScene(SCENE_INSECT, -1, false);
    stage->initSubScene(SCENE_KAERU, -1, false);
    stage->initSubScene(SCENE_MOON, -1, false);
    stage->initSubScene(SCENE_PARASOL, -1, false);
    stage->initSubScene(SCENE_PUMPUP, -1, false);
    stage->initSubScene(SCENE_PUTILABO, -1, false);
    stage->initSubScene(SCENE_RING, -1, false);
    stage->initSubScene(SCENE_ROPE, -1, false);
    stage->initSubScene(SCENE_SAMURAI, -1, false);
    stage->initSubScene(SCENE_SOCCER, -1, false);
    stage->initSubScene(SCENE_SOFTCATCH, -1, false);
    stage->initSubScene(SCENE_TALK, -1, false);
    stage->initSubScene(SCENE_THE_A, -1, false);
    stage->initSubScene(SCENE_THUNDER, -1, false);
    stage->initSubScene(SCENE_WIPER, -1, false);

    rest(6);
    stage->sceneChanger.instant(thread, SCENE_BACTERIA);
    rest(52 - 4);
    stage->sceneChanger.instant(thread, SCENE_BIRDS);
    rest(72 - 52);
    stage->sceneChanger.instant(thread, SCENE_BRUSH);
    rest(112 - 72);
    stage->sceneChanger.instant(thread, SCENE_CARS);
    rest(136 - 112);
    stage->sceneChanger.instant(thread, SCENE_CLAP);
    rest(200 - 136);
    stage->sceneChanger.instant(thread, SCENE_COOKING);
    rest(232 - 200);
    stage->sceneChanger.instant(thread, SCENE_CRAB);
    rest(264 - 232);
    stage->sceneChanger.instant(thread, SCENE_DANCER);
    rest(296 - 264);
    stage->sceneChanger.instant(thread, SCENE_FLYDISC);
    rest(320 - 296);
    stage->sceneChanger.instant(thread, SCENE_GRASP);
    rest(352 - 320);
    stage->sceneChanger.instant(thread, SCENE_GUARDIAN);
    rest(384 - 352);
    stage->sceneChanger.instant(thread, SCENE_HAMMER);
    rest(424 - 384);
    stage->sceneChanger.instant(thread, SCENE_HUNGRY);
    rest(464 - 424);
    stage->sceneChanger.instant(thread, SCENE_HURDLE);
    rest(504 - 464);
    stage->sceneChanger.instant(thread, SCENE_INSECT);
    rest(544 - 504);
    stage->sceneChanger.instant(thread, SCENE_KAERU);
    rest(600 - 544);
    stage->sceneChanger.instant(thread, SCENE_MOON);
    rest(632 - 600);
    stage->sceneChanger.instant(thread, SCENE_PARASOL);
    rest(664 - 632);
    stage->sceneChanger.instant(thread, SCENE_PUMPUP);
    rest(688 - 664);
    stage->sceneChanger.instant(thread, SCENE_PUTILABO);
    rest(712 - 688);
    stage->sceneChanger.instant(thread, SCENE_RING);
    rest(728 - 712);
    stage->sceneChanger.instant(thread, SCENE_ROPE);
    rest(752 - 728);
    stage->sceneChanger.instant(thread, SCENE_SAMURAI);
    rest(776 - 752);
    stage->sceneChanger.instant(thread, SCENE_SHINKAI);
    rest(800 - 776);
    stage->sceneChanger.instant(thread, SCENE_SOCCER);
    rest(832 - 800);
    stage->sceneChanger.instant(thread, SCENE_SOFTCATCH);
    rest(848 - 832);
    stage->sceneChanger.instant(thread, SCENE_TALK);
    rest(880 - 848);
    stage->sceneChanger.instant(thread, SCENE_THE_A);
    rest(912 - 880);
    stage->sceneChanger.instant(thread, SCENE_THUNDER);
    rest(952 - 912);
    stage->sceneChanger.instant(thread, SCENE_WIPER);
}


void chartAnim(StageRemix20* stage, SeqThread* thread) {
    log("chartAnim");
}


void chartCues00(StageRemix20* stage, SeqThread* thread) {
    log("chartCues00");
    rest(12 - 0);
    stage->sceneBacteria.scene->regularAerobics(thread, 1, true);
    rest(20 - 12);
    stage->sceneBacteria.scene->slowAerobics(thread, 1, true);
    rest(28 - 20);
    stage->sceneBacteria.scene->stopAerobics(thread, 0);
    rest(36 - 28);
    stage->sceneBacteria.scene->quickAerobics(thread);
    rest(44 - 36);
    stage->sceneBacteria.scene->quickAerobics(thread);
    rest(60 - 44);
    stage->sceneBirds.scene->pattern(thread, "D...U...D...U?..");
    rest(80 - 60);
    stage->sceneBrush.scene->continuousSweeping(thread, 1, true, true, false);
    rest(88 - 80);
    stage->sceneBrush.scene->sweepThree(thread);
    rest(96 - 88);
    stage->sceneBrush.scene->spinSpin(thread, false);
    rest(104 - 96);
    stage->sceneBrush.scene->stopSpinning(thread);
    rest(120 - 104);
    stage->sceneCars.scene->accelerate(thread, true, false);
    rest(128 - 120);
    stage->sceneCars.scene->brake(thread, 0, 0xffffffff, false);
    rest(144 - 128);
    stage->sceneClap.scene->countIn(thread);
    rest(152 - 144);
    stage->sceneClap.scene->countOut(thread);
    rest(160 - 152);
    stage->sceneClap.scene->singleHighFive(thread, 0);
    rest(168 - 160);
    stage->sceneClap.scene->preDoubleHighFive(thread);
    rest(176 - 168);
    stage->sceneClap.scene->doubleHighFive(thread);
    rest(184 - 176);
    stage->sceneClap.scene->preTripleHighFive(thread);
    rest(192 - 184);
    stage->sceneClap.scene->tripleHighFive(thread);
    rest(208 - 192);
    stage->sceneCooking.scene->singleVeggie(thread, 0, 1);
    rest(216 - 208);
    stage->sceneCooking.scene->singleVeggie(thread, 3, 1);
    rest(224 - 216);
    stage->sceneCooking.scene->broccoli(thread, 3, 2, 0xffffffff, 0xffffffff);
    rest(240 - 224);
    stage->sceneCrab.scene->macaron(thread, -1, -1, -1);
    rest(248 - 240);
    stage->sceneCrab.scene->mangosteen(thread, 0,0x4b0,0x10000012);
    rest(256 - 248);
    stage->sceneCrab.scene->favaBean(thread, -1, -1, -1);
}
