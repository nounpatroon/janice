
#include <stdio.h>

#include "../source/llist.h"

int main() {
    typedef struct vex_st {
        int x;
        float y;
    } vex_st;

    llist_st *vertexes; vex_st *vertexes_;
    llist_st *strings; char *strings_;

    llist_alloc(&vertexes, (char**)&vertexes_, sizeof(vex_st));
    llist_alloc(&strings, (char**)&strings_, sizeof(char) * (12+1));

    llist_free(&vertexes, (char**)&vertexes_);
    llist_free(&strings, (char**)&strings_);

    if((!vertexes) && (!vertexes_)) {
        printf("Yes, they are NULL, %p %p\r\n", vertexes, vertexes_);
    }

    return 0;
}
