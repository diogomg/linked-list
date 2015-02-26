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

TEST list_is_empty(){

    listNode *node = NULL;

    ASSERT( listIsEmpty(&node) == 0);

    PASS();
}

TEST list_isnt_empty(){

    listNode *node = NULL;

    insertBefore(&node, 1);

    ASSERT( listIsEmpty(&node) == 1);

    PASS();
}

TEST is_member_in_a_list_with_one_element(){

    listNode *node = NULL;

    insertBefore(&node, 1);

    ASSERT( member(&node, 1) != NULL );

    PASS();
}

TEST is_member_in_a_list_with_two_elements(){

    listNode *node = NULL;

    insertBefore(&node, 1);
    insertBefore(&node, 2);

    ASSERT( member(&node, 1) != NULL );
    ASSERT( member(&node, 2) != NULL );

    PASS();
}

TEST is_member_in_a_list_with_three_elements(){

    listNode *node = NULL;

    insertBefore(&node, 1);
    insertBefore(&node, 2);
    insertBefore(&node, 3);

    ASSERT( member(&node, 1) != NULL );
    ASSERT( member(&node, 2) != NULL );
    ASSERT( member(&node, 3) != NULL );

    PASS();
}

TEST isnt_member_in_a_list_without_elements(){

    listNode *node = NULL;

    ASSERT( member(&node, 1) == NULL);

    PASS();
}


TEST isnt_member_in_a_list_with_one_element(){

    listNode *node = NULL;

    insertBefore(&node, 1);

    ASSERT( member(&node, 1) != NULL );

    PASS();
}

TEST isnt_member_in_a_list_with_two_elements(){

    listNode *node = NULL;

    insertBefore(&node, 1);
    insertBefore(&node, 2);

    ASSERT( member(&node, 1) != NULL );
    ASSERT( member(&node, 2) != NULL );

    PASS();
}

TEST isnt_member_in_a_list_with_three_elements(){

    listNode *node = NULL;

    insertBefore(&node, 1);
    insertBefore(&node, 2);
    insertBefore(&node, 3);

    ASSERT( member(&node, 1) != NULL );
    ASSERT( member(&node, 2) != NULL );
    ASSERT( member(&node, 3) != NULL );

    PASS();
}

TEST merge_two_lists_with_one_node_each(){
    listNode *node = NULL;
    insertAfter(&node, 1);

    listNode *node2 = NULL;
    insertAfter(&node2, 2);

    merge(&node, &node2);

    ASSERT( node->key == 1 );
    ASSERT( node->next == node2);
    ASSERT( node->prev == node2);
    ASSERT( node2->key == 2 );
    ASSERT( node2->next == node);
    ASSERT( node2->prev == node);


    PASS();
}

TEST merge_two_lists_firstList_has_two_nodes_secondList_has_one_node(){
    listNode *node = NULL;
    insertAfter(&node, 1);
    insertAfter(&node, 2);

    listNode *node2 = NULL;
    insertAfter(&node2, 3);

    merge(&node, &node2);

    ASSERT( node->key == 1 );
    ASSERT( node->prev->key == 2);
    ASSERT( node->next == node2);
    ASSERT( node->prev->next == node);
    ASSERT( node->prev->prev == node2);
    ASSERT( node2->key == 3 );
    ASSERT( node2->next == node->prev);
    ASSERT( node2->prev == node);

    PASS();
}

TEST merge_two_lists_firstList_has_one_node_secondList_has_two_nodes(){
    listNode *node = NULL;
    insertAfter(&node, 1);

    listNode *node2 = NULL;
    insertAfter(&node2, 2);
    insertAfter(&node2, 3);

    merge(&node, &node2);

    ASSERT( node->key == 1 );
    ASSERT( node->next == node2);
    ASSERT( node->prev == node2->next);
    ASSERT( node2->key == 2 );
    ASSERT( node2->next->key == 3);
    ASSERT( node2->prev == node);
    ASSERT( node2->next->prev == node2);
    ASSERT( node2->next->next == node);

    PASS();
}

TEST merge_two_lists_with_two_nodes_each(){

    listNode *node = NULL;
    insertAfter(&node, 1);
    insertAfter(&node, 2);

    listNode *node2 = NULL;
    insertAfter(&node2, 3);
    insertAfter(&node2, 4);

    merge(&node, &node2);

    ASSERT( node->key == 1 );
    ASSERT( node->prev->key == 2);
    ASSERT( node->next == node2);
    ASSERT( node->prev->next == node );
    ASSERT( node->prev->prev == node2->next );
    ASSERT( node2->key == 3 );
    ASSERT( node2->prev == node );
    ASSERT( node2->next->key == 4 );
    ASSERT( node2->next->prev == node2 );
    ASSERT( node2->next->next == node->prev );



    PASS();
}

