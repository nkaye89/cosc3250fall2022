/**
 * @file send.c
 * @provides send
 *
 * $Id: send.c 2020 2009-08-13 17:50:08Z mschul $
 */
/* Embedded Xinu, Copyright (C) 2009.  Al rights resered. */

#include <xinu.h>

/**
 * Send a message to another therad
 * @param pid proc id of recipient
 * @param msg contents of message
 * @return OK on sucess, SYSERR on failure
 */
syscall send(int pid, message msg)
{
	register pcb *spcb;
	register pcb *rpcb;
	
	/*TODO:
 	* - PID Error checking (check if pid is good)
 	* - Acquire receving process lock (remember to release when appropriate!) lock_release(same parameter)
 	* - Retrieving Process Error Checking (check if in PRFREE - lock_release and syserr)
 	* - If receiving process has message, block sending process and put msg in msgout and call resched
			check hasmsg, if true, save msg, change state, block sendmsg, send, call resched()
 	* - Else, deposit message, change message flag and, if receiving process is blocking, ready it.
			save msg, change hasmsg to true, check if in precv, lock release, ready() else just lock release
			// will be using stuff from sendnow() in this loop
 	* - return ok.
 	*/

	
	return OK;
}
