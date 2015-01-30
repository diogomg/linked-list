#include <stdio.h>
#include "list.h"

int main(){

    listNode *node = NULL;

    insertBefore(&node, 1);
    insertBefore(&node, 2);
    printInOrder(node);
    printf("%p\n", member(&node, 1));
    printf("%p\n", member(&node, 2));

    return 0;
}