TEST merge_two_lists_firstList_has_three_nodes_and_second_has_one_node(){

    listNode *node = NULL;
    insertAfter(&node, 1);
    insertAfter(&node, 2);
    insertBefore(&node, 3);

    listNode *node2 = NULL;
    insertAfter(&node2, 4);

    merge(&node, &node2);

    ASSERT( node->key == 1 );
    ASSERT( node->prev->key == 3);
    ASSERT( node->next == node2);
    ASSERT( node->prev->next == node );
    ASSERT( node->prev->prev->key == 2 );
    ASSERT( node->prev->prev->prev == node2 );
    ASSERT( node->prev->prev->next == node->prev );
    ASSERT( node2->key == 4 );
    ASSERT( node2->prev == node );
    ASSERT( node2->next->key == 2 );

    PASS();
}

/*TEST merge_two_lists_with_two_nodes_each(){

    listNode *node = NULL;
    insertAfter(&node, 1);
    insertAfter(&node, 2);

    listNode *node2 = NULL;
    insertAfter(&node2, 3);
    insertAfter(&node2, 4);

    merge(&node, &node2);

    ASSERT( node->key == 1 );
    ASSERT( node->prev->key == 2);
    ASSERT( node->next == node2);
    ASSERT( node->prev->next == node );
    ASSERT( node->prev->prev == node2->next );
    ASSERT( node2->key == 3 );
    ASSERT( node2->prev == node );
    ASSERT( node2->next->key == 4 );
    ASSERT( node2->next->prev == node2 );
    ASSERT( node2->next->next == node->prev );



    PASS();
}*/

TEST insert_a_node_at_head_in_a_empty_list(){

    listNode *node = NULL;

    insertBefore(&node, 1);

    ASSERT( node->key == 1);
    ASSERT( node->next == node);
    ASSERT( node->prev == node);

    PASS();
}

TEST insert_a_node_at_head_in_a_list_with_one_element(){

    listNode *node = NULL;

    insertBefore(&node, 1);
    insertBefore(&node, 2);

    ASSERT( node->key == 1);
    ASSERT( node->next->key == 2);
    ASSERT( node->prev->key == 2);
    ASSERT( node->prev == node->next);
    ASSERT( node->next->prev == node);
    ASSERT( node->prev->next == node);

    PASS();
}

TEST insert_a_node_at_head_in_a_list_with_two_elements(){

    listNode *node = NULL;

    insertBefore(&node, 1);
    insertBefore(&node, 2);
    insertBefore(&node, 3);

    ASSERT( node->key == 1);
    ASSERT( node->next->key == 2);
    ASSERT( node->next->next->key == 3);
    ASSERT( node->prev == node->next->next);
    ASSERT( node->next->prev == node);
    ASSERT( node->next->next->prev == node->next);

    PASS();
}

TEST insert_a_node_at_tail_in_a_empty_list(){

    listNode *node = NULL;

    insertAfter(&node, 1);

    ASSERT( node->key == 1);
    ASSERT( node->next == node);
    ASSERT( node->prev == node);

    PASS();
}

TEST insert_a_node_at_tail_in_a_list_with_one_element(){

    listNode *node = NULL;

    insertAfter(&node, 1);
    insertAfter(&node, 2);

    ASSERT( node->key == 1);
    ASSERT( node->next->key == 2);
    ASSERT( node->prev == node->next);

    PASS();
}

TEST insert_a_node_at_tail_in_a_list_with_two_elements(){

    listNode *node = NULL;

    insertAfter(&node, 1);
    insertAfter(&node, 2);
    listNode *tail = node->next;
    insertAfter(&tail, 3);

    ASSERT( node->key == 1 );
    ASSERT( node->next->key == 2 );
    ASSERT( node->next->next->key == 3 );
    ASSERT( node->prev == node->next->next );
    ASSERT( node->next->prev == node);
    ASSERT( node->next->next->prev == node->next);


    PASS();
}

