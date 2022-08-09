// utilizado pelo usuario

/*
		TAD Racionais:
	Dados: 3 numeros racioanis R1, R2 e R3
	Lista de Op: generate, set_velue, get_value, sum, delete

	Op:
		generate: gera um num racioanal.
		set_velue: atribui valor ao num/den
		get_value: le o num/den de um num racional
		sum: soma dois num racionais
		delete: libera memoria

	gcc -c main.c
	gcc -c Racional.c

	gcc -o "nome exec" main.c Racional.c
*/

#include <stdlib.h>
#include <stdio.h>
#include "Racional.h"

int main(){
	Racional *R1, *R2, *R3;
	int n, d;
	R1 = generate(); R2 = generate();
	if(R1 == NULL || R2 == NULL){
		printf("Error ao alocar\n");
		exit(1);
	}

	printf("Digite NUM e DEN do R1:\n");
	scanf("%d%d", &n, &d);
	if(!set_velue(R1, n, d)){
		printf("Erro ao atribuir R1\n");
		return -1;
	}

	printf("Digite NUM e DEN do R2:\n");
	scanf("%d%d", &n, &d);
	if(!set_velue(R2, n, d)){
		printf("Erro ao atribuir R2\n");
		return -1;
	}

	printf("Somando R1 + R2:\n");
	R3 = sum(R1, R2);
	if(R3 == NULL){
		printf("Erro ao somar R1 e R2\n");
		return -1;
	}
	
	if(!get_value(R3, &n, &d)){ // pega num e den de R3
		printf("Error ao consultar num e den de R3\n");
		return -1;
	}
	printf("R3 = %d / %d\n", n, d);

	printf("Deletando racionais\n");
	del(&R1); del(&R2); del(&R3);

	return 0;
}