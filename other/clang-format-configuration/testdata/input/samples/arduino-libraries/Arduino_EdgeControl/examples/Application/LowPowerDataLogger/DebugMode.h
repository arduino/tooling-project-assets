#pragma once

#ifdef DEBUG
constexpr bool debugMode = true;
#else
constexpr bool debugMode = false;
#endif

#define DebugSerial if constexpr (debugMode) Serial