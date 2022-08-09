#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "queue.h"

#define MAX 30

struct node{
    int dataArr[MAX];
    int ini, fim; 

};

void _alloc_check(const void* p, char msg[]){
    if(p == NULL){
        perror(msg);
        exit(EXIT_FAILURE);
    }
}

Queue _create_queue(){
    Queue qu = (Queue) malloc(sizeof(struct node));
    _alloc_check(qu, "Error while allocating queue!");
    qu->ini = 0;
    qu->fim = 0; /// inicialmente lista vazia

    return qu;
}

bool _empty_queue(Queue qu){ if(!qu->cont) return 1; else return 0; }

bool _full_queue(Queue qu){ if(qu->ini == (qu->fim+1)%MAX) return 1; else return 0; }

bool _push_back(Queue qu, char c_grade, float f_grade, bool key){
    if(_full_queue(qu)) return 0;

    int f = (qu->ini + qu->cont)%MAX; /// calcula ultima pos da queue
    qu->dataArr[f].key = key;
    if(key)
        qu->dataArr[f].info.f_grade = f_grade;
    else
        qu->dataArr[f].info.c_grade = c_grade;
    qu->fim = (qu->fim+1)%MAX;

    return 1;
}

bool _pop_back(Queue qu, char* c_grade, float* f_grade){
    if(_empty_queue(qu)) return 0;

    int f = (qu->ini + qu->cont-1)%MAX; /// calcula ultima pos
    if(qu->dataArr[f].key) /// se key == 1 -> float
        *f_grade = qu->dataArr[f].info.f_grade; /// copia elemento da ultima pos
    else
        *c_grade = qu->dataArr[f].info.c_grade;
    qu->fim = (qu->fim-1)%MAX; 

    return 1;
}

bool _push_front(Queue qu, char c_grade, float f_grade, bool key){
    if(_full_queue(qu)) return 0;

    qu->ini = (qu->ini-1)%MAX; /// calcula indice onde data vai ser adc, decremento circ.
    qu->dataArr[qu->ini].key = key;
    if(key)
        qu->dataArr[qu->ini].info.f_grade = f_grade;
    else
        qu->dataArr[qu->ini].info.c_grade = c_grade;
    qu->cont ++; /// +1 elemento no deque

    return 1;
}

bool _pop_front(Queue qu, char* c_grade, float* f_grade){
    if(_empty_queue(qu)) return 0;

    if(qu->dataArr[qu->ini].key)
        *f_grade = qu->dataArr[qu->ini].info.f_grade; /// salva elemento a ser removido
    else
        *c_grade = qu->dataArr[qu->ini].info.c_grade;
    qu->ini = (qu->ini+1)%MAX; /// incremento circular de ini
    qu->cont --;

    return 1;
}

void _print(Queue qu){
    int f = (qu->ini+qu->cont)%MAX; /// calc final da queue
    if(f > qu->ini){
        /// percorre e printa sentido normal [0 ... f-1]
        for(int i = qu->ini; i < f; i++)
            if(qu->dataArr[i].key)
                _print_float(&(qu->dataArr[i].info.f_grade));
            else
                _print_char(&(qu->dataArr[i].info.c_grade));
    }else{
        /// printa de (ini ... MAX-1) e de (0 ... f-1)
        for(int i = qu->ini; i < MAX; i++)
            if(qu->dataArr[i].key)
                _print_float(&(qu->dataArr[i].info.f_grade));
            else
                _print_char(&(qu->dataArr[i].info.c_grade));
        for(int i = 0; i < f; i++)
            if(qu->dataArr[i].key)
                _print_float(&(qu->dataArr[i].info.f_grade));
            else
                _print_char(&(qu->dataArr[i].info.c_grade));
    }
    printf("\n");
}

