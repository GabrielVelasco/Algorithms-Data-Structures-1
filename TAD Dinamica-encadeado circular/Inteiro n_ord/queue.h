typedef struct node* List;
typedef unsigned int ui;
typedef long long ll;

List createList();
int getElem(List, int, int*);
int emptyList(List);
int fullList(List);
int insertBegi(List*, int);
int insertFinal(List*, int);
int removeIni(List*, int*);
int removeFinal(List*, int*);
int getSize(List);