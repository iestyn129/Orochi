#pragma once

#include "aloha/Scene.h"

// ReSharper disable once CppPolymorphicClassWithNonVirtualPublicDestructor
struct SubSceneBase {
    virtual void FUN_00();

    void* unk08;
};

static_assert(sizeof(SubSceneBase) == 0x10);

// ReSharper disable once CppPolymorphicClassWithNonVirtualPublicDestructor
struct SubSceneBacteria : SubSceneBase {
    SceneBacteria* scene;
};

static_assert(sizeof(SubSceneBacteria) == 0x18);

// ReSharper disable once CppPolymorphicClassWithNonVirtualPublicDestructor
struct SubSceneBirds : SubSceneBase {
    SceneBirds* scene;
};

static_assert(sizeof(SubSceneBirds) == 0x18);

// ReSharper disable once CppPolymorphicClassWithNonVirtualPublicDestructor
struct SubSceneBrush : SubSceneBase {
    SceneBrush* scene;
};

static_assert(sizeof(SubSceneBrush) == 0x18);

// ReSharper disable once CppPolymorphicClassWithNonVirtualPublicDestructor
struct SubSceneCars : SubSceneBase {
    SceneCars* scene;
};

static_assert(sizeof(SubSceneCars) == 0x18);

// ReSharper disable once CppPolymorphicClassWithNonVirtualPublicDestructor
struct SubSceneClap : SubSceneBase {
    SceneClap* scene;
};

static_assert(sizeof(SubSceneClap) == 0x18);

// ReSharper disable once CppPolymorphicClassWithNonVirtualPublicDestructor
struct SubSceneCooking : SubSceneBase {
    SceneCooking* scene;
};

static_assert(sizeof(SubSceneCooking) == 0x18);

// ReSharper disable once CppPolymorphicClassWithNonVirtualPublicDestructor
struct SubSceneCrab : SubSceneBase {
    SceneCrab* scene;
};

static_assert(sizeof(SubSceneCrab) == 0x18);

// ReSharper disable once CppPolymorphicClassWithNonVirtualPublicDestructor
struct SubSceneDancer : SubSceneBase {
    SceneDancer* scene;
};

static_assert(sizeof(SubSceneDancer) == 0x18);

// ReSharper disable once CppPolymorphicClassWithNonVirtualPublicDestructor
struct SubSceneFlydisc : SubSceneBase {
    SceneFlydisc* scene;
};

static_assert(sizeof(SubSceneFlydisc) == 0x18);

// ReSharper disable once CppPolymorphicClassWithNonVirtualPublicDestructor
struct SubSceneGrasp : SubSceneBase {
    SceneGrasp* scene;
};

static_assert(sizeof(SubSceneGrasp) == 0x18);

// ReSharper disable once CppPolymorphicClassWithNonVirtualPublicDestructor
struct SubSceneGuardian : SubSceneBase {
    SceneGuardian* scene;
};

static_assert(sizeof(SubSceneGuardian) == 0x18);

// ReSharper disable once CppPolymorphicClassWithNonVirtualPublicDestructor
struct SubSceneHammer : SubSceneBase {
    SceneHammer* scene;
};

static_assert(sizeof(SubSceneHammer) == 0x18);

// ReSharper disable once CppPolymorphicClassWithNonVirtualPublicDestructor
struct SubSceneHungry : SubSceneBase {
    SceneHungry* scene;
};

static_assert(sizeof(SubSceneHungry) == 0x18);

// ReSharper disable once CppPolymorphicClassWithNonVirtualPublicDestructor
struct SubSceneHurdle : SubSceneBase {
    SceneHurdle* scene;
};

static_assert(sizeof(SubSceneHurdle) == 0x18);

// ReSharper disable once CppPolymorphicClassWithNonVirtualPublicDestructor
struct SubSceneInsect : SubSceneBase {
    SceneInsect* scene;
};

static_assert(sizeof(SubSceneInsect) == 0x18);

