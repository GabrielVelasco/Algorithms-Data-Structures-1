#include <stdio.h>
#include <stdlib.h>
#include "header.h"
int main()
{
    Lista lista;
    Lista lista2;
    int numero, i,op,verifica = 0;
    lista=cria_lista();
    lista2=cria_lista();

        printf("[1]- Criar lista                    [7]- Retornar maior elemento\n");
        printf("[2]- Inserir elemento               [8]- Intercalar lista\n");
        printf("[3]- Remover elemento               [9]- Imprimir lista\n");
        printf("[4]- Remover pares                  [10]- Esvaziar lista\n");
        printf("[6]- Consultar tamanho da lista              [11]- Sair\n");
        printf("[7]- Consultar tamanho maximo da lista \n ");

    while(1)
    {
        printf("\nEntre com uma opcao valida: ");
        setbuf(stdin,NULL);
        scanf("%d",&op);
        switch (op)
        {
        case 1:
           if(verifica == 0){
            lista=cria_lista();
           if(lista!=NULL)
            {

                printf("\nLista criada com sucesso!\n");
                verifica = 1;
                break;
            } else{
              printf("\nErro ao criar lista\n");
            }
           }
           if(verifica == 1){
             lista2=cria_lista();
             if(lista2 != NULL){
               printf("\nSegunda lista criada com sucesso\n");
               verifica = 2;
               break;
             } else{
               printf("\nErro ao criar lista\n");
             }
          }
          if(verifica == 2){
            printf("Maximo de listas criado\n");
          }
          break;
//------------------------------------------------------------------------------------------------------------------
        case 2:
            if(verifica==0){
                printf("Lista nao existente\n");
              }else{
                if(verifica == 1){
                  if(lista_cheia(lista)){
                    printf("A lista esta cheia\n");
                    break;
                  }
                  printf("Digite um numero: ");
                  scanf("%d",&numero);
                  if(insere_ordenado(lista,numero))
                  {
                      printf("\ninsercao realizada com sucesso\n");
                  }else{
                     printf("Erro ao inserir\n");
                  }
                }
                if(verifica == 2){
                  printf("Qual lista deseja inserir? 1 ou 2:\n");
                  scanf("%d",&i);
                  if(i == 1){
                    if(lista_cheia(lista) == 1 ){
                      printf("A lista 1 esta cheia\n");
                      break;
                    }
                    printf("Digite um numero: ");
                    scanf("%d",&numero);
                    if(insere_ordenado(lista,numero))
                    {
                        printf("insercao realizada com sucesso na lista 1\n");
                    }
                    else{
                        printf("Erro ao inserir na lista 1\n");
                    }
                  }
                  if(i==2){
                    if(lista_cheia(lista2) == 1){
                      printf("A lista 2 esta cheia\n");
                      break;
                    }
                    printf("Digite um numero: ");
                    scanf("%d",&numero);
                    if(insere_ordenado(lista2,numero))
                    {
                        printf("insercao realizada com sucesso na lista 2\n");
                    }
                    else{
                        printf("Erro ao inserir na lista 2\n");
                    }
                  }
                }
              }
            break;
//------------------------------------------------------------------------------------------------------------------
        case 3:
            if(verifica == 0){
              printf("Lista nao existente\n");
            }else{
              if(verifica == 1){
                printf("diga o elemento voce quer remover\n");
                scanf("%d",&numero);
                if(remove_ordenado(lista,numero))
                {
                  printf("removido com sucesso\n");
                }
              }else if(verifica == 2){
                printf("Em qual lista deseja remover o elemento?\n");
                scanf("%d",&i);
               if(i == 1){
                  printf("diga o elemento voce quer remover\n");
                  scanf("%d",&numero);
                  if(remove_ordenado(lista,numero))
                  {
                    printf("removido com sucesso\n");
                  }
                }
                if(i == 2){
                  printf("diga o elemento voce quer remover\n");
                  scanf("%d",&numero);
                  if(remove_ordenado(lista2,numero))
                  {
                    printf("removido com sucesso\n");
                  }
                }
              }
            }
            break;
//------------------------------------------------------------------------------------------------------------------
        case 4:
            if(verifica == 0){
              printf("Lista nao existente\n");
            }else{
              if(verifica == 1){
               if(remove_pares(lista)==1)
                 printf("Pares removidos com sucesso\n");
                 else{
                   printf("Erro ao remover pares\n");
                 }
              }
              else{
                printf("De qual lista deseja remover os pares? 1 ou 2\n");
                scanf("%d",&i);
                if(i == 1){
                 if(remove_pares(lista)==1)
                 printf("Pares removidos com sucesso\n");
                 else{
                   printf("Erro ao remover pares\n");
                 }
                }
                if(i==2){
                  if(remove_pares(lista2)==1)
                 printf("Pares removidos com sucesso\n");
                 else{
                   printf("Erro ao remover pares\n");
               }
              }
             }
            }
            break;
//------------------------------------------------------------------------------------------------------------------
/*        case 5:

            if(verifica == 0){
              printf("Lista nao existente\n");
            }
            else{
              Lista inversa;
                if(verifica == 1){
                if(lista_vazia(lista)){
                    printf("A lista esta vazia\n");
                    break;
                }
                inversa=inverte(lista);
                if(inversa != NULL){
                printf("A lista foi invertida com sucesso\n");
                for(i=1; ;  i++)
                 {
                int n;
                if(get_elemento(inversa,i,&n)==0)
                {
                    break;
                }
                printf("%d\n",n);

                }
                }
                else
                    printf("Falha ao inverter\n");
              }
              else{
                printf("Qual lista deseja inverter ?\n");
                scanf("%d",&i);
                if(i == 1){
                    if(lista_vazia(lista)){
                    printf("A lista esta vazia\n");
                    break;
                }
                  inversa=inverte(lista);
                  if(inversa != NULL){
                    printf("Lista 1 invertida com sucesso\n");
                    for(i=1; ;  i++)
                      {
                     int n;
                     if(get_elemento(inversa,i,&n)==0)
                     {
                      break;
                     }
                     printf("%d\n",n);
                    }
                  }
                  else
                    printf("Falha ao inverter\n");
                }
                if(i == 2){
                if(lista_vazia(lista2)){
                    printf("A lista esta vazia\n");
                    break;
                }
                  inversa=inverte(lista2);
                  if(inversa != NULL){
                    printf("Lista 2 invertida com sucesso\n");
                    for(i=1; ;  i++)
                     {
                      int n;
                      if(get_elemento(inversa,i,&n)==0)
                     {
                      break;
                      }
                      printf("%d\n",n);
                    }
                  }
                  else
                    printf("Falha ao inverter\n");
                }
                if(i > 2){
                    printf("Escolha uma lista valida\n");
                }
              }
            }
            break;
   */
//------------------------------------------------------------------------------------------------------------------
        case 5:
            if(verifica == 0){
              printf("Lista nao existente\n");
            }
            else{
            if(verifica == 1){
            if(lista_vazia(lista) == 1){
              printf("A lista esta vazia\n");
            }
            else
            printf("A quantidade de elemento e %d\n",quantidade_elementos(lista));
           }
           else{
             printf("Qual lista deseja verificar a quantidade de elementos?\n");
             scanf("%d",&i);
          if(i == 1){
            if(lista_vazia(lista) == 1){
              printf("A lista 1 esta vazia\n");
                }
            else
            printf("A quantidade de elemento e %d\n",quantidade_elementos(lista));
             }
          if(i == 2){
            if(lista_vazia(lista2) == 1){
              printf("A lista 2 esta vazia\n");
                }
            else
            printf("A quantidade de elemento e %d\n",quantidade_elementos(lista2));
             }
           }
          }
        break;
//------------------------------------------------------------------------------------------------------------------
        case 6:

        printf("Tamanho maximo da lista: %d\n", tamanho(lista));
        break;
//------------------------------------------------------------------------------------------------------------------
        case 7:
            if(verifica == 0){
             printf("Lista nao existente\n");
            }
            else{
            if(verifica == 1){
            if(lista_vazia(lista) == 1){
              printf("Lista esta vazia\n");
              break;
            }
            printf("o maior elemento da lista e %d",maior_elemento(lista));
            }
            else{
              if(verifica == 2){
              printf("Qual lista deseja verificar?\n");
              scanf("%d",&i);
              if(i == 1){
                if(lista_vazia(lista) == 1){
                   printf("Lista 1 esta vazia\n");
                    break;
                  }
               printf("O maior elemento da lista e %d",maior_elemento(lista));
               }
               if(i == 2){
                 if(lista_vazia(lista2) == 1){
                   printf("Lista 2 esta vazia\n");
                    break;
                  }
                printf("O maior elemento da lista e %d",maior_elemento(lista2));
               }
              }
             }
            }
            break;
//------------------------------------------------------------------------------------------------------------------
        case 8:
            if(verifica < 2){
              printf("Precisa de duas listas\n");
              break;
            }
            else{
            Lista lista3;
            lista3 = intercala(lista,lista2);
            if(lista3!= NULL){
                printf("Intercalada, lembre-se do limite de elementos de cada lista\n");
            }
            else{
                printf("Erro ao intercalar\n");
            }
            for(i=1; ; i++)
            {
                int n;
                if(get_elemento(lista3,i,&n)==0)
                {
                    break;
                }
                printf("%d ",n);
              }
              printf("\n");
            }
            break;
//------------------------------------------------------------------------------------------------------------------
        case 9:
            if(verifica == 0){
              printf("Lista nao existente\n");
            }
            else{
            if(verifica == 1){
            if(lista_vazia(lista) == 1){
              printf("A lista esta vazia\n");
              break;
            }
            printf("IMPRIMINDO A LISTA\n");
            for(i=1; ;  i++)
            {
                int n;
                if(get_elemento(lista,i,&n)==0)
                {
                    break;
                }
                printf("%d\n",n);

            }
           }
           else{
             if(verifica == 2){
               printf("Qual lista deseja imprimir?");
               int j;
               scanf("%d",&j);
               if(j == 1){
                 if(lista_vazia(lista) == 1){
                   printf("Lista 1 vazia\n");
                   break;
                 }
                 printf("IMPRIMINDO A LISTA 1\n");
                 for(i=1; ;  i++)
               {
                int n;
                 if(get_elemento(lista,i,&n)==0)
                 {
                    break;
                 }
                printf("%d\n",n);

               }
              } if(j == 2){
                if(lista_vazia(lista2) == 1){
                   printf("Lista 2 vazia\n");
                   break;
                 }
                printf("IMPRIMINDO A LISTA 2\n");
                 for(i=1; ;  i++)
               {
                int n;
                 if(get_elemento(lista2,i,&n)==0)
                 {
                    break;
                 }
                printf("%d\n",n);
               }
              }
             }
            }
           }
            break;
//------------------------------------------------------------------------------------------------------------------
        case 10:
            if(verifica == 0){
              printf("Lista nao existente\n");
            }else if(verifica == 1){
              if(esvazia(lista) == 1){
                printf("Esvaziada com sucesso\n");
              }
              else{
                printf("A lista ja estava vazia\n");
              }
             }
             else{
              printf("Qual lista vc deseja esvaziar?\n");
              scanf("%d",&i);
              if(i == 1){
                if(esvazia(lista) == 1){
                printf("Esvaziada com sucesso\n");
              }
              else{
                printf("A lista ja estava vazia\n");
              }
            }
            if(i == 2){
              if(esvazia(lista2) == 1){
                printf("Esvaziada com sucesso\n");
              }
              else{
                printf("A lista ja estava vazia\n");
              }

            }
          }

            break;
//------------------------------------------------------------------------------------------------------------------
        case 11:
            printf("Saindo...\n");
            return 0;
        }

    }
    return 0;

}









