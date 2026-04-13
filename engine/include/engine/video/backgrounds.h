#ifndef BACKGROUNDS_H
#define BACKGROUNDS_H

#include "dsgbalib/types.h"
#include "engine/math/math.h"

// --- Constants ---

#define BG_TILEMAP_WIDTH   32
#define BG_TILEMAP_HEIGHT  32

#define SCREEN_TILE_WIDTH  30
#define SCREEN_TILE_HEIGHT 20

// --- Init ---

void bg_init(uint8_t bg, uint8_t charblock, uint8_t screenblock, uint8_t priority, bool mode256);
void bg_deinit(uint8_t bg);

// --- Data Loading ---

void bg_load_tiles(const uint16_t* tiles, uint8_t charblock, uint32_t size_words);
void bg_load_map(const uint16_t* map, uint8_t screenblock, uint32_t size_words);

// --- Scroll ---

void bg_set_scroll(uint8_t bg, uint16_t x, uint16_t y);

// --- Tile Manipulation ---

void bg_set_tile(
    uint8_t screenblock,
    Vec2_uint8 pos,
    uint16_t tile_id,
    uint8_t palette,
    uint8_t flags
);

uint16_t bg_get_tile(uint8_t screenblock, Vec2_uint8 pos);

// --- Raw Attributes ---

uint16_t bg_get_attr(uint8_t screenblock, Vec2_uint8 pos);
void     bg_set_attr(uint8_t screenblock, Vec2_uint8 pos, uint16_t attr);

#endif