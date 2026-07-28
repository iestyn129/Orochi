#include "hk/hook/Trampoline.h"
#include "nn/fs.h"
#include "global.h"
#include "aloha.h"
#include "log.h"
#include "string"

#define INIT_SCENE SCENE_GERM_AEROBICS


HkTrampoline initHook = [](TrampolineStatic(), u64* a1) -> void {
    nn::fs::MountSdCard(SD_DRIVE);
    nn::fs::CreateDirectory(ROOT_FOLDER);

    initLog();

    log("=== Orichi Initialised! ===");
    orig(a1);
};


HkTrampoline mainLoopHook = [](TrampolineStatic(), s32 a1) -> void {
    orig(a1);
};


HkTrampoline getTextHook = [](TrampolineStatic(), void* a1, const char* a2, void* a3) -> const char* {
    const auto key = std::string(a2);
    const char* result = orig(a1, a2, a3);

    //if (key.ends_with("cold_open_title")) {
    //    result = "♪ Cold Open\nVocal：Rin Penrose";
    //}

    return result;
};


void remix20Main(StageRemix* stage, SeqThread* thread) {
    thread->wait(12 * 480);

    stage->FUN_7100138CD0();

    stage->fadeScreen(3 * 480, 0.0);
    thread->wait(3 * 480);

    stage->FUN_7100138FC0();
    thread->wait(1 * 480);

    stage->FUN_7100137140();
}


void remix20Control(StageRemix* stage, SeqThread* thread) {}


void remix20Anim(StageRemix* stage, SeqThread* thread) {}


HkTrampoline remix20Cues00Hook = [](TrampolineStatic(), StageRemix* stage, SeqThread* thread) -> s64 {
    return thread->popUnk270();
};


HkTrampoline remix20Cues01Hook = [](TrampolineStatic(), StageRemix* stage, SeqThread* thread) -> s64 {
    return thread->popUnk270();
};


HkTrampoline remix20Cues02Hook = [](TrampolineStatic(), StageRemix* stage, SeqThread* thread) -> s64 {
    return thread->popUnk270();
};


HkTrampoline remix20Cues03Hook = [](TrampolineStatic(), StageRemix* stage, SeqThread* thread) -> s64 {
    return thread->popUnk270();
};


HkTrampoline remix20Cues04Hook = [](TrampolineStatic(), StageRemix* stage, SeqThread* thread) -> s64 {
    return thread->popUnk270();
};


HkTrampoline remix20Cues05Hook = [](TrampolineStatic(), StageRemix* stage, SeqThread* thread) -> s64 {
    return thread->popUnk270();
};


HkTrampoline remix20Cues06Hook = [](TrampolineStatic(), StageRemix* stage, SeqThread* thread) -> s64 {
    return thread->popUnk270();
};


HkTrampoline remix20Cues07Hook = [](TrampolineStatic(), StageRemix* stage, SeqThread* thread) -> s64 {
    return thread->popUnk270();
};


extern "C" void hkMain() {
    const u64 mainBase = hk::ro::getMainModule()->range().start();

    initHook.installAtMainOffset(0x50CBA0);
    mainLoopHook.installAtMainOffset(0x509E10);
    getTextHook.installAtMainOffset(0x4EFE80);

    hk::hook::a64::assemble<"mov w1, {}">()
        .arg(INIT_SCENE)
        .installAtMainOffset(0x4170B8); // FUN_71004d9dc0

    hk::hook::a64::assemble<"mov w2, {}">()
        .arg(INIT_SCENE)
        .installAtMainOffset(0x4170DC); // FUN_71004d9ec0

    hk::hook::a64::assemble<"mov w2, {}">()
        .arg(INIT_SCENE)
        .installAtMainOffset(0x417118); // sceneChangeInstant

    constexpr u64 remix20MainOffset = 0x417574;
    hk::hook::a64::assemble<"mov x0, x20">().installAtMainOffset(remix20MainOffset);
    hk::hook::a64::assemble<"mov x1, x19">().installAtMainOffset(remix20MainOffset + 4);
    hk::hook::writeBranchLinkAtMainOffset(remix20MainOffset + 8, &remix20Main);
    hk::hook::writeBranchAtMainOffset(remix20MainOffset + 12, reinterpret_cast<void*>(mainBase + 0x41799C));

    constexpr u64 remix20ControlOffset = 0x41F198;
    hk::hook::a64::assemble<"mov x0, x21">().installAtMainOffset(remix20ControlOffset);
    hk::hook::a64::assemble<"mov x1, x19">().installAtMainOffset(remix20ControlOffset + 4);
    hk::hook::writeBranchLinkAtMainOffset(remix20ControlOffset + 8, &remix20Control);
    hk::hook::writeBranchAtMainOffset(remix20ControlOffset + 12, reinterpret_cast<void*>(mainBase + 0x42029C));

    constexpr u64 remix20AnimOffset = 0x4179F0;
    hk::hook::a64::assemble<"mov x0, x20">().installAtMainOffset(remix20AnimOffset);
    hk::hook::a64::assemble<"mov x1, x19">().installAtMainOffset(remix20AnimOffset + 4);
    hk::hook::writeBranchLinkAtMainOffset(remix20AnimOffset + 8, &remix20Anim);
    hk::hook::writeBranchAtMainOffset(remix20AnimOffset + 12, reinterpret_cast<void*>(mainBase + 0x41800C));

    remix20Cues00Hook.installAtMainOffset(0x418AE0);
    remix20Cues01Hook.installAtMainOffset(0x4194D0);
    remix20Cues02Hook.installAtMainOffset(0x41A020);
    remix20Cues03Hook.installAtMainOffset(0x41B8F0);
    remix20Cues04Hook.installAtMainOffset(0x41DCE0);
    remix20Cues05Hook.installAtMainOffset(0x41E770);
    remix20Cues06Hook.installAtMainOffset(0x418020);
    remix20Cues07Hook.installAtMainOffset(0x418500);
}
