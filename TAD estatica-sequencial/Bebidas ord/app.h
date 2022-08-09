typedef struct drinks Drinks;
typedef struct drinkList List;

List* createList();
void getPos(List* lst, char name[], int *vol, float *prince, int idx);
int emptyList(List* lst);
int fullList(List* lst);
int insertOrd(List* lst, char name[], int vol, float price);
int removeOrd(List* lst, char name[]);
int getSize(List* lst);
int clearList(List* *lst);