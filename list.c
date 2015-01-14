#include "list.h"

listNode* initNode(keyType key){
    listNode *node = (listNode*)calloc(1, sizeof(listNode));
    if(!node)
        return NULL;
    node->key = key;
    return node;
}

void insertAfter(listNode **node, keyType key){}

void insertBefore(listNode **node, keyType key){
    listNode *new_node = initNode(key);
    if(*node){
        new_node->next = *node;
        new_node->prev = (*node)->prev;
        (*node)->prev = new_node;
    }
    else{
        new_node->next = new_node;
        new_node->prev = new_node;
    }
    (*node) = new_node;
}

void removeAfter(listNode *node){}

void removeBefore(listNode *node){}

void printInOrder(listNode *node){}

void printReverse(listNode *node){}
