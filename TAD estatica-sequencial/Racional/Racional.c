// implementacao das funcoes e declaracao de structs
#include <stdio.h>
#include <stdlib.h>
#include "Racional.h"

struct racional{
	int num, den;

};

Racional* generate(){
	Racional *p = malloc(sizeof(Racional));

	return p;
}

int set_velue(Racional *R, int n, int d){
	if(d == 0 || R == NULL)
		return 0;

	R->num = n;
	R->den = d;

	return 1;
}

Racional* sum(Racional *R1, Racional *R2){
	Racional *R3 = generate();
	if(R3 == NULL){
		printf("Erro ao alocar R3\n");
		return 0;
	}

	R3->num = (R1->num * R2->den) + (R1->den * R2->num);
	R3->den = R1->den * R2->den;

	return R3;
}

int get_value(Racional *R, int *n, int *d){
	if(R != NULL){
		*n = R->num;
		*d = R->den;

		return 1;
	}

	return 0;
}

void del(Racional **R){
	free(*R); *R = NULL;
}