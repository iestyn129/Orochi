#pragma once

#include <cstddef>

enum FilePartitionType : unsigned int {
    PartitionType_Data  = 0x00,
    PartitionType_User  = 0x01,
    PartitionType_Demo  = 0x02,
    PartitionType_Debug = 0x03
};

struct Graph {
    int startup(const char*, FilePartitionType, void*);

    char _pad00[0x28];
    char path[0x104];
    char _pad01[0x2C];
};

static_assert(sizeof(Graph) == 0x158);
static_assert(offsetof(Graph, path) == 0x28);

struct GraphAnime {
    bool playAction(const char* action);
    GraphAnime* getChildMaybe(const char* name, bool);
    void setAnimationSimple(const char* name, bool);

    char _pad00[0x60];
    Graph* graph;

    char _pad01[0x368 - (0x60 + sizeof(Graph*))];
};

static_assert(sizeof(GraphAnime) == 0x368);
static_assert(offsetof(GraphAnime, graph) == 0x60);

