#include "list.h"

listNode* initNode(keyType key){
    listNode *node = (listNode*)calloc(1, sizeof(listNode));
    if(!node)
        return NULL;
    node->key = key;
    return node;
}

void insertFront(listNode *head, keyType key){}

void insertBack(listNode *head, keyType key){}

void removeFront(listNode *head){}

void removeBack(listNode *head){}

void printInOrder(listNode *head){}

void printReverse(listNode *head){}
