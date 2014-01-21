/*
 * =====================================================================================
 *
 *       Filename:  anagrams.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2014/01/21 13时57分12秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  bigdog (), 
 *   Organization:  
 *
 * =====================================================================================
 */
#include <stdlib.h>


#ifndef yes
#define yes 0
#endif 
#ifndef no
#define no -1 
#endif 


/* string anagrams : abba */
int detector(char *str) {
    if (NULL == str) return no;
    char *s = str, *e = str + strlen(str)-1;

    while(e > s) {
        if (*e-- != *s++)
            return no;
    }

    return yes;
}

/* 2 strings anagrams : hello, hlloe */
int if_anagrams(char *a, char *b) {
    if (NULL == a || NULL == b) return no;

    int up=0, down=0, i;
    char tags[256];
    for (i=0; i<256; ++i) {
        tags[i] = 0;
    }

    if (strlen(a) != strlen(b)) return no;

    for (i=0; i<strlen(a); ++i) {
        if (tags[*(a + i)] == 0) {
           ++ up ;
        }

        ++ tags[*(a + i)] ;
    }

    for (i=0; i<strlen(b); ++i) {
        if (tags[*(b + i)] == 0) {
            return no;
        } else {
            -- tags[*(b + i)] ;
        }

        if (tags[*(b+i)] == 0) {
            ++down ;
            if (down == up)
                return yes;
        }
    }
    return no;
}


/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  main
 *  Description:  
 * =====================================================================================
 */
int main ( int argc, char *argv[] ) {
    
    char *str = "abba";

    printf ( "str : %s\n", str );
    printf ( "is anagrams : %s\n", detector(str)==yes?"yes":"no" );

    char *a = "helal", *b = "ahlle";
    printf ( "a : %s, b : %s\n", a, b);
    printf ( "if anagrams : %s\n", if_anagrams(a, b)==yes?"yes":"no" );


    return EXIT_SUCCESS;
}				/* ----------  end of function main  ---------- */

