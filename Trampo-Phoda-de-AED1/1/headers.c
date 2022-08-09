#include <stdio.h>
#include <stdlib.h>
#include "headers.h"
//#include "prototipos/headers.h"
#define Maximo 20
struct lista
{
    int no [Maximo];
    int fim;

};

Lista cria_lista()
{
    Lista lista;
    lista=(Lista)malloc(sizeof(struct lista));
    if(lista!=NULL)
    {
        lista->fim=0;
    }
    return lista;
}

//saiu da func cria
int lista_vazia(Lista lista)
{
    if(lista->fim==0)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
//saiu func lista vazia
int lista_cheia(Lista lista)
{
    if(lista->fim>=Maximo)
    {
        return 1; // lista esta cheia
    }
    else
    {
        return 0; // lista nao esta cheia

    }
}
//saiu da func lista cheia
int insere_elemento_nao_ordenado(Lista lista, int numero)
{
    if(lista==NULL)
    {
        return -1; // cod de erro nao e um lista valida
    }
    else if(lista_cheia(lista)==1)
    {
        return 0; //ta cheia
    }
    lista->no[lista->fim]=numero;
    lista->fim++;
    return 1; //inseriu com sucesso
}
//saiu do insere

int remove_elemento_nao_ordenado(Lista lista, int numero)
{
    if(lista==NULL)
    {
        return -1;
    }
    else if(lista_vazia(lista)==1)
    {
        return 0;
    }
    int i,aux=0;

    while(aux <lista->fim && lista->no[aux]!=numero)
    {
        aux++;
    }
    if(aux==lista->fim)
    {
        return -2; //elemento nao esta na lista
    }
    for(i=aux+1; i<lista->fim; i++)
    {
        lista->no[i-1]=lista->no[i];
    }
    lista->fim--;
    return 1; //E. removido
}

// saiu da func remove

int get_elemento(Lista lista, int pos, int *n)
{
    if(lista_vazia(lista)==1 || pos> lista->fim)
    {
       return 0;
    }
    *n=lista->no[pos-1];
    return 1;
}
// saiu da get elemento

int tamanho()
{
    return Maximo;
}
//saiu do tamanho
int quantidade_elementos(Lista lista)
{
    return lista->fim;
}
//saiu do quantidade_elementos

int menor_elemento(Lista lista)
{
    int i=0, menor=lista->no[0];
    if(lista==NULL)
    {
        return -1;
    }
    else if(lista_vazia(lista)==1)
    {
        return 0;
    }
    while(i<lista->fim)
    {
        if(lista->no[i]<menor)
        {
            menor=lista->no[i];

        }
        i++;

    }


    return menor;
}

int esvazia(Lista lista)
{
    if(lista->fim == 0){
      return 0;
    }else
      lista->fim=0;

    return 1;
}
int remove_impares(Lista lista)
{
    if(lista==NULL)
    {
        return -1;
    }
    if(lista_vazia(lista)==1)
    {
        return 0;
    }

    int i,j=0;

    for(i=0; i<lista->fim; i++)
    {
        if(lista->no[i]%2==0){
        lista->no[j]=lista->no[i];
        j++;
        }
    }
    lista->fim=j;
    return 1;
}


Lista inverte(Lista lista)
{
    int i,j=0;
    Lista inversa;
    inversa = cria_lista();
    if(inversa == NULL)
    return NULL;
    for(i=lista->fim-1; i>=0; i--)
    {
        inversa->no[j]=lista->no[i];
        j++;
    }
    inversa->fim=lista->fim;

    return inversa;
}

Lista concatena(Lista lista1, Lista lista2)
{
    int i,j;
    Lista lista3 = cria_lista();
    if(lista3 == NULL)
      return NULL;
    for (i = 0; i < lista1->fim; i++)
    {
        lista3->no[i] = lista1->no[i];
        lista3->fim = lista3->fim + 1;
    }

    j = lista3->fim;
    if(lista_cheia(lista3))
      return lista3;

    for (i = 0;i < lista2->fim; i++)
    {

       lista3->no[j] = lista2->no[i];
       lista3->fim = lista3->fim + 1;
       if(lista_cheia(lista3))
        return lista3;
       j++;
    }

    lista3->fim = lista1->fim + (lista2->fim);
    return lista3;
}

