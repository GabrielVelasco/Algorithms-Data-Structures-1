#include <stdio.h>
#include <stdlib.h>
#include "app.h"

struct node{
	char info;
	List* next;

};

List* createList(){
	// retorna NULL 
	return NULL;
}

int emptyList(List* lst){
	// verifica se E o primeiro node
	if(lst == NULL)
		return 1; // lista vazia
	else
		return 0;
}

// void fullList(List* lst){
// 	// nao existe na dinam/encadeada
// }

int insertOrd(List* *lst, char elem){
	// *lst == end memo do ponteiro p/ primeiro node
	// primeiro cria o node a ser inserido e atribui os valores

	List* node = (List*) malloc(sizeof(List));
	if(node == NULL) return 0; // node nao alocado por falta de memoria
	node->info = elem;

	if(emptyList(*lst) || elem <= (*lst)->info){
		node->next = *lst; // atual primeiro node passa a ser o segundo
		*lst = node; // node passa a ser o novo primeiro

		return 1;
	}
	//printf("YES\n");
	// percorrer para encontrar pos correta
	List* tmp = *lst;
	while(tmp->next != NULL && tmp->next->info < elem)
		tmp = tmp->next;

	node->next = tmp->next;
	tmp->next = node;

	return 1;
}

int removeOrd(List* *lst, char elem){
	if(emptyList(*lst) || elem < (*lst)->info) return 0;
	List* tmp = *lst; // tmp = atual peimeiro node

	// verf se o primeiro elem da lista é o alvo
	if( (*lst)->info == elem ){
		*lst = tmp->next; // primeiro node passa a ser o atual segundo
		free(tmp); // deleta node que era o primeiro
		return 1;
	}

	// elem pode estar mais a direita, percorrer
	while(tmp->next != NULL && tmp->next->info < elem)
		tmp = tmp->next; // avanca para proximo node

	if(tmp->next == NULL || (int)tmp->next->info > (int)elem) 
		return 0; // chegou no final da lista ou nao achou elem
	// cara que vem A DIREITA do node TMP vou remover
	List* tmp2 = tmp->next; // tmp2 = node a ser removido
	tmp->next = tmp2->next;
	free(tmp2);

	return 1;
}

List* getPos(List* lst, char elem){
	if(emptyList(lst)) return 0;
	// retorna o node do elemento procurado
	// verf se elemento procurado esta no primeiro node
	if(lst->info == elem)
		return lst;

	List* tmp = lst;
	while(tmp->next != NULL && tmp->next->info < elem)
		tmp = tmp->next;

	if(tmp->next == NULL || tmp->next->info > elem)

	return tmp->next;
}

char getElem(List* *lst){ // lst = &piv
	// piv aponta para o node a ser printado
	// usada para imprimir lista
	// *lst == conteudo q esta dentro do end de mem de piv

	char a = (*lst)->info;
	*lst = (*lst)->next;
	return a;
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