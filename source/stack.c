
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#include "stack.h"

int stack_alloc(stack_st **self, char **buffer, int size) {
  (*self) = (stack_st*)malloc(sizeof(stack_st));
  (*buffer) = (char*)malloc(size);

  (*self)->size = size;
  (*self)->top = 0;
  (*self)->items = (char**)malloc(sizeof(char*));
  
  return true;
}

int stack_free(stack_st **self, char **buffer) {
  while((*self)->top) {
    (*self)->top--;
    free((*self)->items[(*self)->top]);
  }

  free((*self)->items);
  free((*self));
  free((*buffer));

  (*self) = NULL;
  (*buffer) = NULL;
  
  return true;
}

int stack_push(stack_st *self, char *buffer) {
  self->top++;

  self->items = (char**)realloc(self->items, sizeof(char*) * self->top);
  self->items[self->top - 1] = (char*)malloc(self->size);
  memcpy(self->items[self->top - 1], buffer, self->size);

  return true;
}

int stack_pop(stack_st *self) {
  if(!self->top) {
    return false;
  }
  
  self->top--;

  free(self->items[self->top]);
  self->items = (char**)realloc(self->items, ((self->top) ? (sizeof(char*) * self->top) : (sizeof(char*))));

  return true;
}

int stack_top(stack_st *self, char *buffer) {
  if(!self->top) {
    memset(buffer, 0, self->size);
    return false;
  } else {
    memcpy(buffer, self->items[self->top - 1], self->size);
    return true;
  }
}

int stack_lenght(stack_st *self) {
  return self->top;
}

int stack_clear(stack_st *self) {
  while(self->top) {
    self->top--;
    free(self->items[self->top]);
  }

  return true;
}
