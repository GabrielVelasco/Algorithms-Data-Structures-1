typedef struct node* List;
typedef unsigned int ui;
typedef long long ll;

List createList();
int getElem(List, int);
int emptyList(List);
int fullList(List);
int insertOrd(List, int);
int removeOrd(List, int);
int getSize(List);