#pragma once

#include "cstddef"
#include "vector"

enum SeqThreadState : unsigned int {
    THREAD_NOT_STARTED     = 0x00,
    THREAD_RUNNING         = 0x01,
    THREAD_STOP_REQUESTED  = 0x02,
    THREAD_STOPPED         = 0x03
};

// ReSharper disable once CppPolymorphicClassWithNonVirtualPublicDestructor
struct TickTimerBase {
    virtual void FUN_00();
};

static_assert(sizeof(TickTimerBase) == 0x08);

struct SeqRunnerInfo {
    int id;
    const char* name;
    int usedNum;
};

static_assert(offsetof(SeqRunnerInfo, id) == 0x00);
static_assert(offsetof(SeqRunnerInfo, name) == 0x08);
static_assert(offsetof(SeqRunnerInfo, usedNum) == 0x10);
static_assert(sizeof(SeqRunnerInfo) == 0x18);

struct SeqCallback {
    void* context;
    void* function;
    unsigned long long offset;
};

static_assert(offsetof(SeqCallback, context) == 0x00);
static_assert(offsetof(SeqCallback, function) == 0x08);
static_assert(offsetof(SeqCallback, offset) == 0x10);
static_assert(sizeof(SeqCallback) == 0x18);

// ReSharper disable once CppPolymorphicClassWithNonVirtualPublicDestructor
struct SeqThreadBase { // NOLINT(*-pro-type-member-init)
    virtual void FUN_00();

    SeqThreadBase* nextOrPrev;
    int unk10;
};

static_assert(offsetof(SeqThreadBase, nextOrPrev) == 0x08);
static_assert(sizeof(SeqThreadBase) == 0x18);

// ReSharper disable once CppPolymorphicClassWithNonVirtualPublicDestructor
struct SeqRunnerBase { // NOLINT(*-pro-type-member-init)
    virtual void FUN_00();
    void appendThread(SeqThreadBase*);

    SeqRunnerBase* threadHeadOrTail;
    // ReSharper disable once CppPolymorphicClassWithNonVirtualPublicDestructor
    struct SeqRunnerTickTimerVector {
        virtual void FUN_00();

        std::vector<TickTimerBase*> vec;
    } tickTimers;
    TickTimerBase* seqTickTimer;

    int unk38;
    int unk3C;
    float unk40[4];
};

static_assert(offsetof(SeqRunnerBase, threadHeadOrTail) == 0x08);
static_assert(offsetof(SeqRunnerBase, tickTimers) == 0x10);
static_assert(offsetof(SeqRunnerBase, seqTickTimer) == 0x30);
static_assert(sizeof(SeqRunnerBase) == 0x50);
static_assert(sizeof(SeqRunnerBase::SeqRunnerTickTimerVector) == 0x20);

// ReSharper disable once CppPolymorphicClassWithNonVirtualPublicDestructor
struct SeqRunner : SeqRunnerBase {
    std::vector<SeqRunnerInfo> seqRunnerInfo;
    int prevInfoID;
};

static_assert(offsetof(SeqRunner, seqRunnerInfo) == 0x50);
static_assert(offsetof(SeqRunner, prevInfoID) == 0x68);
static_assert(sizeof(SeqRunner) == 0x70);

// ReSharper disable once CppPolymorphicClassWithNonVirtualPublicDestructor
struct SeqThread : SeqThreadBase { // NOLINT(*-pro-type-member-init)
    SeqThread(SeqRunner* runner, int, void* func, void* arg, SeqThread*);
    void wait(int ticks);
    bool stopRequested();

    int pushUnk270();
    int popUnk270();

    void STUB_7100514ff0(int);

    // ReSharper disable once CppPolymorphicClassWithNonVirtualPublicDestructor
    struct class_71004df040 {
        virtual void FUN_00();
    } unk18;
    SeqRunner* runner;
    char thread[0x1e0]; // Thread
    char interruptStart[0x18]; // LightEvent
    char interruptEnd[0x18]; // LightEvent

    struct ThreadInfo {
        SeqThread* self;
        void* func;
        void* arg;
    } threadInfo;
    SeqThreadState state;
    int index;

    int unk258;
    int unk25C;
    int unk260;
    int unk264;
    int unk268;
    int unk26C;
    int unk270;
    int unk274;
    int unk278;
    int unk27C;
};

static_assert(offsetof(SeqThread, runner) == 0x20);
static_assert(offsetof(SeqThread, thread) == 0x28);
static_assert(offsetof(SeqThread, threadInfo) == 0x238);
static_assert(offsetof(SeqThread, state) == 0x250);
static_assert(offsetof(SeqThread, index) == 0x254);
static_assert(sizeof(SeqThread) == 0x280);
static_assert(offsetof(SeqThread::ThreadInfo, self) == 0x00);
static_assert(offsetof(SeqThread::ThreadInfo, func) == 0x08);
static_assert(offsetof(SeqThread::ThreadInfo, arg) == 0x10);
static_assert(sizeof(SeqThread::ThreadInfo) == 0x18);
