#include <stdio.h>
#include <stdlib.h>
#include "deque.h"

struct no{
    int info;
    struct no *prox, *ant;
};

struct deque{
    struct no *ini, *fim;
};

Deque cria_deque(){
    Deque d;
    d = (Deque) malloc(sizeof(struct deque));
    if(d != NULL){
        d->ini = NULL;
        d->fim = NULL;
    }
    return d;
}

int deque_vazio(Deque d){
    return (d->fim == NULL);
}

int insere_fim(Deque d, int elem){
    struct no *N;
    N = (struct no*) malloc(sizeof(struct no));
    if(N == NULL)
        return 0;
    N->info = elem;
    N->prox = NULL;
    if(deque_vazio(d)){
        d->ini = N;
        N->ant = NULL;
    }
    else{
        N->ant = d->fim;
        (d->fim)->prox = N;
    }
    d->fim = N;
    return 1;
}

int insere_ini(Deque d, int elem){
    struct no *N;
    N = (struct no*) malloc(sizeof(struct no));
    if(N == NULL)
        return 0;
    N->info = elem;
    N->ant = NULL;
    if(deque_vazio(d)){
        d->fim = N;
        N->prox = NULL;
    }
    else{
        N->prox = d->ini;
        (d->ini)->ant = N;
    }
    d->ini = N;
    return 1;
}


int remove_ini(Deque d, int *elem){
    if(deque_vazio(d))
        return 0;
    struct no *aux = d->ini;
    *elem = aux->info;
    if(d->ini == d->fim)
        d->fim = NULL;
    else
        d->ini->ant = NULL;
    d->ini = aux->prox;
    free(aux);
    return 1;
}

int remove_fim(Deque d, int *elem){
    if(deque_vazio(d))
        return 0;
    struct no *aux = d->fim;
    *elem = aux->info;
    if(d->ini == d->fim)
        d->ini = NULL;
    else
        d->fim->prox = NULL;
    d->fim = aux->ant;
    free(aux);
    return 1;
}

int libera_deque(Deque d){
    int x;
    while(remove_ini(d, &x))
        continue;
    free(d);
    return 1;
}
