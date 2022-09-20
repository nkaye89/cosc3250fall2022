/**
 * @file testcases.c
 * @provides testcases
 *
 * $Id: testcases.c 175 2008-01-30 01:18:27Z brylow $
 *
 * Modified by:
 *
 * and
 *
 */
/* Embedded XINU, Copyright (C) 2007.  All rights reserved. */

#include <xinu.h>

devcall putc(int dev, char c) { return 0; }


/**
 * testcases - called after initialization completes to test things.
 */
void testcases(void)
{
    int c;

    kprintf("===TEST BEGIN===\r\n");
    //kputc must work if kgetc works
    //kgetc works
    c = kgetc();
    switch (c)
    {
    // TODO: Test your operating system!

    //kcheckc 
    case '2': 
    if(kungetc('1') == '1'){}
    if(kcheckc() == 1) {
        kprintf("kcheckc test passed\n");
    }else {
        kprintf("kcheckc test failed\n");
    }
    break;

    //kungetc
    case '1':
    if(kungetc('1') == '1') {
	    kprintf("kungetc test passed\n");
    }else {
        kprintf("kungetc test failed\n");
    }
    break;

    default:
	kprintf("Hello Xinu World!\r\n");
    }


    kprintf("\r\n===TEST END===\r\n");
    return;
}
