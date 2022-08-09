#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define true 1
#define false 0
#define min(a, b) (((a) < (b)) ? ((a) : (b)))

typedef struct{
    char nome[50];
    int vol;
    float preco;

}bebidas;

void entraDados(bebidas **p){
    *p = (bebidas*) malloc(sizeof(bebidas));
    printf("Digite o nome:\n");
    scanf(" %[^\n]", (*p)->nome);
    printf("Digite o volume:\n");
    scanf("%d", &(*p)->vol);
    printf("Digite o preco:\n");
    scanf("%f", &(*p)->preco);
}

void printaTabela(bebidas *p[], int n){
    if(n == 0)
        printf("Tabela vazia!\n");

    for(int i = 0; i < n; i++){
        printf("Bebida (%d):\n", i+1);
        printf("Nome: %s\n", p[i]->nome);
        printf("Volume: %d\n", p[i]->vol);
        printf("Preco: %.2f\n", p[i]->preco);
        printf("\n");
    }
}

int main(){
    bebidas *p[20];
    for(int i = 0; i < 20; i++)
        p[i] = NULL;

    int i = 0, opc;
    while(true){
        printf("\nDigite uma opcao:\n");
        scanf("%d", &opc);
        if(opc == 4) break;

        if(opc == 1){
            printf("\nInserir bebida\n");
            if(p[19] != NULL){
                printf("Vetor Cheio\n");
                continue;
            }
            //p[i] = entraDados(); i++;
            entraDados(&p[i]); i ++;

        }else if(opc == 2){
            printf("\nApagar ultimo registro\n");
            if(p[0] == NULL){
                printf("Vetor vazio!\n");
                continue;
            }
            i --;
            free(p[i]);
            p[i] = NULL;
            continue;

        }else if(opc == 3){
            printf("\nPrintar Tabela:\n");
            printaTabela(p, i);
            continue;

        }else{
            printf("Opcao invalida!\n"); 
            continue;
        }
    }

    for(int i = 0; i < 20; i++)
        free(p[i]);

    return 0;
}