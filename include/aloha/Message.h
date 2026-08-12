#pragma once

// ReSharper disable once CppPolymorphicClassWithNonVirtualPublicDestructor
struct Message {
    virtual void FUN_00();
    const char* getText(const char* label, int* size);

    void* fileData;
    void* message;
};

static_assert(sizeof(Message) == 0x18);
