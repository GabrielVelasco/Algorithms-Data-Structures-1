#include <stdio.h>
#include <stdlib.h>
#include "deque.h"

void imprime_deque(Deque d){
    int x;
    if(deque_vazio(d)){
        printf("Fila vazia!\n");
        return;
    }
    printf("\nDeque: ");
    Deque aux = cria_deque();
    while(remove_ini(d, &x)){
        printf("%d ", x);
        insere_fim(aux, x);
    }
    printf("\n\n");
    while(remove_ini(aux, &x))
        insere_fim(d, x);
}
int main()
{
    int opt, cr = 0, opt2, x;
    Deque d;
    while(1){
        printf("MENU:\n");
        printf("[1]- Criar deque\n");
        printf("[2]- Inserir elemento\n");
        printf("[3]- Remover elemento\n");
        printf("[4]- Imprimir o deque\n");
        printf("[5]- Liberar deque\n");
        scanf("%d", &opt);
        if(opt == 1){
            if(cr == 0){
                d = cria_deque();
                if(d != NULL)
                    printf("Deque criado com sucesso!\n");
                else{
                    printf("FALHA!\n");
                    break;
                }
                cr = 1;
            }
            else
                printf("Deque ja criado!\n");

        }
        else if(cr == 0){
            printf("Deque nao foi criado!\n");
            continue;
        }
        if(opt == 2){
            while(1){
                printf("[1]- inserir no inicio\n");
                printf("[2]- inserir no final\n");
                printf("[3]- sair da insercao\n");
                scanf("%d", &opt2);
                if(opt2 == 3)
                    break;
                printf("Numero a ser inserido: ");
                scanf("%d", &x);
                if(opt2 == 1){
                    if(insere_ini(d, x))
                        printf("Elemento inserido com sucesso!\n");
                    else{
                        printf("FALHA!");
                        return 0;
                    }
                }
                if(opt2 == 2){
                    if(insere_fim(d, x))
                        printf("Elemento inserido com sucesso!\n");
                    else{
                        printf("FALHA!");
                        return 0;
                    }
                }
            }
        }
         if(opt == 3){
            while(1){
                printf("[1]- remover o inicio\n");
                printf("[2]- remover o final\n");
                printf("[3]- sair da remocao\n");
                scanf("%d", &opt2);
                if(opt2 == 3)
                    break;
                if(opt2 == 1){
                    if(remove_ini(d, &x))
                        printf("Elemento removido: %d\n", x);
                    else{
                        printf("Lista vazia!\n");
                    }
                }
                if(opt2 == 2){
                    if(remove_fim(d, &x))
                        printf("Elemento removido: %d\n", x);
                    else{
                        printf("Lista vazia!");
                        return 0;
                    }
                }
            }
        }
        if(opt == 4)
            imprime_deque(d);
        if(opt == 5){
            if(libera_deque(d)){
                cr = 0;
                printf("Deque liberado com sucesso!\n");
            }
        }
    }
}
