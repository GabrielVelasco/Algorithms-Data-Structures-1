#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "list.h"

struct node{
	int info; // informacao da lista
	List next;
	List prev;

};

List createList(){
	// retorna NULL == lista vazia
	return NULL;
}

int emptyList(List lst){
	// lst == no cabecalho
	if(lst == NULL)
		return 1;
	else
		return 0;
}

int insertElem(List *lst, int elem){
	List node = (List) malloc(sizeof(struct node));
	if( node == NULL ) return 0;

	node->info = elem;
	node->prev = NULL; // nao ordenada == NODE sempre no inicio
	node->next = *lst; // atual primeiro passa a ser o segundo

	if( !emptyList(*lst) )
		(*lst)->prev = node;

	*lst = node;
	return 1;
}

int removeElem(List *lst, int elem){
	if( (emptyList(*lst)) ) return 0;

	List tmp = *lst;
	while( tmp->next != NULL && tmp->info != elem )
		tmp = tmp->next;

	if( tmp->info != elem ) return 0; // nao existe na lista

	// tmp == node a ser removido
	if( tmp->next != NULL ) tmp->next->prev = tmp->prev;
	if( tmp->prev != NULL ) tmp->prev->next = tmp->next;
	if( tmp == *lst ) *lst = tmp->next; // node a ser removido eh o primeiro
 
 	free(tmp);
	return 1;
}

int getElem(List lst, int idx, int *elem){
	if( (emptyList(lst)) || (idx >= getSize(lst)) ) return 0; // pos n existe

	while(idx --)
		lst = lst->next;

	*elem = lst->info;
	return 1;
}

void imprimiLista(List lst){
	while( lst != NULL ){
		printf("[%d] ", lst->info);
		lst = lst->next;
	}
}

int getSize(List lst){ 
	if( emptyList(lst) ) return 0;
	int size = 1;
	while( lst->next != NULL ){
		lst = lst->next;
		size ++;
	}

	return size;
}