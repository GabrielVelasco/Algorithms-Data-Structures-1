typedef struct node List;

List* createList();
List* getPos(List* lst, char elem);
int emptyList(List* lst);
int insertElem(List* *lst, char elem);
int removeElem(List* *lst, char elem);
int clearList(List* *lst);
char getElem(List* *lst);