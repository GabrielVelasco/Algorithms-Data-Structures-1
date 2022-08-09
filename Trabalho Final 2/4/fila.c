#include <stdio.h>
#include <stdlib.h>
#include "fila.h"

struct cliente{
    int tcaixa, tesp, tcheg;
};
typedef struct cliente cliente;
struct no{
    cliente c;
    struct no *prox;
};

struct fila{
    struct no *ini, *fim;
};

Fila cria_fila(){
    Fila F;
    F = (Fila) malloc(sizeof(struct fila));
    if(F != NULL){
        F->ini = NULL;
        F->fim = NULL;
    }
    return F;
}

int fila_vazia(Fila f){
    return (f->fim == NULL);
}

int insere_cliente(Fila f, int tc, int tesp, int tempo){
    struct no *N;
    N = (struct no*) malloc(sizeof(struct no));
    if(N == NULL)
        return 0;
    N->c.tesp = tesp;
    N->c.tcaixa = tc;
    N->c.tcheg = tempo;
    N->prox = NULL;
    if(fila_vazia(f))
        f->ini = N;
    else
        (f->fim)->prox = N;
    f->fim = N;
    return 1;
}

int remove_cliente(Fila f, int *caixa, int *esp, int *cheg){
    if(fila_vazia(f)){
        return 0;
    }
    struct no *aux = f->ini;
    *caixa = aux->c.tcaixa;
    *esp = aux->c.tesp;
    *cheg = aux->c.tcheg;
    if(f->ini == f->fim)
        f->fim = NULL;
    f->ini = aux->prox;
    free(aux);
    return 1;
}

int tamanho_fila(Fila f){
    int ca, fi, ch, cnt = 0;
    if(fila_vazia(f))
        return 0;
    Fila aux = cria_fila();
    while(remove_cliente(f, &ca, &fi, &ch)){
        insere_cliente(aux, ca, fi, ch);
        cnt++;
    }
    while(remove_cliente(aux, &ca, &fi, &ch))
        insere_cliente(f, ca, fi, ch);
    return cnt;
}