// ReSharper disable once CppPolymorphicClassWithNonVirtualPublicDestructor
struct SubSceneKaeru : SubSceneBase {
    SceneKaeru* scene;
};

static_assert(sizeof(SubSceneKaeru) == 0x18);

// ReSharper disable once CppPolymorphicClassWithNonVirtualPublicDestructor
struct SubSceneMoon : SubSceneBase {
    SceneMoon* scene;
};

static_assert(sizeof(SubSceneMoon) == 0x18);

// ReSharper disable once CppPolymorphicClassWithNonVirtualPublicDestructor
struct SubSceneParasol : SubSceneBase {
    SceneParasol* scene;
};

static_assert(sizeof(SubSceneParasol) == 0x18);

// ReSharper disable once CppPolymorphicClassWithNonVirtualPublicDestructor
struct SubScenePumpup : SubSceneBase {
    ScenePumpup* scene;
};

static_assert(sizeof(SubScenePumpup) == 0x18);

// ReSharper disable once CppPolymorphicClassWithNonVirtualPublicDestructor
struct SubScenePutilabo : SubSceneBase {
    ScenePutilabo* scene;
};

static_assert(sizeof(SubScenePutilabo) == 0x18);

// ReSharper disable once CppPolymorphicClassWithNonVirtualPublicDestructor
struct SubSceneRing : SubSceneBase {
    SceneRing* scene;
};

static_assert(sizeof(SubSceneRing) == 0x18);

// ReSharper disable once CppPolymorphicClassWithNonVirtualPublicDestructor
struct SubSceneRolling : SubSceneBase {
    SceneRolling* scene;
};

static_assert(sizeof(SubSceneRolling) == 0x18);

// ReSharper disable once CppPolymorphicClassWithNonVirtualPublicDestructor
struct SubSceneRope : SubSceneBase {
    SceneRope* scene;
};

static_assert(sizeof(SubSceneRope) == 0x18);

// ReSharper disable once CppPolymorphicClassWithNonVirtualPublicDestructor
struct SubSceneSamurai : SubSceneBase {
    SceneSamurai* scene;
};

static_assert(sizeof(SubSceneSamurai) == 0x18);

// ReSharper disable once CppPolymorphicClassWithNonVirtualPublicDestructor
struct SubSceneSoccer : SubSceneBase {
    SceneSoccer* scene;
};

static_assert(sizeof(SubSceneSoccer) == 0x18);

// ReSharper disable once CppPolymorphicClassWithNonVirtualPublicDestructor
struct SubSceneSoftcatch : SubSceneBase {
    SceneSoftcatch* scene;
};

static_assert(sizeof(SubSceneSoftcatch) == 0x18);

// ReSharper disable once CppPolymorphicClassWithNonVirtualPublicDestructor
struct SubSceneTalk : SubSceneBase {
    SceneTalk* scene;
};

static_assert(sizeof(SubSceneTalk) == 0x18);

// ReSharper disable once CppPolymorphicClassWithNonVirtualPublicDestructor
struct SubSceneTheA : SubSceneBase {
    SceneTheA* scene;
};

static_assert(sizeof(SubSceneTheA) == 0x18);

// ReSharper disable once CppPolymorphicClassWithNonVirtualPublicDestructor
struct SubSceneThunder : SubSceneBase {
    SceneThunder* scene;
};

static_assert(sizeof(SubSceneThunder) == 0x18);

// ReSharper disable once CppPolymorphicClassWithNonVirtualPublicDestructor
struct SubSceneWiper : SubSceneBase {
    SceneWiper* scene;
};

static_assert(sizeof(SubSceneWiper) == 0x18);

// ReSharper disable once CppPolymorphicClassWithNonVirtualPublicDestructor
struct SubSceneShinkai : SubSceneBase {
    SceneShinkai* scene;
};

static_assert(sizeof(SubSceneShinkai) == 0x18);

// ReSharper disable once CppPolymorphicClassWithNonVirtualPublicDestructor
struct SubSceneOnion : SubSceneBase {
    SceneOnion* scene;
};

static_assert(sizeof(SubSceneOnion) == 0x18);
