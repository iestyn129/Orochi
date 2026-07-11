#pragma once

extern "C" unsigned int* rest_ticks(long long int, int);
extern "C" bool is_thread_stopping(long long int);
extern "C" long long int sub_7100514FB0(long long int);
extern "C" long long int change_cue_scene(long long int, long long int, int);
extern "C" long long int set_marking_criteria(long long int, char*);
extern "C" void spawn_guardian_cue00(long long int, long long int, long long int, long long int);
extern "C" void spawn_guardian_cue01(long long int, long long int, long long int, long long int);
extern "C" void spawn_guardian_cue02(long long int, long long int, long long int, long long int);
extern "C" long long int sub_7100514FD0(long long int);

extern "C" void spawn_parasol_cue(long long int, long long int, unsigned int, unsigned int, unsigned int, unsigned int);
extern "C" void spawn_birds_cue(long long int, long long int, char*);
extern "C" void spawn_talk_cue01(long long int);
extern "C" void spawn_wiper_cue01(long long int);
extern "C" void spawn_wiper_cue02(long long int);

extern "C" long long int sub_7100137990();
extern "C" long long int set_anim(long long int, long long int, int ticks, int alsoTicks, int maybeAnID); // ???
extern "C" long long int stop_anim(long long int); // ???

extern "C" long long int sub_7100514A90(long long int, long long int, int, long long int, long long int, long long int);
extern "C" unsigned long long int* sub_71005153A0(long long int, long long int);
extern "C" unsigned int* sub_71004DA420(unsigned int*, int);
extern "C" unsigned int* sub_71004D9E10(unsigned int*, int);
extern "C" long long int change_scene(long long int, long long int, unsigned int);
extern "C" long long int change_scene_fade(long long int, long long int, unsigned int, unsigned int);
extern "C" long long int sub_71004F8260(long long int, char*);
extern "C" long long int sub_71003B8770(long long int, long long int, unsigned int, unsigned int);
extern "C" void sub_710018C730(long long int, char*);
extern "C" long long int sub_71002A8E10(long long int);
extern "C" long long int sub_71004FBA20(long long int, char*, char);
extern "C" long long int sub_71004F7A80(long long int, char*, char);
extern "C" long long int sub_71001792D0(long long int, long long int, char);
extern "C" long long int sub_7100137B50(long long int, int);
extern "C" long long int sub_7100137B60(long long int, int);
extern "C" long long int sub_71001B24D0(long long int);
extern "C" long long int sub_71003BE7D0(long long int, long long int, unsigned int, unsigned int);
extern "C" long long int sub_71004F4610(long long int, char*, char*, char, unsigned int);
extern "C" long long int sub_71004DA400(long long int, int, int);
extern "C" long long int unk_thread_check(long long int, long long int);

extern "C" long long int sub_7100138CD0(long long int);
extern "C" long long int sub_71001366E0(long long int);
extern "C" long long int sub_7100138FC0(long long int);
extern "C" void sub_7100137140(long long int);
