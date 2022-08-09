#include "header.h"
#include <stdio.h>
#include <stdlib.h>

struct no
{
    int info;
    struct no *ant;
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

int insere_elemento(Lista *lst,int elem){
    //aloca novo no e preenche campo info
    Lista N = (Lista) malloc(sizeof(struct no));
    if(N == NULL){
        return 0; //falha
    }

    N->info = elem; // insere conteudo
    N->ant = NULL; // nao tem antecessor do novo no
    N->prox = *lst; //sucessor do novo no recebe mesmo end da lista

    if(lista_vazia(*lst) == 0)
        (*lst)->ant = N; // faz o antecessor do 1 no ser o novo no

    *lst = N; // faz a lista apontar para o novo no
    return 1;
}

int remove_elemento(Lista *lst,int elem){
    if(lista_vazia(*lst)) return 0;
    Lista aux = *lst; //faz apontar para o 1 no
    while(aux->prox != NULL && aux->info != elem)
        aux = aux->prox;
    if(aux->info != elem) return 0; //elemento nao esta na lista
    if(aux->prox != NULL) aux->prox->ant = aux->ant;
    if(aux->ant != NULL) aux->ant->prox = aux->prox;
    if(aux == *lst) *lst = aux->prox;
      free(aux);
      return 1;
}

int remove_todos(Lista *lst, int elem){
    if(lista_vazia(*lst)) return 0;
    int ch = 0;
    Lista tmp = *lst, tmp2;
    while(tmp != NULL){
        ch = 0;
        if(tmp->info == elem){
            ch = 1;
            tmp2 = tmp;
            if(tmp->ant != NULL) tmp->ant->prox = tmp->prox;
            if(tmp->prox != NULL) tmp->prox->ant = tmp->ant;
            if(*lst == tmp) *lst = tmp->prox;
        }
        tmp = tmp->prox;
        if(ch) free(tmp2);
    }
    return 1;
}

void printa(Lista lst){
    while(lst != NULL){
        printf("%d ", lst->info);
        lst = lst->prox;
    }
    printf("\n");
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

int remove_maior_elemento(Lista *lista, int* elem){
    if(lista_vazia(*lista)) return 0;

    int maior = (*lista)->info;
    Lista tmp = (*lista)->prox, tmp2 = *lista;
    while(tmp != NULL){
        if(tmp->info > maior){
            tmp2 = tmp; // ate aqui tmp2 eh o maior
            maior = tmp->info;
        }
        tmp = tmp->prox;
    }

    // tmp2 vai ser deletado
    if(tmp2->ant != NULL) tmp2->ant->prox = tmp2->prox;
    if(tmp2->prox != NULL) tmp2->prox->ant = tmp2->ant;
    if(*lista == tmp2) *lista = tmp2->prox;
    *elem = tmp2->info;

    free(tmp2);
    return 1;
}


int get_elemento(Lista lista, int pos, int *numero)
{
    if(lista_vazia(lista)|| pos<=0)
    {
        return 0;
    }
    int contador=1;
    Lista aux=lista;

    while(aux->prox!=NULL && contador<pos)
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

int esvazia(Lista *lista)
{
    while(*lista!=NULL)
    {
        Lista aux=*lista;
        *lista=aux->prox;
        free(aux);
    }
    return 1;
}

void multiplo_de_3(Lista lista, Lista* lista2){
    if(!lista_vazia(*lista2)){
        printf("Esvaziando lista 2...\n");
        esvazia(lista2);
    }
    int insere;
    Lista aux = lista;

    while(aux != NULL){
        if(aux->info % 3 == 0)
            insere = insere_elemento(lista2, aux->info);
        aux = aux->prox;
    }
}

Lista inverter_lista(Lista *lst){
  Lista lst2 = cria_lista();
  Lista aux = *lst;
  while(aux->prox != NULL){
    insere_elemento(&lst2, aux->info);
    aux = aux->prox;
  }
  insere_elemento(&lst2, aux->info);
  return lst2;
}