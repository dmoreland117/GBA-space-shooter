#if !defined(STATE_H)
#define STATE_H

typedef void(*StateInitFn)(void);
typedef void(*StateUpdateFn)(void);
typedef void(*StateDrawFn)(void);

typedef struct
{
    StateInitFn init_callback;
    StateUpdateFn update_callback;
    StateDrawFn draw_callback;
} State;


#endif // STATE_H
