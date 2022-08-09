// ex4
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "list.h"

struct node{
	int tam; // informacao da lista
	char info, maior;
	List next;

};

List createList(){
	// aloca e retorna no cabecalho
	List cab = (List) malloc(sizeof(struct node));
	if(cab != NULL){
		cab->next = NULL; // inicialmente lista vazia
		cab->tam = 0;
		cab->maior = 0;
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

int insertOrd(List lst, char elem){
	// cria o node e atribui
	List node = (List) malloc(sizeof(struct node));
	List cab = lst; // copia do cabecalho
	if(node == NULL) return 0;

	//List tmp = lst; // tmp == cabecalho
	node->info = elem;
	while( lst->next != NULL && lst->next->info < elem )
		lst = lst->next;

	node->next = lst->next;
	lst->next = node;

	// node entrou na ultima pos, logo eh o maior ate aqui
	if( node->next == NULL )
		cab->maior = elem;

	cab->tam ++; // mais um elemento na lista // lst == cabecalho
	return 1;
}

int removeOrd(List lst, char elem){
	if( (emptyList(lst)) ) return 0;
	List cab = lst; // copia do cabecalho

	while(lst->next != NULL && lst->next->info < elem)
		lst = lst->next;

	if( lst->next == NULL || lst->next->info > elem ) return 0; // nao existe na lista

	List tmp2 = lst->next; // tmp2 node a ser removido

	// caso eu remover o ultimo node
	// terei um novo maior
	if( tmp2->next == NULL )
		cab->maior = lst->info;

	lst->next = tmp2->next;
	free(tmp2);

	cab->tam --; // menos um elemento na lista
	return 1;
}

int getElem(List lst, int idx, char *elem){
	if( (emptyList(lst)) || (idx >= lst->tam) ) return 0; // pos n existe

	while(idx --)
		lst = lst->next;

	*elem = lst->next->info;
	return 1;
}

void imprimiLista(List lst){
	while( lst->next != NULL ){
		printf("[%c] ", lst->next->info);
		lst = lst->next;
	}
}

int comparaLista(List L, List L2){
	int cont = 0, size = L->tam;
	if(size != L2->tam) return 0;

	// chegou ate aqui, listas tem tamanhos iguais
	while((L->next != NULL) && (L->next->info == L2->next->info)){
		L = L->next;
		L2 = L2->next;
		cont ++;
	}

	if(cont == size) return 1;
	else return 0;
}

int getSize(List lst){ return lst->tam; }

int maiorElem(List lst, char *elem){
	if( emptyList(lst) ) return 0;

	*elem = lst->maior;
	return 1;
}

int inserePos(List *node, char elem){
	// node == ultimo node da l3
	List newNode = (List) malloc(sizeof(struct node));
	if(newNode == NULL) return 0;;

	newNode->info = elem;
	newNode->next = NULL;
	if(*node != NULL)
		(*node)->next = newNode;
	*node = newNode;
	return 1;
}

int intercalar(List l1, List l2, List *l3){
	if(!emptyList(*l3)) esvaziaLista(*l3);

	int ch = 1;
	List tmp3 = NULL;

	while( (l1->next != NULL) && (l2->next != NULL) ){
		if( l1->next->info <= l2->next->info ){
			if(!inserePos(&tmp3, l1->next->info))
				return 0;
			l1 = l1->next;

		}else{
			if(!inserePos(&tmp3, l2->next->info))
				return 0;
			l2 = l2->next;
		}
		if(ch){
			(*l3)->next = tmp3; 
			ch = 0;
		}
		(*l3)->tam ++;
		// (*l3)->maior = tmp3->info;
	}

	while(l1->next != NULL){
		if(!inserePos(&tmp3, l1->next->info))
			return 0;
		l1 = l1->next;
		if(ch){
			(*l3)->next = tmp3; ch = 0;
		}
		(*l3)->tam ++;
		// (*l3)->maior = tmp3->info;
	}

	while(l2->next != NULL){
		if(!inserePos(&tmp3, l2->next->info))
			return 0;
		l2 = l2->next;
		if(ch){
			(*l3)->next = tmp3; ch = 0;
		}
		(*l3)->tam ++;
		// (*l3)->maior = tmp3->info;
	}
	(*l3)->maior = tmp3->info;
}

int esvaziaLista(List lst){
	if( emptyList(lst) ) return 0;

	List tmp = lst->next, tmp2; // tmp == primeiro node
	while( tmp != NULL ){
		tmp2 = tmp;
		tmp = tmp->next;
		free(tmp2);
	}

	lst->tam = 0;
	lst->maior = 0;
	lst->next = NULL;

	return 1;
}

// void intercalar(List L, List L2, List L3){
// 	// L3 contem elemento, logo tenho que limpar antes de intercalar
// 	if( !emptyList(L3) && esvaziaLista(L3) )
// 		printf("Lista 3 limpa, intercalando...\n");
	
// 	// primeiro copiar L para L3
// 	// trata primeiro node separado, se L tiver pelo menos 1 node
// 	int a;

// 	while( L->next != NULL ){
// 		L = L->next;
// 		a = insertOrd(L3, L->info);
// 	}

// 	while( L2->next != NULL ){
// 		L2 = L2->next;
// 		a = insertOrd(L3, L2->info);
// 	}
// }