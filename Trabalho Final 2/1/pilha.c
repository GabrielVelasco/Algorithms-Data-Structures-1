#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pilha.h"
#define max 20
struct Pilha{
  int tipo[max];
   union{
    int n;
    char hexal[33];
    }info[max];
  int topo;
};

pilha cria_pilha(){
pilha p;
p = (pilha) malloc(sizeof(struct Pilha));
if(p != NULL)
    p->topo = -1;
return p;
}

int pilha_vazia(pilha p){
if(p->topo == -1)
    return 1;
return 0;
}

int pilha_cheia(pilha p){
if(p->topo == max-1)
    return 1;
return 0;
}

int push(pilha p,int tipo,int elem,char hexa[33]){
if(p == NULL || pilha_cheia(p) == 1)
    return 0;
p->topo++;
if(tipo == 0){
p->info[p->topo].n = elem;
p->tipo[p->topo] = tipo;
}
else{
strcpy(p->info[p->topo].hexal,hexa);
p->tipo[p->topo] = tipo;
}
return 1;
}

int pop(pilha p,int *tipo,int *elem,char hexa[33]){
if(p == NULL || pilha_vazia(p) == 1)
    return 0;
if(p->tipo[p->topo] == 0){
    *elem = p->info[p->topo].n;
    *tipo = p->tipo[p->topo];
    }
else{
    strcpy(hexa,p->info[p->topo].hexal);
    *tipo = p->tipo[p->topo];
}
p->topo--;
return 1;
}

int le_topo(pilha p,int *elem,char hexa[33],int *tipo){
if(p == NULL || pilha_vazia(p) == 1)
    return 0;
if(p->tipo[p->topo] == 0)
    *elem = p->info[p->topo].n;
else
    strcpy(hexa,p->info[p->topo].hexal);
*tipo = p->tipo[p->topo];
return 1;
}

int binario(pilha p,int decimal){
if(p == NULL || pilha_cheia(p) == 1)
    return 0;

int valor_binario = 0;
int resto,sequencial = 1;

while(decimal != 0  ){
        resto = decimal % 2;

        decimal /= 2;

        valor_binario += resto * sequencial;

        sequencial *= 10;
     }
if(push(p,0,valor_binario,NULL))
  return 1;
else
  return 0;
}

int octal(pilha p,int decimal){
if(p == NULL || pilha_cheia(p) == 1)
    return 0;

int valor_octal = 0,sequencia = 1;
    while (decimal != 0){
        //Soma o valor octal com o resto da divisão do decimal por 8 multiplicado pelo sequencial
        valor_octal += (decimal % 8) * sequencia;

        decimal /= 8;

        sequencia *= 10;
    }
if(push(p,0,valor_octal,NULL))
    return 1;
else
    return 0;
}

int hexadecimal(pilha p,int decimal){
 if(p == NULL || pilha_cheia(p) == 1)
    return 0;

int sequencial = 1, c = decimal,temp = 0;
char hexa[33];

while(c > 15){
    c = c / 16;
    sequencial++;
}
hexa[sequencial] = '\0';
sequencial--;
while(decimal != 0){
    temp = decimal % 16;

    if(temp < 10 ) //menor q 10 soma com 48(tabela ASCII para numeros)
       temp = temp + 48;
    else
       temp = temp + 55; //caso contrario 55(tabela ASCII para letras)
    hexa[sequencial] = temp;
    sequencial = sequencial - 1;
    decimal = decimal / 16;
  }
  if(push(p,1,0,hexa))
    return 1;
  else
    return 0;
}

int esvazia_pilha(pilha p){
if(pilha_vazia(p)==1)
    {
        return 0;
    }
    p->topo=-1;
    return 1;
}
/*
void imprime(pilha p){
if(pilha_vazia(p))
    printf("A pilha esta vazia\n");
else{
  int i;
  for(i = 0; i <= p->topo;i++){
       if(p->tipo[i] == 0)
            printf("%d\n",p->info[i].n);
       else
            printf("%s\n",p->info[i].hexal);
    }
   }
}
*/


