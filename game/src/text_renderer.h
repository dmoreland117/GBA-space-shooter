#if !defined(TEXT_H)
#define TEXT_H

#include "engine/math/vectors.h"

#define ASCII_OFFSET 32  // how many chars into the ascii table our tiles start
#define FONT_TILESET_SIZE_WORDS 96 * 16


/// @brief Gets a background ready for drawing text
/// @param bg The background to use
/// @param charmap The charbase block the font is in
/// @param mapbase The mapbase block to store text data
/// @param palette The palette block (0 - 15) that the font palette is in
void text_init(uint8_t bg, uint8_t charmap, uint8_t mapbase, uint8_t palette);

/// @brief Loads font data to vram at the initailized charbase
/// @param fnt Pointer to an array of tiledata
/// @param size_words size of the array in words (sizeof(fnt) >> 1) or / 2
void text_load_font(uint16_t* fnt, uint16_t size_words);

void draw_string(Vec2_uint8* pos, char*);

void text_clear();

void int_to_string(uint32_t value, char* buffer);

#endif // TEXT_H
