
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#include "llist.h"

int llist_alloc(llist_st **self, char **buffer, int size) {
    (*self) = (llist_st*)malloc(sizeof(llist_st));
    (*buffer) = (char*)malloc(size);

    (*self)->head = NULL;
    (*self)->size = size;

    return true;
}

int llist_free(llist_st **self, char **buffer) {
    llist_st__ *current;

    while((*self)->head != NULL) {
        current = (*self)->head;
        (*self)->head = (*self)->head->next;
        free(current->data);
        free(current);
    }

    free(*self);
    free(*buffer);

    *self = NULL;
    *buffer = NULL;

    return true;
}

int llist_insert(llist_st *self, char *buffer, int index) {
    llist_st__ *current, *tmpcurrent;
    int count;

    current = (llist_st__*)malloc(sizeof(llist_st__));
    current->data = (char*)malloc(self->size);
    current->next = NULL;

    memcpy(current->data, buffer, self->size);

    /*SET*/
    if((self->head == NULL) || (index == 0)) {
        current->next = self->head;
        self->head = current;
    }
    /*CUR*/
    else {
        tmpcurrent = self->head;
        count = 1;
        while((tmpcurrent->next != NULL) && (count != index)) {
            tmpcurrent = tmpcurrent->next;
            count++;
        }

        current->next = tmpcurrent->next;
        tmpcurrent->next = current;
    }

    return true;
}

int llist_erase(llist_st *self, int index) {
    llist_st__ *current, *beforecurrent;
    int count, lenght;

    current = self->head;
    beforecurrent = NULL;
    count = 0;
    lenght = llist_lenght(self);

    if((self->head == NULL) || (index > lenght)) {
        return false;
    }

    /*SET*/
    if(index == 0) {
        self->head = self->head->next;
        
        free(current->data);
        free(current);
    }
    /*CUR*/
    else {
        while((count < (index)) && (current->next != NULL)) {
            beforecurrent = current;
            current = current->next;
            count++;
        }

        beforecurrent->next = current->next;
        free(current->data);
        free(current);
    }

    return true;
}

int llist_get(llist_st *self, char *buffer, int index) {
    llist_st__ *current;
    int count;

    current = self->head;
    count = 0;

    if(current == NULL) {
        memset(buffer, 0, self->size);
        return false;
    }

    while((count < (index)) && (current->next != NULL)) {
        current = current->next;
        count++;
    }

    memcpy(buffer, current->data, self->size);
    return true;
}

int llist_lenght(llist_st *self) {
    llist_st__ *current;
    int count;

    current = self->head;
    count = 0;

    while(current != NULL) {
        current = current->next;
        count++;
    }

    return count;
}

int llist_size(llist_st *self) {
    return self->size;
}

int llist_clear(llist_st *self) {
    llist_st__ *current, *next;

    current = self->head;

    while(current != NULL) {
        next = current->next;
        free(current->data);
        free(current);
        current = next;
    }

    self->head = NULL;

    return true;
}
