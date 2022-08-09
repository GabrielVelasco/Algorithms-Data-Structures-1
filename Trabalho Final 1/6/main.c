#include <stdio.h>
#include <stdlib.h>
#include "header.h"

int main(){

    int opc, ch = 0, idx;
    int elem;
    Lista L,L2;

    while(1){
        printf("\n======================MENU=========================================\n");
        printf("[0] Cria Lista                      [6] Inverter lista\n");
        printf("[1] Insere elemento                 [7] Multiplos de 3\n");
        printf("[2] Remover elemento                [8] Imprimir listas\n");
        printf("[3] Remover todos                   [any] Sair\n");
        printf("[4] Remover maior\n");
        printf("[5] Esvaziar listas\n");
        printf("\nEscolha uma opcao: ");
        scanf("%d", &opc);


        switch(opc){
            case 0:
                L = cria_lista(); // cria lista vazia (sem nodes)
                L2 = cria_lista();
                printf("\nLista criada\n");

                break;

            case 1:
                printf("\nDigite o elemento a ser inserido:\n");
                scanf("%d", &elem);
                if(insere_elemento(&L, elem))
                    printf("Elemento inserido com sucesso!\n");
                else
                    printf("Erro ao inserir elemento na lista!\n");

                break;

            case 2:
                printf("\nDigite o elemento a ser removido:\n");
                scanf("%d", &elem);
                if(remove_elemento(&L, elem))
                    printf("Elemento removido com sucesso!\n");
                else
                    printf("Erro ao remover elemento da lista!\n");

                break;

            case 3:
                if(!ch) printf("Lista nao inicializada\n");

                else{
                    printf("\nDigite o elemento a ser removido por completo da lista:\n");
                    scanf("%d", &elem);
                    if(remove_todos(&L, elem))
                        printf("Todas ocorrencias de %d foram removidas.\n", elem);
                    else
                        printf("Erro ao remover!\n");
                }

                break;

            case 4:
                if(!ch)
                    printf("Lista nao inicializada\n");
                else
                    if(remove_maior_elemento(&L, &elem))
                        printf("Maior elemento %d removido da lista.\n", elem);

                break;


            case 5:
                if(esvazia(&L) && esvazia(&L2))
                    printf("Lista esvaziada.\n");
                else
                    printf("Erro ao esvaziar lista.\n");

                break;

             case 6:
                 if(!ch){
                    printf("Lista nao criada\n");
                 }
                 else{
                 printf("Qual lista deseja inverter? 1 ou 2\n");
                 scanf("%d",&elem);
                 if(elem == 1){
                  if(lista_vazia(L)){
                    printf("Lista 1 vazia\n");
                    break;
                  }
                  Lista L3 = cria_lista();
                  L3 = inverter_lista(&L);
                  printa(L3);
                 }
                 if(elem == 2){
                   if(lista_vazia(L2)){
                    printf("Lista 2 vazia\n");
                    break;
                   }
                  Lista L3 = cria_lista();
                  L3 = inverter_lista(&L2);
                  printa(L3);
                 }
                 if(elem != 1 && elem != 2){
                    printf("Entre com uma opcao valida\n");
                 }
                }
                 break;

            case 7:
                multiplo_de_3(L, &L2);
                if(L2 != NULL)
                    printf("Lista com multiplos de 3 criada.\n");
                else
                    printf("Erro ao criar lista com multiplos de 3.\n");

                break;

            case 8:
                if(!ch)
                    printf("Listas nao inicializadas!\n");
                else{
                    printf("Lista 1: ");
                    if(!lista_vazia(L))
                        printa(L);
                    else
                        printf("Vazia\n");

                    printf("Lista 2: ");
                    if(!lista_vazia(L2))
                        printa(L2);
                    else
                        printf("Vazia\n");
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
