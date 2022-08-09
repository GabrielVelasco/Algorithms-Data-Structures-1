// ex3
#include <stdio.h>
#include <stdlib.h>
#include "list.h"

struct node{
	float info;
	struct node* next;

};

List createList(){ return NULL; }

int emptyList(List lst){
	// verifica se E o primeiro node
	if(lst == NULL)
		return 1; // lista vazia
	else
		return 0;
}

int insertOrd(List *lst, float elem){
	// *lst == ponteiro p/ primeiro node
	// primeiro cria o node a ser inserido e atribui os valores

	List node = (List) malloc(sizeof(struct node));
	if(node == NULL) return 0; // node nao alocado por falta de memoria
	node->info = elem;

	if(emptyList(*lst) || elem <= (*lst)->info){
		node->next = *lst; // atual primeiro node passa a ser o segundo
		*lst = node; // node passa a ser o novo primeiro

		return 1;
	}

	// percorrer para encontrar pos correta
	List tmp = *lst;
	while(tmp->next != NULL && tmp->next->info < elem)
		tmp = tmp->next;

	node->next = tmp->next;
	tmp->next = node;

	return 1;
}

int removeOrd(List *lst, float elem){
	if(emptyList(*lst) || elem < (*lst)->info) return 0;
	List tmp = *lst; // tmp = atual peimeiro node

	// verf se o primeiro elem da lista é o alvo
	if( (*lst)->info == elem ){
		*lst = tmp->next; // primeiro node passa a ser o atual segundo
		free(tmp); // deleta node que era o primeiro
		return 1;
	}

	// elem pode estar mais a direita, percorrer
	while(tmp->next != NULL && tmp->next->info < elem)
		tmp = tmp->next; // avanca para proximo node

	if(tmp->next == NULL || tmp->next->info > elem) 
		return 0; // chegou no final da lista ou nao achou elem
	// cara que vem A DIREITA do node TMP vou remover
	List tmp2 = tmp->next; // tmp2 = node a ser removido
	tmp->next = tmp2->next;
	free(tmp2);

	return 1;
}

int getSize(List lst){
	if(emptyList(lst)) return 0;

	int size = 1; // se n esta vazia ja tem pelo menos um node
	while(lst->next != NULL){
		lst = lst->next;
		size ++;
	}

	return size;
}

int getElem(List lst, int idx, float *num){
	// retorna o conteudo do node dado o indice (posicao do node) a partir do 0
	if(idx >= getSize(lst) || idx < 0) return 0; // fora da lista

	while(idx --)
		lst = lst->next;

	// tmp == node a ser retornado
	*num = lst->info;
	return 1;
}

void imprimiLista(List lst){
	while(lst != NULL){
		printf("[%.2f] ", lst->info);
		lst = lst->next;
	}
}

int comparaLista(List L, List L2){
	int size1 = getSize(L), size2 = getSize(L2);
	if(size1 != size2) return 0;

	// chegou ate aqui, listas tem tamanhos iguais
	int cont = 0;
	while((L != NULL) && (L->info == L2->info)){
		L = L->next;
		L2 = L2->next;
		cont ++;
	}

	if(cont == size1) return 1;
	else return 0;
}

int inserePos(List *node, float elem){
	// node == ultimo node da l3
	List newNode = (List) malloc(sizeof(struct node));
	if(newNode == NULL) return 0;

	newNode->info = elem;
	newNode->next = NULL;
	if(*node != NULL)
		(*node)->next = newNode; // direciona ponteiro para novo ultimo node
	*node = newNode;
	return 1;
}

int intercalar(List l1, List l2, List *l3){
	if(!emptyList(*l3)) clearList(l3);

	int ch = 1; // fazer l3 apontar para o primeiro node
	List tmp3 = NULL; // tmp3 aponta para o ultimo node da lista 3
	while((l1 != NULL) && (l2 != NULL)){
		if(l1->info <= l2->info){
			if(!inserePos(&tmp3, l1->info))
				return 0;
			l1 = l1->next;

		}else{
			// l1->info > l2->info
			if(!inserePos(&tmp3, l2->info))
				return 0;
			l2 = l2->next;
		}
		if(ch){
			*l3 = tmp3; 
			ch = 0;
			// aponta o primeiro node da lista 3.
		}
	}
	// aqui ch == 1 se l1 ou l2 estiver vazia, logo l3 == l1 ou l2.
	// se sobrar elementos na l1 ou l2.
	while(l1 != NULL){
		if(!inserePos(&tmp3, l1->info))
			return 0;
		l1 = l1->next;
		if(ch){
			*l3 = tmp3;
			ch = 0;
		}
	}
	while(l2 != NULL){
		if(!inserePos(&tmp3, l2->info))
			return 0;
		l2 = l2->next;
		if(ch){
			*l3 = tmp3;
			ch = 0;
		}
	}

	return 1;
}

int clearList(List *lst){
	if(emptyList(*lst)) return 0;

	// Limpar node por node
	List tmp;
	while(*lst != NULL){
		tmp = *lst;
		*lst = (*lst)->next;
		free(tmp);
	}

	return 1;
}

// funcao usada anteriormante para intercalar
// void intercalar(List L, List L2, List *L3){
// 	// L3 contem elemento, logo tenho que limpar antes de intercalar
// 	if( !emptyList(*L3) && clearList(L3) )
// 		printf("Lista 3 limpa, intercalando...\n");
	
// 	// primeiro copiar L para L3
// 	// trata primeiro node separado, se L tiver pelo menos 1 node
// 	int a;
// 	if( !emptyList(L) && insertOrd(L3, L->info) ){
// 		while( L->next != NULL ){
// 			L = L->next;
// 			a = insertOrd(L3, L->info);
// 		}
// 	}

// 	if( emptyList(L2) ) return; // L3 == L pois L2 esta vazia
// 	a = insertOrd(L3, L2->info); // trata primeiro node
// 	while( L2->next != NULL ){
// 		L2 = L2->next;
// 		a = insertOrd(L3, L2->info);
// 	}
// }