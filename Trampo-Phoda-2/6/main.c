#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "donators.h"
#include "queue.h"

/*
	pacientes[0] = fila de pacientes esperando por coracao
	pacientes[1] = fila de pacientes esperando por figado
	.
	.
	.

	- Inicializar todas as filas, paci[0] ... paci[4]

	- Inserir paciente:
		Entrar com os dados (nome, ...), identificar o orgao e seu respectivo indice no array pacientes[]
		ex; se orgao == coracao, logo sera adicionado em pacientes[0] de acordo com a ordenacao.
	
	- Cadastro doador:
		Entrar com os dados (nome, orgaos doados e beneficiado), para cada orgao ler um nome de beneficiado.
		O beneficiado de cada orgao sai da sua respectiva fila de espera.
		Se um doador doa um orgao em que sua respectiva fila de espera esta vazia, o orgao vai para uma fila
		de disponibilidade.
		ex; Fulano doa coracao, se _size(pacientes[0]) == 0, _push(disp, coracao)

*/

void _print_patient_node(char nome[], char orgao[], int idade, int grau, int cont){
	printf("%d - Nome: %s, Orgao: %s, Idade: %d, Grau: %d.\n", cont, nome, orgao, idade, grau);
}

void _print_don_node(char nome[], char orgao_benef[][300]){
	printf("Doador: %s\n", nome);
	for(int i = 0; strcmp(orgao_benef[i], "##") != 0; i++){
		printf("%s\n", orgao_benef[i]);
	}
	printf("\n");
}

void _print_disp_node(char orgao[], int last){
	if(!last)
		printf("%s, ", orgao);
	else
		printf("%s.", orgao);
}

