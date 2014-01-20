/*
 * =====================================================================================
 *
 *       Filename:  reverse.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2014/01/20 15时02分58秒
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

int reverse(char *src ) {
    if (NULL == src ) return no;

    char tmp;
    char *ptr = src;
    while(*ptr++ != '\0'); 
    ptr -= 2;

    while (ptr > src) {
        tmp = *ptr; *ptr = *src; *src = tmp;
        src ++; ptr--;
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
    char string[128];
    char *str = "hello, world";
    char *str2 = "hedksfjk woejfsdkf\tskfdljwioe";
    memset(string, '\0', 128);
    memcpy(string, str, strlen(str));
    printf("reversed : %s\n", reverse(string)==yes?string:"faild");

    memcpy(string, str2, strlen(str2));
    printf("reversed : %s\n", reverse(string)==yes?string:"faild");
    return EXIT_SUCCESS;
}	

