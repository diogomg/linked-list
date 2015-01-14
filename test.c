#include <stdlib.h>

#include "list.h"
#include "greatest.h"

TEST init_node_success(){

    keyType key = 1;
    listNode *node = initNode(key);

    ASSERT( node->key == 1);
    ASSERT( node->next == NULL);
    ASSERT( node->prev == NULL);

    PASS();
}

TEST insert_a_node_at_tail_in_a_empty_list(){

    listNode *node = NULL;

    insertBefore(&node, 1);

    ASSERT( node->key == 1);
    ASSERT( node->next == node);
    ASSERT( node->prev == node);

    PASS();
}

TEST insert_a_node_at_tail_in_a_list_with_one_element(){

    listNode *node = NULL;

    insertBefore(&node, 1);
    insertBefore(&node, 2);

    ASSERT( node->key == 2);
    ASSERT( node->next->key == 1);
    ASSERT( node->prev == node->next);

    PASS();
}

TEST insert_a_node_at_tail_in_a_list_with_two_elements(){

    listNode *node = NULL;

    insertBefore(&node, 1);
    insertBefore(&node, 2);
    insertBefore(&node, 3);

    ASSERT( node->key == 3);
    ASSERT( node->next->key == 2);
    ASSERT( node->next->next->key == 1);
    ASSERT( node->prev == node->next->next);
    ASSERT( node->next->prev == node);
    ASSERT( node->next->next->prev == node->next);

    printInOrder(node);

    PASS();
}

SUITE( insert ){
    RUN_TEST( init_node_success );
    RUN_TEST( insert_a_node_at_tail_in_a_empty_list );
    RUN_TEST( insert_a_node_at_tail_in_a_list_with_one_element );
    RUN_TEST( insert_a_node_at_tail_in_a_list_with_two_elements );
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