int main(){
	Queue pacientes[5], disp;
	Qu_don don;
	char nome[150], orgao[50], benef[150], tmp[300];
	char arr_str[10][300];
	char *nomes_org[7] = {"coracao", "figado", "rins", "corneas", "pulmao"};
	int idade, grau, opc, ch = 0, idx;

	while(1){
		printf("\n-------MENU-----------\n");
		printf("[0] Inicializar filas\n");
		printf("[1] Inserir pacientes\n");
		printf("[2] Inserir doador\n");
		printf("[3] Printar filas\n");
		printf("[4] Esvaziar fila\n");
		printf("[Outra] Sair\n");
		printf("Escolha uma opcao: ");
		scanf("%d", &opc);

		int j = 0;
		switch(opc){
			case 0:
				for(int i = 0; i < 5; i++)
					pacientes[i] = _create_list();
				disp = _create_list();
				don = _create_list_d();
				printf("\nListas criadas.\n");
				ch = 1;

				break;

			case 1:
				if(!ch){
					printf("Filas nao inicializadas!\n");
					break;
				}
				printf("\n-Inserir paciente-\n");
				printf("Digite o nome: ");
				scanf(" %[^\n]", nome);

				printf("\nNumero do orgao a ser transplantado [1- coracao] [2- figado] [3- rins] [4- corneas] [5- pulmao]: ");
				scanf("%d", &opc);

				printf("\nIdade do paciente: ");
				scanf("%d", &idade);

				printf("\nGrau de gravidade: ");
				scanf("%d", &grau);

				if(opc == 1){
					/// verifica se tem o orgao na fila de disponibilidade
					idx = opc-1; /// numero da fila do coracao
					strcpy(orgao, nomes_org[idx]);
					if(_is_available(&disp, orgao)){
						printf("Havia '%s' na lista de disponibilidade, paciente foi transplantado.\n", orgao);
					
					/// add paciente na fila de espera
					}else{
						if(_push_patient(&pacientes[idx], nome, orgao, idade, grau))
							printf("'%s' inserido na fila de espera para '%s'.\n", nome, orgao);
					}
				}

				if(opc == 2){
					idx = opc-1;
					strcpy(orgao, nomes_org[idx]);
					if(_is_available(&disp, orgao)){
						printf("Havia '%s' na lista de disponibilidade, paciente foi transplantado.\n", orgao);
					
					}else{
						if(_push_patient(&pacientes[idx], nome, orgao, idade, grau))
							printf("'%s' inserido na fila de espera para '%s'.\n", nome, orgao);
					}
				}

				if(opc == 3){
					idx = opc-1;
					strcpy(orgao, nomes_org[idx]);
					if(_is_available(&disp, orgao)){
						printf("Havia '%s' na lista de disponibilidade, paciente foi transplantado.\n", orgao);
					
					}else{
						if(_push_patient(&pacientes[idx], nome, orgao, idade, grau))
							printf("'%s' inserido na fila de espera para '%s'.\n", nome, orgao);
					}
				}

				if(opc == 4){
					idx = opc-1;
					strcpy(orgao, nomes_org[idx]);
					if(_is_available(&disp, orgao)){
						printf("Havia '%s' na lista de disponibilidade, paciente foi transplantado.\n", orgao);
					
					}else{
						if(_push_patient(&pacientes[idx], nome, orgao, idade, grau))
							printf("'%s' inserido na fila de espera para '%s'.\n", nome, orgao);
					}
				}

				if(opc == 5){
					idx = opc-1;
					strcpy(orgao, nomes_org[idx]);
					if(_is_available(&disp, orgao)){
						printf("Havia '%s' na lista de disponibilidade, paciente foi transplantado.\n", orgao);
					
					}else{
						if(_push_patient(&pacientes[idx], nome, orgao, idade, grau))
							printf("'%s' inserido na fila de espera para '%s'.\n", nome, orgao);
					}
				}

				break;

			case 2:
				printf("\n-Inserir doador-\n");
				printf("Digite o nome do doador: ");
				scanf(" %[^\n]", nome);

				while(1){
					printf("Numero do orgao doado por '%s'\n[1- coracao] [2- figado] [3- rins] [4- corneas] [5- pulmao] [0- FIM]: ", nome);
					scanf("%d", &opc);
					if(opc == 0)
						break;
					idx = opc-1;
					int piv = 0;
					strcpy(orgao, nomes_org[idx]);
					printf("Nome do paciente que recebera '%s': ", orgao);
					scanf(" %[^\n]", benef);
					if(_pop_name(&pacientes[idx], benef)){
						printf("'%s' foi transplantado!\n\n", benef);
					}else{
						/// fila para tal orgao esta vaizia, orgao doado vai para
						/// fila de disponibilidade
						if(_push_back(&disp, orgao)){
							printf("Fila para '%s' esta vazia, o mesmo fica a disposicao.\n\n", orgao);
							piv = 1;
						}
					}
					if(piv){
						sprintf(tmp, "%s foi para fila de disponibilidade.", orgao);
					}else{
						/// Doou orgao para benef
						sprintf(tmp, "Doou %s para %s.", orgao, benef);
					}
					strcpy(arr_str[j], tmp);
					j++;
				}
				/// aqui ja tenho os dados do doador, logo add na fila
				if(_push_back_donator(&don, nome, arr_str, j))
					printf("'%s' adicionado a fila de doadores.\n", nome);

				break;

			case 3:
				printf("\n");
				for(int i = 0; i < 5; i++){
					printf("-Fila de espera %s-\n", nomes_org[i]);
					if(!_print_patient_queue(&pacientes[i]))
						printf("Vazia!\n");
					printf("\n");
				}

				printf("-Fila de doadores-:\n");
				if(!_print_donator_queue(&don))
					printf("Vazia!\n");
				printf("\n");

				printf("-Fila de disponibilidade-:\n");
				if(!_print_disp_queue(&disp))
					printf("Vazia!\n");
				printf("\n");

				break;

			case 4:
				printf("\n-Esvaziar fila-:\n");
				printf("Qual fila deseja esvaziar:\n" );
				printf("[1- coracao] [2- figado] [3- rins] [4- corneas]\n[5- pulmao] [6- disponibilidade] [7- doadores] [8- todas]\n");
				scanf("%d", &opc);
				if(opc != 8){
					if(opc == 7){
						if(_clean_don_queue(&don))
							printf("Fila de doadores limpa!\n");
						else
							printf("Fila vazia!\n");

					}else if(opc == 6){
						if(_clear_patient_queue(&disp))
							printf("Fila de disponibilidade limpa!\n");
						else
							printf("Fila vazia!\n");

					}else{
						/// limpa fila de algum orgao especifico
						if(_clear_patient_queue(&pacientes[opc-1]))
							printf("Fila de %s limpa!\n", nomes_org[opc-1]);
						else
							printf("Fila vazia!\n");
					}

				}else{
					/// limpa todas as filas
					if(_clean_don_queue(&don))
						printf("Fila de doadores limpa!\n");
					else
						printf("Fila de doadores vazia!\n");

					if(_clear_patient_queue(&disp))
						printf("Fila de disponibilidade limpa!\n");
					else
						printf("Fila de disponibilidade vazia!\n");

					for(int i = 0; i < 5; i++){
						if(_clear_patient_queue(&pacientes[i]))
							printf("Fila de %s limpa!\n", nomes_org[i]);
						else
							printf("Fila de %s vazia!\n", nomes_org[i]);
					}
				}

				break;

			default:
				ch = 2;
		}

		if(ch == 2) break;
	}

	return 0;
}