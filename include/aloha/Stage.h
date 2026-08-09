#pragma once

#include "cstddef"
#include "vector"
#include "aloha/Message.h"
#include "aloha/SubScene.h"
#include "aloha/Seq.h"
#include "aloha/WavMark.h"

#define SCENE_BACTERIA 0
#define SCENE_GERM_AEROBICS SCENE_BACTERIA

#define SCENE_BIRDS 1
#define SCENE_SYNCHRO_WINGS SCENE_BIRDS

#define SCENE_BRUSH 2
#define SCENE_SWEEPER_STAR SCENE_BRUSH

#define SCENE_CARS 3
#define SCENE_STOP_N_GO_STOP SCENE_CARS

#define SCENE_CLAP 4
#define SCENE_HIGH_FIVE_FEVER SCENE_CLAP

#define SCENE_COOKING 5
#define SCENE_SLICE_N_DICE_KITCHEN SCENE_COOKING

#define SCENE_CRAB 6
#define SCENE_CRAB_SNACKS SCENE_CRAB

#define SCENE_DANCER 7
#define SCENE_BACKUP_SPOTLIGHT SCENE_DANCER

#define SCENE_FLYDISC 8
#define SCENE_DISC_DOG SCENE_FLYDISC

#define SCENE_GRASP 9
#define SCENE_QUICK_HANDS SCENE_GRASP

#define SCENE_GUARDIAN 10
#define SCENE_SPACE_SENTRY SCENE_GUARDIAN

#define SCENE_HAMMER 11
#define SCENE_CAN_DO SCENE_HAMMER

#define SCENE_HUNGRY 12
#define SCENE_FEEDING_THE_BEAST SCENE_HUNGRY

#define SCENE_HURDLE 13
#define SCENE_HOP_N_SLIDE SCENE_HURDLE

#define SCENE_INSECT 14
#define SCENE_FLUTTER_SPEED SCENE_INSECT

#define SCENE_KAERU 15
#define SCENE_RIBBIT_ROCKET SCENE_KAERU

#define SCENE_MOON 16
#define SCENE_SNEEZY_MOON SCENE_MOON

#define SCENE_PARASOL 17
#define SCENE_BROLLY_GOOD_SHOW SCENE_PARASOL

#define SCENE_PUMPUP 18
#define SCENE_FRUIT_FLEX SCENE_PUMPUP

#define SCENE_PUTILABO 19
#define SCENE_POP_DONT_DROP SCENE_PUTILABO

#define SCENE_RING 20
#define SCENE_HOOP_TRUNDLING SCENE_RING

#define SCENE_ROLLING 21
#define SCENE_HOP_STOP_N_ROLL SCENE_ROLLING

#define SCENE_ROPE 22
#define SCENE_SODA_HOP SCENE_ROPE

#define SCENE_SAMURAI 23
#define SCENE_SPIRIT_SLASHER SCENE_SAMURAI

#define SCENE_SOCCER 24
#define SCENE_FOOTBALL_DREAMS SCENE_SOCCER
#define SCENE_SOCCER_DREAMS SCENE_SOCCER

#define SCENE_SOFTCATCH 25
#define SCENE_YUM_BOT_SIMULATOR SCENE_SOFTCATCH

#define SCENE_TALK 26
#define SCENE_ALIEN_ALPHABET SCENE_TALK

#define SCENE_THE_A 27
#define SCENE_A_FOR_EFFORT SCENE_THE_A

#define SCENE_THUNDER 28
#define SCENE_LIGHTNING_BOLTING SCENE_THUNDER

#define SCENE_WIPER 29
#define SCENE_WIPER_BOSSES SCENE_WIPER

#define SCENE_SHINKAI 30
#define SCENE_DEEP_SEA SCENE_SHINKAI

enum SceneCarryoverType : unsigned int {
    SceneCarryoverAll   = 0x00,
    SceneCarryoverState = 0x01,
    SceneCarryoverNone  = 0x02
};

struct Scene_710013ad00 {
    char _pad00[0x3898]; // could be 0x3890
};

static_assert(sizeof(Scene_710013ad00) == 0x3898);

struct SceneChanger {
    int instant(SeqThread* thread, int sceneID);
    int fade1Beat(SeqThread* thread, int sceneID, int);
    int fade2Beat(SeqThread* thread, int sceneID, int);
    int fade4Beat(SeqThread* thread, int sceneID, int);
    int fade8Beat(SeqThread* thread, int sceneID, int);

    char _pad00[0x3A68]; // could be 0x3A60
};

static_assert(sizeof(SceneChanger) == 0x3A68);

struct SceneEffect {
    // _very_ unsure of these names
    int bOnA(SeqThread* thread, int sceneID, int ticks, int alsoTicks, int maybeTicks, int);
    int aOnB(SeqThread* thread, int sceneID, int ticks);

    char _padIOTicks[0x3A68];
    int bubbleInTicks;
    int bubbleOutTicks;
};

static_assert(offsetof(SceneEffect, bubbleInTicks) == 0x3A68);
static_assert(offsetof(SceneEffect, bubbleOutTicks) == 0x3A6C);
static_assert(sizeof(SceneEffect) == 0x3A70);

struct Stage : IStage {
    void waitUntilUnk(SeqThread*, bool, int); // Stage::FUN_71001398b0

