// ex7
typedef struct node* List;
typedef unsigned int ui;
typedef long long ll;

List _cria_lista();
int _lista_vazia(const void*);
int _insere_soldado(List*, char*);
int _busca_nome(List, char*, int);
void _printa_lista(List);
void _remove_cur_next(List);
void _contador_elimina(List*, List, int, int, char*, List*);
void _get_elem(List, int, int, char*);
void _alloc_check(const void*);
void _limpa_lista(List*);