
#include <stdio.h>

#include "../source/stack.h"

int main() {
  typedef struct {
    int x;
    float y;
  } vex_st;
  
  int i;
  stack_st *vertexes; vex_st *vertexes_;

  stack_alloc(&vertexes, (char**)&vertexes_, sizeof(vex_st));

  for(i = 0;i < 5;i++) {
    vertexes_->x = i+1; vertexes_->y = i+i;
    stack_push(vertexes, (char*)vertexes_);
  }
  for(i = 0;i < 10;i++) {
    stack_pop(vertexes);
  }
  for(i = 0;i < 5;i++) {
    vertexes_->x = i+1; vertexes_->y = (float)i + 1.25;
    stack_push(vertexes, (char*)vertexes_);
  }

  stack_pop(vertexes);
  stack_top(vertexes, (char*)vertexes_);
  
  printf("vertexes top: x:%d y:%f\r\n", vertexes_->x, vertexes_->y);

  stack_free(&vertexes, (char**)&vertexes_);

  if((!vertexes) && (!vertexes_)) {
    printf("Yes, they are null, %p %p\r\n", vertexes, vertexes_);
  }

  return 0;
}
