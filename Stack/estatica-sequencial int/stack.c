#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

#define MAX 20

struct stack{
    int arrStack[MAX], top;

};

void _alloc_check(const void* p, char msg[]){
    if(p == NULL){
        perror(msg);
        exit(EXIT_FAILURE);
    }
}

Stack _create_stack(){
    Stack S = (Stack) malloc(sizeof(struct stack));
    _alloc_check(S, "Error allocating stack");

    S->top = -1; // aponta para fora da stack

    return S;
}

int _empty_stack(Stack S){
    if(S->top == -1) return 1;
    else return 0;
}

int _full_stack(Stack S){
    if(S->top == MAX-1) return 1;
    else return 0;
}

int _push(Stack S, int data){
    if(S == NULL || _full_stack(S)) return 0;
    S->top ++; // add mais um elemento na stack
    S->arrStack[S->top] = data;
    return 1;
}

int _pop(Stack S, int *data){
    if(_empty_stack(S) || S == NULL) return 0;

    *data = S->arrStack[S->top];
    S->top --;
    return 1;
}

int _get_top(Stack S, int *data){
    if(_empty_stack(S) || S == NULL) return 0;

    *data = S->arrStack[S->top];
    return 1;
}

void _print(Stack S){
    for(int i = 0;i <= S->top; i++)
        printf("[%d] ", S->arrStack[i]);
    printf("\n");
}