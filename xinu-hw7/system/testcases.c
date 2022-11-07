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

void printList(int core)	{
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
    kprintf("2) freemem testcase\r\n");
    kprintf("3) malloc testcase\r\n");
    kprintf("4) free testcase\r\n");

    // TODO: Test your operating system!

    c = kgetc();
    switch (c)
    {
    case '0':
        /*ready(create
              ((void *)printList, INITSTK, PRIORITY_HIGH, "PRINTER-A", 1
               ), RESCHED_YES, 0);*/
        printList(getcpuid());
        
        break;
    case '1':
        printList(getcpuid());

        //get 100 bytes
        getmem((ulong)100);
        printList(getcpuid());

        //get 10 bytes
        getmem((ulong)10);
        printList(getcpuid());

        break;
    case '2':
        printList(getcpuid());

        //get 100 bytes
        memblk *block = getmem((ulong)100);
        printList(getcpuid());

        //free 100 bytes
        freemem(block, (ulong)100);
        printList(getcpuid());

        break;

    case '3':
        printList(getcpuid());

        //malloc 100 bytes
        malloc((ulong)100);
        printList(getcpuid());

        //malloc 500 bytes
        malloc((ulong)500);
        printList(getcpuid());

        //mallc 1000 bytes
        malloc((ulong)1000);
        printList(getcpuid());

        //malloc 1 bytes
        malloc((ulong)1);
        printList(getcpuid());


        break;
    case '4':
        //todo
        //test free

        break;
    default:
        break;
    }

    kprintf("\r\n===TEST END===\r\n");
    return;
}
