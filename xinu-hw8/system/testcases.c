/**
 * @file testcases.c
 * @provides testcases
 *
 *
 * Modified by:	
 *
 * TA-BOT:MAILTO 
 *
 */
/* Embedded XINU, Copyright (C) 2007.  All rights reserved. */

/**
 * COSC 3250 - Project 3
 * Implements kprintf
 * @authors [Noah Kaye; Zach Thompson]
 * Instructor [sabirat]
 * TA-BOT:MAILTO [noah.kaye@marquette.edu; zach.thompson@marquette.edu]
 */

#include <xinu.h>

void printpid(int times)
{
    int i = 0;
    uint cpuid = getcpuid();

    enable();
    for (i = 0; i < times; i++)
    {
        kprintf("This is process %d\r\n", currpid[cpuid]);
        udelay(1);
    }
}

/* need to make helper function to assist with this
// recv test
    var = recv()
    if we dont get a message back
            loop until we get message
                call resched
*/

//test methods
void testSendnow() 
{
    
}

void testRecvnow() 
{

}

void testSend()
{

}

void testRecv()
{

}

void testBlocking()
{

}

int apid;
int testpid;
void receiveMsg()
{

}

void killFunc(ulong pid) {
    kill(pid);
}

/**
 * testcases - called after initialization completes to test things.
 */
void testcases(void)
{
    kprintf("===TEST BEGIN===\r\n");
    kprintf("0) sendnow() & recvnow() testcase\r\n");
    kprintf("1) send() & recv() testcase\r\n");
    kprintf("2) send() queue testcase\r\n");
    kprintf("4) recv() testcase\r\n");    

    // TODO: Test your operating system!
    uchar c = kgetc();
    switch (c)
    {
    case '0':

        /*kprintf("sending message: 1\r\n");
        ready(create
              ((void *)sendnow, INITSTK, PRIORITY_MED, "PROCESS-A", 2,
               currpid[getcpuid()], 1), RESCHED_YES, 0);

        message in = recvnow();

        kprintf("message received: %d", in);*/

        
        //this is from assignment 8 word doc.
        apid = 0;
        testpid = create((void*) receiveMsg, INITSTK, PRIORITY_LOW, "RECV", 0);
        pcb *ppcb = &proctab[apid];
        ppcb->core_affinity = 0;
        syscall result = sendnow(apid, 0x5);
        kprintf("Result: %d\r\n", result);
        if((TRUE == ppcb->msg_var.hasMessage) && (0x5 == ppcb->msg_var.msgin)) {
            kprintf("Message correctly sent.\r\n");
        }else {
            kprintf("Recv process hasMessage == %d, msgin == %d\r\n",
            ppcb->msg_var.hasMessage, ppcb->msg_var.msgin);
        }
        kill(apid);
        
        
        break;
    case '1':

        kprintf("sending message: 2\r\n");
        ready(create
              ((void *)send, INITSTK, PRIORITY_MED, "PROCESS-A", 2,
               currpid[getcpuid()], 2), RESCHED_YES, 0);

        message in1 = recv();

        kprintf("message received: %d", in1);

        break;
    case '2':

        ready(create
              ((void *)send, INITSTK, PRIORITY_MED, "PROCESS-A", 2,
               currpid[getcpuid()], 3), RESCHED_YES, 0);
        ready(create
              ((void *)sendnow, INITSTK, PRIORITY_MED, "PROCESS-B", 2,
               currpid[getcpuid()], 4), RESCHED_YES, 0);

        message in2 = recv();
        message in3 = recvnow();

        kprintf("1st message received: %d\r\n", in2);
        kprintf("2nd message received: %d", in3);

        break;
    case '3':
        
        break;
    case '4':

        break;
    case '5':

        break;
    default:
        break;
    }
    
    kprintf("\r\n===TEST END===\r\n");
    return;
}
