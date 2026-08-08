#include "aloha/Stage.h"
#include "global.h"

SceneSkater* StageRemix::makeSceneSkater(StageRemix*, s32 version) {
    if (version < 0)
        version = 0;

    const auto scene = new SceneSkater{this, version};
    this->setRatingInfo(scene, 0, "selfish");

    return scene;
}

SceneOwl* StageRemix::makeSceneOwl(StageRemix*, s32 version) {
    if (version < 0)
        version = 0;

    const auto scene = new SceneOwl{this, version};
    this->setRatingInfo(scene, 0, "selfish");

    return scene;
}

SceneSkater* makeSceneSkater(StageRemix* stage, StageRemix* a2, s32 version) {
    return stage->makeSceneSkater(a2, 0);
}

SceneOwl* makeSceneOwl(StageRemix* stage, StageRemix* a2, s32 version) {
    return stage->makeSceneOwl(a2, 0);
}
