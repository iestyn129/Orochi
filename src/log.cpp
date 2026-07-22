#include "log.h"

#include "hk/svc/api.h"
#include "nn/fs.h"
#include "nn/time.h"
#include "cstdio"


void initLog() {
   if (nn::fs::CreateFile(LOG_FILE, 0).IsFailure()) {
       log("\n"); // print a new line if log already exists (assuming that's the only cause for this to fail)
   }

    log("=== Initialising Orichi ===");
    log("Log initialised!");
}


void vlog(const char* fmt, va_list args) {
    char msg[2048];

    const s32 msgLen = vsnprintf(msg, sizeof(msg), fmt, args);
    if (msgLen < 0) {
        return;
    }

    hk::svc::OutputDebugString(msg, std::min<size_t>(msgLen, sizeof(msg) - 1));

    nn::fs::FileHandle file{};

    while (true) {
        if (nn::fs::OpenFile(&file, LOG_FILE, nn::fs::OpenMode_Write).IsFailure())
            break;

        s64 fileSize = 0;
        if (nn::fs::GetFileSize(&fileSize, file).IsFailure())
            break;

        if (fileSize > 64 * 1024 * 1024) {
            fileSize = 0;
        }

        nn::time::PosixTime pTime{};
        if (nn::time::StandardUserSystemClock::GetCurrentTime(&pTime).IsFailure())
            break;

        nn::time::CalendarTime cTime{};
        nn::time::CalendarAdditionalInfo cTimeInfo{};
        if (ToCalendarTime(&cTime, &cTimeInfo, pTime).IsFailure())
            break;

        char newMsg[msgLen + 32];
        sprintf(newMsg, "[%04d/%02d/%02d %02d:%02d:%02d.%03lu] %s",
            cTime.year, cTime.month, cTime.day,
            cTime.hour, cTime.minute, cTime.second,
            pTime.time % 1000,
            msg
        );

        const s64 newMsgLen = static_cast<s64>(strlen(newMsg));

        if (nn::fs::SetFileSize(file, fileSize + newMsgLen + 1).IsFailure())
            break;

        const auto opt = nn::fs::WriteOption::CreateOption(nn::fs::WriteOptionFlag_Flush);
        static constexpr char newline = '\n';

        if (nn::fs::WriteFile(file, fileSize, newMsg, newMsgLen, opt).IsFailure())
            break;

        if (nn::fs::WriteFile(file, fileSize + newMsgLen, &newline, 1, opt).IsFailure())
            break;

        break;
    }

    nn::fs::CloseFile(file);
}


void log(const char* fmt, ...) {
    va_list args;
    va_start(args, fmt);
    vlog(fmt, args);
    va_end(args);
}
