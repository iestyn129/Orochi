#include "hk/hook/Trampoline.h"
#include "nn/fs.h"
#include "global.h"
#include "aloha.h"
#include "log.h"
#include "scripting.h"
#include "string"


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


    if (key.ends_with("cold_open_title")) {
        result = "♪ Cold Open\nVocal：Rin Penrose";
    } else if (key.ends_with("cold_open_composer")) {
        result = "Lyricist: Rin Penrose・WUNDER RiKU  Composer: WUNDER RiKU\nCharting: iestyn129";
    } else if (key.ends_with("cold_open_lyrics00")) {
        result = "I'm thinking here we'll play ourselves a different song\nWhat a wonderful twist, it's a whim so you'll act upon it";
    } else if (key.ends_with("cold_open_lyrics01")) {
        result = "So it's in the script but is that so wrong?\nNow I'm taking the lead, so you might want to play along";
    } else if (key.ends_with("cold_open_lyrics02")) {
        result = "To you it's devious, to me you're the liar\nTo you it's nebulous, to me it's inspired";
    } else if (key.ends_with("cold_open_lyrics03")) {
        result = "Claw back that relevance, toss out that hesitance\nLet me give you something new to admire";
    } else if (key.ends_with("cold_open_lyrics04")) {
        result = "Do you believe in someone like me?\nBreaking, blazing, burning like a laser beam";
    } else if (key.ends_with("cold_open_lyrics05")) {
        result = "Oh satellite, don't hide your eyes, 'cause\nI'll be here as long as you've got eyes to see";
    } else if (key.ends_with("cold_open_lyrics06")) {
        result = "Fade background sound to mute, directive absolute\nKeep me in focus as the star of the shoot";
    } else if (key.ends_with("cold_open_lyrics07")) {
        result = "Until they cue that theme...";
    } else if (key.ends_with("cold_open_lyrics08")) {
        result = "Let's make a scene";
    }

    return result;
};


void remix20Main(s64 a1, s64 a2) {
    runLuaChart(a1, a2, MAIN_SCRIPT);

    //sub_7100138CD0(a1);
    //sub_71001366E0(a1);
    //sub_7100138FC0(a1);
    //sub_7100137140(a1);
}


void remix20Control(s64 a1, s64 a2) {
    runLuaChart(a1, a2, CONTROL_SCRIPT);
}


void remix20Anim(s64 a1, s64 a2) {
    runLuaChart(a1, a2, ANIM_SCRIPT);
}


HkTrampoline remix20Cues00Hook = [](TrampolineStatic(), s64 a1, s64 a2) -> s64 {
    runLuaChart(a1, a2, CUES00_SCRIPT);

    return a2;
};


HkTrampoline remix20Cues01Hook = [](TrampolineStatic(), s64 a1, s64 a2) -> s64 {
    runLuaChart(a1, a2, CUES01_SCRIPT);

    return a2;
};


HkTrampoline remix20Cues02Hook = [](TrampolineStatic(), s64 a1, s64 a2) -> s64 {
    runLuaChart(a1, a2, CUES02_SCRIPT);

    return a2;
};


HkTrampoline remix20Cues03Hook = [](TrampolineStatic(), s64 a1, s64 a2) -> s64 {
    runLuaChart(a1, a2, CUES03_SCRIPT);

    return a2;
};


HkTrampoline remix20Cues04Hook = [](TrampolineStatic(), s64 a1, s64 a2) -> s64 {
    runLuaChart(a1, a2, CUES04_SCRIPT);

    return a2;
};


HkTrampoline remix20Cues05Hook = [](TrampolineStatic(), s64 a1, s64 a2) -> s64 {
    runLuaChart(a1, a2, CUES05_SCRIPT);

    return a2;
};


HkTrampoline remix20Cues06Hook = [](TrampolineStatic(), s64 a1, s64 a2) -> s64 {
    runLuaChart(a1, a2, CUES06_SCRIPT);

    return a2;
};


HkTrampoline remix20Cues07Hook = [](TrampolineStatic(), s64 a1, s64 a2) -> s64 {
    runLuaChart(a1, a2, CUES07_SCRIPT);

    return a2;
};

extern "C" void hkMain() {
    u64 mainBase = hk::ro::getMainModule()->range().start();

    initHook.installAtMainOffset(0x50CBA0);
    mainLoopHook.installAtMainOffset(0x509E10);
    getTextHook.installAtMainOffset(0x4EFE80);

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
