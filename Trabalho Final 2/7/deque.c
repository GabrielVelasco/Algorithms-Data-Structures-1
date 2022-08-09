#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "deque.h"

#define MAX 30

struct node{
    int dataArr[MAX];
    int ini, cont; 

};

void _alloc_check(const void* p, char msg[]){
    if(p == NULL){
        perror(msg);
        exit(EXIT_FAILURE);
    }
}

Deque _create_deque(){
    Deque de = (Deque) malloc(sizeof(struct node));
    _alloc_check(de, "Error while allocating deque!");
    de->ini = 0;
    de->cont = 0; /// inicialmente deque vazio

    return de;
}

bool _empty_deque(Deque de){ if(!de->cont) return true; else return false; }

bool _full_deque(Deque de){ if(de->cont == MAX) return true; else return false; }

bool _push_back(Deque de, int data){
    if(_full_deque(de)) return false;

    int f = (de->ini + de->cont)%MAX; /// calcula ultima pos da queue
    de->dataArr[f] = data;
    de->cont ++;

    return true;
}

bool _pop_back(Deque de, int* data){
    if(_empty_deque(de)) return false;

    int f = (de->ini + de->cont-1)%MAX; /// calcula ultima pos
    *data = de->dataArr[f];
    de->cont --;

    return true;
}

bool _push_front(Deque de, int data){
    if(_full_deque(de)) return false;

    de->ini = (de->ini-1)%MAX; /// calcula indice onde data vai ser adc, decremento circ.
    de->dataArr[de->ini] = data;
    de->cont++;

    return true;
}

bool _pop_front(Deque de, int* data){
    if(_empty_deque(de)) return false;

    *data = de->dataArr[de->ini];
    de->ini = (de->ini+1)%MAX; /// incremento circular de ini
    de->cont --;

    return true;
}

void _delete_deque(Deque* de){
    if((*de) != NULL)
        free(*de);
    *de = NULL;
}

void _print(Deque de){
    /// printa todo o deque, mais optimizado
    int f = (de->ini+de->cont)%MAX; /// calc final da deque
    if(f > de->ini){
        /// percorre e printa sentido normal [0 ... f-1]
        for(int i = de->ini; i < f; i++)
            _print_node(de->dataArr[i]);
    }else{
        /// printa de (ini ... MAX-1) e de (0 ... f-1)
        for(int i = de->ini; i < MAX; i++)
            _print_node(de->dataArr[i]);
        for(int i = 0; i < f; i++)
            _print_node(de->dataArr[i]);
    }
    printf("\n");
}