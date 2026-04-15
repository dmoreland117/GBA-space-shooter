#if !defined(PALETTES_H)
#define PALETTES_H

#include "dsgbalib/types.h"

void pal_load_bg_data     (uint16_t* colors, uint16_t count, uint8_t offset);
void pal_load_bg_data_slot(uint8_t slot, uint16_t* colors, uint16_t count);

void pal_load_sprite_data(uint16_t* colors, uint16_t count, uint8_t offset);
void pal_load_sprite_data_slot(uint8_t slot, uint16_t* colors, uint16_t count);

void pal_set_bg_color    (uint8_t color_id, uint16_t color);
void pal_set_sprite_color(uint8_t color_id, uint16_t color);

#endif // PALETTES_H
