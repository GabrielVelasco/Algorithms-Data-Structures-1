typedef struct node* List;
typedef unsigned int ui;
typedef long long ll;

List createList();
int getElem(List, int);
int emptyList(List);
int fullList(List);
int insertElem(List, int);
int removeElem(List, int);
int clearList(List* lst);
int getSize(List);