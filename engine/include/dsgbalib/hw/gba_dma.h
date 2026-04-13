#if !defined(GBA_DMA_H)
#define GBA_DMA_H

#include "../types.h"


#define DMA3SAD *((volatile uint32_t*)0x40000D4)
#define DMA3DAD *((volatile uint32_t*)0x40000D8)
#define DMA3CNT *((volatile uint32_t*)0x40000DC)

#define DMA_ENABLE      (1 << 31)
#define DMA_16BIT       (0 << 26)
#define DMA_32BIT       (1 << 26)
#define DMA_NOW         (0 << 28)

#define DMA_SRC_MODE(n) (n) << 23

enum DMA_SRC_MODES {
    DMA_FIXED_SRC = 2
};


#endif // GBA_DMA_H
