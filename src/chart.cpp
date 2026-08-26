#include "chart.h"

#include "log.h"
#include "script.h"

const s32 initRingBubbleState = ring_bubble_mask(true, true, true, true);


void chartEntry(const Chart& chart, StageRemix20* stage, SeqThread* thread) {
    stage->fadeScreen(0, 0.0);
    stage->initWavMark(chart.wavmark, true);
    wait_until_unk(false, -1);
    stage->prepareWavMark(chart.wavmark);
    thread->pushUnk270();

    stage->FUN_7100137050(false);
    stage->setUnk3535(false);
    stage->setInitRingBubbleState(initRingBubbleState);
    stage->initSubScene(chart.init_scene, -1, true);
    wait_until_scene_ready(chart.init_scene, false);
    change_scene_instant(chart.init_scene);
    stage->fadeScreen(480, 1.0);
    unk_7100139250(-1, 0);
    rest(1);

    stage->FUN_7100138f80();
    stage->setSwingSubdivision(chart.swingSubdivision);
    stage->setSwingRatio(chart.swingRatio);
    startup_bgm(chart.wavmark, 960, 0, 1.0, 1.0);

    for (const auto& lua_thread : chart.threads) {
        stage->runner->appendThread(new SeqThread(
            stage->runner, stage->seqThreadIndex,
            reinterpret_cast<void*>(&invokeLuaStageCallback),
            new LuaStageCallback(
                stage,
                lua_thread
            ),
            thread
        ));
    }

    stage->FUN_7100138d20();
    stage->FUN_7100138ce0();
    rest(std::max(chart.length - 3, 1.0f));

    stage->FUN_7100138CD0();
    stage->fadeScreen(1 * 480, 0.0);
    rest(1);
    stage->FUN_7100138FC0();
    rest(1);
    stage->FUN_7100137140();

    check_thread();
    stage->registerResults();
}


void invokeLuaStageCallback(SeqThread* thread, LuaStageCallback* callback) {
    auto result = callback->func(LuaStage(callback->stage, thread));

    thread->popUnk270();
}
