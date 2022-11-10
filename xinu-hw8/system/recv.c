/**
 * @file recv.c
 * @provides recv.
 *
 * $Id: receive.c 2020 2009-08-13 17:50:08Z mschul $
 */
/* Embedded Xinu, Copyright (C) 2009.  All rights reserved. */

#include <xinu.h>

/**
 * recv - wait for a mesage and return it
 * @return message
 */

message recv(void)
{
	register pcb *ppcb;
	int senderpid = -1;
	message msg;
	ppcb = &proctab[currpid[getcpuid()]];
	
	/* TODO:
 	* - Remember to acquire lock and release lock when interacting with the msg structure
		- set spinlock and release on return
 	* - Check for Message. If no message, put in blocking state and reschedule
 	*   			If there is message, retrive message
		if (hasmsg = false, state_recv, lock release, resched(), acquire lock)
			msg = msgin
 	* - Now, check queue for wating send processes,
 	*   If stuff in queue collect message for next time recv is called and ready send process
		if (queue !empty, make variable for first dequeue, find struct holding message, set = to else in order to collect message)
			(msgout = empty, lock release, ready())
 	*   else, reset message flag
		else (set hasmsg = false, lock release)
 	*   return collected message
 	*/	
	

	return msg;
}
