typedef struct no *Lista;
Lista cria_lista();
int lista_vazia(Lista);
int insere_elemento(Lista *lst,int elem);
int get_elemento(Lista lista, int pos, int *numero);
int tamanho(Lista lista);
int remove_elemento(Lista *lst,int elem);
int remove_maior_elemento(Lista*, int*);
int remove_todos(Lista *lista,int elem);
int esvazia(Lista *lista);
void multiplo_de_3(Lista, Lista*);
void printa(Lista);
Lista inverter_lista(Lista *lst);