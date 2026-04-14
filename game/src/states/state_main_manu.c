#include "dsgbalib/gba.h"
#include "memory_sections.h"


void main_menu_init()
{
    REG_DISPCNT = BLANK_DISPLAY;
}
void main_menu_update()
{
}
void main_menu_draw()
{
}

STATES_TABLE State MAIN_MENU_STATE = {
    .init_callback = main_menu_init,
    .update_callback = main_menu_update,
    .draw_callback = main_menu_draw
};