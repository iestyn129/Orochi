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
    rest(14)
    log("regularAerobicsAAAAAAAAAAAAAAAA");
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
    rest(272 - 256);
    stage->sceneDancer.scene->startDance(thread, 2, 3, true, true);
    rest(280 - 272);
    stage->sceneDancer.scene->startTurnAndDance(thread, 2, 3, true);
    rest(288 - 280);
    stage->sceneDancer.scene->fastTurn(thread, true);
    rest(304 - 288);
    stage->sceneFlydisc.scene->throwDisc(thread, 0, 0xd20, 0xffffffff, false);
    rest(328 - 304);
    stage->sceneGrasp.scene->throwObject(thread, 0, false);
    rest(336 - 328);
    stage->sceneGrasp.scene->doubleCatchA(thread);
    rest(344 - 336);
    stage->sceneGrasp.scene->doubleCatchB(thread, false);
    rest(360 - 344);
    stage->sceneGuardian.scene->farMeteor(thread, 0, 0);
    rest(368 - 360);
    stage->sceneGuardian.scene->nearMeteor(thread, 0, 0);
    rest(376 - 368);
    stage->sceneGuardian.scene->normalMeteor(thread, 0, 0);
    rest(392 - 376);
    stage->sceneHammer.scene->spawnRedCan(thread, 0, false, 7680);
    rest(408 - 392);
    stage->sceneHammer.scene->spawnBlueCan(thread, 0, false, 7680);
    rest(432 - 408);
    stage->sceneHungry.scene->spawnFlower(thread, 0);
    rest(448 - 432);
    stage->sceneHungry.scene->spawnFlower(thread, 1);
    rest(472 - 448);
    stage->sceneHurdle.scene->spawnObstacle(thread, false);
    rest(488 - 472);
    stage->sceneHurdle.scene->spawnObstacle(thread, true);
    rest(512 - 488);
    stage->sceneInsect.scene->butterfly(thread, 360, 1920, 0);
    rest(520 - 512);
    stage->sceneInsect.scene->grasshopper(thread, 240, 1920, 0);
    rest(528 - 520);
    stage->sceneInsect.scene->dragonfly(thread, 480, 1920, 0);
    rest(552 - 528);
    stage->sceneKaeru.scene->greenFrog(thread, 4);
    rest(560 - 552);
    stage->sceneKaeru.scene->greenFrog(thread, 3);
    rest(568 - 560);
    stage->sceneKaeru.scene->greenFrog(thread, 2);
    rest(576 - 568);
    stage->sceneKaeru.scene->redFrog(thread, 4);
    rest(584 - 576);
    stage->sceneKaeru.scene->redFrog(thread, 3);
    rest(592 - 584);
    stage->sceneKaeru.scene->redFrog(thread, 2);
    rest(608 - 592);
    stage->sceneMoon.scene->greenSneeze(thread, true);
    rest(616 - 608);
    stage->sceneMoon.scene->greenWindup(thread);
    rest(624 - 616);
    stage->sceneMoon.scene->redSneeze(thread, true);
    rest(640 - 624);
    stage->sceneParasol.scene->cue(thread, 480, 1, 0, 0);
    rest(648 - 640);
    stage->sceneParasol.scene->cue(thread, 480, 0, 0, 0);
    rest(656 - 648);
    stage->sceneParasol.scene->openTogether(thread, 1, 1);
    rest(672 - 656);
    stage->scenePumpup.scene->apple(thread, 0, 0);
    rest(680 - 672);
    stage->scenePumpup.scene->lemon(thread, 0, 0);
    rest(696 - 680);
    stage->scenePutilabo.scene->regularBubble(thread, 0);
    rest(698 - 696);
    stage->scenePutilabo.scene->hardBubble(thread, 480, 0);
    rest(720 - 698);
    stage->sceneRing.scene->hoop(thread, ring_bubble_mask(1, 1, 1, 1));
    rest(736 - 720);
    stage->sceneRope.scene->singleJump(thread, 480, true);
    rest(744 - 736);
    stage->sceneRope.scene->doubleUnder(thread, 480, true, false);
    rest(760 - 744);
    stage->sceneSamurai.scene->singleSlice(thread, 1, 1);
    rest(768 - 760);
    stage->sceneSamurai.scene->doubleSlice(thread, 1, 1);
    rest(784 - 768);
    stage->sceneShinkai.scene->singleRow(thread, 0, 0, 0);
    rest(792 - 784);
    stage->sceneShinkai.scene->tripleRow(thread, 0, 0, 0);
    rest(808 - 792);
    stage->sceneSoccer.scene->kick(thread, 0);
    rest(816 - 808);
    stage->sceneSoccer.scene->trapKick(thread, 0);
    rest(824 - 816);
    stage->sceneSoccer.scene->trapJumpKick(thread, 0);
    rest(840 - 824);
    stage->sceneSoftcatch.scene->pudding(thread, 0, 480);
    rest(856 - 840);
    stage->sceneTalk.scene->bomBom(thread);
    rest(864 - 856);
    stage->sceneTalk.scene->bomCha(thread);
    rest(872 - 864);
    stage->sceneTalk.scene->cha(thread);
    // rest(888 - 872);
    // stage->sceneTheA.scene->word(thread, "AAA", float, void *, const char *background);
    // rest(896 - 888);
    // stage->sceneTheA.scene->word(thread, "AAAA", float, void *, const char *background);
    // rest(904 - 896);
    // stage->sceneTheA.scene->word(thread, "AAAAA", float, void *, const char *background);
    rest(920 - 872);
    stage->sceneThunder.scene->pinkLightning(thread, 1, 0);
    rest(928 - 920);
    stage->sceneThunder.scene->pinkLightningFast(thread, 0);
    rest(936 - 928);
    stage->sceneThunder.scene->yellowLightning(thread, 1, 0);
    rest(944 - 936);
    stage->sceneThunder.scene->yellowLightningFast(thread, 0);
    rest(960 - 944);
    stage->sceneWiper.scene->quickBoth(thread);
    rest(968 - 960);
    stage->sceneWiper.scene->quickLeft(thread);
    rest(976 - 968);
    stage->sceneWiper.scene->quickRight(thread);
    rest(984 - 976);
    stage->sceneWiper.scene->slowBoth(thread);
    rest(992 - 984);
    stage->sceneWiper.scene->slowLeft(thread, 0);
    rest(1000 - 992);
    stage->sceneWiper.scene->slowRight(thread, 0);
}
