typedef struct fila *Fila;

Fila cria_fila();
int fila_vazia(Fila);
int insere_cliente(Fila, int, int, int);
int remove_cliente(Fila, int *, int *, int *);
int tamanho_fila(Fila);
