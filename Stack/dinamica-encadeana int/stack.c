#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

#define MAX 20

struct node{
    int data;
    struct node* next;

};

void _alloc_check(const void* p, char msg[]){
    if(p == NULL){
        perror(msg);
        exit(EXIT_FAILURE);
    }
}

Stack _create_stack(){ return NULL; }

int _empty_stack(Stack S){
    if(S == NULL) return 1;
    else return 0;
}

int _push(Stack *S, int data){
    Stack node = (Stack) malloc(sizeof(struct node));
    _alloc_check(node, "Error while allocating!");

    node->data = data;
    node->next = *S; // add no comeco (topo da stack)
    *S = node; // aponta p/ comeco(topo da stack)

    return 1;
}

int _pop(Stack *S, int *data){
    if(_empty_stack(*S)) return 0;

    Stack tmp = *S;
    *data = tmp->data;
    *S = tmp->next;
    free(tmp);

    return 1;
}

int _get_top(Stack S, int *data){
    if(_empty_stack(S)) return 0;

    *data = S->data;
    return 1;
}

void _print(Stack S){
    while(S != NULL){
        printf("[%d] ", S->data);
        S = S->next;
    }
    printf("\n");
}