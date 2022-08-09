// implementacao das funcoes e declaracao de structs
#include <stdio.h>
#include <stdlib.h>
#include "app.h"

#define MAXS 20

struct lista{
	float arr[MAXS];
	int fim;

};

Lista* cria_lista(){
	// aloca e inicialia fim = 0
	Lista *l = malloc(sizeof(Lista));
	// verifica se a alocacao deu certo antes para atribuir o campo
	if(l != NULL)
		l->fim = 0;

	return l;
}

int lista_vazia(Lista *l){
	if(l == NULL)
		return 1;
	if(l->fim == 0)
		return 1; // esta vazia
	if(l->fim != 0)
		return 0; // nao esta vazia
}

int lista_cheia(Lista *l){
	if(l->fim == MAXS)
		return 1;
	else
		return 0;
}

int insere_ord(Lista *l, float elem){
	if(l == NULL || lista_cheia(l))
		return 0;

	// se lista estiver vazia add na pos fim(size) == 0
	// se for maior ou igual ao ultimo elemento da lista add na ultima pos == fim
	if(lista_vazia(l) || elem >= l->arr[l->fim-1])
		l->arr[ l->fim ] = elem;

	// elem vai ficar no meio da lista, tenho que percorrer
	else{
		int idx = 0;
		// percorre array buscando pela posicao correta para add elem
		while(elem >= l->arr[idx])
			idx ++;

		// idx eh a posicao correta para add elem em arr
		// puxa tudo a direita
		for(int i = l->fim; i > idx; i--)
			l->arr[i] = l->arr[i-1];
		l->arr[idx] = elem;

	}

	l->fim ++; // +1 elem para essa lista
	return 1;
}

int remove_ord(Lista *l, float elem){
	if(l == NULL || lista_vazia(l) || elem > l->arr[ l->fim-1 ])
		return 0;

	int aux = 0;
	// achar elem no arr
	while(elem > l->arr[aux])
		aux ++;

	if(elem < l->arr[aux])
		return 0; // elem nao pertence na lista
	// elem == arr[aux]
	else{
		for(int i = aux; i < l->fim-1; i++)
			l->arr[i] = l->arr[i+1];
	}

	l->fim --;
	return 1;
}

int get_pos(Lista *l, float elem, int *p){
	if(l == NULL || lista_vazia(l))
		return 0;

	for(int i = 0; i < l->fim; i++){
		if(l->arr[i] == elem){
			*p = i;
			return 1;
		}
	}

	return 0;
}

int get_elem(Lista *l, int *idx, float *elem){
	if(*idx < l->fim){
		*elem = l->arr[*idx];
		(*idx) ++;
		return 1;
	}else
		return 0; // percorri todo o arr da lista
}

void limpa_lista(Lista **l){
	free(*l); *l = NULL;
}