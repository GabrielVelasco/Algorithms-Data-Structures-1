#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "app.h"

struct node{
	int cab_inf, num; // cab_inf == tamanho da lista
	List next;

};

List createList(){
	// aloca e retorna no cabecalho
	List cab = (List) malloc(sizeof(struct node));
	if(cab != NULL){
		cab->next = NULL; // inicialmente lista vazia
		cab->cab_inf = 0;
	}

	return cab;
}

int emptyList(List lst){
	// lst == no cabecalho
	if(lst->next == NULL)
		return 1;
	else
		return 0;
}

int insertElem(List lst, int elem){
	// cria o node e atribui
	List node = (List) malloc(sizeof(struct node));
	if(node == NULL) return 0;

	node->num = elem;
	node->next = lst->next;
	lst->next = node;
	lst->cab_inf ++; // mais um elemento na lista

	return 1;
}

int removeElem(List lst, int elem){
	if( (emptyList(lst)) ) return 0;

	List tmp = lst;
	while(tmp->next != NULL && tmp->next->num != elem)
		tmp = tmp->next;

	if(tmp->next == NULL) return 0; // nao existe na lista

	List tmp2 = tmp->next; // node a ser removido
	tmp->next = tmp2->next;
	free(tmp2);
	lst->cab_inf --; // menos um elemento na lista

	return 1;
}

int getElem(List lst, int idx){
	if( (emptyList(lst)) || (idx >= lst->cab_inf) ) return 0; // pos n existe

	List tmp = lst;
	while(idx --)
		tmp = tmp->next;

	return tmp->next->num;
}

int getSize(List lst){ return lst->cab_inf; }

int clearList(List* lst){
	if(emptyList(*lst)) return 0;

	// Limpar node por node
	List tmp;
	while( (*lst)->next != NULL ){
		tmp = (*lst)->next; // node a ser excluido
		(*lst)->next = tmp->next; // novo primeiro node
		free(tmp);
	}
	// so fica o no cabecalho

	return 1;
}