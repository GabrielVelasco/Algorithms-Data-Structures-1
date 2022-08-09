typedef struct node List;
typedef unsigned int ui;

List* createList();
int getSize(List* lst);
int getPos(List* lst, int idx, ui *matr, char name[], float *mean, int *missed);
int emptyList(List* lst);
int fullList(List* lst);
int insertElem(List* *lst, ui matr, char name[], float mean, int missed);
int removeElem(List* *lst, ui matr);
int clearList(List* *lst);