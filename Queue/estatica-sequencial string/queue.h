typedef struct node* Queue;

void _alloc_check(const void*, char*);
Queue _create_queue();
int _empty_queue(Queue);
int _full_queue(Queue);
int _push_back(Queue, char*);
int _pop_front(Queue, char*);
void _print(Queue);