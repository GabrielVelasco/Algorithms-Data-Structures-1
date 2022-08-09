// ex5
typedef struct no* Lista;

Lista cria_lista();
int lista_vazia(Lista);

int insere_final(Lista *, double);
int insere_inicio(Lista*, double);
int get_elemento(Lista, int, double *);
double maior_elemento(Lista);
int tamanho(Lista);
int remove_inicio(Lista*);
int remove_final(Lista*);
int insere_posicao(Lista *,int,double);
int remove__posicao(Lista *,int);
void imprime(Lista);