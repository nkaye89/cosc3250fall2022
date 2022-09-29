/**
 * @file     ctxsw.s
 * @provides ctxsw
 *
 * COSC 3250 / COEN 4820 Assignment 4
 */
/* Embedded XINU, Copyright (C) 2013.  All rights reserved. */

#include <arm.h>

.text
	.align 4
	.globl	ctxsw


/**
 * @fn void ctxsw(&oldregs, &newregs)
 *
 * Switch context (values in registers) to another process, saving the
 * current processes information. This function will not return as normally
 * thought as it will load in the stack pointer for a different process and
 * jump to that location and begin executing code.
 *
 * @param  &oldstack address of outgoing stack save area - old registers (save these [str])
 * @param  &newstack address of incoming stack save area - new registers (load these [ldr])
 * @return special case -- see above
 */
ctxsw:
	.func ctxsw

	// TODO: Save callee-save ("non-volatile") registers.
	// TODO: Restore callee-save ("non-volatile") registers.
	// TODO: Jump to next function.

	// using ldr to load new registers and str to save old registers
	// a lot of copy and paste, with come changes due to special cases (like r15 or possible overwriting)

	.end ctxsw
