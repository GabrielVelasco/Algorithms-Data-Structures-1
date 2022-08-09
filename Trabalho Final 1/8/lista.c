#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "lista.h"

struct no{
    int pot, coef;
    struct no *prox;
};

Lista cria_lista(){
    Lista N = (Lista) malloc(sizeof(struct no));
    N->pot = 0;
    N->coef = 0;
    N->prox = NULL;
    return N;
}

int get_pos(Lista lst, int *p, int *c, int pos){
    Lista aux = lst;
    int it = 0;
    while(aux->prox != NULL && pos != it){
        aux = aux->prox;
        it++;
    }
    if(aux->prox == NULL && pos != it)
        return 0;
    *p = aux->pot;
    *c = aux->coef;
    return 1;
}
int insere_termo(Lista *lst, int p, int c){
    Lista aux = *lst;
    while(aux->prox != NULL && aux->prox->pot <= p)
        aux = aux->prox;
    if(p == aux->pot){
        aux->coef += c;
        return 1;
    }
    Lista N = (Lista) malloc(sizeof(struct no));
    if(N == NULL)
        return 0;
    N->pot = p;
    N->coef = c;
    N->prox = aux->prox;
    aux->prox = N;
    return 1;
}

int remove_pot(Lista *lst, int p){
    Lista aux = *lst;
    while(aux->prox != NULL && aux->prox->pot < p)
        aux = aux->prox;
    if(aux->prox == NULL || aux->prox->pot > p)
        return 0;
    Lista aux2 = aux->prox;
    aux->prox = aux2->prox;
    free(aux2);
    return 1;
}

int reset_lista(Lista *lst){
    Lista aux = *lst, aux2 = *lst;
    if(aux->prox != NULL)
        aux = aux->prox;
    while(aux->prox != NULL){
        free(aux2);
        aux2 = aux;
        aux = aux->prox;
    }
    free(aux);
    aux = cria_lista();
    *lst = aux;
    return 1;
}

int calcula_poli(Lista *lst, int x){
    Lista aux = *lst;
    int tot = 0;
    while(aux->prox != NULL){
        tot += aux->coef * (pow(x, aux->pot));
        aux = aux->prox;
    }
    tot += aux->coef * (pow(x, aux->pot));
    return tot;
}
