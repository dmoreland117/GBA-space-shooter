#if !defined(TEXT_H)
#define TEXT_H

#include "dsgbalib/types.h"

#define ASCII_OFFSET 32
#define FONT_TILESET_SIZE_WORDS 96 * 16


void text_init(uint8_t bg, uint8_t charmap, uint8_t mapbase);

#endif // TEXT_H
