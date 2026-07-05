#pragma once

#include "hk/prim/traits/Integer.h"
#include "cstdarg"
#include "cstdio"

extern void initLog();
extern void vlog(const char* fmt, va_list args);
extern void log(const char* fmt, ...);
