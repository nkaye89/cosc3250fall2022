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

/*
void printLoop()
{
    uint cpuid = getcpuid();

    enable();
    while(TRUE) {
        kprintf("This is process %d\r\n", currpid[cpuid]);
        udelay(40);
    }
}
*/

/*
void printList(uint core)	{
	memblk *curr;
	curr = freelist[core].head;

	kprintf("\nSTART PRINT\r\n");
	while(curr != NULL)	{
		kprintf("\r\nAddress: %d \r\n", curr);
		kprintf("Length: %d \r\n", curr->length);
		kprintf("End Address: %d \r\n", ((ulong)(curr) + (curr->length)));
		//kprintf("-----------------\r\n");
		curr = curr->next;
	}
	kprintf("END PRINT\r\n");
} */

/**
 * testcases - called after initialization completes to test things.
 */
void testcases(void)
{
    kprintf("===TEST BEGIN===\r\n");
    kprintf("1) sendnow() testcase\r\n");
    kprintf("0) send() testcase\r\n");
    kprintf("0) send() blocking testcase\r\n");
    kprintf("3) recvnow() testcase\r\n");
    kprintf("2) recv() testcase\r\n");
    kprintf("2) recv() blocking testcase\r\n");    

    // TODO: Test your operating system!
    uchar c = kgetc();
    switch (c)
    {
    case '0':
        
        break;
    case '1':

        break;
    case '2':

        break;
    case '3':
        
        break;
    default:
        break;
    }
    
    kprintf("\r\n===TEST END===\r\n");
    return;
}
