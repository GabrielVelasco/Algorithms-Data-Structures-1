#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "app.h"

struct node{
	int number;
	List* next;

};

List* createList(){ return NULL; }

int emptyList(List* lst){
	if(lst == NULL)
		return 1;
	else
		return 0;
}

int insertOrd(List* *lst, int num){
	// cria o node e atribui
	List* node = (List*) malloc(sizeof(List));
	if(node == NULL) return 0;
	node->number = num;

	// achar pos correta para inserir
	if( (emptyList(*lst)) || (num >= (*lst)->number) ){
		node->next = *lst;
		*lst = node;
		return 1;
	}

	List* tmp = *lst;
	while(tmp->next != NULL && tmp->next->number > num)
		tmp = tmp->next;

	node->next = tmp->next;
	tmp->next = node;
	return 1;
}

int removeOrd(List* *lst, int num){
	if( (emptyList(*lst)) || (num > (*lst)->number) ) return 0;

	List* tmp = *lst;
	// tratar o 1 node
	if( (*lst)->number == num ){
		*lst = tmp->next;
		free(tmp);
	}


	while( (tmp->next != NULL) && (num < tmp->next->number) )
		tmp = tmp->next;

	// pode acontecer de n precisar de percorrer ate o final da lista
	if( (tmp->next == NULL) || (num > tmp->next->number) ) return 0;

	// tenho q remover node a direta de tmp
	List* tmp2 = tmp->next;
	tmp->next = tmp2->next;
	free(tmp2);
	return 1;
}

int getPos(List* lst, int idx){
	// navega ate a posicao correta
	while(idx --)
		lst = lst->next;	
	
	return lst->number;
}

int removePos(List* *lst, int idx){
	// achar o node que contem o elemento que quero remover e chamar funcao
	List* tmp = *lst;
	int a = tmp->number;
	// remover num do primeiro node [0]
	if( (!idx) && removeOrd(lst, (*lst)->number) )
		return a;
	
	else{
		// partir do node[0] e chegar no node[idx] vao ser idx movimentos
		while(idx --)
			tmp = tmp->next;
		// tmp == node para ser excluido
		a = tmp->number;
		if(removeOrd(lst, tmp->number))
			return a;
		else
			return -1;
	}
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