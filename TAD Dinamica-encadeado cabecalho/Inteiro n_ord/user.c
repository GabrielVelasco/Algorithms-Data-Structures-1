#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "app.h"

/*
gcc -c user.c
gcc -c app.c
gcc -o a user.c app.c

input:
0 3 1 4 1 8 1 -1 1 19 1 2 1 7 1 8 1 5 1 9 1 22 1 45 3 2 8 3 0 3

*/

int main(){
	List L;
	int num, ch = 0, idx, size, opc;

	while(1){
		printf("\n[0] Initialize list\n");
		printf("[1] Insert\n");
		printf("[2] Remove\n");
		printf("[3] Print list\n");
		printf("[4] Consult\n");
		printf("[5] Clear list\n");
		printf("[Any] Quit\n");
		printf("\nChoose an option: ");
		scanf("%d", &opc);

		switch(opc){
			case 0:
				L = createList(); // cria cabecalho, lista vazia (sem node) 
				printf("\nLista criada\n");

				break;

			case 1:
				printf("\nInserir numero: ");
				scanf("%d", &num);

				if( insertElem(L, num) )
					printf("Elemento inserido com sucesso!\n");
				else
					printf("Erro ao inserir elemento na lista!\n");

				break;

			case 2:
				printf("\nRemover numero: ");
				scanf("%d", &num);
				if( removeElem(L, num) )
					printf("Elemento removido com sucesso!\n");
				else
					printf("Erro ao remover elemento da lista!\n");

				break;

			case 3:
				if( !ch || emptyList(L) )
					printf("\nLista nao inicializada ou vazia\n");
				else{
					size = getSize(L);
					for(int i = 0; i < size; i++)
						printf("[%d] ", getElem(L, i));
					printf("\n");	
				}

				break;

			case 4:
				if( !ch || emptyList(L) )
					printf("Lista nao inicializada ou vazia\n");
				else{
					printf("Digite a posicao de consulta: ");
					scanf("%d", &idx);
					printf("Elemento de [%d]: %d\n", idx, getElem(L, idx));
				}

				break;

			case 5:
				if( !ch || emptyList(L) )
					printf("Lista ja limpa ou nao inicializada\n");
				
				if( clearList(&L) )
					printf("Lista limpa!\n");
				else
					printf("Erro ao limpar a lista\n");
				break;

			default:
				ch = 2;
		}

		if(!ch) ch = 1;
		if(ch == 2) break;
	}

	return 0;
}