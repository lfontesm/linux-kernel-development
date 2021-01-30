#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "list.h"

struct test {
    const char       *name;
    const int        age;
    struct list_head list;
};

int main(){
    struct test *t;
    t = kmalloc(sizeof(struct test), GFP_KERNEL);
    t->name=strdup("oompaloompa");
    t->age=100;
    INIT_LIST_HEAD(&t->list);
}