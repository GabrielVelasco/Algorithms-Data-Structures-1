/*
		TAD Lista ordenada decrescente de numeros:
	Dados: numeros
	Lista de Op: createList, emptyList, fullList, insertOrd, removeOrd, get_pos

	Op:
		createList: inicializa lista sem node (L = NULL)
		emptyList: verifica se a lista esta vazia
		fullList: verifica se a lista esta cheia
		insertOrd: insere elem na posicao
		removeOrd: remove certo elem da lista
		get_pos: retorna o valor do elem na posicao indicada

gcc -c user.c
gcc -c app.c
gcc -o a user.c app.c

*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "app.h"

int main(){
	int opc, num, ch = 0, idx;
	List* L;

	while(1){
		printf("\n[0] Initialize list\n");
		printf("[1] Insert\n");
		printf("[2] Remove\n");
		printf("[3] Print list\n");
		printf("[4] Consult\n");
		printf("[5] Remove element by positon\n");
		printf("[Any] Quit\n");
		printf("\nChoose an option: ");
		scanf("%d", &opc);

		switch(opc){
			case 0:
				L = createList(); // cria lista vazia 
				printf("\nLista criada\n");

				break;

			case 1:
				printf("\nDigite numero que quer inserir: ");
				scanf("%d", &num);

				if(insertOrd(&L, num))
					printf("Elemento inserido com sucesso!\n");
				else
					printf("Erro ao inserir elemento na lista!\n");

				break;

			case 2:
				printf("\nDigite o numero a ser removido: ");
				scanf("%d", &num);
				if(removeOrd(&L, num))
					printf("Elemento removido com sucesso!\n");
				else
					printf("Erro ao remover elemento da lista!\n");

				break;

			case 3:
				if(!ch || emptyList(L))
					printf("\nLista vazia\n");
				else{
					int size = getSize(L);
					for(int i = 0; i < size; i++)
						printf("%d ", getPos(L, i));				
					printf("\nFIM\n");
				}

				break;

			case 4:
				if(!ch || emptyList(L))
					printf("Lista vazia\n");
				else{
					printf("Digite a posicao de consulta: ");
					scanf("%d", &idx);
					printf("%d \n", getPos(L, idx));
				}

				break;

			case 5:
				if(!ch || emptyList(L))
					printf("Erro ao remover\n");
				else{
					printf("Digite a posicao a remover:\n");
					scanf("%d", &idx);
					printf("[%d] removido\n", removePos(&L, idx));
				}

				break;

			default:
				return 0;
		}
		if(!ch) ch = 1;
	}

	return 0;
}