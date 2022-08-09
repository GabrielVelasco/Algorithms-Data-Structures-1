typedef struct deque *Deque;

Deque cria_deque();
int deque_vazio(Deque);
int insere_fim(Deque, int);
int insere_ini(Deque, int);
int remove_ini(Deque, int *);
int remove_fim(Deque, int *);
int libera_deque(Deque);
