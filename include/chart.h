#pragma once

#include "global.h"
#include "aloha/Stage.h"

#define check_thread() \
    if (thread->stopRequested()) \
        return

#define wait_until_unk(a1, a2) \
    thread->pushUnk270(); \
    stage->waitUntilUnk(thread, a1, a2); \
    check_thread()

#define rest(beats) \
    thread->wait((beats) * 480); \
    check_thread()

#define change_scene_instant(scene) \
    thread->pushUnk270(); \
    stage->sceneChanger.instant(thread, scene); \
    check_thread()

#define change_scene_fade_1_beat(scene) \
    thread->pushUnk270(); \
    stage->sceneChanger.fade1Beat(thread, scene, 2); \
    check_thread()

#define change_scene_fade_2_beat(scene) \
    thread->pushUnk270(); \
    stage->sceneChanger.fade2Beat(thread, scene, 2); \
    check_thread()

#define change_scene_fade_4_beat(scene) \
    thread->pushUnk270(); \
    stage->sceneChanger.fade4Beat(thread, scene, 2); \
    check_thread()

#define change_scene_fade_8_beat(scene) \
    thread->pushUnk270(); \
    stage->sceneChanger.fade8Beat(thread, scene, 2); \
    check_thread()

#define effect_b_on_a(sceneB, beats, a3, a4, a5) \
    thread->pushUnk270(); \
    stage->sceneEffect.bOnA(thread, sceneB, (beats) * 480, a3, a4, a5); \
    check_thread()

#define ring_bubble_mask(pa, pi, pu, pe) ( \
    ((pa != 0) << 0) | \
    ((pi != 0) << 1) | \
    ((pu != 0) << 2) | \
    ((pe != 0) << 3) )

extern const u32 initSceneID;
extern const s32 initRingBubbleState;

extern void evilThread(StageRemix20* stage, SeqThread* thread);
extern void chartMain(StageRemix20* stage, SeqThread* thread);
extern void chartControl(StageRemix20* stage, SeqThread* thread);
extern void chartAnim(StageRemix20* stage, SeqThread* thread);
extern void chartInitSubScenes(StageRemix20* stage, SeqThread* thread);
extern void chartCues00(StageRemix20* stage, SeqThread* thread);
extern void chartCues01(StageRemix20* stage, SeqThread* thread);
extern void chartCues02(StageRemix20* stage, SeqThread* thread);
extern void chartCues03(StageRemix20* stage, SeqThread* thread);
extern void chartCues04(StageRemix20* stage, SeqThread* thread);
extern void chartCues05(StageRemix20* stage, SeqThread* thread);
extern void chartCues06(StageRemix20* stage, SeqThread* thread);
extern void chartCues07(StageRemix20* stage, SeqThread* thread);
