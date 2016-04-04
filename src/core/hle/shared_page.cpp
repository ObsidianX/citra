// Copyright 2015 Citra Emulator Project
// Licensed under GPLv2 or any later version
// Refer to the license.txt file included.

#include <cstring>
#include <ctime>

#include "core/hle/shared_page.h"

////////////////////////////////////////////////////////////////////////////////////////////////////

namespace SharedPage {

SharedPageDef shared_page;

void Init() {
    std::memset(&shared_page, 0, sizeof(shared_page));

    // 3DS uses 1/1/1900 for Epoch
    time_t plat_time = time(NULL);
    struct tm console_epoch = {0};
    console_epoch.tm_mday = 1;
    u64_le console_time = (u64_le) difftime(plat_time, mktime(&console_epoch)) * 1000L;

    shared_page.running_hw = 0x1; // product
    shared_page.date_time_0 = {
            .date_time = console_time,
    };
}

} // namespace
