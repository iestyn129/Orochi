#include "chart.h"

const u32 initSceneID = SCENE_GERM_AEROBICS;
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
    stage->setSceneCarryover(SCENE_GERM_AEROBICS, SceneCarryoverNone);
    rest(36);

    change_scene_fade_2_beat(SCENE_HOOP_TRUNDLING);
    stage->setSceneCarryover(SCENE_HOOP_TRUNDLING, SceneCarryoverState);
    rest(6.75); // -0.25

    change_scene_instant(SCENE_SNEEZY_MOON);
    stage->setSceneCarryover(SCENE_SNEEZY_MOON, SceneCarryoverState);
    rest(4);

    change_scene_instant(SCENE_HOOP_TRUNDLING);
    rest(3);

    change_scene_instant(SCENE_HIGH_FIVE_FEVER);
    stage->setSceneCarryover(SCENE_HIGH_FIVE_FEVER, SceneCarryoverState);
    stage->clap->setTVText("THE BACKROOMS\nTV CHANNEL");
    rest(4);

    change_scene_instant(SCENE_HOOP_TRUNDLING);
    rest(4);

    change_scene_instant(SCENE_GERM_AEROBICS);
    rest(4);

    change_scene_instant(SCENE_HOOP_TRUNDLING);
    rest(6.25); // +0.25

    change_scene_fade_1_beat(SCENE_HIGH_FIVE_FEVER);
    rest(28.75); // -0.25
    stage->fadeGameplay(0, 0.0);
    rest(4);

    change_scene_instant(SCENE_GERM_AEROBICS);
    stage->fadeGameplay(0, 1.0);
    rest(4);

    change_scene_instant(SCENE_HOOP_TRUNDLING);
    rest(12);

    change_scene_instant(SCENE_SNEEZY_MOON);
    rest(4);

    change_scene_instant(SCENE_HOOP_TRUNDLING);
    rest(12);

    change_scene_fade_1_beat(SCENE_GERM_AEROBICS);
    stage->setSceneCarryover(SCENE_GERM_AEROBICS, SceneCarryoverState);
    rest(13.5); // -0.5

    change_scene_fade_1_beat(SCENE_HOOP_TRUNDLING);
    rest(1.75); // -0.25

    change_scene_fade_1_beat(SCENE_GERM_AEROBICS);
    stage->setSceneCarryover(SCENE_GERM_AEROBICS, SceneCarryoverNone);
    rest(16.75); // +0.5 +0.25

    change_scene_fade_2_beat(SCENE_HOOP_TRUNDLING);
    rest(29);

    change_scene_fade_1_beat(SCENE_SODA_HOP);
    stage->setSceneCarryover(SCENE_SODA_HOP, SceneCarryoverState);
    rest(31);

    change_scene_instant(SCENE_SWEEPER_STAR);
    stage->setSceneCarryover(SCENE_SWEEPER_STAR, SceneCarryoverState);
    stage->brush->bg->playAction("FinishSceneChange");
    stage->brush->you->getChildMaybe("you", true)->setAnimationSimple("YOU_B", false);
    stage->fadeGameplay(0, 0.0);
    rest(2);
    stage->fadeGameplay(480, 1.0);
    rest(34);

    change_scene_fade_1_beat(SCENE_CAN_DO);
    stage->setSceneCarryover(SCENE_CAN_DO, SceneCarryoverState);
    stage->ring->anime->playAction("MaskStep");
    stage->ring->anime->playAction("MaskStep");
    stage->ring->anime->playAction("MaskStep");
    rest(28.25); // -0.75
    stage->fadeGameplay(0, 0.0);
    rest(0.75); // +0.75

    change_scene_instant(SCENE_HOOP_TRUNDLING);
    rest(1);
    stage->fadeGameplay(480, 1.0);
    rest(3);

    change_scene_fade_1_beat(SCENE_SNEEZY_MOON);
    rest(28);

    change_scene_fade_1_beat(SCENE_GERM_AEROBICS);
    //rest(0);
}


void chartAnim(StageRemix20* stage, SeqThread* thread) {
    rest(5);
    stage->beatAnim(thread, 0, 480, 0);
}


