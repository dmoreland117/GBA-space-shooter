#if !defined(GBA_DMA_COPY_H)
#define GBA_DMA_COPY_H

#include "../gba_dma.h"


#define DMA3CPY(src, dst, count_mode) \
    DMA3SAD = (uint32_t)src; \
    DMA3DAD = (uint32_t)dst; \
    DMA3CNT = (count_mode) | DMA_ENABLE

#define DMA3FILL(src, dst, size) DMA3CPY((src), (dst), (size) | DMA_32BIT | DMA_SRC_MODE(DMA_FIXED_SRC))

#endif // GBA_DMA_COPY_H