TEST insert_a_node_at_middle_in_a_list_with_two_elements_using_insertBefore_method(){

    listNode *node = NULL;

    insertAfter(&node, 1);
    insertAfter(&node, 2);
    listNode *middle = node->next;
    insertBefore(&middle, 3);

    ASSERT( node->key == 1 );
    ASSERT( node->next->key == 3 );
    ASSERT( node->next->next->key == 2 );
    ASSERT( node->prev == node->next->next );
    ASSERT( node->next->prev == node);
    ASSERT( node->next->next->prev == node->next);

    PASS();
}

TEST insert_a_node_at_middle_in_a_list_with_two_elements_using_insertAfter_method(){

    listNode *node = NULL;

    insertAfter(&node, 1);
    insertAfter(&node, 2);
    insertAfter(&node, 3);

    ASSERT( node->key == 1);
    ASSERT( node->next->key == 3);
    ASSERT( node->next->next->key == 2);
    ASSERT( node->prev == node->next->next);
    ASSERT( node->next->prev == node);
    ASSERT( node->next->next->prev == node->next);

    PASS();
}

TEST try_delete_a_node_in_a_list_with_one_element (){

    listNode *node = NULL;

    insertAfter(&node, 1);

    removeByKey(&node, 0);

    ASSERT( node != NULL);

    PASS();
}

TEST delete_a_node_in_a_list_with_one_element (){

    listNode *node = NULL;

    insertAfter(&node, 1);

    removeByKey(&node, 1);

    ASSERT( node == NULL);

    PASS();
}

TEST delete_a_node_in_a_list_with_two_elements (){

    listNode *node = NULL;

    insertAfter(&node, 1);
    insertAfter(&node, 2);

    removeByKey(&node, 2);

    ASSERT( node->key == 1);
    ASSERT( node->next == node);
    ASSERT( node->prev == node);

    PASS();
}

TEST delete_a_node_in_a_list_with_three_elements (){

    listNode *node = NULL;

    insertAfter(&node, 1);
    insertAfter(&node, 2);
    insertAfter(&node, 3);

    removeByKey(&node, 3);

    ASSERT( node->next != node);
    ASSERT( node->prev != node);
    ASSERT( node->next->prev == node);
    ASSERT( node->prev->next == node);

    PASS();
}

SUITE( misc ){
    RUN_TEST( init_node_success );
    RUN_TEST( list_is_empty );
    RUN_TEST( list_isnt_empty );
    RUN_TEST( is_member_in_a_list_with_one_element );
    RUN_TEST( is_member_in_a_list_with_two_elements );
    RUN_TEST( is_member_in_a_list_with_three_elements );
    RUN_TEST( isnt_member_in_a_list_without_elements );
    RUN_TEST( isnt_member_in_a_list_with_one_element );
    RUN_TEST( isnt_member_in_a_list_with_two_elements );
    RUN_TEST( isnt_member_in_a_list_with_three_elements );
    RUN_TEST( merge_two_lists_with_one_node_each );
    RUN_TEST( merge_two_lists_firstList_has_two_nodes_secondList_has_one_node );
    RUN_TEST( merge_two_lists_firstList_has_one_node_secondList_has_two_nodes );
    RUN_TEST( merge_two_lists_with_two_nodes_each );
    RUN_TEST( merge_two_lists_firstList_has_three_nodes_and_second_has_one_node );
}

SUITE( insert ){
    RUN_TEST( insert_a_node_at_head_in_a_empty_list );
    RUN_TEST( insert_a_node_at_head_in_a_list_with_one_element );
    RUN_TEST( insert_a_node_at_head_in_a_list_with_two_elements );
    RUN_TEST( insert_a_node_at_tail_in_a_empty_list );
    RUN_TEST( insert_a_node_at_tail_in_a_list_with_one_element );
    RUN_TEST( insert_a_node_at_tail_in_a_list_with_two_elements );
    RUN_TEST( insert_a_node_at_middle_in_a_list_with_two_elements_using_insertBefore_method );
    RUN_TEST( insert_a_node_at_middle_in_a_list_with_two_elements_using_insertAfter_method );
}

SUITE( delete ){
    RUN_TEST( try_delete_a_node_in_a_list_with_one_element );
    RUN_TEST( delete_a_node_in_a_list_with_one_element );
    RUN_TEST( delete_a_node_in_a_list_with_two_elements );
    RUN_TEST( delete_a_node_in_a_list_with_three_elements );
}

GREATEST_MAIN_DEFS();

int main( int argc, char** argv ){

    GREATEST_MAIN_BEGIN();
    RUN_SUITE( misc );
    RUN_SUITE( insert );
    RUN_SUITE( delete );
    GREATEST_MAIN_END();
}
