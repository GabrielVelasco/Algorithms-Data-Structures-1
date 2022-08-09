#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "app.h"

#define MAXS 20

struct strList{
	char arrStr[25][15];
	int size; // indica qnts string tenho na lista

};

List* createList(){
	List* lst = (List*) malloc(sizeof(List));
	if(lst != NULL)
		lst->size = 0;

	return lst;
}

int emptyList(List* lst){
	if(lst == NULL || lst->size == 0)
		return 1;
	else
		return 0;
}

int fullList(List* lst){
	if(lst->size == MAXS)
		return 1;
	else
		return 0;
}

int insertStr(List* lst, char str[]){
	if(lst == NULL || fullList(lst))
		return 0;

	strcpy(lst->arrStr[ lst->size ], str);
	lst->size ++;

	return 1;
}

int removeStr(List* lst, char str[]){
	if(lst == NULL || emptyList(lst))
		return 0;

	int idx = 0;
	while( idx < lst->size && strcmp(str, lst->arrStr[ idx ]) )
		idx ++;

	if(idx == lst->size)
		return 0;
	// idx == pos da str que quero remover
	for(int i = idx; i < (lst->size)-1; i++)
		strcpy(lst->arrStr[i], lst->arrStr[i+1]);

	lst->size --;
	return 1;
}

char* getPos(List* lst, int idx){
	if(idx < lst->size)
		return lst->arrStr[idx];

	return NULL;
}

int getSize(List* lst){

	return lst->size;
}

int clearList(List* *lst){
	if(emptyList(*lst)) return 0;

	free(*lst);
	*lst = NULL;

	return 1;
}