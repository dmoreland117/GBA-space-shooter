#include "state_scores.h"

#include "memory_sections.h"
#include "text_renderer.h"

#include "engine/video/palettes.h"
#include "engine/video/sprites.h"
#include "engine/input/input.h"

#include "dsgbalib/gba.h"


void scores_state_init()
{
    Vec2_uint8 v = {10, 10};
    draw_string(&v, "HELLO");
}
void scores_state_update()
{
}
void scores_state_draw()
{
}
void scores_state_destroy()
{
}


STATES_TABLE State SCORES_STATE = {
    .init_callback = scores_state_init,
    .update_callback = scores_state_update,
    .draw_callback = scores_state_draw,
    .destroy_callback = scores_state_destroy
};