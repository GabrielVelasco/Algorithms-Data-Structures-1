#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "app.h"

struct node{
	ui matr;
	char name[15];
	float mean;
	int missed;
	List* next;

};

List* createList(){ return NULL; } // n aponta pra nenhum node

int emptyList(List* lst){
	if(lst == NULL)
		return 1;
	else
		return 0;
}

int insertElem(List* *lst, ui matr, char name[], float mean, int missed){
	// cria o node e atribui
	List* node = (List*) malloc(sizeof(List));
	if(node == NULL) return 0;

	node->matr = matr;
	strcpy(node->name, name);
	node->mean = mean;
	node->missed = missed;

	node->next = *lst;
	*lst = node;

	return 1;
}

int removeElem(List* *lst, ui matr){
	if( (emptyList(*lst)) ) return 0;

	List* tmp = *lst;
	// trata primeiro node
	if( tmp->matr == matr ){
		*lst = tmp->next;
		free(tmp);
		return 1;
	}
	// trata resto da lista
	while( (tmp->next != NULL) && (tmp->next->matr != matr) )
		tmp = tmp->next;

	if( tmp->next == NULL ) return 0;
	List* tmp2 = tmp->next; // tmp2 aponta p/ node a ser removido
	tmp->next = tmp2->next;
	free(tmp2);

	return 1;
}

int getPos(List* lst, int idx, ui *matr, char name[], float *mean, int *missed){
	if( (emptyList(lst)) || (idx >= getSize(lst)) ) return 0;
	// navega ate a posicao correta
	while(idx --)
		lst = lst->next;
	// lst == node a ser retornado
	*matr = lst->matr;
	strcpy(name, lst->name);
	*mean = lst->mean;
	*missed = lst->missed;

	return 1;
}

int getSize(List* lst){
	if(emptyList(lst)) return 0;
	int size = 1;
	while(lst->next != NULL){
		size ++;
		lst = lst->next;
	}

	return size;
}

int clearList(List* *lst){
	if(emptyList(*lst)) return 0;

	// Limpar node por node
	List* tmp;
	while(*lst != NULL){
		tmp = *lst;
		*lst = (*lst)->next;
		free(tmp);
	}

	return 1;
}

// int getElem(List* *lst){ // para printar a lista
// 	int a = (*lst)->number;
// 	*lst = (*lst)->next;

// 	return a;
// }

// int removePos(List* *lst, int idx){
// 	// achar o node que contem o elemento que quero remover e chamar funcao
// 	List* tmp = *lst;
// 	int a = tmp->number;
// 	// remover num do primeiro node [0]
// 	if( (!idx) && removeOrd(lst, (*lst)->number) )
// 		return a;
	
// 	else{
// 		// partir do node[0] e chegar no node[idx] vao ser idx movimentos
// 		while(idx --)
// 			tmp = tmp->next;
// 		// tmp == node para ser excluido
// 		a = tmp->number;
// 		if(removeOrd(lst, tmp->number))
// 			return a;
// 		else
// 			return -1;
// 	}
// }