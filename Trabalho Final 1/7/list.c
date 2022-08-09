// ex7
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "list.h"

struct node{
	char nome[20];
	struct node* next;

};

void _alloc_check(const void* tmp){
	if(tmp == NULL){
		perror("Erro na alocacao do soldado!");
		exit(EXIT_FAILURE);
	}
}

List _cria_lista(){ return NULL; }

int _lista_vazia(const void* lst){
	// lista vazia so tem cabecalho
	if(lst == NULL)
		return 1;
	else
		return 0;	
}

int _insere_soldado(List* lst, char nome_sld[]){
	// insere soldado no final
	List node = (List) malloc(sizeof(struct node));
	_alloc_check(node);

	strcpy(node->nome, nome_sld);
	if(_lista_vazia(*lst))
		node->next = node; // node aponta para ele mesmo	

	else{
		node->next = (*lst)->next; // aponta para o primeiro node
		(*lst)->next = node; // add node no final
	}

	*lst = node; // ponteiro para o ultimo node
	return 1;
}

void _remove_cur_next(List cur){
	List tmp = cur->next;
	cur->next = tmp->next;
	free(tmp);
}

void _contador_elimina(List* lst, List cur, int s, int opc, char rem[], List* lst_elim){
	if(cur->next == cur) return; // ja tenho o vencedor

	if(opc > 0){
		// fica um node antras do node que sera usado para
		// iniciar a contagem
		while(opc--)
			cur = cur->next;
	}
	int i = 0;
	while(i < (s-1)){
		cur = cur->next;
		i ++;
	}
	// cur == um node antes do que eu quero remover
	strcpy(rem, cur->next->nome);
	if(cur->next == *lst) *lst = cur; // se o node a ser removido for o ultimo
	_remove_cur_next(cur);
	_insere_soldado(lst_elim, rem);

	_contador_elimina(lst, cur, s, opc, rem, lst_elim);
}

void _get_elem(List lst, int pos, int qntd_sold, char nome[]){
	// se pos sorteada for a ultima
	if(qntd_sold == pos){
		strcpy(nome, lst->nome);
		return;
	}

	while(pos--)
		lst = lst->next;
	strcpy(nome, lst->next->nome);
}

int _busca_nome(List lst, char nome[], int qntd_sold){
	// dado o nome do soldado, procura-lo na lista e retornar seu indice
	if( !(strcmp(nome, lst->nome)) ) return qntd_sold; // trata ultimo soldado
	int i = 0; List tmp = lst;
	while(tmp->next != lst && strcmp(tmp->next->nome, nome) != 0){
		tmp = tmp->next;
		i ++;
	}

	if(i < qntd_sold) return i;
	else return -1; // soldado n esta na lista
}

void _printa_lista(List lst){
	List ult = lst;
	while(lst->next != ult){
		printf("%s, ", lst->next->nome);
		lst = lst->next;
	}
	printf("%s.", ult->nome);
}

void _limpa_lista(List* lst){
	List tmp = *lst;
	*lst = (*lst)->next;
	tmp->next = NULL;
	while(*lst != NULL){
		tmp = *lst;
		*lst = (*lst)->next;
		free(tmp);
	}
}