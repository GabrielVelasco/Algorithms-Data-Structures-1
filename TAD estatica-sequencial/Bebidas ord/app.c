#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "app.h"

#define MAXS 20

struct drinks{
	char name[MAXS];
	int vol;
	float price;

};

struct drinkList{
	Drinks arr[MAXS];
	int size;

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

int insertOrd(List* lst, char name[], int vol, float price){
	if(lst == NULL || fullList(lst))	
		return 0;

	// se lista vazia ou se for na ultima posicao
	if( (emptyList(lst)) || ((strcmp(name, lst->arr[ lst->size-1 ].name) >= 0) && vol >= lst->arr[lst->size-1].vol) ){
		strcpy(lst->arr[ lst->size ].name, name);
		lst->arr[ lst->size ].vol = vol;
		lst->arr[ lst->size ].price = price;

	}else{
		int idx = 0;
		while( ((idx < lst->size) && (strcmp(name, lst->arr[idx].name) > 0))
	      ||   ((idx < lst->size) && (strcmp(name, lst->arr[idx].name) == 0) && vol > lst->arr[idx].vol ) )
			idx ++;

		for(int i = lst->size; i > idx; i--){
			strcpy(lst->arr[i].name, lst->arr[i-1].name);
			lst->arr[i].vol = lst->arr[i-1].vol;
			lst->arr[i].price = lst->arr[i-1].price;
		}
		// posicao idx esta livre
		strcpy(lst->arr[idx].name, name);
		lst->arr[idx].vol = vol;
		lst->arr[idx].price = price;
	}

	lst->size ++;
	return 1;
}

int removeOrd(List* lst, char name[]){
	if(lst == NULL || emptyList(lst) || ((strcmp(name, lst->arr[0].name)) < 0))
		return 0;

	int idx = 0;
	while( (idx < lst->size) && (strcmp(name, lst->arr[idx].name) > 0) )
		idx ++;

	if(idx == lst->size) return 0; // n pertence a lista
	for(int i = idx; i < lst->size-1; i++){
		strcpy(lst->arr[i].name, lst->arr[i+1].name);
		lst->arr[i].vol = lst->arr[i+1].vol;
		lst->arr[i].price = lst->arr[i+1].price;
	}

	lst->size --;
	return 1;
}

void getPos(List* lst, char name[], int *vol, float *price, int idx){
	strcpy(name, lst->arr[idx].name);
	*vol = lst->arr[idx].vol;
	*price = lst->arr[idx].price;
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