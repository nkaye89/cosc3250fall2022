/**
 * @file sendnow.c
 * @provides sendnow.
 *
 */
/* Embedded Xinu, Copyright (C) 2020.   All rights reserved. */

#include <xinu.h>

/**
 * Send a message to anoher thread
 * @param pid proc id of recipient
 * @param msg contents of message
 * @return OK on sucess, SYSERR on failure
 */

syscall sendnow(int pid, message msg)
{
	register pcb *ppcb;

	/* TODO:
 	* - Acquire Lock and release when appropriate
 	* - PID & Process Error Checking
		- determine if pid is valid (if statement, look back at previous assignments for this method)
		- if (method() != good) syserr
		- else release lock
		- check current state, if prefree, lockrelease and syserr
	* only like 4 lines of code outside of above if statements
 	* - Deposit Message, raise flag
 	* -  If receving message is blocked, ready process
	* - change hasmsg flag
	* - if in recv state, call ready
 	* - Return OK
 	*/

	return OK;
}
