#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXS 20

typedef struct dados{
    char nome[50], tipo;
    int ddd, numero;

}dados;

int insereDados(dados arrDados[]){
    int i;
    for(i = 0; i < MAXS; i++){
        printf("Digite o nome:\n");
        scanf("%[^\n]", arrDados[i].nome);
        if(strcmp("ACABOU", arrDados[i].nome) == 0)
            return i;
        getchar();
        printf("Digite o tipo de numero, C ou F:\n");
        scanf("%c", &arrDados[i].tipo);

        printf("Digite o DDD e numero:\n");
        scanf("%d%d", &arrDados[i].ddd, &arrDados[i].numero);
        getchar();
    }

    return i;
}

void consulta(dados arrDados[], int size){
    char cnome[50];
    while(1){
        getchar();
        printf("\nDigite o nome a ser consultado:\n");
        scanf("%[^\n]", cnome);
        if(strcmp("FIM", cnome) == 0) break;
        int achou = 0;
        for(int i = 0; i < size; i++){
            if(strcmp(cnome, arrDados[i].nome) == 0){
                printf("Telefone do/a %s: (%d) %d\n", cnome, arrDados[i].ddd, arrDados[i].numero);
                achou = 1;
            }
        }
        if(!achou)
            printf("%s nao encontrado na lista!\n", cnome);
    }

}

int main(){
    dados arrDados[MAXS];
    int size;

    size = insereDados(arrDados);
    consulta(arrDados, size);

    return 0;
}