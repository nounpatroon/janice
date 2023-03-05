#include "../source/stack.h"

int main() {
  typedef struct {
    int x;
    float y;
  } vex_st;
  
  stack_st *vertexes; vex_st *vertexes_;

  stack_alloc(&vertexes, (char**)&vertexes_, sizeof(vex_st));

  stack_free(&vertexes, (char**)&vertexes_);

  return 0;
}
