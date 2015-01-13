#include <stdio.h>
#include <stdlib.h>

typedef int keyType;

typedef struct listNode{
    keyType key;
    struct listNode *next;
    struct listNode *prev;
    struct listNode *first;
    struct listNode *last;
}listNode;

listNode* initNode(keyType);

void insertFront(listNode *head, keyType key);

void insertBack(listNode *head, keyType key);

void removeFront(listNode *head);

void removeBack(listNode *head);

void printInOrder(listNode *head);

void printReverse(listNode *head);
