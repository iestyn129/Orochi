#pragma once

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

typedef enum FilePartitionType {
    PartitionType_Data=0x00,
    PartitionType_User=0x01,
    PartitionType_Demo=0x02,
    PartitionType_Debug=0x03
} FilePartitionType;

struct Graph {
    int startup(const char*, FilePartitionType, void*);
};

struct SeqThread {
    void wait(int ticks);
    bool stopRequested();

    int pushUnk270();
    int popUnk270();

    void STUB_7100514ff0(int);
};

struct SceneChanger {
    int instant(SeqThread* thread, int sceneID);
    int fade1Beat(SeqThread* thread, int sceneID, int);
    int fade2Beat(SeqThread* thread, int sceneID, int);
    int fade4Beat(SeqThread* thread, int sceneID, int);
    int fade8Beat(SeqThread* thread, int sceneID, int);
};

struct SceneBacteria {
    void startAerobics(SeqThread*, int beats, bool start);
    void startSlowAerobics(SeqThread*, int beats, bool start);
    void stopAerobics(SeqThread*, int);
    void tripleAerobics(SeqThread*);
};

struct SceneClap {
    void cue123(SeqThread*);
    void cue321(SeqThread*);
    void clap(SeqThread*, int type);
    void clapCueDouble(SeqThread*);
    void doubleClap(SeqThread*);
    void clapCueTriple(SeqThread*);
    void tripleClap(SeqThread*);
};

struct SceneMoon {
    void sneezeGreen(SeqThread*, bool windup);
};

struct SceneRing {
    void spawnRing(SeqThread*, int bubbleState);
};

struct Stage {
    void FUN_7100138CD0();
    void fadeScreen(int ticks, float opacity);
    void FUN_7100138FC0();
    void FUN_7100137140();

    void setComment(const char* comment);

    char _pad00[0x2c60];
};

static_assert(sizeof(Stage) == 0x2C60);

struct StageRemix : Stage {
    void saveSceneState(int sceneID, int slot); // ???
    void setCueScene(SeqThread* thread, int sceneID);

    char _pad00[0x3600 - 0x2C60];
};

static_assert(sizeof(StageRemix) == 0x3600);

struct StageRemix20 : StageRemix {
    char _pad00[0x6E08 - 0x3600];
    SceneChanger sceneChanger;

    char _pad01[0xE2F0 - (0x6E08 + sizeof(SceneChanger))];
    SceneBacteria* bacteria;

    char _pad02[0xE350 - (0xE2F0 + sizeof(SceneBacteria*))];
    SceneClap* clap;

    char _pad03[0xE470 - (0xE350 + sizeof(SceneClap*))];
    SceneMoon* moon;

    char _pad04[0xE4D0 - (0xE470 + sizeof(SceneMoon*))];
    SceneRing* ring;
};

static_assert(offsetof(StageRemix20, sceneChanger) == 0x6E08);
static_assert(offsetof(StageRemix20, bacteria) == 0xE2F0);
static_assert(offsetof(StageRemix20, clap) == 0xE350);
static_assert(offsetof(StageRemix20, moon) == 0xE470);
static_assert(offsetof(StageRemix20, ring) == 0xE4D0);

struct StageFactory {
    Stage* create(unsigned int stageID, unsigned long long, unsigned int, unsigned int, unsigned int, unsigned int, unsigned int);
};
