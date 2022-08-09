#include <stdio.h>
#include <stdlib.h>
#include "header.h"
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
int insere_ordenado(Lista lst,int elem){
if(lst == NULL || lista_cheia(lst) == 1){
    return 0; //falha
}

if(lista_vazia(lst) == 1 || elem >= lst->no[(lst->fim) - 1]){
    lst->no[lst->fim] = elem;
}
else{
    int i,Aux = 0;
    while(elem >= lst->no[Aux])
        Aux++;

    for(i = lst->fim;i>Aux;i--)
    lst->no[i] = lst->no[i-1];

    lst->no[Aux] = elem;
    }
lst->fim++;
return 1; // sucesso
}

int remove_ordenado(Lista lst,int elem){
if(lst == NULL || lista_vazia(lst) == 1 || elem < lst->no[0] || elem > lst->no[lst->fim-1]){
    return 0; //falha
}
int i,Aux = 0;
while(Aux < lst->fim && lst->no[Aux] < elem ){
    Aux++;
}

if(Aux == lst->fim || lst->no[Aux] > elem)
    return 0; // falha
for(i=Aux+1;i<lst->fim;i++)
lst->no[i-1] = lst->no[i];

lst->fim = (lst->fim) - 1;

return 1;//sucesso
}



int get_elemento(Lista lista, int pos, int *n)
{
    if(lista_vazia(lista)==1 || pos> lista->fim || pos<=0)
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

int esvazia(Lista lista)
{
    lista->fim=0;
    return 1;


}

int remove_pares(Lista lista)
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
        if(lista->no[i]%2!=0)
        {
            lista->no[j]=lista->no[i];
            j++;
        }
    }
    lista->fim=j;
    return 1;
}

int maior_elemento(Lista lista)
{
    return lista->no[lista->fim-1];
}

Lista intercala(Lista lista1,Lista lista2){
  Lista lista3 = cria_lista();
    if(lista3 == NULL)
        return NULL;
    int i = 0, j = 0;
    while(i < lista1->fim || j < lista2->fim){
        if(lista1->no[i] <= lista2->no[j]){
            lista3->no[lista3->fim] = lista1->no[i];
            i++;
        }
        else{
            lista3->no[lista3->fim] = lista2->no[j];
            j++;
        }
        lista3->fim++;
        if(lista_cheia(lista3)){
            return lista3;
        }
    }
    return lista3;
}




/*
Lista intercala(Lista lista1,Lista lista2){
  int i;
  Lista lista3 = cria_lista();

  if(lista3 == NULL)
    return NULL;

  for (i = 0; i < lista1->fim; i++)
    {
        lista3->no[i] = lista1->no[i];
        lista3->fim = lista3->fim + 1;
    }

    if(lista_cheia(lista3))
        return lista3;

  for(i = 0;i<lista2->fim;i++){
        if(lista_cheia(lista3)){
         return lista3;
        }
      insere_ordenado(lista3,lista2->no[i]);
     }
    lista3->fim = lista1->fim + (lista2->fim);
    return lista3;
}
*/

/*
Lista inverte(Lista lista)
{
    int i,j=0;
    Lista inversa;
    for(i=lista->fim-1; i>=0; i--)
    {
        inversa->no[j]=lista->no[i];
        j++;
    }
    inversa->fim=lista->fim;

    return inversa;
}
*/