/*
int main()
{
    Lista lista;
    Lista inversa;
    Lista lista2;
    Lista lista3;
    int numero, insere, i, remo,menor,remove, op,para=1;
    lista=cria_lista();
    lista2=cria_lista();


    while(para==1)
    {
        printf("1- para criar a lista 1\n 2- para inserir elemento\n 3- para remover um elemento \n 4 para remover pares\n 5 - inverter a lista\n 6-quantidade elementos da lista \n 7 -tamanho maximo lista\n 8- maior elemnento da lista \n9-para concatenar lista\n10- para imprimir\n 11-criar e inserir uma segunda lista \n 12-esvaziar\n 13- imprimir lista concatenada \n 14 sair\n");
        scanf("%d",&op);

        switch (op)
        {
        case 1:
            lista=cria_lista();

            if(lista!=NULL)
            {
                printf("\nlista crianda com sucesso\n");
            }

            break;
        case 2:
            if(lista==NULL)
            {
                printf("nao posso inserir pois nao existe uma lista\n");
            }
            if(lista!=NULL)
            {
                printf("diga o numero");
                scanf("%d",&numero);
                insere=insere_ordenado(lista,numero);
                if(insere==1)
                {
                    printf("\ninsercao realizada com sucesso\n");
                }
            }
            break;
        case 3:
            printf("diga o elemento voce quer remover\n");
            scanf("%d",&numero);
            remo=remove_ordenado(lista,numero);
            if(remo==1)
            {
                printf("removido com sucesso\n");
            }
            break;

        case 4:
            if(remove_pares(lista)==1)
            {
                printf("os pares foram removidos\n");
            }
            break;
        case 5:
            inversa=inverte(lista);

            break;

        case 6:
            printf(" a quantidade de elemento e %d\n",quantidade_elementos(lista));

            break;
        case 7:
            printf("o tamanho maximo da lista e %d\n",tamanho(lista));
            break;
        case 8:
            printf("o maior elemento da lista e %d",maior_elemento(lista));
            break;

        case 9:
            lista3=concatena(lista,lista2);
            if(concatena(lista,lista2)!=NULL)
            {
                printf("concatenada com sucesso\n");
            }
            break;
        case 10:
            printf("IMPRIMINDO A LISTA\n");

            for(i=1; ;  i++)
            {
                int n;
                if(get_elemento(lista,i,&n)==0)
                {
                    break;
                }
                printf("%d\n",n);

            }
            break;
        case 11:
            lista2=cria_lista();
            printf("diga um elemento para inserir na lista 2");
            scanf("%d",&numero);
            if(insere_ordenado(lista2,numero)==1)
            {
                printf("inserido com sucesso\n");
            }
            break;
        case 12:
            esvazia(lista);
        case 13:
            printf("IMPRIMINDO A LISTA\n");

            for(i=1; ;  i++)
            {
                int n;
                if(get_elemento(lista3,i,&n)==0)
                {
                    break;
                }
                printf("%d\n",n);

            }
            break;


            case 14:
            printf("saindo \n");
            para=2;

        }





    }
    return 0;

}
*/

