#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "header.h"
#define max 21
int main()
{
    FILA f;
    int ano_ingresso,carga_horaria,op;
    char nome[100],matricula[15];
    float CRA;

    f = cria_fila();
    if(f == NULL){
        printf("Problema ao criar a fila");
        return 0;
    }
    printf("Fila criada\n");
    printf("1-Insere        2-Remove\n");
    printf("3-Esvazia       4-Imprime\n5-Sair");

    while(1){
        printf("\nInsira uma opcao valida:");
        scanf("%d",&op);
        switch(op){
         case 1:
            printf("Insira a matricula\n");
            setbuf(stdin,NULL);
            gets(matricula);
            printf("Digite o nome\n");
            gets(nome);
            printf("CRA\n");
            scanf("%f",&CRA);
            printf("Carga horaria\n");
            scanf("%d",&carga_horaria);
            printf("Ano de ingresso\n");
            scanf("%d",&ano_ingresso);

            if(insere(f,matricula,nome,CRA,carga_horaria,ano_ingresso))
                printf("Sucesso na insercao\n");
            else
                printf("Falha na insercao\n");
            break;
//--------------------------------------------------------------------------------------------
         case 2:
             if(remover(f,matricula,nome,&CRA,&carga_horaria,&ano_ingresso)){
                printf("Matricula:%s\nNome:%s\nCRA:%f\n",matricula,nome,CRA);
                printf("Carga horaria:%d\nAno de ingresso:%d\n",carga_horaria,ano_ingresso);
                printf("Foi removido com sucesso\n");
             }
             else
                printf("Falha na remocao\n");
             break;
//--------------------------------------------------------------------------------------------
         case 3:
            if(esvazia(f))
                printf("Sucesso ao esvaziar\n");
            else
                printf("Fila ja estava vazia\n");
            break;
//--------------------------------------------------------------------------------------------
         case 4:
            if(fila_vazia(f)){
                printf("Falha na impressao");
            }
            else{
                FILA aux = cria_fila(); //remove tudo e passa para uma temporaria
                while(remover(f,matricula,nome,&CRA,&carga_horaria,&ano_ingresso)){
                printf("Matricula:%s\nNome:%s\nCRA:%f\n",matricula,nome,CRA);
                printf("Carga horaria:%d\nAno de ingresso:%d",carga_horaria,ano_ingresso);
                printf("\n-------------------------\n");
                insere(aux,matricula,nome,CRA,carga_horaria,ano_ingresso);
                } //remove tudo da temporaria e devolve pra principal
               while(remover(aux,matricula,nome,&CRA,&carga_horaria,&ano_ingresso)){
                insere(f,matricula,nome,CRA,carga_horaria,ano_ingresso);
               }
               free(aux);
            }
            break;
//--------------------------------------------------------------------------------------------
         case 5:
            printf("Saindo");
            return 0;
        }
    }
}
