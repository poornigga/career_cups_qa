/*
 * =====================================================================================
 *
 *       Filename:  hash_table.h
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2014/01/17 14时43分30秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  bigdog (), 
 *   Organization:  
 *
 * =====================================================================================
 */
#ifndef _HASH_TABLE_H_
#define _HASH_TABLE_H_

#include <stdio.h>
#include <string.h>
#include <stdint.h>

typedef int (*hash_func)(int size, char *str);

#pragma pack(push)
#pragma pack(1)
typedef struct _node_{
    struct _node_ *next;
    int  key;
    int  len;
    char value[0];
} node;
#pragma pack(pop)

typedef struct _list_ {
    struct _list_ *next;
    node *n;
    int num;
} list;


typedef struct _hash_table_ {
    int size;
    hash_func func[2];
    list *bucket;
} hash_table;


/*
 * hash table api
 */
int htb_init(hash_table **htb, int size) ;
int htb_release(hash_table *htb) ;

char *get(hash_table *htb, char *key);
int set(hash_table *htb, char *key, char *value);

#endif
