#include "state_main_manu.h"
#include "state_0.h"

#include "memory_sections.h"
#include "text_renderer.h"

#include "data/space.h"
#include "data/ds_font.h"

#include "engine/video/backgrounds.h"
#include "engine/video/palettes.h"
#include "engine/video/sprites.h"
#include "engine/input/input.h"

#include "dsgbalib/gba.h"

const char TITLE_STRING[] = "SPACE GAME!";

const char* const OPTION_STRINGS[] = {
    "START",
    "OPTIONS"
};
#define OPTIONS_STRINGS_COUNT 2

const uint16_t FNT_PAL[] = 
{
    RGB15(0, 0, 0),
    RGB15(31, 40, 40)
};

void main_menu_init()
{
    REG_DISPCNT = BLANK_DISPLAY;

    bg_init(0, 0, 24, 3, false);
    bg_load_tiles(spaceTiles, 0, spaceTilesLen / 2);
    bg_load_map(spaceMap, 24, spaceMapLen / 2);

    pal_load_bg_data(spacePal, spacePalLen / 2, 0);
    pal_load_bg_data_slot(15, FNT_PAL, 2);

    text_init(3, 1, 25, 15);
    text_load_font(ds_fontTiles, ds_fontTilesLen / 2);

    for (uint8_t i = 0; i < OPTIONS_STRINGS_COUNT; i++)
    {
        draw_string(&(Vec2_uint8){10, 13 + (i * 2)}, OPTION_STRINGS[i]);
    }
    

    draw_string(&(Vec2_uint8){10, 10}, TITLE_STRING);

    REG_DISPCNT &= ~BLANK_DISPLAY;
}
void main_menu_update()
{
    input_update();

    if (input_is_key_just_pressed(KEY_A))
    {
        set_current_state(&LEVEL_STATE);
    }
}
void main_menu_draw()
{
}
void main_menu_destroy()
{
    text_clear();
}


STATES_TABLE State MAIN_MENU_STATE = {
    .init_callback = main_menu_init,
    .update_callback = main_menu_update,
    .draw_callback = main_menu_draw,
    .destroy_callback = main_menu_destroy
};