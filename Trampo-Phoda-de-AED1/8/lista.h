typedef struct no *Lista;

Lista cria_lista();
int get_pos(Lista, int *, int *, int);
int insere_termo(Lista *, int, int);
int remove_pot(Lista *, int);
int reset_lista(Lista *);
int calcula_poli(Lista *, int);
