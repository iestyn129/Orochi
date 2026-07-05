#include "hk/hook/Trampoline.h"
#include "nn/fs.h"
#include "arm_neon.h"
#include "log.h"


HkTrampoline initHook = [](TrampolineStatic(), u64* a1) -> void {
    nn::fs::MountSdCard("sdmc");
    nn::fs::CreateDirectory("sdmc:/Pyrite");

    initLog();

    orig(a1);
};


HkTrampoline mainLoopHook = [](TrampolineStatic(), s32 a1) -> void {
    orig(a1);
};

extern "C" void hkMain() {
    initHook.installAtMainOffset(0x50CBA0);
    mainLoopHook.installAtMainOffset(0x509E10);
}