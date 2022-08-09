/*
		TAD Lista Nao Ordenada Caracteres:
	Dados: Caracteres
	Lista de Op: cria_lista, lista_vazia, lista_cheia, insere_ord, remove_ord
				 limpa_lista, get_pos

	Op:
		cria_lista: aloca lista na memoria apontando para NULL (sem nós)
		lista_vazia: verifica se a lista esta vazia
		lista_cheia: verifica se a lista esta cheia
		insere_elem: insere elem antes do atual 1° elemento 
		remove_elem: remove certo elem da lista
		get_pos: pega posicao (end memoria) de um certo elemento
		limpa_lista: libera memoria (libera os nós e lst = NULL)

gcc -c user.c
gcc -c app.c
gcc -o a user.c app.c
gcc -o "nome exec" user.c app.c
*/

#include <stdlib.h>
#include <stdio.h>
#include "app.h"

int main(){
	int opc;
	List* L; // ponteiro para o primeiro node da lista

	while(1){
		printf("\n[0] Cria lista\n");
		printf("[1] Insere elemento na lista\n");
		printf("[2] Remover elemento da lista\n");
		printf("[3] Imprimir lista\n");
		printf("[4] Pegar posicao de algum elemento\n");
		printf("[5] Limpa lista\n");
		printf("[6] Sair\n");
		printf("\nEscolha uma opcao: ");
		scanf("%d", &opc); getchar();
		
		if(opc == 6) break;
		if(opc == 0){
			L = createList(); // cria lista vazia (sem nodes)
			printf("\nLista criada\n");
		}

		if(opc == 1){
			char elem;
			printf("\nDigite o elemento a ser inserido:\n");
			scanf("%c", &elem); getchar();
			if(insertElem(&L, elem))
				printf("Elemento inserido com sucesso!\n");
			else
				printf("Erro ao inserir elemento na lista!\n");
		}

		if(opc == 2){
			char elem;
			printf("\nDigite o elemento a ser removido:\n");
			scanf("%c", &elem); getchar();
			if(removeElem(&L, elem))
				printf("Elemento removido com sucesso!\n");
			else
				printf("Erro ao remover elemento da lista!\n");
		}

		if(opc == 3){
			if(emptyList(L))
				printf("\nLista vazia\n");
			else{
				List* piv = L;
				while(piv != NULL){
					printf("%c \n", getElem(&piv));
				}

				free(piv);
				printf("\nFIM!\n");
			}
		}

		if(opc == 4){
			printf("\nFunc inoperante:\n");
		}

		if(opc == 5){
			if(clearList(&L))
				printf("Lista Limpa com sucesso!\n");
			else
				printf("\nErro ao Limpar lista!\n");
		}

	}

	return 0;
}