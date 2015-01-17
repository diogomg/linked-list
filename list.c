#include "list.h"

listNode* initNode(keyType key){
    listNode *node = (listNode*)calloc(1, sizeof(listNode));
    if(!node)
        return NULL;
    node->key = key;
    return node;
}

int listIsEmpty(listNode **node){
    return *node ? 1 : 0;
}

listNode* member(listNode **node, keyType key){
    listNode *aux = *node;

    if(*node == NULL)
        return NULL;
    do{
        if(aux->key == key)
            return aux;
    }while(aux->next != *node);
    return NULL;
}

void insertAfter(listNode **node, keyType key){
    listNode *new_node = initNode(key);
    if(listIsEmpty(node)){
        new_node->prev = *node;
        new_node->next = (*node)->next;
        (*node)->next->prev = new_node;
        (*node)->next = new_node;
    }
    else{
        new_node->next = new_node;
        new_node->prev = new_node;
        (*node) = new_node;
    }
}

void insertBefore(listNode **node, keyType key){
    listNode *new_node = initNode(key);
    if(listIsEmpty(node)){
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

void removeByKey(listNode **node, keyType key){}

void printInOrder(listNode *node){
    listNode *aux = node;
    if(!aux)
        return;
    do{
        printf("add: %p\tkey: %d\tprev: %p\tnext: %p\n", aux, aux->key, aux->prev, aux->next);
        aux = aux->next;
    }while(aux != node);
}

void printReverse(listNode *node){
    listNode *aux = node;
    if(!aux)
        return;
    do{
        printf("add: %p\tkey: %d\tprev: %p\tnext: %p\n", aux, aux->key, aux->prev, aux->next);
        aux = aux->prev;
    }while(aux != node);
}
