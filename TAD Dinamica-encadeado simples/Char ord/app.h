typedef struct node List;

List* createList();
List* getPos(List* lst, char elem);
int emptyList(List* lst);
int insertOrd(List* *lst, char elem);
int removeOrd(List* *lst, char elem);
int clearList(List* *lst);
char getElem(List* *lst);