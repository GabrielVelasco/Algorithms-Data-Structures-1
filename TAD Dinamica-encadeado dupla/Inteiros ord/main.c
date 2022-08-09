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
	int elem;
	List L;

	while(1){
		printf("\n==================================\n");
		printf("[0] Initialize list\n");
		printf("[1] Insert\n");
		printf("[2] Remove\n");
		printf("[3] Print list\n");
		printf("[4] Consult\n");
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
				scanf("%d", &elem);
				if(insertOrd(&L, elem))
					printf("Elemento inserido com sucesso!\n");
				else
					printf("Erro ao inserir elemento na lista!\n");

				break;

			case 2:
				printf("\nDigite o elemento a ser removido:\n");
				scanf("%d", &elem);
				if(removeOrd(&L, elem))
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
					if(getElem(L, idx, &elem))
						printf("Elemento da posicao [%d]: %d\n", idx, elem);
					else
						printf("Erro ao consultar elemento\n");
				}

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