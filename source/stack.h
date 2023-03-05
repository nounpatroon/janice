
#ifndef __JANICE_STACK_H__
#define __JANICE_STACK_H__

#ifdef __cplusplus
extern "C" {
#endif /*__cplusplus*/

typedef struct {
  int size;
  int top;
  char **items;
} stack_st;

int stack_alloc(stack_st **self, char **buffer, int size);
int stack_free(stack_st **self, char **buffer);
int stack_push(stack_st *self, char *buffer);
int stack_pop(stack_st *self);
int stack_top(stack_st *self, char *buffer);
int stack_lenght(stack_st *self);
int stack_clear(stack_st *self);

#ifdef __cplusplus
}
#endif /*__cplusplus*/
  
#endif /*__JANICE_STACK_H__*/
