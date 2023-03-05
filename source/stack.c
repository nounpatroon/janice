
#include <stdlib.h>
#include <string.h>

#include "stack.h"

int stack_alloc(stack_st **self, char **buffer, size_t size) {
  (*self) = (stack_st*)malloc(sizeof(stack_st));
  (*buffer) = (char*)malloc(sizeof(size));

  (*self)->size = size;
  (*self)->top = 0;
  (*self)->items = (char**)malloc(sizeof(char*));
  
  return 0;
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
  
  return 0;
}
