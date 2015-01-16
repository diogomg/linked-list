#include <stdio.h>
#include <stdlib.h>

typedef int keyType;

typedef struct listNode{
    keyType key;
    struct listNode *next;
    struct listNode *prev;
}listNode;

listNode* initNode(keyType);

int listIsEmpty(listNode **node);

void insertAfter(listNode **node, keyType key);

void insertBefore(listNode **node, keyType key);

void removeAfter(listNode *node);

void removeBefore(listNode *node);

void printInOrder(listNode *node);

void printReverse(listNode *node);
