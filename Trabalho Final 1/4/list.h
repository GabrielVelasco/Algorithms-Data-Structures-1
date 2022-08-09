// ex4
typedef struct node* List;
typedef unsigned int ui;
typedef long long ll;

List createList();
int getElem(List, int, char*);
int emptyList(List);
int insertOrd(List, char);
int removeOrd(List, char);
int getSize(List);
int comparaLista(List, List);
int maiorElem(List, char*);
int inserePos(List*, char);
int esvaziaLista(List);
int intercalar(List, List, List*);
void imprimiLista(List);