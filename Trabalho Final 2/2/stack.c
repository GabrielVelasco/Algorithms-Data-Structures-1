#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include "stack.h"

struct node{
    int key; /// se 1 node armazena int, 0 armazena char.
    void* data;
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

int _push(Stack *S, char data, float f_data, int key){
    /// se key == 1, vou add um float no node
    /// se nao, vou add um char
    Stack node = (Stack) malloc(sizeof(struct node));
    _alloc_check(node, "Error while allocating!");

    node->key = key;
    if(key){
        float* p = (float*) malloc(sizeof(float));
        _alloc_check(p, "Error while allocating float pointer!");
        *p = f_data;
        node->data = p;
    }else{
        char* p = (char*) malloc(sizeof(int));
        _alloc_check(p, "Error while allocating char pointer!");
        *p = data;
        node->data = p;
    }
    //node->data = data;
    node->next = *S; // add no comeco (topo da stack)
    *S = node; // aponta p/ comeco(topo da stack)

    return 1;
}

int _pop(Stack *S, char *c_data, float *f_data){
    if(_empty_stack(*S)) return 0;

    Stack tmp = *S;
    if(tmp->key){
        /// node armazena um float
        *f_data = *((float*)tmp->data);
    }else{
        /// node armazena um char
        *c_data = *((char*)tmp->data);
    }
    //*data = tmp->data;
    *S = tmp->next;
    free(tmp->data);
    free(tmp);

    return 1;
}

int _get_top(Stack *S, char *data){
    if(_empty_stack(*S)) return 0;

    *data = *((char*)(*S)->data);
    return 1;
}

void _clean(Stack *S){
    Stack tmp = NULL; /// aponta para topo da stack
    while(*S != NULL){
        tmp = *S; /// aponta para topo da stack, node a ser deletado
        *S = (*S)->next; /// aponta para o node de baixo (novo topo)
        free(tmp->data);
        free(tmp);
    }
}

void _print(Stack node){
    /// node == ponteiro para o topo da stack
    if(_empty_stack(node))
        _empty_msg();
    while(node != NULL){
        /// se key == 1, node armazena um float, informar funcao print que sera printado
        /// um float.
        if(node->key)
            _print_elem('0', *((float*)node->data), 1);
        else
            _print_elem(*((char*)node->data), 0, 0);
        node = node->next;
    }
}