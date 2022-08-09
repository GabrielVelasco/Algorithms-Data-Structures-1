/*
gcc -c app.c
gcc -c list.c
gcc -o a app.c list.c

*/

#include <stdlib.h>
#include <stdio.h>
#include "list.h"

int main(){
	int opc, ch = 0, idx;
	float elem;
	List L;

	while(1){
		printf("\n==================================\n");
		printf("[0] Initialize list\n");
		printf("[1] Insert\n");
		printf("[2] Remove\n");
		printf("[3] Print list\n");
		printf("[4] Consult\n");
		printf("[5] Insert Final\n");
		printf("[6] Remove Beginning\n");
		printf("[7] Clear List\n");
		printf("[Any] Quit\n");
		printf("\nChoose an option: ");
		scanf("%d", &opc);


		switch(opc){
			case 0:
				L = createList();
				printf("\nLista criada\n");

				break;

			case 1:
				printf("\nDigite o elemento a ser inserido:\n");
				scanf("%f", &elem);
				if(insertRecOrd(&L, elem))
					printf("Elemento inserido com sucesso!\n");
				else
					printf("Erro ao inserir elemento na lista!\n");

				break;

			case 2:
				printf("\nDigite o elemento a ser removido:\n");
				scanf("%f", &elem);
				if(removeRecOrd(&L, elem))
					printf("Elemento removido com sucesso!\n");
				else
					printf("Erro ao remover elemento da lista!\n");

				break;

			case 3:
				// printa lista 1
				if( !ch || emptyList(L) )
					printf("Lista: vazia\n");
				else{
					printf("Lista: ");
					imprimiLista(L);
					printf("\n");
				}

				break;

			case 4:
				if( !ch )
					printf("\nLista vazia nao inicializada\n");
				else{
					printf("Digite a posicao que deseja consultar: \n");
					scanf("%d", &idx);
					int size = getSize(L);
					if(getPos(L, idx, 0, &elem, size))
						printf("Elemento da posicao [%d]: %.2f\n", idx, elem);
					else
						printf("Erro ao consultar elemento\n");
				}

				break;

			case 5:
				printf("\nDigite o elemento a ser inserido no final:\n");
				scanf("%f", &elem);
				if(insertFinal(&L, elem))
					printf("Elemento inserido com sucesso!\n");
				else
					printf("Erro ao inserir elemento na lista!\n");

				break;

			case 6:
				if(removeInit(&L))
					printf("Elemento inicio removido com sucesso!\n");
				else
					printf("Erro ao remover elemento da lista!\n");

				break;

			case 7:
				clearList(&L);
				printf("Lista limpa\n");

				break;

			default:
				ch = 2;

				break;
		}

		if(!ch) ch = 1;
		if(ch == 2) break;
	}

	return 0;
}