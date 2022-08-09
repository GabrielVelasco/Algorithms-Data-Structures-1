#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "donators.h"
#include "queue.h"

struct node{
	char nome[150], orgao[15];
	int idade, grau; 
	struct node* next;

};

void _alloc_check(const void* p, const void* msg){
	if(p == NULL){
		perror(msg);
		exit(EXIT_FAILURE);
	}
}

Queue _create_list(){
	return NULL; // inicializa lista sem nenhum node
}

int _is_empty(const void *qu){
	// qu == ponteiro para ultimo node
	if(qu == NULL)
		return 1;
	else
		return 0;
}

int _is_available(Queue *qu, char orgao[]){
	/// se orgao estiver na fila de disponibilidade, paciente ja eh transplantado
	/// e orgao eh deletado da fila de disponibilidade
	if(_is_empty(*qu)) return 0;

	Queue tmp = *qu, tmp2;
	while(tmp->next != *qu && strcmp(tmp->next->orgao, orgao) != 0)
		tmp = tmp->next;

	if(strcmp(tmp->next->orgao, orgao) == 0){
		tmp2 = tmp->next;
		if(tmp->next == tmp){
			*qu = NULL;
		}else{
			tmp->next = tmp2->next;
			if(tmp2 == *qu)
				*qu = tmp;
		}

		free(tmp2);

		return 1;
	}

	return 0;
}

int _pop_name(Queue *qu, char nome[]){
	/// remover elemento da fila por nome, 'nome' ja foi transplantado
	if(_is_empty(*qu))	return 0; /// orgao vai para fila de disponibilidade

	Queue tmp = *qu, tmp2;
	while(tmp->next != *qu && strcmp(tmp->next->nome, nome) != 0)
		tmp = tmp->next;

	if(strcmp(tmp->next->nome, nome) == 0){
		tmp2 = tmp->next;
		if(tmp->next == tmp){
			*qu = NULL;
		}else{
			tmp->next = tmp2->next;
			if(tmp2 == *qu)
				*qu = tmp;
		}

		free(tmp2);

		return 1;
	}

	/// se nome n existir na fila, orgao vai para o primeiro (grau de gravidade maior)
	tmp = (*qu)->next; // aponta p/ node a ser removido
	strcpy(nome, tmp->nome); /// copia nome do paciente transplantado
	if(*qu == (*qu)->next)
		*qu = NULL; // fila com um unico node
	else
		(*qu)->next = tmp->next;
	free(tmp);
	
	return 1;
}

int _push_patient(Queue *qu, char nome[], char orgao[], int idade, int grau){
	// cria o node e atribui
	Queue node = (Queue) malloc(sizeof(struct node));
	_alloc_check(node, "Error while allocating node, func _push!");

	strcpy(node->nome, nome);
	strcpy(node->orgao, orgao);
	node->idade = idade;
	node->grau = grau;

	// qu == ponteiro para ultimo node
	if(_is_empty(*qu)){
		// node será o primeiro e ultimo
		node->next = node;
		*qu = node;
	
	}else if(grau <= (*qu)->grau){
		/// ordem descendente de grau, logo node instanciado vai na ultima pos.
		node->next = (*qu)->next; // node aponta p/ primeiro
		(*qu)->next = node;
		*qu = node;
	
	}else{
		/// percorrer fila
		Queue tmp = *qu;
		while(tmp->next != *qu && tmp->next->grau >= grau){
			tmp = tmp->next;
		}
		node->next = tmp->next;
		tmp->next = node;
	}

	return 1;
}

int _push_back(Queue *qu, char orgao[]){
	/// add orgao na fila de disponibilidade
	Queue node = (Queue) malloc(sizeof(struct node));
	_alloc_check(node, "Error while allocating node, func _push_back!");
	strcpy(node->orgao, orgao);

	if(_is_empty(*qu)){
		// node será o primeiro e ultimo
		node->next = node;
		*qu = node;
	
	}else{
		node->next = (*qu)->next; // node aponta p/ primeiro
		(*qu)->next = node;
		*qu = node; /// novo ultimo node
	}

	return 1;
}

int _pop_front(Queue *qu, char nome[]){
	if(_is_empty(*qu)) return 0;

	Queue tmp = (*qu)->next; // aponta p/ node a ser removido
	strcpy(nome, tmp->nome); /// copia nome do paciente transplantado
	if(*qu == (*qu)->next)
		*qu = NULL; // fila com um unico node
	else
		(*qu)->next = tmp->next;
	free(tmp);

	return 1;
}

int _print_patient_queue(Queue *qu){
	if(_is_empty(*qu)) return 0;
	int cont = 1;
	Queue tmp = (*qu)->next;
	while(tmp != *qu){
		_print_patient_node(tmp->nome, tmp->orgao, tmp->idade, tmp->grau, cont);
		tmp = tmp->next;
		cont ++;
	}
	_print_patient_node(tmp->nome, tmp->orgao, tmp->idade, tmp->grau, cont);
	return 1;
}

int _print_disp_queue(Queue *qu){
	if(_is_empty(*qu)) return 0;
	Queue tmp = (*qu)->next;
	while(tmp != *qu){
		_print_disp_node(tmp->orgao, 0);
		tmp = tmp->next;
	}
	_print_disp_node(tmp->orgao, 1);
	return 1;
}

int _clear_patient_queue(Queue *qu){
	if(_is_empty(*qu)) return 0;
	Queue tmp = (*qu)->next, tmp2;
	while(tmp != *qu){
		tmp2 = tmp;
		tmp = tmp->next;
		free(tmp2);
	}
	free(tmp);
	*qu = NULL;

	return 1;
}