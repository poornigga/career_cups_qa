/*
 * =====================================================================================
 *
 *       Filename:  rm_dc.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2014/01/20 15时32分12秒
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


#ifndef yes
#define yes 0
#endif 
#ifndef no
#define no -1 
#endif 

char *str = "hello world,hv";

int rdc(char *src) {
    if (NULL == src) return no;
    
    char *s = src;
    char *ptr = src + strlen(src) - 1;
    char *e;

    while(ptr > src) {
        if (*ptr == *s) {
            e = ptr;
            while (*(e+1)) {
                *e = *(e+1);
                e++;
            }
            *e = '\0';
            ptr --;
            s = src;
            continue;
        } 

        s++;

        if (ptr == s) {
            ptr --;
            s = src;
        }
    }

    return yes;
}



/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  main
 *  Description:  
 * =====================================================================================
 */
int main ( int argc, char *argv[] ) {
    char src[128];
    char *str = "hello, world";
    char *str2 = "yello, yellowo\n";

    memset(src, '\0', 128);
    memcpy(src, str, strlen(str));
    printf ( "origin str: %s\n", src );
    printf ( "duped str: %s\n", rdc(src)==yes?src : "fiald");

    memcpy(src, str2, strlen(str2));
    printf ( "origin str2: %s\n", src );
    printf ( "duped str2 : %s\n", rdc(src)==yes?src : "fiald");
    return EXIT_SUCCESS;
}				/* ----------  end of function main  ---------- */
