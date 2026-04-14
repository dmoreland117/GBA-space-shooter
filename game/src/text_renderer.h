#if !defined(TEXT_H)
#define TEXT_H

#include "engine/math/vectors.h"

#define ASCII_OFFSET 32  // how many chars into the ascii table our tiles start
#define FONT_TILESET_SIZE_WORDS 96 * 16


void text_init(uint8_t bg, uint8_t charmap, uint8_t mapbase, uint8_t palette);

void text_load_font(uint16_t* fnt, uint16_t size_words);

void draw_string(Vec2_uint8* pos, char*);

void int_to_string(uint32_t value, char* buffer);

#endif // TEXT_H
