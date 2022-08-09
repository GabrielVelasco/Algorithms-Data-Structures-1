// ex 4
// lista ORDENADA de caracteres COM cabecalho
#include <stdlib.h>
#include <stdio.h>
#include "list.h"

int main(){
	int opc, ch = 0, idx;
	char elem;
	List L, L2, L3; // ponteiro para o cabecalho da lista

	while(1){
		printf("\n======================MENU=========================================\n");
		printf("[0] Cria Listas                     [7] Limpa lista 1\n");
		printf("[1] Insere elemento na lista 1      [8] Limpa lista 2\n");
		printf("[2] Remover elemento da lista 1     [9] Limpa lista 3\n");
		printf("[3] Insere elemento na lista 2      [10] Maior elemento da lista 1\n");
		printf("[4] Remover elemento da lista 2     [11] Comparar Lista 1 e Lista 2\n");
		printf("[5] Imprimir listas                 [12] Intercalar Lista 1 e Lista 2\n");
		printf("[6] Consultar elemento na lista 1   [13] Tamanho da lista 1\n");
		printf("\nEscolha uma opcao: ");
		scanf("%d", &opc); getchar();


		switch(opc){
			case 0:
				L = createList(); // retorna cabecalho sem node (lista vazia)
				L2 = createList();
				L3 = createList();
				printf("\nLista criada\n");
				break;

			case 1:
				printf("\nLista 1, digite o elemento a ser inserido:\n");
				scanf("%c", &elem);
				if(insertOrd(L, elem))
					printf("Elemento inserido com sucesso!\n");
				else
					printf("Erro ao inserir elemento na lista!\n");
				break;

			case 2:
				printf("\nLista 1, digite o elemento a ser removido:\n");
				scanf("%c", &elem);
				if(removeOrd(L, elem))
					printf("Elemento removido com sucesso!\n");
				else
					printf("Erro ao remover elemento da lista!\n");
				break;

			case 3:
				printf("\nLista 2, digite o elemento a ser inserido:\n");
				scanf("%c", &elem);
				if(insertOrd(L2, elem))
					printf("Elemento inserido com sucesso!\n");
				else
					printf("Erro ao inserir elemento na lista!\n");
				break;

			case 4:
				printf("\nLista 2, digite o elemento a ser removido:\n");
				scanf("%c", &elem);
				if(removeOrd(L2, elem))
					printf("Elemento removido com sucesso!\n");
				else
					printf("Erro ao remover elemento da lista!\n");
				break;


			case 5:
				// printa lista 1
				if( !ch || emptyList(L) )
					printf("Lista 1: vazia\n");
				else{
					printf("Lista 1: ");
					imprimiLista(L);
					printf("\n");
				}

				// printa lista 2
				if( !ch || emptyList(L2) )
					printf("Lista 2: vazia\n");
				else{
					printf("Lista 2: ");
					imprimiLista(L2);
					printf("\n");
				}

				// printa lista 3
				if( !ch || emptyList(L3) )
					printf("Lista 3: vazia\n");
				else{
					printf("Lista 3: ");
					imprimiLista(L3);
					printf("\n");
				}
				break;

			case 6:
				if( !ch || emptyList(L) )
					printf("\nLista vazia ou nao inicializada\n");
				else{
					printf("Digite a posicao que deseja consultar: \n");
					scanf("%d", &idx);
					if(getElem(L, idx, &elem))
						printf("Elemento da posicao [%d]: %c\n", idx, elem);
					else
						printf("Erro ao consultar elemento\n");
				}
				break;

			case 7:
				if( !ch )
					printf("Lista 1 nao inicializada\n");
				if(esvaziaLista(L))
					printf("Lista 1 limpa!\n");
				else
					printf("Lista 1 vazia!\n");
				break;

			case 8:
				if( !ch )
					printf("Lista 2 nao inicializada\n");
				if(esvaziaLista(L2))
					printf("Lista 2 limpa!\n");
				else
					printf("Lista 2 vazia!\n");
				break;

			case 9:
				if( !ch )
					printf("Lista 3 nao inicializada\n");
				if(esvaziaLista(L3))
					printf("Lista 3 limpa!\n");
				else
					printf("Lista 3 vazia!\n");
				break;

			case 10:
				if( !ch )
					printf("\nLista nao inicializada\n");
				else{
					if( maiorElem(L, &elem) )
						printf("Maior elemento: %c\n", elem);
					else
						printf("Lista vazia!\n");
				}
				break;

			case 11:
				if( !ch || (emptyList(L) && emptyList(L2)) )
					printf("Listas nao inicializadas ou vazias\n");
				else if( comparaLista(L, L2) )
					printf("Listas iguais\n");
				else
					printf("Listas diferentes\n");
				break;

			case 12:
				if( !ch || ((emptyList(L) && emptyList(L2))) )
					printf("Listas vazias ou nao inicializadas.\n");
				else if(intercalar(L, L2, &L3))
					printf("Listas 1 e 2 intercaladas, printar lista 3.\n");
				break;

			case 13:
				printf("[%d] elementos\n", getSize(L));
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