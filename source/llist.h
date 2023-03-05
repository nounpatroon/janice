
#ifndef __JANICE_LLIST_H__
#define __JANICE_LLIST_H__

#ifdef __cplusplus
extern "C" {
#endif /*__cplusplus*/

typedef struct llist_st__ {
    char *data;
    struct llist_st__ *next;
} llist_st__;

typedef struct llist_st {
    int size;
    llist_st__ *head;
} llist_st;

int llist_alloc(llist_st **self, char **buffer, int size);
int llist_free(llist_st **self, char **buffer);
int llist_insert(llist_st *self, char *buffer, int index);
int llist_erase(llist_st *self, int index);
int llist_get(llist_st *self, char *buffer, int index);
int llist_lenght(llist_st *self);
int llist_size(llist_st *self);
int llist_clear(llist_st *self);

#ifdef __cplusplus
}
#endif

#endif /*__JANICE_LLIST_H__*/
