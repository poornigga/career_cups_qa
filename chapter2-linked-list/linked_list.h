/*
 * =====================================================================================
 *
 *       Filename:  linked_list.h
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2014/01/24 16时02分02秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  bigdog (), 
 *   Organization:  
 *
 * =====================================================================================
 */

#ifndef _LINKED_LIST_H_
#define _LINKED_LIST_H_


#pragma pack(push)
#pragma pack(1)
typedef struct _list_node_{
    struct _list_node_ *next;
    char data[0];
} node ;
#pragma pack(pop)

#endif
