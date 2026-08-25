#pragma once

#include "global.h"
#include "aloha/Stage.h"
#include "aloha/WavMark.h"

#define check_thread() \
    if (thread->stopRequested()) \
        return

#define wait_until_scene_ready(sceneID, a2) \
    thread->pushUnk270(); \
    stage->waitUntilSceneReady(thread, sceneID, a2); \
    check_thread()

#define unk_7100139250(a1, a2) \
    thread->pushUnk270(); \
    stage->FUN_7100139250(thread, a1, a2); \
    check_thread()

#define startup_bgm(wavmarkID, ticks, a3, a4, a5) \
    thread->pushUnk270(); \
    stage->startupBGM(thread, wavmarkID, ticks, a3, a4, a5); \
    check_thread()

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

struct Chart {
    WavMarkId wavmark;
    Remix20SceneID init_scene;
    f32 length;
};
extern const s32 initRingBubbleState;

extern void chartEntry(Chart chart, StageRemix20* stage, SeqThread* thread);
