/*
		TAD Lista n ord de alunos:
	Dados: matric, nome, media, faltas
	Lista de Op: createList, emptyList, fullList, insertElem, removeElem, getPos
	getSize

	Op:
		createList: inicializa lista sem node (L = NULL)
		emptyList: verifica se a lista esta vazia
		fullList: verifica se a lista esta cheia
		insert: insere node na primeira pos
		remove: remove certo por matricula
		getPos: retorna o valor do elem na posicao indicada
		getSize: retorna tamanho da lista

gcc -c user.c
gcc -c app.c
gcc -o a user.c app.c

*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "app.h"

int main(){
	ui matr;
	char name[15];
	float mean;
	int missed;

	int opc, num, ch = 0, idx, size;
	List* L;

	while(1){
		printf("\n[0] Initialize list\n");
		printf("[1] Insert\n");
		printf("[2] Remove\n");
		printf("[3] Print list\n");
		printf("[4] Consult\n");
		printf("[5] Clear list\n");
		printf("[6] List size\n");
		printf("[Any] Quit\n");
		printf("\nChoose an option: ");
		scanf("%d", &opc);

		switch(opc){
			case 0:
				L = createList(); // cria lista vazia 
				printf("\nLista criada\n");

				break;

			case 1:
				printf("\nDigite matricula, nome, media e faltas: ");
				scanf("%u", &matr);
				scanf(" %[^\n]", name);
				scanf("%f", &mean);
				scanf("%d", &missed);

				if( insertElem(&L, matr, name, mean, missed) )
					printf("Elemento inserido com sucesso!\n");
				else
					printf("Erro ao inserir elemento na lista!\n");

				break;

			case 2:
				printf("\nDigite o numero da matricula do aluno a ser removido: ");
				scanf("%u", &matr);
				if( removeElem(&L, matr) )
					printf("Elemento removido com sucesso!\n");
				else
					printf("Erro ao remover elemento da lista!\n");

				break;

			case 3:
				if( !ch || emptyList(L) )
					printf("\nLista vazia\n");
				else{
					size = getSize(L);
					for(int i = 0; i < size; i++){
						if( getPos(L, i, &matr, name, &mean, &missed) )
							printf("[%d] - %u %s %.2f %d\n", i, matr, name, mean, missed);
						else
							printf("Erro ao printar elemento [%d]\n", i);
					}
					printf("FIM\n");
				}

				break;

			case 4:
				if( !ch || emptyList(L) )
					printf("Lista vazia\n");
				else{
					printf("Digite a posicao de consulta: ");
					scanf("%d", &idx);
					if( getPos(L, idx, &matr, name, &mean, &missed) )
						printf("Elemeno de [%d]: %u %s %.2f %d\n", idx, matr, name, mean, missed);
					else
						printf("Erro ao consultar elemento\n");
				}

				break;

			case 5:
				if( emptyList(L) )
					printf("Lista ja limpa\n");
				
				if( clearList(&L) )
					printf("Lista limpa!\n");
				else
					printf("Erro ao limpar a lista\n");
				break;

			case 6:
				printf("Tamanho da lista: %d\n", getSize(L));
				break;

			default:
				return 0;
		}
		if(!ch) ch = 1;
	}

	return 0;
}