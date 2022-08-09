// ex5
#include <stdlib.h>
#include <stdio.h>
#include "list.h"

struct no
{
    double info;
    struct no *prox;

};

Lista cria_lista()
{
    return NULL;

}

int lista_vazia(Lista lista)
{
    if(lista==NULL)
    {
        return 1;
    }
    else
    {
        return 0;
    }

}

int insere_final(Lista *lista,double numero)
{
    Lista novo=(Lista)malloc(sizeof(struct no));
    if(novo==NULL)
    {
        return 0;
    }
    novo->info=numero;

    if(lista_vazia(*lista)==1)
    {
        *lista=novo;
        novo->prox=novo;
    }
    else
    {
        Lista aux=*lista;
        while(aux->prox!=(*lista))
        {
            aux=aux->prox;
        }
        aux->prox=novo;
        novo->prox=*lista;
    }
    return 1;
}

int insere_inicio(Lista*lista, double numero)
{
    Lista novo=(Lista)malloc(sizeof(struct no));
    if(novo==NULL)
    {
        return 0;
    }
    novo->info=numero;

    if(lista_vazia(*lista)==1)
    {
        novo->prox=novo;
        *lista=novo;
    }
    else
    {
        Lista aux=*lista;
        while(aux->prox!=(*lista))
        {
            aux=aux->prox;
        }
        aux->prox=novo;
        novo->prox=*lista;
        *lista=novo;
    }
    return 1;
}


int get_elemento(Lista lista, int pos, double *numero)
{
    if(lista_vazia(lista)|| pos<=0)
    {
        return 0;
    }
    int contador=1;
    Lista aux=lista;

    while(aux->prox!=lista && contador<pos)
    {
        aux=aux->prox;
        contador++;
    }
    if(contador !=pos)
    {
        return 0;
    }
    *numero=aux->info;
    return 1;
}

double maior_elemento(Lista lista)
{
    Lista aux=lista;

    double maior=aux->info;
    while(aux->prox!=(lista))
    {
        aux=aux->prox;
        if(aux->info>maior)
        {
            maior=aux->info;
        }
    }
    return maior;
}
int tamanho(Lista lista)
{
    Lista aux=lista;
    int conta=1;
    if(lista_vazia(lista)==1)
    {
        return conta=0;
    }
    while(aux->prox!=(lista))
    {
        aux=aux->prox;
        conta++;

    }
    return conta;
}

int remove_inicio(Lista *lista)
{
    if(lista==NULL)
        return 0;
    if(lista_vazia(*lista)==1)
        return 0;
    if((*lista)==(*lista)->prox)
    {
        free(*lista);
        *lista=NULL;
        return 1;
    }
    Lista aux=*lista;
    while(aux->prox!=*lista)
        aux=aux->prox;
    Lista novo=*lista;
    aux->prox=novo->prox;
    *lista=novo->prox;
    free(novo);
    return 1;
}

int remove_final(Lista*lista)
{

    if(lista==NULL)
        return 0;
    if(lista_vazia(*lista)==1)
        return 0;
    if((*lista)==(*lista)->prox)
    {
        free(*lista);
        *lista=NULL;
        return 1;
    }
    Lista novo=*lista,ant;
    while(novo->prox != (*lista))
    {
        ant=novo;
        novo=novo->prox;
    }
    ant->prox=novo->prox;
    free(novo);
    return 1;
}


int insere_posicao(Lista *lista,int pos ,double numero){
if(pos<=0)
    {
        return 0;
    }
    int contador=1;
    Lista aux=*lista;

    while(aux->prox!=*lista && contador<pos-1)
    {
        aux=aux->prox;
        contador++;
    }
    if(contador !=pos-1)
    {
        return 0;
    }
        Lista novo=(Lista)malloc(sizeof(struct no));
    if(novo==NULL)
    {
        return 0;
    }
    novo->info=numero;

    if(lista_vazia(*lista)==1)
    {
        *lista=novo;
        novo->prox=novo;
    }
aux->prox=novo;
novo->prox=aux->prox;
novo->prox=*lista;

  return 1;

}

int remove__posicao(Lista *lista,int pos){

    if(pos==1){
        remove_inicio(lista);
        return 1;
    }
if(pos<=0)
    {
        return 0;
    }
    int contador=1;
    Lista aux=*lista;

    while(aux->prox!=*lista && contador<pos-1)
    {
        aux=aux->prox;
        contador++;
    }
    if(contador !=pos-1)
    {
        return 0;
    }
        if((*lista)==(*lista)->prox)
    {
        free(*lista);
        *lista=NULL;
        return 1;
    }

 Lista ant;

       ant=aux->prox;
    aux->prox=ant->prox;
    free(ant);
  return 1;
}

void imprime(Lista l)
{
    int i;
    for(i=1; ; i++)
    {
        double n;
        if(get_elemento(l,i,&n)==0)
            break;
        printf("[%.2lf] ",n);
    }
    printf("\n");
}