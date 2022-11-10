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


	ppcb = &proctab[pid];
	lock_acquire(ppcb->msg_var.core_com_lock);

	//	CHECK PID
	if(isbadpid(pid)) {
		lock_release(ppcb->msg_var.core_com_lock);
		return SYSERR;
	}
	//set ppcb if not bad


	//	ACQUIRE LOCK
	lock_acquire(ppcb->msg_var.core_com_lock);

	//	CHECK PROCESS STATE
	if(ppcb->state == PRFREE || ppcb->msg_var.hasMessage) {
		lock_release(ppcb->msg_var.core_com_lock);
		return SYSERR;
	}

	//depositing message (don't know if we have to check if empty)
	ppcb->msg_var.msgin = msg;
	ppcb->msg_var.hasMessage = TRUE;

	if(ppcb->state == PRRECV) {
		ready(pid, RESCHED_NO, ppcb->core_affinity);
	}

	return OK;
}
