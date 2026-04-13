#if !defined(GBA_TIMERS_H)
#define GBA_TIMERS_H

#include "dsgbalib/types.h"

#define REG_TM0_VAL *((volatile uint16_t*)0x04000100)
#define REG_TM0_CNT *((volatile uint16_t*)0x04000102)

#define REG_TM1_VAL *((volatile uint16_t*)0x04000104)
#define REG_TM1_CNT *((volatile uint16_t*)0x04000106)

#define REG_TM2_VAL *((volatile uint16_t*)0x04000108)
#define REG_TM2_CNT *((volatile uint16_t*)0x0400010A)

#define REG_TM3_VAL *((volatile uint16_t*)0x0400010C)
#define REG_TM3_CNT *((volatile uint16_t*)0x0400010E)

enum TimerSpeed
{
    TIMER_SPEED_FULL,
    TIMER_SPEED_64,
    TIMER_SPEED_256,
    TIMER_SPEED_1024,
};

#define TIMER_CASCADE    1 << 2
#define TIMER_GEN_INTRPT 1 << 6
#define TIMER_ENABLE     1 << 7

#endif // GBA_TIMERS_H
