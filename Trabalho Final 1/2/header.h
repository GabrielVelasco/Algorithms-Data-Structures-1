typedef struct lista *Lista;

Lista cria_lista();
int insere_ordenado(Lista lst, int elem);
int remove_ordenado(Lista lst, int elem);
int lista_cheia(Lista lista);
int lista_vazia(Lista lista);
int quantidade_elementos(Lista lista);
int get_elemento(Lista,int pos,int* n);
int esvazia(Lista lista);
int remove_pares(Lista lista);
int tamanho();
int maior_elemento(Lista lista);
Lista intercala(Lista lista1,Lista lista2);
