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

int insertElem(List* *lst, char elem){
	// *lst == end memo do ponteiro p/ primeiro node
	// nao ordenado insere sempre antes do primeiro atual (lst)
	// que passará a ser o segundo ao final da execucao
	// primeiro cria o node a ser inserido e atribui os valores

	List* node = (List*) malloc(sizeof(List));
	if(node == NULL) return 0; // node nao alocado por falta de memoria
	
	node->info = elem;
	node->next = *lst; // atual primeiro node passa a ser o segundo
	*lst = node; // node passa a ser o novo primeiro

	return 1;
}

int removeElem(List* *lst, char elem){
	if(emptyList(*lst)) return 0;

	// verf se o primeiro elem da lista é o alvo
	if( (*lst)->info == elem ){
		List* tmp = *lst; // tmp = atual peimeiro node
		*lst = tmp->next; // primeiro node passa a ser o atual segundo
		free(tmp); // deleta node que era o primeiro
		return 1;
	}

	// elem pode estar mais a direito, percorrer
	List* tmp = *lst; // tmp = atual peimeiro node
	while(tmp->next != NULL && tmp->next->info != elem)
		tmp = tmp->next; // avanca para proximo node

	if(tmp->next == NULL) return 0; // chegou no final da lista, nao achou elem
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
	while(tmp->next != NULL && tmp->next->info != elem)
		tmp = tmp->next;

	return tmp->next;
}

char getElem(List* *lst){ // lst = &piv
	// piv aponta para o node a ser printado
	// modifica *elem para que ele possa ser impresso em user.c
	// usada para imprimir lista
	// *lst == conteudo q esta dentro do end de mem de piv

	List* tmp = *lst; // tmp aponta para o msm node de piv
	*lst = (*lst)->next;
	return tmp->info;
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