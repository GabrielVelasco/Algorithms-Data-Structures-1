#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "queue.h"

#define MAX 20

struct node{
    char dataArr[MAX][12];
    int ini, cont; 

};

void _alloc_check(const void* p, char msg[]){
    if(p == NULL){
        perror(msg);
        exit(EXIT_FAILURE);
    }
}

Queue _create_queue(){
    Queue qu = (Queue) malloc(sizeof(struct node));
    if(qu != NULL){
        qu->ini = 0;
        qu->cont = 0; /// inicialmente lista vazia
    }
    return qu;
}

int _empty_queue(Queue qu){ if(!qu->cont) return 1; else return 0; }

int _full_queue(Queue qu){ if(qu->cont == MAX) return 1; else return 0; }

int _push_back(Queue qu, char data[]){
    if(_full_queue(qu)) return 0;

    strcpy(qu->dataArr[ (qu->ini+qu->cont)%MAX ], data);
    qu->cont ++;

    return 1;
}

int _pop_front(Queue qu, char data[]){
    if(_empty_queue(qu)) return 0;

    strcpy(data, qu->dataArr[ qu->ini ]); /// salva elemento a ser removido
    qu->ini = (qu->ini+1)%MAX;
    qu->cont --;

    return 1;
}

void _print(Queue qu){
    if(_empty_queue(qu)){
        printf("Queue is empty!\n");
    }else{
        int f = (qu->ini+qu->cont)%MAX;
        if(f > qu->ini){
            /// percorre e printa normal
            for(int i = qu->ini; i < f; i++)
                printf("[%s] ", qu->dataArr[i]);
        }else{
            /// printa de (ini ... MAX-1) e de (0 ... ini-1)
            for(int i = qu->ini; i < MAX; i++)
                printf("[%s] ", qu->dataArr[i]);
            for(int i = 0; i < qu->ini; i++)
                printf("[%s] ", qu->dataArr[i]);
        }
    }
    printf("\n");
}