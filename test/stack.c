
#include <stdio.h>

#include "../source/stack.h"

int main() {
  /*Define*/
  typedef struct {
    int x;
    float y;
  } vex_st;
  
  int i;
  stack_st *vertexes; vex_st *vertexes_;
  stack_st *strings; char *strings_;

  /*Alloc*/
  stack_alloc(&vertexes, (char**)&vertexes_, sizeof(vex_st));
  stack_alloc(&strings, (char**)&strings_, sizeof(char) * (12 + 1)); /*one more character for end string '\0'*/

  /*Push and clear*/
  vertexes_->x = 10; vertexes_->y = 3.3;
  stack_push(vertexes, (char*)vertexes_);
  for(i = 0;i < 10;i++) {
    stack_clear(vertexes);
  }
  vertexes_->x = 42; vertexes_->y = 8.24;
  stack_push(vertexes, (char*)vertexes_);
  vertexes_->x = 34; vertexes_->y = 6.55;
  stack_push(vertexes, (char*)vertexes_);

  for(i = 0;i < 10;i++) {
    stack_clear(strings);
  }
  sprintf(strings_, "%-12.12s", "Hello world!");
  stack_push(strings, (char*)strings_);
  sprintf(strings_, "%-12.12s", "Knee-Deep in the dead");
  stack_push(strings, (char*)strings_);
  sprintf(strings_, "%-12.12s", "Bye world");
  stack_push(strings, (char*)strings_);

  /*Pop and top*/
  stack_pop(vertexes);
  stack_top(vertexes, (char*)vertexes_);

  stack_pop(strings);
  stack_top(strings, (char*)strings_);
  
  /*Print*/
  printf("vertexes total items: %d\r\n", stack_lenght(vertexes));
  printf("vertexes top: x:%d y:%f\r\n", vertexes_->x, vertexes_->y);

  printf("strings total items: %d\r\n", stack_lenght(strings));
  printf("strings top: %s\r\n", strings_);

  /*Free*/
  stack_free(&vertexes, (char**)&vertexes_);
  stack_free(&strings, (char**)&strings_);

  if((!vertexes) && (!vertexes_)) {
    printf("Yes, they are null, %p %p\r\n", vertexes, vertexes_);
  }

  return 0;
}
