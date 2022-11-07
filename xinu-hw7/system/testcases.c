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

void printLoop()
{
    uint cpuid = getcpuid();

    enable();
    while(TRUE) {
        kprintf("This is process %d\r\n", currpid[cpuid]);
        udelay(40);
    }
}

void printList()
{
    uint cpuid = getcpuid();
    enable();
    memblk *node = freelist[cpuid].head;
    kprintf("freeList on core %d:\r\n"+ cpuid);
    kprintf("base: %lu, current length: %lu\r\n", freelist[cpuid].base, freelist[cpuid].length);
    int cnt = 1;
    while(node != NULL) {
        kprintf("|memblock list|\r\nLength of memblock %d: %lu\t", cnt, node->length);
        cnt++;
        node = node->next;
    }
}

void testGetmem()
{
    printList();
    getmem(50);
    printList();
    getmem(75);
    printList();
    getmem(25);
    printList();
}

void printFreelist(int core)	{
	memblk *curr;
	curr = freelist[core].head;

	kprintf("-=-=-=-=-START PRINT-=-=-=-=-\r\n");
	while(curr != NULL)	{
		kprintf("\r\nAddr: %d \r\n", curr);
		kprintf("Length: %d \r\n", curr->length);
		kprintf("End Addr: %d \r\n", ((ulong)(curr) + (curr->length)));
		kprintf("-----------------\r\n");
		curr = curr->next;
	}
	kprintf("-=-=-=-=-END PRINT-=-=-=-=-\r\n");
	
}

/**
 * testcases - called after initialization completes to test things.
 */
void testcases(void)
{
    uchar c;

    kprintf("===TEST BEGIN===\r\n");
    kprintf("0) Test printLoop\r\n");
    kprintf("1) getmem testcase\r\n");
    kprintf("2) Preemption testcase\r\n");

    // TODO: Test your operating system!

    c = kgetc();
    switch (c)
    {
    case '0':
        /*ready(create
              ((void *)printList, INITSTK, PRIORITY_HIGH, "PRINTER-A", 1
               ), RESCHED_YES, 0);*/
        printFreelist(getcpuid());
        
        break;
    case '1':
        ready(create
              ((void *)testGetmem, INITSTK, PRIORITY_HIGH, "PRINTER-A", 1
               ), RESCHED_YES, 0);
        break;
    case '2':

        break;
    default:
        break;
    }

    kprintf("\r\n===TEST END===\r\n");
    return;
}
