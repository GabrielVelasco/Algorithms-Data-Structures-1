#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "list.h"

struct node{
	float info; // informacao da lista
	struct node* next;

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

int insertRecOrd(List *lst, float elem){
	if( emptyList(*lst) || elem <= (*lst)->info ){
		List node = (List) malloc(sizeof(struct node));
		if(node == NULL) return 0;

		node->info = elem;
		node->next = *lst;
		*lst = node;

		return 1;

	}else
		return insertRecOrd(&((*lst)->next), elem);

	return 1;
}

int insertFinal(List *lst, float elem){
	if( emptyList(*lst) ){
		List node = (List) malloc(sizeof(struct node));
		if(node == NULL) return 0;

		node->info = elem;
		node->next = *lst;
		*lst = node;

		return 1;

	}else
		return insertFinal(&((*lst)->next), elem);

	return 1;
}

int removeRecOrd(List *lst, float elem){
	// elem nao pertence a lista
	if( emptyList(*lst) || elem < (*lst)->info )
		return 0;

	else if( elem == (*lst)->info ){
		// remove o node da lista
		List tmp = *lst;
		*lst = tmp->next;
		free(tmp);

		return 1;

	}else
		return removeRecOrd(&((*lst)->next), elem);

}

int removeInit(List *lst){
	// elem nao pertence a lista
	if( emptyList(*lst) )
		return 0;

	List tmp = *lst;
	*lst = tmp->next;
	free(tmp);

	return 1;
}

int getPos(List lst, int idx, int cont, float *elem, int size){
	if( emptyList(lst) || (!cont && idx >= size) ) return 0;
	else if(cont == idx){
		*elem = lst->info;
		return 1;
	}

	return getPos(lst->next, idx, cont+1, elem, size);
}

void imprimiLista(List lst){
	if( lst == NULL ) return;
	else{
		printf("[%.2f] ", lst->info);
		imprimiLista(lst->next);
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

void clearList(List *lst){
	if( !emptyList(*lst) ){
		List tmp = *lst;
		*lst = (*lst)->next;
		free(tmp);
		clearList(lst);	
	}
}