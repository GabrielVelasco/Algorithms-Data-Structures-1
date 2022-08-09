/*
		TAD Lista nao ordenada de string:
	Dados: strings
	Lista de Op: cria_lista, lista_vazia, lista_cheia, insere_str, remove_str, get_pos

	Op:
		createList: aloca lista
		emptyList: verifica se a lista esta vazia
		fullList: verifica se a lista esta cheia
		insertElem: insere elem na ultima pos
		removeElem: remove certo elem da lista
		get_pos: retorna str da pos solicitada
		clearList: libera lista

gcc -c user.c
gcc -c app.c
gcc -o a user.c app.c

*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "app.h"

int main(){
	int opc;
	List* L = NULL;

	while(1){
		printf("\n[0] Create list\n");
		printf("[1] Insert\n");
		printf("[2] Remove\n");
		printf("[3] Print list\n");
		printf("[4] Consult\n");
		printf("[5] Clean list\n");
		printf("[Any] Quit\n");
		printf("\nChose an option: ");
		scanf("%d", &opc);
		char elem[12];
		int idx, s;

		switch(opc){
			case 0:
				L = createList(); // cria lista vazia (sem nodes)
				printf("\nLista criada\n");

				break;

			case 1:
				printf("\nDigite o elemento a ser inserido: ");
				scanf(" %[^\n]", elem);
				if(insertStr(L, elem))
					printf("Elemento inserido com sucesso!\n");
				else
					printf("Erro ao inserir elemento na lista!\n");

				break;

			case 2:
				printf("\nDigite o elemento a ser removido: ");
				scanf(" %[^\n]", elem);
				if(removeStr(L, elem))
					printf("Elemento removido com sucesso!\n");
				else
					printf("Erro ao remover elemento da lista!\n");

				break;

			case 3:
				if(emptyList(L))
					printf("\nLista vazia\n");
				else{
					int i = 0, s = getSize(L);
					while(i < s){
						printf("%s\n", getPos(L, i));
						i ++;
					}
				}

				break;

			case 4:
				printf("Digite a posicao de consulta: ");
				scanf("%d", &idx);
				s = getSize(L);
				if(idx < s){
					strcpy(elem, getPos(L, idx));
					printf("%s\n", elem);
				}else
					printf("Erro ao consultar\n");

				break;

			case 5:
				if(clearList(&L))
					printf("Lista Limpa com sucesso!\n");
				else
					printf("\nErro ao Limpar lista!\n");
				break;

			default:
				return 0;
		}

	}

	return 0;
}