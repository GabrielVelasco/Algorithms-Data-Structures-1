// utilizado pelo usuario

/*
		TAD Complexos:
	Dados: 3 numeros complexos C1, C2 e C3
	Lista de Op: cria_nro, get_value, sum, sub, mult, libera_nro

	Op:
		cria_nro: gera um endereco de num complexo com parte imaginaria e parte real (aloca e atribui)
		get_value: le parte real e imaginaria de um num complexo
		sum: soma dois num complexos
		sub: subtrai dois num complexos
		mult: multiplica dois num complexos
		pega_nro: extrai parte real e img de um num complexo para o usuario
		libera_nro: libera memoria

	(C1 – C3) * C2

	gcc -c user.c
	gcc -c app.c

	gcc -o "nome exec" user.c app.c
*/

#include <stdlib.h>
#include <stdio.h>
#include "Complexos.h"

int main(){
	Complexos *C1, *C2, *C3, *S, *M;
	int n = 0;
	float r, i;
	while(n < 3){
		printf("Digite a parte real e imaginaria de C%d:\n", n+1);
		scanf("%f%f", &r, &i);
		if(n == 0){
			C1 = cria_nro(r, i);

		}else if(n == 1){
			C2 = cria_nro(r, i);

		}else if(n == 2){
			C3 = cria_nro(r, i);
		}

		n ++;
	}

	// S armazena resultado de C1 - C3
	// sub pega parte real/img dos nros e faz a operacao
	S = sub(C1, C3);
	if(S == NULL){
		printf("Erro ao fazer subtracao\n");
		exit(1);
	}

	// S armazena resultado de S * C2
	M = mult(S, C2);
	if(M == NULL){
		printf("Erro ao fazer multp\n");
		exit(1);
	}

	if(pega_nro(M, &r, &i)){
		printf("Resultado de (C1 – C3) * C2:\n");
		printf("%.0f %.0fi\n", r, i);
	}else{
		printf("Erro ao calcular a expressao\n");
	}

	printf("Liberando numeros\n");
	del(&C1); del(&C2); del(&C3); del(&S); del(&M);

	return 0;
}