    void initWavMark(WavMarkId, bool);
    void prepareWavMark(WavMarkId);
    void FUN_7100137050(bool);
    void FUN_7100138CD0();
    void fadeScreen(int ticks, float opacity);
    void fadeGameplay(int ticks, float opacity);
    void FUN_7100138FC0();
    void FUN_7100137140();
    void FUN_7100139250(SeqThread*, int, int);
    void FUN_7100138f80();
    void FUN_7100137b50(int ticks);
    void FUN_7100137b60(int);
    void startupBGM(SeqThread*, WavMarkId, unsigned int ticks, int, float, float);
    void FUN_7100138d20();
    void FUN_7100138ce0();
    void registerResults();

    void setComment(const char* comment);

    void beatAnim(SeqThread*, int ticks, int alsoTicks, int loops);
    void stopAnim(SeqThread*);

    char _pad00[0x2c60 - sizeof(IStage)];
};

static_assert(sizeof(Stage) == 0x2C60);

struct StageRemix : Stage {
    SceneRing* makeSceneRing(StageRemix*, int version);
    void setUnk3535(bool);
    void setInitRingBubbleState(int bubbleState);
    void initSubScene(int sceneID, int, bool);
    void waitUntilSceneReady(SeqThread*, int sceneID, bool);

    void setRatingInfo(Scene*, int, const char*);
    void setSceneCarryover(int sceneID, SceneCarryoverType carryoverType); // i think
    void setCueScene(SeqThread* thread, int sceneID);

    char _padSeqCallbackContext[0x3548 - sizeof(Stage)];
    void** seqCallbackContext;

    char _padRunner[0x3550 - (0x3548 + sizeof(void*))];
    SeqRunner* runner;

    int unk3558;
    int unk355C;

    int seqThreadIndex;
    int unk3564;
    long long unk3568;
};

static_assert(offsetof(StageRemix, seqCallbackContext) == 0x3548);
static_assert(offsetof(StageRemix, runner) == 0x3550);
static_assert(offsetof(StageRemix, seqThreadIndex) == 0x3560);
static_assert(sizeof(StageRemix) == 0x3570);

struct StageRemix20 : StageRemix {
    static void invokeSeqCallback(SeqThread*, SeqCallback*);

    Scene_710013ad00 scene_710013ad00;
    SceneChanger sceneChanger;
    SceneEffect sceneEffect;

    SubSceneBacteria sceneBacteria;
    SubSceneBirds sceneBirds;
    SubSceneBrush sceneBrush;
    SubSceneCars sceneCars;
    SubSceneClap sceneClap;
    SubSceneCooking sceneCooking;
    SubSceneCrab sceneCrab;
    SubSceneDancer sceneDancer;
    SubSceneFlydisc sceneFlydisc;
    SubSceneGrasp sceneGrasp;
    SubSceneGuardian sceneGuardian;
    SubSceneHammer sceneHammer;
    SubSceneHungry sceneHungry;
    SubSceneHurdle sceneHurdle;
    SubSceneInsect sceneInsect;
    SubSceneKaeru sceneKaeru;
    SubSceneMoon sceneMoon;
    SubSceneParasol sceneParasol;
    SubScenePumpup scenePumpup;
    SubScenePutilabo scenePutilabo;
    SubSceneRing sceneRing;
    SubSceneRolling sceneRolling;
    SubSceneRope sceneRope;
    SubSceneSamurai sceneSamurai;
    SubSceneSoccer sceneSoccer;
    SubSceneSoftcatch sceneSoftcatch;
    SubSceneTalk sceneTalk;
    SubSceneTheA sceneTheA;
    SubSceneThunder sceneThunder;
    SubSceneWiper sceneWiper;
    SubSceneShinkai sceneShinkai;

    Message clapMessage;
    Message graspMessage;

    StageRemix20* self; // i think??
};

static_assert(offsetof(StageRemix20, sceneChanger) == 0x6E08);
static_assert(offsetof(StageRemix20, sceneEffect) == 0xA870);
static_assert(offsetof(StageRemix20, sceneBacteria) == 0xE2E0);
static_assert(offsetof(StageRemix20, sceneBirds) == 0xE2F8);
static_assert(offsetof(StageRemix20, sceneBrush) == 0xE310);
static_assert(offsetof(StageRemix20, sceneClap) == 0xE340);
static_assert(offsetof(StageRemix20, sceneHammer) == 0xE3E8);
static_assert(offsetof(StageRemix20, sceneMoon) == 0xE460);
static_assert(offsetof(StageRemix20, sceneRing) == 0xE4C0);
static_assert(offsetof(StageRemix20, sceneRope) == 0xE4F0);
static_assert(offsetof(StageRemix20, sceneTheA) == 0xE568);
static_assert(offsetof(StageRemix20, sceneShinkai) == 0xE5B0);
static_assert(offsetof(StageRemix20, clapMessage) == 0xE5C8);
static_assert(offsetof(StageRemix20, graspMessage) == 0xE5E0);
static_assert(sizeof(StageRemix20) == 0xE600);

struct StageFactory {
    Stage* create(unsigned int stageID, unsigned long long, unsigned int, unsigned int, unsigned int, unsigned int, unsigned int);
};

extern SceneSkater* makeSceneSkater(StageRemix* stage, StageRemix*, int version);
extern SceneOwl* makeSceneOwl(StageRemix* stage, StageRemix*, int version);
