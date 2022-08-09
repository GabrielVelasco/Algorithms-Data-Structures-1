// ex 5
#include <stdlib.h>
#include <stdio.h>
#include "list.h"

int main(){
    int opc, ch = 0, idx;
    double elem;
    Lista L; // ponteiro para o primeiro node da lista

    while(1){
        printf("\n======================MENU=========================================\n");
        printf("[0] Cria Listas                     [6] Remove inicio\n");
        printf("[1] Insere final                    [7] Remove final\n");
        printf("[2] Insere inicio                   [8] Inserir posicao\n");
        printf("[3] Consultar posicao               [9] Remover posicao\n");
        printf("[4] Maior elemento                  [10] Imprimir lista\n");
        printf("[5] Tamanho da lista\n");
        printf("\nEscolha uma opcao: ");
        scanf("%d", &opc);


        switch(opc){
            case 0:
                L = cria_lista(); // cria lista vazia (sem nodes)
                printf("\nLista criada\n");

                break;

            case 1:
                printf("\nInsere final, digite o elemento:\n");
                scanf("%lf", &elem);
                if(insere_final(&L, elem))
                    printf("Elemento inserido com sucesso!\n");
                else
                    printf("Erro ao inserir elemento na lista!\n");

                break;

            case 2:
                printf("\nInsere inicio, digite o elemento:\n");
                scanf("%lf", &elem);
                if(insere_inicio(&L, elem))
                    printf("Elemento inserido com sucesso!\n");
                else
                    printf("Erro ao inserir elemento na lista!\n");

                break;

            case 3:
                if(!ch) printf("Lista nao inicializada\n");

                else{
                    printf("\nDigite a posicao a ser consultada:\n");
                    scanf("%d", &idx);
                    if(get_elemento(L, idx, &elem))
                        printf("Elemento da posicao %d: %.2lf\n", idx, elem);
                    else
                        printf("Erro ao consultar!\n");
                }

                break;

            case 4:
                if( !ch || lista_vazia(L) )
                    printf("Lista nao inicializada ou vazia\n");
                else
                    printf("Maior elemento: %lf\n", maior_elemento(L));

                break;


            case 5:
                printf("Tamanho da lista: %d\n", tamanho(L));

                break;

            case 6:
                if(remove_inicio(&L))
                    printf("Inicio removido!\n");
                else
                    printf("Erro ao remover inicio da lista\n");

                break;

            case 7:
                if(remove_final(&L))
                    printf("Final removido!\n");
                else
                    printf("Erro ao remover final da lista\n");

                break;

            case 8:
                printf("\nDigite o elemento a ser inserido e sua posicao respectivamente:\n");
                scanf("%lf%d", &elem, &idx);
                if(insere_posicao(&L, idx, elem))
                    printf("Elemento inserido com sucesso!\n");
                else
                    printf("Erro ao inserir elemento na lista!\n");

                break;

            case 9:
                printf("\nDigite a posicao a ser removida:\n");
                scanf("%d", &idx);
                if(remove__posicao(&L, idx))
                    printf("Elemento removido com sucesso!\n");
                else
                    printf("Erro ao remover da lista!\n");

                break;

            case 10:
                if( !ch || lista_vazia(L) )
                    printf("\nLista vazia ou nao inicializada\n");
                else{
                    imprime(L);
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