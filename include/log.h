#pragma once

#include <cstdarg>
#include <cstdio>
#include "hk/prim/traits/Integer.h"
#include "global.h"

extern void initLog();
extern void vlog(const char* fmt, va_list args);
extern void log(const char* fmt, ...);
