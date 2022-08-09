// aqui fica as predefinocoes das funcoes e typedef

typedef struct lista Lista;

Lista* cria_lista();
int lista_vazia(Lista *l);
int lista_cheia(Lista *l);
int insere_ord(Lista *l, float elem);
int remove_ord(Lista *l, float elem);
int get_pos(Lista *l, float elem, int *p);
int get_elem(Lista *l, int *idx, float *elem);
void limpa_lista(Lista **l);