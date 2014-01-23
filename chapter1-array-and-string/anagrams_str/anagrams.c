/*
 * =====================================================================================
 *
 *       Filename:  anagrams.c
 *
 *    Description:  
 
                                           .. .vr       
                                         qBMBBBMBMY     
                                        8BBBBBOBMBMv    
                                      iMBMM5vOY:BMBBv        
                      .r,             OBM;   .: rBBBBBY     
                      vUL             7BB   .;7. LBMMBBM.   
                     .@Wwz.           :uvir .i:.iLMOMOBM..  
                      vv::r;             iY. ...rv,@arqiao. 
                       Li. i:             v:.::::7vOBBMBL.. 
                       ,i7: vSUi,         :M7.:.,:u08OP. .  
                         .N2k5u1ju7,..     BMGiiL7   ,i,i.  
                          :rLjFYjvjLY7r::.  ;v  vr... rE8q;.:,, 
                         751jSLXPFu5uU@guohezou.,1vjY2E8@Yizero.    
                         BB:FMu rkM8Eq0PFjF15FZ0Xu15F25uuLuu25Gi.   
                       ivSvvXL    :v58ZOGZXF2UUkFSFkU1u125uUJUUZ,   
                     :@kevensun.      ,iY20GOXSUXkSuS2F5XXkUX5SEv.  
                 .:i0BMBMBBOOBMUi;,        ,;8PkFP5NkPXkFqPEqqkZu.  
               .rqMqBBMOMMBMBBBM .           @kexianli.S11kFSU5q5   
             .7BBOi1L1MM8BBBOMBB..,          8kqS52XkkU1Uqkk1kUEJ   
             .;MBZ;iiMBMBMMOBBBu ,           1OkS1F1X5kPP112F51kU   
               .rPY  OMBMBBBMBB2 ,.          rME5SSSFk1XPqFNkSUPZ,.
                      ;;JuBML::r:.:.,,        SZPX0SXSP5kXGNP15UBr.
                          L,    :@huhao.      :MNZqNXqSqXk2E0PSXPE .
                      viLBX.,,v8Bj. i:r7:,     2Zkqq0XXSNN0NOXXSXOU 
                    :r2. rMBGBMGi .7Y, 1i::i   vO0PMNNSXXEqP@Secbone.
                    .i1r. .jkY,    vE. iY....  20Fq0q5X5F1S2F22uuv1M; 


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

