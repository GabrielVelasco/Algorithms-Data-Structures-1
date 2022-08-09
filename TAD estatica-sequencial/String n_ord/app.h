typedef struct strList List;

List* createList();
char* getPos(List* lst, int idx);
int emptyList(List* lst);
int fullList(List* lst);
int insertStr(List* lst, char str[]);
int removeStr(List* lst, char str[]);
int getSize(List* lst);
int clearList(List* *lst);