/*
	ex7
	Será usado encadeamento circular pois posso adicionar soldados no final da lista sem
	precisar percorre-la e fica mais fácil de dar "voltas" na lista.
	Nome dos soldados é lido até EOF (ctrl + D)

	Meu entendimento da questão foi o seguinte, os soldados estão cercados e um deles
	vai ser escolhido para iniciar a contagem (inicia a partir dele), é sorteado um número S
	e esse número nunca vai se alterar, os soldados são identificados de 0 a N-1, sendo N
	o número de soldados.
	Uma vez sorteado o S, conta-se S soldados a partir do escolhido para iniciar
	a contagem, ex; tem 4 soldados na lista [0, 1, 2, 3], S = 2, soldado usado para iniciar a
	contagem será o primeiro (soldado 0), logo o primeiro eliminado será o soldado 1, restando
	[0, 2, 3] depois a contagem reinicia a partir do soldado que está à frente (soldado 2) do soldado
	eliminado, eliminando o soldado 3, restando [0, 2], repetindo o processo o soldado 2 é eliminado
	restando o 0 que é o sobrevivente.
	Exemplo: https://prnt.sc/upo91t
*/

#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <string.h>
#include "list.h"

int main(){
	char nome_sld[20] = { 0 };
	int pos, s, randon_pos = 0, qntd_sold = 0, ch = 0;
	List lst_soldados = _cria_lista(), lst_elim = _cria_lista(); // lista para os soldados eliminados
	// lst aponta para o ultimo node(soldado)
	// entrada dos nomes
	// a cada nome aloca um node
	printf("Digite os nomes dos soldados cercados:\n");
	while(scanf("%s", nome_sld)){
		if(strcmp(nome_sld, "0") == 0)
			break;
		if(_insere_soldado(&lst_soldados, nome_sld)){
			printf("Soldado inserido com sucesso!\n");
			qntd_sold ++;
		}
	}

	printf("\nLista de soldados em volta da fogueira a beira da morte:\n");
	if(_lista_vazia(lst_soldados)){
		printf("Nenhum, todos ja morreram! RIP\n");
		exit(0);
	}else
		_printa_lista(lst_soldados);

	printf("\n\n");
	printf("1 - Iniciar contagem a partir do primeiro soldado da lista.\n");
	printf("2 - Iniciar contagem a partir de uma posição sorteada aleatoriamente da lista.\n");
	printf("3 - Iniciar contagem a partir de um soldado especifico.\n");
	printf("Escolha uma opcao: ");	
	scanf("%d", &pos); getchar();
	srand(time(0));
	s = (rand()%100) + 1; // sorteia um numero de 1 a 100

	switch(pos){
		case 1:
			// aqui randon_pos == 0, ou seja, vou comecar a partir do soldado 0
			printf("\nContar [%d] soldado(s) a partir do primeiro(inclusive)\n", s);
			_contador_elimina(&lst_soldados, lst_soldados, s, randon_pos, nome_sld, &lst_elim);
			ch = 1;
			break;

		case 2:
			// sorteia um numero de 0 a [qntd_sold-1] == indice do soldado no qual sera
			// iniciado a contagem
			randon_pos = rand()%qntd_sold;
			_get_elem(lst_soldados, randon_pos, qntd_sold-1, nome_sld); // pega nome do soldado sorteado
			printf("\nContar [%d] soldado(s) a partir do soldado [%s]\n", s, nome_sld);
			_contador_elimina(&lst_soldados, lst_soldados, s, randon_pos, nome_sld, &lst_elim);
			ch = 1;
			break;

		case 3:
			printf("Digite o nome do soldado onde sera iniciada a contagem: ");
			scanf("%s", nome_sld);
			randon_pos = _busca_nome(lst_soldados, nome_sld, qntd_sold-1);
			if(randon_pos != -1){
				printf("\nContar [%d] soldado(s) a partir do soldado [%s]\n", s, nome_sld);
				_contador_elimina(&lst_soldados, lst_soldados, s, randon_pos, nome_sld, &lst_elim);
				ch = 1;
			}else
				printf("Soldado [%s] nao existe\n", nome_sld);
			break;

		default:
			if(!_lista_vazia(lst_soldados))
				_limpa_lista(&lst_soldados);
			printf("Opcao invalida! %d\n", pos);

	}
	if(ch){
		printf("Soldados abatidos na ordem:\n");
		_printa_lista(lst_elim);
		printf("\nSOBREVIVEU o soldado ");
		_printa_lista(lst_soldados); // unico soldado restante
		_limpa_lista(&lst_soldados);
		_limpa_lista(&lst_elim);
		
		if(_lista_vazia(lst_soldados) && _lista_vazia(lst_elim))
			printf("\nListas limpas, saindo...\n");
	}

	return 0;
}