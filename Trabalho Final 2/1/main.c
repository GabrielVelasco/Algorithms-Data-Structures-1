#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pilha.h"

int main()
{
    pilha p;
    int op,num;
    p = cria_pilha();
    if(p == NULL){
        printf("Erro na alocacao de memoria para pilha\n");
        return 0;
    }
    printf("1-Binario           2-Octal\n");
    printf("3-Hexadecimal       4-Imprimir\n");
    printf("5-Esvaziar\n");
    printf("Ao digitar numero negativo o programa terminara\n");

    while(1){
         printf("Digite uma opcao\n");
         scanf("%d",&op);
         if(op < 4){
         printf("Digite um numero:\n");
         scanf("%d",&num);
         if(num < 0){
            printf("Fim\n");
            return 0;
         }
        }
         switch (op){
            case 1:
              if(binario(p,num))
                printf("Sucesso na conversao e insercao em binario\n");
              else
                printf("Falha na conversao e insercao em binario\n");
             break;
//-------------------------------------------------------------------------------------
            case 2:
                if(octal(p,num))
                    printf("Sucesso na conversao e insercao em octal\n");
                else
                    printf("Falha na conversao e insercao em octal\n");
               break;
//-------------------------------------------------------------------------------------
            case 3:
                if(hexadecimal(p,num))
                    printf("Sucesso na conversao e insercao em hexadecimal\n");
                else
                    printf("Falha na conversao e insercao em hexadecimal\n");
                break;
//--------------------------------------------------------------------------------------
            case 4:
                if(pilha_vazia(p) == 0){
                pilha aux = cria_pilha();
                int tipo;
                char hexal[34];
                while(pop(p,&tipo,&num,hexal)){
                    push(aux,tipo,num,hexal);
                }
                while(pop(aux,&tipo,&num,hexal)){
                    push(p,tipo,num,hexal);
                    if(tipo == 0)
                        printf("%d\n",num);
                    else
                        printf("%s\n",hexal);
                 }
                }
                else{
                    printf("A pilha esta vazia\n");
                }
                break;
//--------------------------------------------------------------------------------------
            case 5:
                if(esvazia_pilha(p))
                    printf("Pilha esvaziada com sucesso\n");
                else
                    printf("Falha, ja estava vazia\n");
                break;
//--------------------------------------------------------------------------------------
          }
        }
    return 0;
}
