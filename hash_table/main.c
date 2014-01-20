/*
 * =====================================================================================
 *
 *       Filename:  main.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2014/01/17 15时49分37秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  bigdog (), 
 *   Organization:  
 *
 * =====================================================================================
 */
#include <stdlib.h>
#include "hash_table.h"


static hash_table *htb;

/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  main
 *  Description:  
 * =====================================================================================
 */
int main ( int argc, char *argv[] ) {
    
    int bucket_size = 8;

    htb_init(&htb, 8);

    set(htb, "hello", "world");

    set(htb, "weare", "many wei");

    set(htb, "hello2", "other world");

    set(htb, "hello1", "world again");

    printf ( "key : hello [ %s ]\n", get(htb, "hello") );
    printf ( "key : weare [ %s ]\n", get(htb, "weare") );
    printf ( "key : hello1 [ %s ]\n", get(htb, "hello1") );
    printf ( "key : hello2 [ %s ]\n", get(htb, "hello2") );

    htb_release(htb);

    return EXIT_SUCCESS;
}				/* ----------  end of function main  ---------- */
