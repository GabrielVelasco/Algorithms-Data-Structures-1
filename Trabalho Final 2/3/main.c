#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tad.h"
#define max_veic 10
#define max_box 6 //o sexto box eh a fila de espera
int main()
{
    fila f[max_box];
    char placa[10],op;
    int i,tam,box;
    //-----------Criacao das filas------------------------
    for(i = 0;i < max_box;i++){
        f[i] = cria_fila();
        if(f[i] == NULL){
            printf("Erro ao alocar as filas\n");
            return 0;
        }
    }
    //----------------------------------------------------
    printf("1-Entrada de veic.       2-Saida de veic.\n");
    printf("3-Visualiza             4-Sair");
    //----------------------------------------------------
    while(1){
        printf("\nEscolha uma opcao valida:");
        setbuf(stdin,NULL);
        op = getchar();
        switch(op){
         case '1':
             printf("Qual placa deseja inserir?\n");
             setbuf(stdin,NULL);
             scanf("%s", placa);
             box = 0;
             tam = tamanho(f[0]); //procurando o melhor box para inserir
             for(i = 1;i < max_box-1; i++){
                 if(tam > tamanho(f[i])){
                     tam = tamanho(f[i]);
                     box = i;
             }
            }
            if(insere(f[box],placa)){
                printf("Inserido com sucesso no Box [%d]",box);
            }
            else{
                if(insere(f[max_box-1],placa))
                    printf("Inserido na fila de espera\n");
                else
                    printf("Todos os boxes e a fila de espera estao cheios\n");
            }
            break;
//----------------------------------------------------------------------
         case '2':
            printf("Em qual box deseja retirar seu veiculo?\n");
            scanf("%d",&box);
            printf("Qual placa deseja remover?\n");
            setbuf(stdin,NULL);
            scanf("%s", placa);
            if(remover(f[box],placa)){
             if(tamanho(f[max_box-1])){
                insere_da_espera(f[box],f[max_box-1]);
                remove_ini(f[max_box-1]);
                printf("[%s] Foi removido com sucesso e a fila de espera andou\n",placa);
                }
             else
                printf("[%s] Foi removido com sucesso\n",placa);
                }
            else
                printf("Falha ao remover\n");
            break;
//----------------------------------------------------------------------
         case '3':
            printf("Imprimindo:\n");
            int maximo = max_box-1;
            for(i = 0;i < max_box-1;i++){
                if(fila_vazia(f[i]))
                    maximo = maximo-1; //saber quantos box existem
            }
            for(i = 0; i < maximo;i++){
                tam = tamanho(f[i]);
            if(i < max_box-1) //verifica se esta sendo imprimido um box ou a fila de espera
               printf("Box [%d]:\n",i);
            else
               printf("Fila de espera:\n");
              visualizar(f[i]);
             }
            break;
//----------------------------------------------------------------------
         case '4':
            printf("Saindo");
            return 0;
//----------------------------------------------------------------------
         }
       }
    return 0;
}
