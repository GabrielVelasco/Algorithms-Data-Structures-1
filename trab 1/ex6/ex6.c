#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct dados{
    char nome[50];
    int matr, nota;

}dados;

void entradaDados(int n, dados arrAlunos[]){
    for(int i = 1; i <= n; i++){
        printf("Digite o nome do aluno (%d)\n", i);
        scanf("%[^\n]", arrAlunos[i-1].nome);

        printf("Digite a matricula do aluno (%d)\n", i);
        scanf("%d", &arrAlunos[i-1].matr);

        printf("Digite a nota do aluno (%d)\n", i);
        scanf("%d", &arrAlunos[i-1].nota); getchar();
    }
}

void gravaDados(FILE *p, dados arrAlunos[], int n){
    for(int i = 0; i < n; i++)
        fprintf(p, "%d %s %d\n", arrAlunos[i].matr, arrAlunos[i].nome, arrAlunos[i].nota);
}

int main(int argc, char *argv[]){
    FILE *p = fopen(argv[1], "w");
    int n = atoi(argv[2]);
    dados* arrAlunos = malloc(n*sizeof(dados));

    if(p == NULL){
        printf("Error!\n");
        exit(1);
    }

    entradaDados(n, arrAlunos);
    gravaDados(p, arrAlunos, n);

    fclose(p);
    free(arrAlunos);
    return 0;
}