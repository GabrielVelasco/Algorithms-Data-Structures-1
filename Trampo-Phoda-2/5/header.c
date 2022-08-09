#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "header.h"
#define max 21

struct aluno{
char matricula[15];
char nome[100];
float CRA;
int carga_horaria;
int ano_ingresso; //ordenar por ele na remocao, sempre remove o menor
};
//printar ordenado

struct fila{
struct aluno a[max];
int ini,fim;
};

FILA cria_fila(){
FILA f;
f = (FILA) malloc(sizeof(struct fila));
if(f != NULL){
    f->ini = 0;
    f->fim = 0;
}
return f;
}

int fila_vazia(FILA f){
if(f->ini == f->fim)
    return 1;
return 0;
}

int fila_cheia(FILA f){
if(f->ini == (f->fim + 1)%max)
    return 1;
return 0;
}

int insere(FILA f,char matricula[15],char nome[100],float CRA,int carga_horaria,int ano_ingresso){
if(fila_cheia(f) || f == NULL)
    return 0;
strcpy(f->a[f->fim].matricula,matricula);
strcpy(f->a[f->fim].nome,nome);
f->a[f->fim].CRA = CRA;
f->a[f->fim].carga_horaria = carga_horaria;
f->a[f->fim].ano_ingresso = ano_ingresso;
f->fim = (f->fim+1)%max;
return 1;
}

int remover(FILA f,char matricula[15],char nome[100],float *CRA,int *carga_horaria,int *ano_ingresso){
if(fila_vazia(f) || f == NULL)
    return 0;
//percorrimento pra achar o menor
int menor,indice,i;
menor = f->a[f->ini].ano_ingresso;
indice = f->ini;
for(i = f->ini;i < f->fim;i++){
    if(menor > f->a[i].ano_ingresso){
        menor = f->a[i].ano_ingresso;
        indice = i;
    }
 }
if(indice == f->fim){
    f->fim = f->fim - 1; //se for o ultimo nao precisa movimentar a fila
    return 1;  //so subtrair 1 no fim
}
//Parte que sera usada na impressao
strcpy(matricula,f->a[indice].matricula);
strcpy(nome,f->a[indice].nome);
*CRA = f->a[indice].CRA;
*carga_horaria = f->a[indice].carga_horaria;
*ano_ingresso = f->a[indice].ano_ingresso;
//------------------------------------------
for(i = indice;i < f->fim;i++) // movimentacao da fila
     f->a[i] = f->a[i+1];

    f->fim = f->fim-1;
    return 1;
}

int esvazia(FILA f){
if(fila_vazia(f) || f == NULL)
    return 0; //nao tem pq esvaziar ja esta vazia
f->ini = 0;
f->fim = 0;
return 1;
}
/*
void imprime(FILA f){
if(fila_vazia(f) || f == NULL)
    return 0;
//ordenara apenas para impressao, sera ordenado
//baseado em quicksort
FILA aux = f;
struct aluno x,y;
int i,j;
//------------------------------
i = f->ini;
j = f->fim;
x = f->a[(i+j)/2];

while(i <= j){
    if( f->a[i].ano_ingresso < x.ano_ingresso && i < f->fim )
        i++
    if( f->a[j].ano_ingresso > x.ano_ingresso && j > f->ini )
        j--;


  }
}
*/

