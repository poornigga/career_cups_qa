/*
 * =====================================================================================
 *
 *       Filename:  hash_table.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2014/01/17 14时43分28秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  bigdog (), 
 *   Organization:  
 *
 * =====================================================================================
 */
#include <stdlib.h>
#include <assert.h>

#include "hash_table.h"


/*
 * hash table api
 */

//static hash_table *htb;

node *node_gen(hash_table *htb, const char *key, const char *val) ;

int func(int size, const char *key) {
    assert(key&&strlen(key)>0);
    return (strlen(key)%size);
}

int func2(int size, const char *key) {
    return strlen(key);
}

int htb_init(hash_table **htb, int size) {
    if (NULL == htb) {
        return -1;
    }
    hash_table *ht = malloc(sizeof(hash_table) + sizeof(list)*size);
    assert(ht);

    ht->size= size;
    ht->func[0] = func;
    ht->func[1] = func2;
    ht->bucket =(list *) (ht + sizeof(hash_table));
    *htb = ht;
    return 0;
}

int htb_release(hash_table *htb) {
    if (NULL == htb) {
        return -1;
    }

    list *l;
    node *n, *t;
    for(int i=0; i<htb->size; ++i) {
        l = &htb->bucket[i];
        n = l->n;
        while(n) {
            t = n;
            n = n->next;
            free(t); t = NULL;
        }
    }

    free(htb);
    htb = NULL;

    return 0;
}

char *get(hash_table *htb, const char *key) {
    if (NULL == key) return NULL;
    list *l = &htb->bucket[(*htb->func)(htb->size, key)-1];

    if (l->num == 0 ) {
        return NULL;
    } else if (l->num == 1) {
        return l->n->value;
    } else {
        node *n = l->n;
        while (n) {
            if (n->key == func(htb->size, key) && n->len == strlen(key) && 
                !memcmp(n->value, key, strlen(key)) ) {
                return n->value + strlen(key);
            }
            n = n->next;
        }
    }

    return NULL;
}

int set(hash_table *htb, const char *key, const char *value) {
    if (NULL == key || NULL == value) {
        return 1;
    }

    node *n = node_gen(htb, key, value);
    list *l = &htb->bucket[(*htb->func)(htb->size, key)-1];
    if (l->num == 0) {
        l->n= n;
    } else if (l->num == 1) {
        l->n->next = n;
    } else {
        node *c = l->n;
        while(c->next != NULL) {
            c = c->next;
        }

        c->next = n;
    }

    l->num ++;

    return 0;
}

node *node_gen(hash_table *htb, const char *key, const char *val) {
    if (NULL == key || NULL == val) {
        return NULL;
    }

    node *n = malloc(sizeof(node) + strlen(key) + strlen(val));
    if (NULL == n) return NULL;

    n->next = NULL;
    n->key = (*htb->func)(htb->size, key);
    n->len = strlen(key);
    memcpy(n->value, key, strlen(key));
    memcpy(n->value+strlen(key), val, strlen(val));

    return n;
}


