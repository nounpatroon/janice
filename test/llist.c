
#include <stdio.h>

#include "../source/llist.h"

int main() {
    typedef struct vex_st {
        int x;
        float y;
    } vex_st;

    int i, lenght;
    llist_st *vertexes; vex_st *vertexes_;
    llist_st *strings; char *strings_;

    llist_alloc(&vertexes, (char**)&vertexes_, sizeof(vex_st));
    llist_alloc(&strings, (char**)&strings_, sizeof(char) * (12+1));

    vertexes_->x = 10; vertexes_->y = 2.2;
    llist_insert(vertexes, (char*)vertexes_, 0);
    for(i = 0;i < 10;i++) {
        llist_clear(vertexes);
    }
    vertexes_->x = 10; vertexes_->y = 2.2;
    llist_insert(vertexes, (char*)vertexes_, 0);
    vertexes_->x = 10; vertexes_->y = 2.2;
    llist_insert(vertexes, (char*)vertexes_, 0);
    vertexes_->x = 10; vertexes_->y = 2.2;
    llist_insert(vertexes, (char*)vertexes_, 0);
    vertexes_->x = 14; vertexes_->y = 3.5;
    llist_insert(vertexes, (char*)vertexes_, 1);

    for(i = 0;i < 10;i++) {
        llist_clear(strings);
    }
    sprintf(strings_, "%-12.12s", "Hello world!");
    llist_insert(strings, (char*)strings_, 0);
    sprintf(strings_, "%-12.12s", "Knee-Deep in the dead");
    llist_insert(strings, (char*)strings_, 1);
    sprintf(strings_, "%-12.12s", "Another...");
    llist_insert(strings, (char*)strings_, 2);
    sprintf(strings_, "%-12.12s", "Bye world!");
    llist_insert(strings, (char*)strings_, 3);

    llist_erase(vertexes, 0);
    llist_erase(strings, 0);

    lenght = llist_lenght(vertexes);
    printf("Print vertexes\r\n");
    for(i = 0;i < lenght;i++) {
        llist_get(vertexes, (char*)vertexes_, i);
        printf("i:%d x:%d y:%f\r\n", i, vertexes_->x, vertexes_->y);
    }

    lenght = llist_lenght(strings);
    printf("Print strings\r\n");
    for(i = 0;i < lenght;i++) {
        llist_get(strings, (char*)strings_, i);
        printf("i:%d s:%s\r\n", i, strings_);
    }

    llist_free(&vertexes, (char**)&vertexes_);
    llist_free(&strings, (char**)&strings_);

    if((!vertexes) && (!vertexes_)) {
        printf("Yes, they are NULL, %p %p\r\n", vertexes, vertexes_);
    }

    return 0;
}
