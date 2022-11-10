/**
 * @file recvnow.c
 * @provides recvnow
 *
 */
/* Embedded Xinu, Copyright (C) 2020.  All rights resered. */

#include <xinu.h>

/**
 * recvnow - return pre-stored message, or immediate error.
 * @return message or SYSERR
 */

message recvnow(void)
{
	register pcb *ppcb;
	message msg;

	ppcb = &proctab[currpid[getcpuid()]];
	
	/* TODO:
 	* - Acquire and release lock when working in msg structure
 	* - check for message, if no messsage, error
 	*   		       else, retrieve & return message
			once read message, set hasmsgg to false
 	*/ 
	return msg;
}
