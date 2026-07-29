#pragma once

#include "hk/prim/traits/Integer.h"
#include "global.h"
#include "aloha.h"

#define check_thread() \
    if (thread->stopRequested()) \
        return

#define rest(beats) \
    thread->wait(beats * 480); \
    check_thread()

#define change_scene_instant(scene) \
    thread->pushUnk270(); \
    sceneChangeInstant(stage + 0x6E08, thread, scene); \
    check_thread()

#define change_scene_fade_1_beat(scene) \
    thread->pushUnk270(); \
    sceneChangeFade1Beat(stage + 0x6E08, thread, scene, 2); \
    check_thread()

#define change_scene_fade_2_beat(scene) \
    thread->pushUnk270(); \
    sceneChangeFade2Beat(stage + 0x6E08, thread, scene, 2); \
    check_thread()

#define change_scene_fade_4_beat(scene) \
    thread->pushUnk270(); \
    sceneChangeFade4Beat(stage + 0x6E08, thread, scene, 2); \
    check_thread()

#define change_scene_fade_8_beat(scene) \
    thread->pushUnk270(); \
    sceneChangeFade8Beat(stage + 0x6E08, thread, scene, 2); \
    check_thread()

extern const u32 initSceneID;

extern void chartMain(StageRemix* stage, SeqThread* thread);
extern void chartControl(StageRemix* stage, SeqThread* thread);
extern void chartAnim(StageRemix* stage, SeqThread* thread);
extern void chartCues00(StageRemix* stage, SeqThread* thread);
extern void chartCues01(StageRemix* stage, SeqThread* thread);
extern void chartCues02(StageRemix* stage, SeqThread* thread);
extern void chartCues03(StageRemix* stage, SeqThread* thread);
extern void chartCues04(StageRemix* stage, SeqThread* thread);
extern void chartCues05(StageRemix* stage, SeqThread* thread);
extern void chartCues06(StageRemix* stage, SeqThread* thread);
extern void chartCues07(StageRemix* stage, SeqThread* thread);
