#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "app.h"

/*
gcc -c user.c
gcc -c app.c
gcc -o a user.c app.c

input:
0 3 1 4 1 8 1 -1 1 19 1 2 1 7 1 8 1 5 1 9 1 22 1 45 3 2 3 0 3

*/

int main(){
	List L;
	int num, ch = 0, idx, size, opc;

	while(1){
		printf("\n[0] Initialize list\n");
		printf("[1] Insert Beginning\n");
		printf("[2] Insert Final\n");
		printf("[3] Remove Beginning\n");
		printf("[4] Remove Final\n");
		printf("[5] Print list\n");
		printf("[6] Consult\n");
		printf("[Any] Quit\n");
		printf("\nChoose an option: ");
		scanf("%d", &opc);

		switch(opc){
			case 0:
				L = createList();
				printf("\nLista criada\n");

				break;

			case 1:
				printf("\nInserir inicio: ");
				scanf("%d", &num);

				if( insertBegi(&L, num) )
					printf("Elemento inserido com sucesso!\n");
				else
					printf("Erro ao inserir elemento!\n");

				break;

			case 2:
				printf("\nInserir final: ");
				scanf("%d", &num);

				if( insertFinal(&L, num) )
					printf("Elemento inserido com sucesso!\n");
				else
					printf("Erro ao inserir elemento na lista!\n");

				break;

			case 3:
				printf("\nRemover inicio: ");
				if( removeIni(&L, &num) ) // remocao posicional
					printf("Elemento [%d] removido!\n", num);
				else
					printf("Erro ao remover elemento da lista!\n");

				break;

			case 4:
				printf("\nRemover final: ");
				if( removeFinal(&L, &num) ) // remocao posicional
					printf("Elemento [%d] removido!\n", num);
				else
					printf("Erro ao remover elemento da lista!\n");

				break;

			case 5:
				if( !ch || emptyList(L) )
					printf("\nLista nao inicializada ou vazia\n");
				else{
					idx = 0;
					while( getElem(L, idx, &num) ){
						printf("[%d] ", num);
						idx ++;
					} 
					printf("\n");	
				}

				break;

			case 6:
				if( !ch || emptyList(L) )
					printf("Lista nao inicializada ou vazia\n");
				else{
					printf("Digite a posicao de consulta: ");
					scanf("%d", &idx);
					if( getElem(L, idx, &num) )
						printf("Elemento de [%d]: %d\n", idx, num);
					else
						printf("Erro ao consultar elemento [%d]\n", idx);
					
				}

				break;

			default:
				ch = 2;
		}

		if(!ch) ch = 1;
		if(ch == 2) break;
	}

	return 0;
}