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
    void quickAerobics(SeqThread*);
    void regularAerobics(SeqThread*, int beats, bool countin);
    void slowAerobics(SeqThread*, int beats, bool countin);
    void stopAerobics(SeqThread*, int);
};

struct SceneBirds : Scene {
    void pattern(SeqThread*, const char* pattern);
};

struct SceneBrush : Scene {
    void continuousSweeping(SeqThread*, int beats, bool playUn, bool fadeUn, bool countout);
    void spinSpin(SeqThread*, bool pauseAnim);
    void stopSpinning(SeqThread*);
    void sweepThree(SeqThread*);

    char _padYou[0x40B8 - sizeof(Scene)];
    GraphAnime* you;
    GraphAnime* bg;
};

static_assert(offsetof(SceneBrush, you) == 0x40B8);
static_assert(offsetof(SceneBrush, bg) == 0x40C0);

struct SceneCars : Scene {
    void accelerate(SeqThread*, bool pointCue, bool largeBoost);
    void brake(SeqThread*, long, long, bool);
};

struct SceneClap : Scene {
    void countIn(SeqThread*);
    void countOut(SeqThread*);
    void singleHighFive(SeqThread*, int type);
    void preDoubleHighFive(SeqThread*);
    void doubleHighFive(SeqThread*);
    void preTripleHighFive(SeqThread*);
    void tripleHighFive(SeqThread*);

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

struct SceneCooking : Scene {
    void singleVeggie(SeqThread*, int, int);
    void broccoli(SeqThread*, int, int, int, int);
};

struct SceneCrab : Scene {
    void macaron(SeqThread*, int, int, int);
    void mangosteen(SeqThread*, int, int, int);
    void favaBean(SeqThread*, int, int, int);
};

struct SceneDancer : Scene {
    void startDance(SeqThread*, int beats, int voice, bool startInPosition, bool stayInPosition);
    void startTurnAndDance(SeqThread*, int beats, int voice, bool stayInPosition);
    void fastTurn(SeqThread*, bool);
};

struct SceneFlydisc : Scene {
    void throwDisc(SeqThread*, int color, int length, int soundID, bool);
    void setBackground(const char* background);
    void changeBackground(const char* background);
};

struct SceneGrasp : Scene {
    void throwObject(SeqThread*, int, bool);
    void doubleCatchA(SeqThread*);
    void doubleCatchB(SeqThread*, bool);
};

struct SceneGuardian : Scene {
    void normalMeteor(SeqThread*, int, int);
    void nearMeteor(SeqThread*, int, int);
    void farMeteor(SeqThread*, int, int);

};

struct SceneHammer : Scene {
    /* landTicks = usually a negative number. determines where on the conveyer the can spawns/lands
    hitTicks = how many ticks it takes from the moment you spawn the can to the moment hammer liftup begins. usually 7680 (16 beats)
    when a can is thrown, it takes 1.5 beats to land? */
    void spawnRedCan(SeqThread*, int landTicks, bool throwCan, int hitTicks);
    void spawnBlueCan(SeqThread*, int landTicks, bool throwCan, int hitTicks);
};

struct SceneHungry : Scene {
    // 0 = yellow flower, 1 = purple flower
    void spawnFlower(SeqThread*, int type);
};

struct SceneHurdle : Scene {
    void spawnObstacle(SeqThread*, bool slide);
    void spawnFlowers(SeqThread*);
};

struct SceneInsect : Scene {
    void butterfly(SeqThread*, int interval, int, int);
    void grasshopper(SeqThread*, int interval, int, int);
    void dragonfly(SeqThread*, int interval, int, int);
};

struct SceneKaeru : Scene {
    /* startingLilypad can be a number 0-4, starting at the
    lilypad left of the player and continuing left to the
    farthest offscreen lilypad */
    void greenFrog(SeqThread*, int startingLilypad);
    void redFrog(SeqThread*, int startingLilypad);
};

struct SceneMoon : Scene {
    void greenSneeze(SeqThread*, bool windup);
    void greenWindup(SeqThread*);
    void redSneeze(SeqThread*, bool windup);

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

struct SceneParasol : Scene {
    void cue(SeqThread*, int interval, int type, int, int); // type 0 = close, type 1 = open
    void openTogether(SeqThread*, int, int);
    void encore(SeqThread*, int interval);
};

struct ScenePumpup : Scene {
    void apple(SeqThread*, int interval, int, int);
    void lemon(SeqThread*, int interval, int, int);
};

struct ScenePutilabo : Scene {
    void regularBubble(SeqThread*, int);
    void hardBubble(SeqThread*, int holdTicks, int);
};

struct SceneRing : Scene {
    void hoop(SeqThread*, int bubbleState);

    char _padAnime[0x3B60 - sizeof(Scene)];
    GraphAnime* anime;
};

static_assert(offsetof(SceneRing, anime) == 0x3B60);

struct SceneRolling : Scene {
    void roll(SeqThread*, int);
    void hop(SeqThread*, int type); // 1 = count-in hop, 0 = normal hop, 2 = count-out hop, 3 = count-out hop w/o jump (unused?)
};

struct SceneRope : Scene {
    void singleJump(SeqThread*, int animLength, bool countout);
    void doubleUnder(SeqThread*, int animLength, bool stopRope, bool cutCue);
};

struct SceneSamurai : Scene {
    void singleSlice(SeqThread*, long slashNumber, long totalSlashesInChain);
    void doubleSlice(SeqThread*, long slashNumber, long totalSlashesInChain);
};

struct SceneShinkai : Scene {
    void singleRow(SeqThread*, long, const char*, const char*);
    void tripleRow(SeqThread*, long, const char*, const char*);
};

struct SceneSoccer : Scene {
    void kick(SeqThread*, int);
    void trapKick(SeqThread*, int);
    void trapJumpKick(SeqThread*, int);
};

struct SceneSoftcatch : Scene {
    void pudding(SeqThread*, long type, int ticksBetweenNotes);
};

struct SceneTalk : Scene {
    void bomBom(SeqThread*);
    void cha(SeqThread*);
    void bomCha(SeqThread*);
};

struct SceneTheA : Scene {
    void word(SeqThread*, const char* cueWord, float, void*, const char* background);
};

struct SceneThunder : Scene {
    void yellowLightning(SeqThread*, int numberOfCues, long);
    void yellowLightningFast(SeqThread*, long);
    void pinkLightning(SeqThread*, int numberOfCues, long);
    void pinkLightningFast(SeqThread*, long);
    void spawnAlien(int, int);
};

struct SceneWiper : Scene {
    void quickBoth(SeqThread*);
    void quickLeft(SeqThread*);
    void quickRight(SeqThread*);
    void slowBoth(SeqThread*);
    void slowLeft(SeqThread*, int sound);
    void slowRight(SeqThread*, int sound);
};

struct SceneOnion : Scene {
    SceneOnion(void*, int version);
    void spawnHairs(SeqThread*, int,
        char, char, char, char, char, char, char, char,
        char, char, char, char, char, char, char, char,
        char, char, char, char, char, char, char, char,
        char, char, char, char, char, char, char, char,
    int, int);

    char _pad00[0x6ce0 - sizeof(Scene)];
};

static_assert(sizeof(SceneOnion) == 0x6ce0);

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
