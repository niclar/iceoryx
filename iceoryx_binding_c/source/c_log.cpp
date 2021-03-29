// Copyright (c) 2021 by Apex.AI Inc. All rights reserved.
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.
//
// SPDX-License-Identifier: Apache-2.0

#include "iceoryx_utils/log/logmanager.hpp"

extern "C" {
#include "iceoryx_binding_c/log.h"
}

iox::log::LogLevel toLogLevel(enum iox_LogLevel level) {
    switch (level)
    {
    case Iceoryx_LogLevel_Off:
        return iox::log::LogLevel::kOff;
    case Iceoryx_LogLevel_Verbose:
        return iox::log::LogLevel::kVerbose;
    case Iceoryx_LogLevel_Debug:
        return iox::log::LogLevel::kDebug;
    case Iceoryx_LogLevel_Info:
        return iox::log::LogLevel::kInfo;
    case Iceoryx_LogLevel_Warn:
        return iox::log::LogLevel::kWarn;
    case Iceoryx_LogLevel_Error:
        return iox::log::LogLevel::kError;
    case Iceoryx_LogLevel_Fatal:
        return iox::log::LogLevel::kFatal;
    default:
        return iox::log::LogLevel::kVerbose;
    }
}

void iox_set_loglevel(enum iox_LogLevel level) {
    iox::log::LogManager::GetLogManager().SetDefaultLogLevel(toLogLevel(level));
}