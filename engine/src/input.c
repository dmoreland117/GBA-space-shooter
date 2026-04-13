#include "engine/input/input.h"
#include "dsgbalib/gba.h"

uint16_t _current_keys;
uint16_t _last_keys;

bool input_is_key_pressed(uint16_t key)
{
    return _current_keys & key;
}

bool input_is_key_just_pressed(uint16_t key)
{
    return (_current_keys & key) &! (_last_keys & key);
}

bool input_is_key_released(uint16_t key)
{
    return (_last_keys & key) &! (_current_keys & key);
}

uint16_t input_get_keys()
{
    return _current_keys;
}
void input_update()
{
    _last_keys = _current_keys;
    _current_keys = ~REG_KEYINPUT;
}
