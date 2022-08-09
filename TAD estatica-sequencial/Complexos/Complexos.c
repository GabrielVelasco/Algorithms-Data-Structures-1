// implementacao das funcoes e declaracao de structs
#include <stdio.h>
#include <stdlib.h>
#include "Complexos.h"

struct complexos{
	float real, img;

};

Complexos* cria_nro(float r, float i){
	Complexos *p = malloc(sizeof(Complexos));
	p->real = r;
	p->img = i;

	return p;
}

Complexos* sub(Complexos *C1, Complexos *C3){
	Complexos *S = cria_nro(1.0, 1.0);
	if(S == NULL)
		return S;

	S->real = C1->real - C3->real;
	S->img = C1->img - C3->img;

	return S;
}

Complexos* mult(Complexos *S, Complexos *C2){
	Complexos *M = cria_nro(1.0, 1.0);
	if(M == NULL)
		return M;

	M->real = ( (S->real*C2->real) - (S->img*C2->img) );
	M->img = ( (S->real*C2->img) + (S->img*C2->real) );

	return M;
}

int pega_nro(Complexos *M, float *r, float *i){
	if(M == NULL)
		return 0;

	*r = M->real;
	*i = M->img;

	return 1;
}

void del(Complexos **R){
	free(*R); *R = NULL;

}