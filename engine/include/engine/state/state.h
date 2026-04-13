#if !defined(STATE_H)
#define STATE_H

typedef void(*StateCallbackFn)(void);

typedef struct
{
    StateCallbackFn init_callback;
    StateCallbackFn destroy_callback;
    StateCallbackFn update_callback;
    StateCallbackFn draw_callback;
} State;


#endif // STATE_H
