#include "aloha.h"
#include "global.h"

SceneSkater* StageRemix::makeSceneSkater(StageRemix*, s32 version) {
    if (version < 0)
        version = 0;

    const auto scene = new SceneSkater{this, version};
    this->setRatingInfo(scene, 0, "selfish");

    return scene;
}

SceneSkater* makeSceneSkaterHook(StageRemix* stage, StageRemix* a2, s32 version) {
    return stage->makeSceneSkater(a2, 0);
}
