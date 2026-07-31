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
    stage->saveSceneState(SCENE_GERM_AEROBICS, 1);
    rest(36);
    stage->saveSceneState(SCENE_GERM_AEROBICS, 2);

    change_scene_fade_2_beat(SCENE_HOOP_TRUNDLING);
    stage->saveSceneState(SCENE_HOOP_TRUNDLING, 1);
    rest(6.75); // -0.25

    change_scene_instant(SCENE_SNEEZY_MOON);
    stage->saveSceneState(SCENE_SNEEZY_MOON, 1);
    rest(4);

    change_scene_instant(SCENE_HOOP_TRUNDLING);
    rest(3);

    change_scene_instant(SCENE_HIGH_FIVE_FEVER);
    stage->saveSceneState(SCENE_HIGH_FIVE_FEVER, 1);
    stage->saveSceneState(SCENE_GERM_AEROBICS, 3);
    rest(4);

    change_scene_instant(SCENE_HOOP_TRUNDLING);
    stage->saveSceneState(SCENE_GERM_AEROBICS, 1);
    rest(4);

    change_scene_instant(SCENE_GERM_AEROBICS);
    stage->saveSceneState(SCENE_GERM_AEROBICS, 2);
    rest(4);

    change_scene_instant(SCENE_HOOP_TRUNDLING);
    stage->saveSceneState(SCENE_GERM_AEROBICS, 1);
    rest(6.25); // +0.25

    change_scene_fade_1_beat(SCENE_HIGH_FIVE_FEVER);
    stage->saveSceneState(SCENE_GERM_AEROBICS, 2);
    rest(32.75); // -0.25

    change_scene_instant(SCENE_GERM_AEROBICS);
    stage->saveSceneState(SCENE_GERM_AEROBICS, 3);
    rest(4);

    change_scene_instant(SCENE_HOOP_TRUNDLING);
    rest(12);

    change_scene_instant(SCENE_SNEEZY_MOON);
    stage->saveSceneState(SCENE_GERM_AEROBICS, 4);
    rest(4);

    change_scene_instant(SCENE_HOOP_TRUNDLING);
    stage->saveSceneState(SCENE_GERM_AEROBICS, 5);
    rest(12);

    change_scene_fade_1_beat(SCENE_GERM_AEROBICS);
    stage->saveSceneState(SCENE_GERM_AEROBICS, 6);
}


void chartAnim(StageRemix20* stage, SeqThread* thread) {

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
    rest(3);

    stage->setCueScene(thread, SCENE_GERM_AEROBICS);
    stage->setComment("basic");

    stage->bacteria->startAerobics(thread, 9, true);
    rest(9);
    stage->bacteria->tripleAerobics(thread);
    rest(2);
    stage->bacteria->startAerobics(thread, 3, false);
    rest(3);
    stage->bacteria->stopAerobics(thread, 0);
    rest(25);

    stage->setCueScene(thread, SCENE_GERM_AEROBICS);
    stage->setComment("basic");

    stage->bacteria->tripleAerobics(thread);
    rest(43);

    stage->setCueScene(thread, SCENE_GERM_AEROBICS);
    stage->setComment("basic");

    stage->bacteria->tripleAerobics(thread);
    rest(32);

    stage->setCueScene(thread, SCENE_GERM_AEROBICS);
    stage->setComment("basic");

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

    stage->setCueScene(thread, SCENE_GERM_AEROBICS);
    stage->setComment("basic");

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
}


// sneezy moon
void chartCues02(StageRemix20* stage, SeqThread* thread) {
    rest(42);

    stage->setCueScene(thread, SCENE_SNEEZY_MOON);
    stage->setComment("basic");

    stage->moon->sneezeGreen(thread, true);
}


// high-five fever
void chartCues03(StageRemix20* stage, SeqThread* thread) {
    rest(46);

    stage->setCueScene(thread, SCENE_HIGH_FIVE_FEVER);
    stage->setComment("basic");

    stage->clap->cue321(thread);
    rest(3);
    stage->clap->clap(thread, 0);
    rest(16);

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


void chartCues04(StageRemix20* stage, SeqThread* thread) {

}


void chartCues05(StageRemix20* stage, SeqThread* thread) {

}


void chartCues06(StageRemix20* stage, SeqThread* thread) {

}


void chartCues07(StageRemix20* stage, SeqThread* thread) {

}
