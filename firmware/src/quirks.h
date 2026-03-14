#ifndef _QUIRKS_H_
#define _QUIRKS_H_

#include <stdint.h>
#include <unordered_map>
#include "types.h"

// Handles device that requires special initialization command
#ifndef __ZEPHYR__
bool needs_init_quirk(uint16_t vendor_id, uint16_t product_id, uint8_t itf_num);
void set_pending_init_quirk(uint8_t dev_addr, uint8_t instance, uint16_t vid, uint16_t pid);
void process_timer_quirks(uint32_t current_time_ms);
#endif

// Handles descriptor mapping
void apply_quirks(uint16_t vendor_id, uint16_t product_id, std::unordered_map<uint8_t, std::unordered_map<uint32_t, usage_def_t>>& usage_map, const uint8_t* report_descriptor, int len, uint8_t itf_num);

#endif
