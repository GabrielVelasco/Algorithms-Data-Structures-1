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

void printFinal(dados arrDados[], int size){
    for(int i = 0; i < size; i++){
        printf("Nome: %s\n", arrDados[i].nome);
        printf("Tipo numero: %c\n", arrDados[i].tipo);
        printf("DDD e numero: (%d) %d\n", arrDados[i].ddd, arrDados[i].numero);
        printf("\n");
    }

}

int main(){
    dados arrDados[MAXS];
    int size;

    size = insereDados(arrDados);
    printf("\nPrintando lista final:\n");
    printFinal(arrDados, size);

    return 0;
}