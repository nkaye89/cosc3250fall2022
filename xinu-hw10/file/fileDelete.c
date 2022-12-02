/* fileDelete.c - fileDelete */
/* Copyright (C) 2008, Marquette University.  All rights reserved. */
/*                                                                 */
/* Modified by                                                     */
/*                                                                 */
/* and                                                             */
/*                                                                 */
/*                                                                 */

#include <kernel.h>
#include <memory.h>
#include <file.h>



/*------------------------------------------------------------------------
 * fileDelete - Delete a file.
 *------------------------------------------------------------------------
 */
devcall fileDelete(int fd)
{
    // TODO: Unlink this file from the master directory index,
    //  and return its space to the free disk block list.
    //  Use the superblock's locks to guarantee mutually exclusive
    //  access to the directory index.

    struct dentry *phw = supertab->sb_disk  //found in file.h
    int diskfd = phw - devtab;

    //wait
    //
    //error check: dirlist, current file state
    //
    //zero out file values as well as its data
    //
    //free up data with sbFreeBlock
    //  error check that that worked
    //
    //rewrite block to end of disk
    //  uses seek and write

    return OK;
}
