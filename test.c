#include <stdlib.h>

#include "list.h"
#include "greatest.h"

TEST init_node_success(){

    keyType key = 1;
    listNode *node = initNode(key);

    ASSERT( node->key == 1);
    ASSERT( node->next == NULL);
    ASSERT( node->prev == NULL);
    ASSERT( node->first == NULL);
    ASSERT( node->last == NULL);

    PASS();
}

SUITE( insert ){
    RUN_TEST( init_node_success );
}

SUITE( delete ){

}

GREATEST_MAIN_DEFS();

int main( int argc, char** argv ){

    GREATEST_MAIN_BEGIN();
    RUN_SUITE( insert );
    RUN_SUITE( delete );
    GREATEST_MAIN_END();
}
