typedef struct fila* FILA;
FILA cria_fila();
int fila_vazia(FILA f);
int fila_cheia(FILA f);
int insere(FILA f,char matricula[15],char nome[100],float CRA,int carga_horaria,int ano_ingresso);
int remover(FILA f,char matricula[15],char nome[100],float *CRA,int *carga_horaria,int *ano_ingresso);
int esvazia(FILA f);
