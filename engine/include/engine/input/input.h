#if !defined(INPUT_H)
#define INPUT_H

#include "dsgbalib/types.h"

bool input_is_key_pressed(uint16_t key);
bool input_is_key_just_pressed(uint16_t key);
bool input_is_key_released(uint16_t key);

uint16_t get_keys();

void input_update();

#endif // INPUT_H
