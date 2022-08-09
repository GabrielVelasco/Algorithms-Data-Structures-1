typedef struct node* List;
typedef unsigned int ui;
typedef long long ll;

List createList();
int getElem(List, int, int*);
int emptyList(List);
int insertElem(List*, int);
int removeElem(List*, int);
int getSize(List);
void imprimiLista(List);