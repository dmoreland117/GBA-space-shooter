.section .text
.thumb

.global _soft_reset
_soft_reset:
    swi 0x00

.global _wait_vblank
_wait_vblank:
    push {lr}

    swi 0x05

    bx lr

.global _divide_signed
_divide_signed:
    push {r2, r3, lr}

    swi 0x06

    pop {r2, r3}
    
    str r1, [r2]

    pop {pc}


