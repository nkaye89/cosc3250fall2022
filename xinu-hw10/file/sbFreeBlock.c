/* sbFreeBlock.c - sbFreeBlock */
/* Copyright (C) 2008, Marquette University.  All rights reserved. */
/*                                                                 */
/* Modified by                                                     */
/*                                                                 */
/* and                                                             */
/*                                                                 */
/*                                                                 */

#include <kernel.h>
#include <device.h>
#include <memory.h>
#include <disk.h>
#include <file.h>

devcall swizzle(int diskfd, struct freeblock *freeblk){

    // TODO: Temporarily replace any pointers on the freeblock
    //   with the disk block number of the struct the pointer is referencing. 
    //   Then, seek to the freeblock disk block number and write to the disk.
    //   Remember to reset the pointers to there original memory address before returning.

    struct freeblock *free2 = freeblk->fr_next; //copy the data

    //if free2 is null
    //  set freeblock's fr_next to 0
    //else
    //  set freeblock's fr_next to be freeblock's fr_next's blockname/(blocknum???)
    //
    if(free2 == NULL) {
        freeblk->fr_next = 0;
    }else {
        freeblk->fr_next = freeblk->fr_next->fr_blocknum;
    }

    //given
    seek(diskfd, freeblk->fr_blocknum)
    if(SYSERR == write(diskfd, freeblk, sizeof(struct freeblock))) {    //write(where, what, length)
        return SYSERR;
    }

    //reset the freeblock's fr_next to its copy
    freeblk->fr_next = free2;

    return OK;
}

devcall swizzleSuperBlock(int diskfd, struct superblock *psuper){

    // TODO: Temporarily replace any pointers on the superblock
    //   with the disk block number of the struct the pointer is referencing. 
    //   Then, seek to the superblock disk block number and write to the disk.
    //   Remember to reset the pointers to there original memory address before returning.

    struct freeblock *swizzle = psuper->sb_freelst;
    struct dirblock *swizzle2 = psuper->sb_dirlst;

    //overwrite sb_freelist to be freelist's blocknum
    //overwrite sb_dirlist to be sb_dirlist's blocknum
    //
    psuper->sb_freelist = psuper->sb_freelist->fr_blocknum;
    psuper->sb_dirlst = psuper->sb_dirlist->db_blocknum;

    //given
    seek(diskfd, psuper->blocknum);
    if(SYSERR == write(diskfd, psuper, sizeof(struct superblock))) {
        return SYSERR;
    }
    
    //revert copies
    psuper->sb_freelst = swizzle;
    psuper->sb_dirlst = swizzle2;

    return OK;
}

/*------------------------------------------------------------------------
 * sbFreeBlock - Add a block back into the free list of disk blocks.
 *------------------------------------------------------------------------
 */
devcall sbFreeBlock(struct superblock *psuper, int block)
{
    // TODO: Add the block back into the filesystem's list of
    //  free blocks.  Use the superblock's locks to guarantee
    //  mutually exclusive access to the free list, and write
    //  the changed free list segment(s) back to disk.

    int diskfd;
    struct dentry *phw;

    //error check if superblock is null
    //
    if(psuper == NULL) {
        return SYSERR;
    }

    phw = psuper->sb_disk;  //found in file.h

    //errorcheck != null
    //
    if(phw == NULL) {
        return SYSERR;
    }
    //errorcheck block we got as a param (! <= 0 && !> total blocks on disk)
    //
    if(block <= 0 || block > psuper->sb_blocktotal) {
        return SYSERR;
    }

    //given
    diskfd = phw - devtab;
    //wait
    //
    //first collector node  //not sure what "wait" and "first collector node" are supposed to mean
    //given
    struct freeblock *freeblk = psuper->sb_freelist;

    //CASE 1: if the disk is completely full
    //  free up 1 block, make it a collector node
    //
    //while loop to get to the last collector node
    //  freeblock fr_next
    //
    //CASE 2: the freeblock/collector is completely full or completely empry
    //  create new collector block node, add to the first spot
    //
    //CASE 3: add to the next available index in collector node
    //  put our block into the next spot in the array
    //  write this info to the disk
    //


    return SYSERR;
}
