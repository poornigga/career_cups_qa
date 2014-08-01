/*
 * =====================================================================================
 *
 *       Filename:  mtx_rt.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2014/01/22 13时39分28秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  bigdog (), 
 *   Organization:  
 *
 * =====================================================================================
 */

#include "../../include/common.h"

/* 
 * a : transpose
 * b : 1) left : change rows (1, n), (2, n-1) ..
 *     2) right: change columns
 */ 

static inline void swap(uint32_t *a, uint32_t *b) {
    uint32_t t = *a; *a = *b; *b = t;
}

int transpose(uint32_t *mtx, uint8_t n) {
    if (NULL == mtx) return no;
    int i, j;

    for (i=0; i<n; ++i) {
        for (j=i; j<n; ++j) {
            // mtx[i][j], mtx[j][i]
            swap( mtx+i*n+j, mtx+j*n+i);
        }
    }

    return yes;
}

int rotate_right(uint32_t *mtx, uint8_t n ) {
    if (NULL == mtx) return no;
    int i, j;
    int h = n / 2;

    if (transpose(mtx, n) == no) {
        return no;
    }

    // change columns
    for (i=0; i<n; ++i)  {
        for (j=0; j<h; ++j) {
            swap(mtx+i*n+j, mtx+i*n+n-1-j);
        }
    }
    return yes;
}

int rotate_left(uint32_t *mtx, uint8_t n) {
    if (NULL == mtx) return no;
    int i, j;
    int h = n / 2;

    if (transpose(mtx, n) == no) {
        return no;
    }

    // change rows
    for (j=0; j<n; ++j) {
        for (i=0; i<h; ++i) {
            // swap (mtx[i][j], mtx[n-1-i][j])
            swap(mtx+i*n+j, mtx+(n-1-i)*n+j);
        }
    }

    return yes;
}


#ifdef __MTX_DEBUG

void print(uint32_t *mtx, uint8_t n) {
    if (NULL == mtx) return;
    int i, j;
    printf ( "===============================\n" );
    for (i=0; i<n; ++i) {
        for (j=0; j<n; ++j) {
            printf ( "%d\t", *(mtx+(i*n) + j) );
        }
        printf ( "\n" );
    }
    printf ( "===============================\n\n" );
}


void rotate_debug(uint8_t size, uint8_t right) {
    if (size < 1) return;

    uint32_t *mtx = malloc(sizeof(uint32_t)*(size*size));
    for (int i=0; i<size*size; ++i) {
        mtx[i] = i+1;
    }

    // original N*N
    printf ( "Original [ N*N ] : \n" );
    print(mtx, size);

    if (right == 1) {
        rotate_right(mtx, size);
    } else {
        rotate_left(mtx, size);
    }

    // result N*N
    printf ( "Rotate %s [ N*N ] :\n", right == 1 ? "right" : "left" );
    print(mtx, size);

    free(mtx);
}


int main ( int argc, char *argv[] ) {
#define RIGHT 1
#define LEFT  0
    rotate_debug(7, RIGHT);
    rotate_debug(8, LEFT);

    return EXIT_SUCCESS;
}		

#endif

