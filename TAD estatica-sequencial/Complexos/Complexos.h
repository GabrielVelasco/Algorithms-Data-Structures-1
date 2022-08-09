// aqui fica as predefinocoes das funcoes e typedef

typedef struct complexos Complexos;

Complexos* cria_nro(float r, float i);
Complexos* sub(Complexos *C1, Complexos *C3);
Complexos* mult(Complexos *S, Complexos *C2);
int pega_nro(Complexos *M, float *r, float *i);
void del(Complexos **R);