set(LINKFLAGS -nodefaultlibs)
set(LLDFLAGS --no-demangle --gc-sections)

set(OPTIMIZE_OPTIONS_DEBUG -O2 -gdwarf-4)
set(OPTIMIZE_OPTIONS_RELEASE -O3 -ffast-math -flto)
set(WARN_OPTIONS -Werror=return-type -Wno-invalid-offsetof)

set(INCLUDES include)

set(ASM_OPTIONS "")
set(C_OPTIONS -ffunction-sections -fdata-sections)
set(CXX_OPTIONS "")
set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED TRUE)

set(IS_32_BIT FALSE)
set(TARGET_IS_STATIC FALSE)
set(MODULE_NAME Orichi)
set(TITLE_ID 0100D9F01D474000)
set(MODULE_BINARY subsdk1)
set(SDK_PAST_1900 TRUE)
set(USE_SAIL TRUE)

set(TRAMPOLINE_POOL_SIZE 0x10)
set(BAKE_SYMBOLS FALSE)

set(HAKKUN_ADDONS Nvn DebugRenderer HeapSourceDynamic)
