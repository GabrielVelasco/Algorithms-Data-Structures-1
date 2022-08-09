// ex 1
typedef struct lista *Lista;

Lista cria_lista();

int lista_cheia(Lista);
int lista_vazia(Lista);
int insere_elemento_nao_ordenado(Lista, int);
int remove_elemento_nao_ordenado(Lista, int);
int get_elemento(Lista,int,int*);
int tamanho();
int quantidade_elementos(Lista);
int menor_elemento(Lista);
int esvazia(Lista);
int remove_impares(Lista lista);
Lista inverte(Lista);
Lista concatena(Lista l1, Lista l2);