// germ aerobics
void chartCues00(StageRemix20* stage, SeqThread* thread) {
    stage->setCueScene(thread, SCENE_GERM_AEROBICS);
    stage->setComment("basic");

    stage->bacteria->startAerobics(thread, 9, true);
    rest(9);
    stage->bacteria->tripleAerobics(thread);
    rest(2);
    stage->bacteria->startAerobics(thread, 2, false);
    rest(2);
    stage->bacteria->stopAerobics(thread, 0);
    rest(2); // -1.0

    stage->setCueScene(thread, SCENE_GERM_AEROBICS);
    stage->setComment("basic");
    rest(1); // +1.0

    stage->bacteria->startAerobics(thread, 9, true);
    rest(9);
    stage->bacteria->tripleAerobics(thread);
    rest(2);
    stage->bacteria->startAerobics(thread, 3, false);
    rest(3);
    stage->bacteria->stopAerobics(thread, 0);
    rest(24); // -1.0

    stage->setCueScene(thread, SCENE_GERM_AEROBICS);
    stage->setComment("basic");
    rest(1); // +1.0

    stage->bacteria->tripleAerobics(thread);
    rest(42); // -1.0

    stage->setCueScene(thread, SCENE_GERM_AEROBICS);
    stage->setComment("basic");
    rest(1); // +1.0

    stage->bacteria->tripleAerobics(thread);
    rest(31); // -1.0

    stage->setCueScene(thread, SCENE_GERM_AEROBICS);
    stage->setComment("basic");
    rest(1); // +1.0

    stage->bacteria->startAerobics(thread, 7, true);
    rest(7);
    stage->bacteria->tripleAerobics(thread);
    rest(2);
    stage->bacteria->startAerobics(thread, 2, false);
    rest(2);
    stage->bacteria->stopAerobics(thread, 0);
    rest(3); // -2.0

    stage->setCueScene(thread, SCENE_GERM_AEROBICS);
    stage->setComment("basic");
    rest(2); // +2.0

    stage->bacteria->startAerobics(thread, 7, true);
    rest(7);
    stage->bacteria->tripleAerobics(thread);
    rest(2);
    stage->bacteria->startAerobics(thread, 3, false);
    rest(3);
    stage->bacteria->stopAerobics(thread, 0);
    rest(161); // -1.0

    stage->setCueScene(thread, SCENE_GERM_AEROBICS);
    stage->setComment("basic");
    rest(1); // +1.0

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


// hoop trundling
void chartCues01(StageRemix20* stage, SeqThread* thread) {
    rest(38);

    stage->setCueScene(thread, SCENE_HOOP_TRUNDLING);
    stage->setComment("basic");

    stage->ring->spawnRing(thread, -1);
    rest(8);

    stage->setCueScene(thread, SCENE_HOOP_TRUNDLING);
    stage->setComment("basic");

    stage->ring->spawnRing(thread, -1);
    rest(8);

    stage->setCueScene(thread, SCENE_HOOP_TRUNDLING);
    stage->setComment("basic");

    stage->ring->spawnRing(thread, -1);
    rest(8);

    stage->setCueScene(thread, SCENE_HOOP_TRUNDLING);
    stage->setComment("basic");

    stage->ring->spawnRing(thread, ring_bubble_mask(false, false, true, true));
    rest(2);
    stage->ring->spawnRing(thread, ring_bubble_mask(true, true, true, true));
    rest(39); // -1.0

    stage->setCueScene(thread, SCENE_HOOP_TRUNDLING);
    stage->setComment("basic");
    rest(1); // +1.0

    stage->ring->spawnRing(thread, -1);
    rest(3);
    stage->ring->spawnRing(thread, -1);
    rest(3);
    stage->ring->spawnRing(thread, -1);
    rest(3);
    stage->ring->spawnRing(thread, -1);
    rest(6); // -1.0

    stage->setCueScene(thread, SCENE_HOOP_TRUNDLING);
    stage->setComment("basic");
    rest(1); // +1.0

    stage->ring->spawnRing(thread, -1);
    rest(3);
    stage->ring->spawnRing(thread, -1);
    rest(3);
    stage->ring->spawnRing(thread, -1);
    rest(3);
    stage->ring->spawnRing(thread, ring_bubble_mask(false, false, true, true));
    rest(15); // -1.0

    stage->setCueScene(thread, SCENE_HOOP_TRUNDLING);
    stage->setComment("basic");
    rest(1); // +1.0

    stage->ring->spawnRing(thread, ring_bubble_mask(true, true, true, true));
    rest(20); // -1.0

    stage->setCueScene(thread, SCENE_HOOP_TRUNDLING);
    stage->setComment("basic");
    rest(1); // +1.0

    stage->ring->spawnRing(thread, -1);
    rest(8);
    stage->ring->spawnRing(thread, -1);
    rest(8);

    stage->ring->spawnRing(thread, -1);
    rest(4);
    stage->ring->spawnRing(thread, -1);
    rest(4);
    stage->ring->spawnRing(thread, -1);
    rest(99); // -1.0

    stage->setCueScene(thread, SCENE_HOOP_TRUNDLING);
    stage->setComment("basic");
    rest(1); // +1.0

    stage->ring->spawnRing(thread, -1);
}


// sneezy moon
void chartCues02(StageRemix20* stage, SeqThread* thread) {
    rest(41); // -1.0

    stage->setCueScene(thread, SCENE_SNEEZY_MOON);
    stage->setComment("basic");
    stage->moon->fastSneeze = true;
    rest(1); // +1.0

    stage->moon->sneezeGreen(thread, true);
    rest(73); // -1.0

    stage->setCueScene(thread, SCENE_SNEEZY_MOON);
    stage->setComment("basic");
    rest(1); // +1.0

    stage->moon->sneezeGreen(thread, true);
    rest(177); // -1.0

    stage->setCueScene(thread, SCENE_SNEEZY_MOON);
    stage->setComment("basic");
    rest(1); // +1.0

    stage->moon->sneezeGreen(thread, true);
    rest(2);
    stage->moon->sneezeGreen(thread, false);
    rest(4.5);

    stage->moon->sneezeRed(thread, true);
    rest(3.5);

    stage->moon->sneezeGreen(thread, true);
    rest(4);
    stage->moon->sneezeGreen(thread, true);
    rest(3);

    stage->moon->sneezeGreen(thread, false);
    rest(3);
    stage->moon->sneezeGreen(thread, false);
    rest(4);

    stage->moon->sneezeGreen(thread, true);
}


// high-five fever
void chartCues03(StageRemix20* stage, SeqThread* thread) {
    rest(45); // -1.0

    stage->setCueScene(thread, SCENE_HIGH_FIVE_FEVER);
    stage->setComment("basic");
    rest(1); // +1.0

    stage->clap->cue321(thread);
    rest(3);
    stage->clap->clap(thread, 0);
    rest(15); // -1.0

    stage->setCueScene(thread, SCENE_HIGH_FIVE_FEVER);
    stage->setComment("basic");
    rest(1); // +1.0

    stage->clap->cue123(thread);
    rest(3);
    stage->clap->clap(thread, 0);
    rest(2);

    stage->clap->clapCueDouble(thread);
    rest(2);
    stage->clap->doubleClap(thread);
    rest(2);

    stage->clap->clap(thread, 0);
    rest(2);

    stage->clap->clap(thread, 0);
    rest(1);
    stage->clap->cue321(thread);
    rest(1);

    stage->clap->clap(thread, 0);
    rest(2);
    stage->clap->clap(thread, 0);
    rest(8);

    stage->clap->cue321(thread);
    rest(3);
    stage->clap->clapCueTriple(thread);
    rest(2);
    stage->clap->tripleClap(thread);
    rest(2);
}


// soda hop
void chartCues04(StageRemix20* stage, SeqThread* thread) {
    rest(192); // -1.0

    stage->setCueScene(thread, SCENE_SODA_HOP);
    stage->setComment("basic");
    rest(1); // +1.0

    for (s8 i = 0; i < 7; ++i) {
        stage->rope->jump(thread, 480, false);
        rest(1);
    }

    stage->rope->doubleUnder(thread, 480, false, false);
    rest(1.5);

    for (s8 i = 0; i < 10; ++i) {
        stage->rope->jump(thread, 480, false);
        rest(1);
    }

    stage->rope->doubleUnder(thread, 480, false, false);
    rest(1.5);

    for (s8 i = 0; i < 7; ++i) {
        stage->rope->jump(thread, 480, false);
        rest(1);
    }

    stage->rope->jump(thread, 480, true);
}


// sweeper star
void chartCues05(StageRemix20* stage, SeqThread* thread) {
    rest(224); // -1.0

    stage->setCueScene(thread, SCENE_SWEEPER_STAR);
    stage->setComment("basic");
    rest(1); // +1.0

    stage->brush->sweepContinuous(thread, 4, true, true, false);
    rest(4);
    stage->brush->sweepThree(thread);
    rest(4);
    stage->brush->sweepContinuous(thread, 4, true, false, false);
    rest(4);
    stage->brush->sweepThree(thread);
    rest(4);
    stage->brush->sweepContinuous(thread, 4, true, false, false);
    rest(4);
    stage->brush->sweepThree(thread);
    rest(4);
    stage->brush->sweepContinuous(thread, 4, false, false, true);
    rest(6);

    stage->brush->spinSpin(thread, false);
    rest(1);
    stage->brush->spinStop();
}


// can do
void chartCues06(StageRemix20* stage, SeqThread* thread) {
    rest(248); // -1.0

    stage->setCueScene(thread, SCENE_CAN_DO);
    stage->setComment("basic");
    rest(1); // +1.0

    stage->hammer->spawnCanRed(thread, 480 * 10, true, 480 * 16);
    stage->hammer->spawnCanRed(thread, 480 * 6.25, true, 480 * 20);
    stage->hammer->spawnCanBlue(thread, 480 * 0.5, true, 480 * 26);
    stage->hammer->spawnCanRed(thread, 0, false, 480 * 30);
    stage->hammer->spawnCanBlue(thread, 0, false, 480 * 34);
    stage->hammer->spawnCanRed(thread, 480 * -3, true, 480 * 39);
}


void chartCues07(StageRemix20* stage, SeqThread* thread) {

}
