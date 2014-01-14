/*
 * =====================================================================================
 *
 *       Filename:  array_sprial_print.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2014/01/10 13时54分56秒
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

#define p(a, x, y) \
    printf ( "a[%d][%d] = %d\n", x, y,  a[x][y] );


int main (int argc, char **argv) {
    int a[4][4] = {
        {1, 2, 3, 4}, 
        {5, 6, 7, 8}, 
        {9, 10, 11, 12}, 
        {13, 14, 15, 16}
//        {17, 18, 19, 20},
//        {21, 22, 23, 24}
    };

    int xmax = 4, ymax = 4;
    int pu=0, pt=0, i, j;


    while( xmax>pu && ymax >pt ) {
        j = pu;

        for (i=pt; i<ymax; ++i)  p(a, j, i);

        --i;

        for (j=pu+1; j<xmax; ++j) p(a, j, i);

        --j;

        for (--i; i>pt; --i) p(a, j, i);

        for (j; j>pu; --j) p(a, j, i);

        --xmax; --ymax;
        ++pu; ++pt;
    }

    return EXIT_SUCCESS;
}
