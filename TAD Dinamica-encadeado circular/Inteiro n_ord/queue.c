#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "app.h"

struct node{
	int num; 
	struct node* next;

};

List createList(){
	return NULL; // inicializa lista sem nenhum node
}

int emptyList(List lst){
	// lst == ponteiro para ultimo node
	if( lst == NULL )
		return 1;
	else
		return 0;
}

int insertFinal(List *lst, int elem){
	// cria o node e atribui
	List node = (List) malloc(sizeof(struct node));
	if(node == NULL) return 0;
	node->num = elem;

	if( emptyList(*lst) ){
		// node será o primeiro e ultimo
		node->next = node;
		*lst = node;
	
	}else{
		// lista >1 // lst aponta para ultimo node, que aponta p/ o primeiro
		node->next = (*lst)->next; // node aponta p/ primeiro
		(*lst)->next = node;
		*lst = node;
	}

	return 1;
}

int insertBegi(List *lst, int elem){
	List node = (List) malloc(sizeof(struct node));
	if( node == NULL ) return 0;
	node->num = elem;

	if( emptyList(*lst) ){
		// node será o primeiro e ultimo
		node->next = node;
		*lst = node;
	}else{
		node->next = (*lst)->next; // node passa a ser o primeiro
		(*lst)->next = node;
	}

	return 1;
}

int removeIni(List *lst, int *elem){ // retorno implícito do elem removido
	if( emptyList(*lst) ) return 0;

	List tmp = (*lst)->next; // aponta p/ node a ser removido
	*elem = tmp->num; // copia elemento a ser removido

	if( *lst == (*lst)->next )
		*lst = NULL; // lista com um unico node
	else
		(*lst)->next = tmp->next;
	
	free(tmp);
	return 1;
}

int removeFinal(List *lst, int *elem){
	if( emptyList(*lst) ) return 0;

	List tmp = *lst; // aponta p/ node a ser removido (*lst)
	*elem = tmp->num; // informacao do elemento removido

	if( *lst == (*lst)->next ){
		*lst = NULL;
	}else{
		// move lst p/ o novo ultimo node (atual penultimo)
		while( (*lst)->next != tmp ) 
			(*lst) = (*lst)->next;

		(*lst)->next = tmp->next; // novo ultimo node aponta para o primeiro
	}

	free(tmp);
	return 1;
}

int getElem(List lstk, int idx, int *elem){
	if( (emptyList(lst)) || (idx >= getSize(lst)) ) return 0; // pos n existe

	List tmp = lst->next; // aponta p/ primeiro node
	while(idx --)
		tmp = tmp->next;

	*elem = tmp->num;
	return 1;
}

int getSize(List lst){
	if( emptyList(lst) ) return 0;
	List tmp = lst->next; // aponta p/ primeiro node

	int size = 1;
	while( tmp != lst ){
		tmp = tmp->next;
		size ++;
	}

	return size;
}