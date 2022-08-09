typedef struct node* List;
typedef unsigned int ui;
typedef long long ll;

List createList();
int getPos(List, int, int, float*, int);
int removeInit(List*);
int emptyList(List);
int insertRecOrd(List*, float);
int insertFinal(List*, float);
int removeRecOrd(List*, float);
int getSize(List);
void imprimiLista(List);
void clearList(List*);