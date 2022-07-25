#pragma once

using namespace mbed;


constexpr bd_addr_t SPIF_SIZE { 2 * 1024 * 1024 };

constexpr bd_addr_t USER_BLOCKS_START { 0 };
constexpr bd_addr_t USER_BLOCKS_STOP { SPIF_SIZE };

constexpr int SPIF_FREQ { 32'000'000 };
