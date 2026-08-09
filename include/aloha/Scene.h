#pragma once

#include "cstddef"
#include "aloha/Graph.h"
#include "aloha/Seq.h"

// idfk im just gonna name it this
struct SFXManager {};

// i dislike this name
struct IStage {
    char _pad00[0x2978];
};

static_assert(sizeof(IStage) == 0x2978);

struct Scene : IStage {
    void scheduleSFX(SeqThread*, int ticks, SFXManager*, unsigned int sfxID, int, float, float);

    char _pad00[0x3880 - sizeof(IStage)];
};

static_assert(sizeof(Scene) == 0x3880);

struct SceneBacteria : Scene {
    void startAerobics(SeqThread*, int beats, bool start);
    void startSlowAerobics(SeqThread*, int beats, bool start);
    void stopAerobics(SeqThread*, int);
    void tripleAerobics(SeqThread*);
};

struct SceneBrush : Scene {
    void sweepContinuous(SeqThread*, int beats, bool, bool, bool);
    void sweepThree(SeqThread*);
    void spinSpin(SeqThread*, bool pauseAnim);
    void spinStop();

    char _padYou[0x40B8 - sizeof(Scene)];
    GraphAnime* you;
    GraphAnime* bg;
};

static_assert(offsetof(SceneBrush, you) == 0x40B8);
static_assert(offsetof(SceneBrush, bg) == 0x40C0);

struct SceneClap : Scene {
    void cue123(SeqThread*);
    void cue321(SeqThread*);
    void clap(SeqThread*, int type);
    void clapCueDouble(SeqThread*);
    void doubleClap(SeqThread*);
    void clapCueTriple(SeqThread*);
    void tripleClap(SeqThread*);

    void setBG(int, GraphAnime*);
    void setTVText(const char* text);

    char _padAnime[0x3E10 - sizeof(Scene)];
    GraphAnime* anime;

    char _padChannels[0x5138 - (0x3E10 + sizeof(GraphAnime*))];
    // ReSharper disable once CppPolymorphicClassWithNonVirtualPublicDestructor
    struct ClapChannel {
        ClapChannel(SceneClap* scene, const char* graphPath);
        virtual void FUN_00();
        virtual void FUN_08();
        virtual void FUN_10();
        virtual void FUN_18();
        virtual void setView(const char* view);

        unsigned long id;
        void* unk10;
        SceneClap* scene18;
        void* unk20;
        SceneClap* scene28;
        SceneClap* scene30;
        Graph graph;
        GraphAnime* anime{};
        void* unk198;
    }* channels[20]; // could be more
};

static_assert(offsetof(SceneClap, anime) == 0x3E10);
static_assert(offsetof(SceneClap, channels) == 0x5138);
static_assert(sizeof(SceneClap::ClapChannel) == 0x1A0);
static_assert(offsetof(SceneClap::ClapChannel, graph) == 0x38);
static_assert(offsetof(SceneClap::ClapChannel, anime) == 0x190);

struct SceneHammer : Scene {
    void spawnCanRed(SeqThread*, int landTicks, bool thrown, int hitTicks);
    void spawnCanBlue(SeqThread*, int landTicks, bool thrown, int hitTicks);
};

struct SceneMoon : Scene {
    void sneezeGreen(SeqThread*, bool windup);
    void sneezeRed(SeqThread*, bool windup);
    void windupGreen(SeqThread*);

    char _padMoon[0x3E70 - sizeof(Scene)];
    struct Moon {
        void sign(int);

        char _padAnime[0x10];
        GraphAnime* anime;
    }* moon;

    char _padFastSneeze[0x3E90 - (0x3E70 + sizeof(Moon*))];
    bool fastSneeze;

    char _padSFXManager[0x4238 - (0x3E90 + sizeof(bool))];
    SFXManager sfxManager;
};

static_assert(offsetof(SceneMoon, moon) == 0x3E70);
static_assert(offsetof(SceneMoon, fastSneeze) == 0x3E90);
static_assert(offsetof(SceneMoon, sfxManager) == 0x4238);
static_assert(offsetof(SceneMoon::Moon, anime) == 0x10);

struct SceneRing : Scene {
    void spawnRing(SeqThread*, int bubbleState);

    char _padAnime[0x3B60 - sizeof(Scene)];
    GraphAnime* anime;
};

static_assert(offsetof(SceneRing, anime) == 0x3B60);

struct SceneRope : Scene {
    void jump(SeqThread*, int animLength, bool stopping);
    void doubleUnder(SeqThread*, int animLength, bool stopRope, bool cutAudioCue);
};

struct SceneShinkai : Scene {};

struct SceneOwl : Scene {
    SceneOwl(void*, int version);

    char _pad00[0x43A8 - sizeof(Scene)];
};

static_assert(sizeof(SceneOwl) == 0x43A8);

struct SceneSkater : Scene {
    SceneSkater(void*, int version);
    void initUFO();
    void FUN_710023c9f0(int, int);
    void initGround(SeqThread*, int, int, char);

    void spawnSugarCubes(SeqThread*, int, int);
    void spawnEgg(SeqThread*, int, int);
    void spawnCookieTower(SeqThread*, int, int);

    char _pad00[0x4CB8 - sizeof(Scene)];
};

static_assert(sizeof(SceneSkater) == 0x4CB8);
