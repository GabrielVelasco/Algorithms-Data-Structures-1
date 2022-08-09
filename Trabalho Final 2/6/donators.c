#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "donators.h"
#include "queue.h"

struct node_doadores{
	char nome[150];
	char orgao_benef[10][300]; /// orgao_benef[i] == "Doou orgao para benef"
	struct node_doadores* next;

};

Qu_don _create_list_d(){
	return NULL; // inicializa lista sem nenhum node
}

int _push_back_donator(Qu_don *qu, char nome[], char arr_str[][300], int j){
	/// add doador na fila de doadores
	Qu_don node = (Qu_don) malloc(sizeof(struct node_doadores));
	_alloc_check(node, "Error while allocating node, func _push_donator!");

	strcpy(node->nome, nome);
	/// copia cada orgao doado e beneficiado
	int i = 0;
	for(i = 0; i < j; i++){
		strcpy(node->orgao_benef[i], arr_str[i]);
	}
	strcpy(node->orgao_benef[i], "##");

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

int _print_donator_queue(Qu_don *qu){
	if(_is_empty(*qu)) return 0;
	Qu_don tmp = (*qu)->next;
	while(tmp != *qu){
		_print_don_node(tmp->nome, tmp->orgao_benef);
		tmp = tmp->next;
	}
	_print_don_node(tmp->nome, tmp->orgao_benef);
	return 1;
}

int _clean_don_queue(Qu_don *qu){
	if(_is_empty(*qu)) return 0;
	Qu_don tmp = (*qu)->next, tmp2;
	while(tmp != *qu){
		tmp2 = tmp;
		tmp = tmp->next;
		free(tmp2);
	}
	free(tmp);
	*qu = NULL;

	return 1;
}