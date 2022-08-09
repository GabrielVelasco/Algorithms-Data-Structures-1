typedef struct node List;

List* createList();
int getPos(List* lst, int idx);
int getSize(List* lst);
int removePos(List* *lst, int idx);
int emptyList(List* lst);
int fullList(List* lst);
int insertOrd(List* *lst, int num);
int removeOrd(List* *lst, int num);
int clearList(List* *lst);