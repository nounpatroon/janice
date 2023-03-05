
#ifndef __JANICE_STACK_H__
#define __JANICE_STACK_H__

#include <stddef.h>

#ifdef __cplusplus
extern "C" {
#endif /*__cplusplus*/

typedef struct {
  size_t size;
  size_t top;
  char **items;
} stack_st;

int stack_alloc(stack_st **self, char **buffer, size_t size);
int stack_free(stack_st **self, char **buffer);

#ifdef __cplusplus
}
#endif /*__cplusplus*/
  
#endif /*__JANICE_STACK_H__*/
