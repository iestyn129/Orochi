#include "aloha/Stage.h"
#include "global.h"


SceneSkater* makeSceneSkater(StageRemix* stage, StageRemix*, s32 version) {
    if (version < 0)
        version = 0;

    const auto scene = new SceneSkater{stage, version};
    stage->setRatingInfo(scene, 0, "selfish");

    return scene;
}


SceneOwl* makeSceneOwl(StageRemix* stage, StageRemix*, s32 version) {
    if (version < 0)
        version = 0;

    const auto scene = new SceneOwl{stage, version};
    stage->setRatingInfo(scene, 0, "selfish");

    return scene;
}
