// utilizado pelo usuario

/*
		TAD Lista nao Ord:
	Dados: lista de numeros reais max 20
	Lista de Op: cria_lista, lista_vazia, lista_cheia, insere_elem, remove_elem
				 limpa_lista, get_pos

	Op:
		cria_lista: aloca lista na memoria
		lista_vazia: verifica se a lista esta vazia
		lista_cheia: verifica se a lista esta cheia
		insere_elem: adiciona elemento na lista (ultima pos)
		remove_elem: remove certo elem da lista
		limpa_lista: libera memoria
		geT_pos: pega posicao de um certo elemento

	gcc -c user.c
	gcc -c app.c

	gcc -o "nome exec" user.c app.c
*/

#include <stdlib.h>
#include <stdio.h>
#include "app.h"

int main(){
	int opc;
	Lista *l1 = NULL;

	while(1){
		printf("[0] Cria lista\n");
		printf("[1] Insere elemento na lista\n");
		printf("[2] Remover elemento da lista\n");
		printf("[3] Imprimir lista\n");
		printf("[4] Pegar posicao de algum elemento\n");
		printf("[5] Sair\n");
		printf("\nEscolha uma opcao:\n");
		scanf("%d", &opc);
		
		if(opc == 5) break;
		if(opc == 0){
			l1 = cria_lista();
			if(l1 == NULL){
				printf("Erro ao inicializar a lista!\n");
				exit(1);
			}
			printf("Lista criada\n");
		}

		if(opc == 1){
			float elem;
			printf("Digite o elemento a ser inserido:\n");
			scanf("%f", &elem);
			if(insere_elem(l1, elem))
				printf("Elemento inserido com sucesso!\n");
			else
				printf("Erro ao inserir elemento na lista!\n");
		}

		if(opc == 2){
			float elem;
			printf("Digite o elemento a ser removido:\n");
			scanf("%f", &elem);
			if(remove_elem(l1, elem))
				printf("Elemento removido com sucesso!\n");
			else
				printf("Erro ao remover elemento da lista!\n");
		}

		if(opc == 3){
			if(lista_vazia(l1))
				printf("Lista vazia\n");
			else{
				float elem;
				int idx = 0;
				while(get_elem(l1, &idx, &elem)){
					printf("%.2f ", elem);
				}
				printf("\nFIM!\n");
			}
		}

		if(opc == 4){
			float elem;
			printf("Digite o elemento que deseja achar:\n");
			scanf("%f", &elem);
			int pos;
			if(get_pos(l1, elem, &pos))
				printf("Elemento %.2f esta na posicao [%d]\n", elem, pos);
			else
				printf("Erro ao consultar posicao\n");
		}

	}

	return 0;
}