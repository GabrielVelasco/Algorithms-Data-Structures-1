// aqui fica as predefinocoes das funcoes e typedef

typedef struct racional Racional;

Racional* generate();
Racional* sum(Racional *R1, Racional *R2);
int set_velue(Racional *R, int n, int d);
int get_value(Racional *R, int *n, int *d);
void del(Racional **R);