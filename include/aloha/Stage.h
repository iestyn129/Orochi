#pragma once

#include <cstddef>
#include "aloha/Message.h"
#include "aloha/SubScene.h"
#include "aloha/Seq.h"
#include "aloha/WavMark.h"

enum Remix20SceneID : int {
    SCENE_INVALID = -1,
    SCENE_BACTERIA = 0,
    SCENE_BIRDS = 1,
    SCENE_BRUSH = 2,
    SCENE_CARS = 3,
    SCENE_CLAP = 4,
    SCENE_COOKING = 5,
    SCENE_CRAB = 6,
    SCENE_DANCER = 7,
    SCENE_FLYDISC = 8,
    SCENE_GRASP = 9,
    SCENE_GUARDIAN = 10,
    SCENE_HAMMER = 11,
    SCENE_HUNGRY = 12,
    SCENE_HURDLE = 13,
    SCENE_INSECT = 14,
    SCENE_KAERU = 15,
    SCENE_MOON = 16,
    SCENE_PARASOL = 17,
    SCENE_PUMPUP = 18,
    SCENE_PUTILABO = 19,
    SCENE_RING = 20,
    SCENE_ROLLING = 21,
    SCENE_ROPE = 22,
    SCENE_SAMURAI = 23,
    SCENE_SOCCER = 24,
    SCENE_SOFTCATCH = 25,
    SCENE_TALK = 26,
    SCENE_THE_A = 27,
    SCENE_THUNDER = 28,
    SCENE_WIPER = 29,
    SCENE_SHINKAI = 30
};

enum Remix20SceneIDAlias : int {
    SCENE_GERM_AEROBICS = SCENE_BACTERIA,
    SCENE_SYNCHRO_WINGS = SCENE_BIRDS,
    SCENE_SWEEPER_STAR = SCENE_BRUSH,
    SCENE_STOP_N_GO_STOP = SCENE_CARS,
    SCENE_HIGH_FIVE_FEVER = SCENE_CLAP,
    SCENE_SLICE_N_DICE_KITCHEN = SCENE_COOKING,
    SCENE_CRAB_SNACKS = SCENE_CRAB,
    SCENE_BACKUP_SPOTLIGHT = SCENE_DANCER,
    SCENE_DISC_DOG = SCENE_FLYDISC,
    SCENE_QUICK_HANDS = SCENE_GRASP,
    SCENE_SPACE_SENTRY = SCENE_GUARDIAN,
    SCENE_CAN_DO = SCENE_HAMMER,
    SCENE_FEEDING_THE_BEAST = SCENE_HUNGRY,
    SCENE_HOP_N_SLIDE = SCENE_HURDLE,
    SCENE_FLUTTER_SPEED = SCENE_INSECT,
    SCENE_RIBBIT_ROCKET = SCENE_KAERU,
    SCENE_SNEEZY_MOON = SCENE_MOON,
    SCENE_BROLLY_GOOD_SHOW = SCENE_PARASOL,
    SCENE_FRUIT_FLEX = SCENE_PUMPUP,
    SCENE_POP_DONT_DROP = SCENE_PUTILABO,
    SCENE_HOOP_TRUNDLING = SCENE_RING,
    SCENE_HOP_STOP_N_ROLL = SCENE_ROLLING,
    SCENE_SODA_HOP = SCENE_ROPE,
    SCENE_SPIRIT_SLASHER = SCENE_SAMURAI,
    SCENE_SOCCER_DREAMS = SCENE_SOCCER,
    SCENE_YUM_BOT_SIMULATOR = SCENE_SOFTCATCH,
    SCENE_ALIEN_ALPHABET = SCENE_TALK,
    SCENE_A_FOR_EFFORT = SCENE_THE_A,
    SCENE_LIGHTNING_BOLTING = SCENE_THUNDER,
    SCENE_WIPER_BOSSES = SCENE_WIPER,
    SCENE_DEEP_SEA = SCENE_SHINKAI
};

enum Remix20SceneIDAliasEU : int {
    SCENE_FOOTBALL_DREAMS = SCENE_SOCCER
};

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

    void FUN_7100138840(int, int);
    void FUN_7100138a70();

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
    void subSceneEnableCues(SeqThread* thread, int sceneID);

    char _padSeqCallbackContext[0x3548 - sizeof(Stage)];
    void** seqCallbackContext;

    char _padRunner[0x3550 - (0x3548 + sizeof(void*))];
    SeqRunner* runner;

    int unk3558;
    int unk355C;

    int seqThreadIndex;
};

static_assert(offsetof(StageRemix, seqCallbackContext) == 0x3548);
static_assert(offsetof(StageRemix, runner) == 0x3550);
static_assert(offsetof(StageRemix, seqThreadIndex) == 0x3560);
static_assert(sizeof(StageRemix) == 0x3568);

struct StageRemix20 : StageRemix {
    static void invokeSeqCallback(SeqThread*, SeqCallback*);

    int scenesLoaded;
    int scenesToLoad;
    int unk356C;

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

static_assert(offsetof(StageRemix20, scenesLoaded) == 0x3564);
static_assert(offsetof(StageRemix20, scenesToLoad) == 0x3568);
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

extern SceneOnion* makeSceneOnion(StageRemix* stage, StageRemix*, int version);
extern SceneSkater* makeSceneSkater(StageRemix* stage, StageRemix*, int version);
extern SceneOwl* makeSceneOwl(StageRemix* stage, StageRemix*, int version);
