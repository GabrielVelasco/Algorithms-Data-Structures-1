#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

void printa_lst(Lista lst){
    int pot, coef, cnt = 0;
    while(1){
        if(get_pos(lst, &pot, &coef, cnt) == 0)
            break;
        if(coef > 0)
            printf("+ ");
        printf("%dx^%d ", coef, pot);
        cnt++;
    }
    printf("\n");
}
int main()
{
    int p, c, m, criada = 0, x, tot;
    char ctn;
    Lista lst = cria_lista();
    while(1){
        printf("---------------------MENU---------------------\n");
        printf("[1]: inicia lista          [2]: insere elemento\n");
        printf("[3]: remove elemento       [4]: printar lista\n");
        printf("[5]: Reinicializar         [6]: Calcular polinimio para x\n");
        printf("[7]: Sair\n");
        scanf("%d", &m);
        if(m == 1){
            if(criada == 0){
                lst = cria_lista();
                criada = 1;
                printf("Lista criada!\n");
            }
            else{
                printf("Lista ja criada!\n");
            }
        }
        else{
            if(criada == 0){
                printf("voce deve criar uma lista primeiro!\n");
                continue;
            }
        }
        if(m == 2){
            while(1){
                printf("coeficiente: ");
                scanf("%d", &c);
                printf("potencia: ");
                scanf("%d", &p);
                //para ordenado, trocar por "insere_ord();", trocar tambem a remocao
                insere_termo(&lst, p, c);
                printf("Continuar a operacao?[s/n]: ");
                setbuf(stdin, NULL);
                scanf("%c", &ctn);
                if(ctn == 'n')
                    break;
            }
        }
        if(m == 3){
            printf("Potencia a ser removida: ");
            scanf("%d", &p);
            if(!remove_pot(&lst, p))
                printf("potencia inexistente.\n");
        }
        if(m == 4){
            printa_lst(lst);
        }
        if(m == 5){
            reset_lista(&lst);
        }
        if(m == 6){
            printf("Insira x: ");
            scanf("%d", &x);
            tot = calcula_poli(&lst, x);
            printf("Valor: %d\n", tot);
        }
        if(m == 7){
            printf("Operacao encerrada.\n");
            break;
        }

    }
    return 0;
}
