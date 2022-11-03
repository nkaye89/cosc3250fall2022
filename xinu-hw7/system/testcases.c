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

/**
 * testcases - called after initialization completes to test things.
 */
void testcases(void)
{
    uchar c;

    kprintf("===TEST BEGIN===\r\n");
    kprintf("0) Test priority scheduling\r\n");
    kprintf("1) Aging / Starvation testcase\r\n");
    kprintf("2) Preemption testcase\r\n");

    // TODO: Test your operating system!

    c = kgetc();
    switch (c)
    {
    case '0':
        
    case '1':

    case '2':

    default:
        break;
    }

    kprintf("\r\n===TEST END===\r\n");
    return;
}
