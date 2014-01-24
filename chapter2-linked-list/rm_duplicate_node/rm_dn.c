/*
 * =====================================================================================
 *
 *       Filename:  rm_dn.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2014/01/24 16时07分40秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  bigdog (), 
 *   Organization:  
 *
 * =====================================================================================
 */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include "../linked_list.h"



int rm_dn (node *root) {
    if (NULL == root) return -1;

    return 0;
}


#define p(a, b) \
    printf("%d - %d\n", a, b)

int ac(void) {
    int a[5] = {8, 4, 1, 2, 7};
    int midx = -1;
    for (int i=0; i<5; ++i) {
        if(a[i] < a[4]) {
            p (a[i], a[4]);
            return 0;
        }

        midx = i++;
    }
}


/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  main
 *  Description:  
 * =====================================================================================
 */
int main ( int argc, char *argv[] ) {
    
   return EXIT_SUCCESS;
}				/* ----------  end of function main  ---------- */

