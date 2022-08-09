typedef struct node* Node;
typedef struct queue* Queue;

void _alloc_check(const void*, char*);
Queue _create_queue();
bool _empty_queue(Queue);
bool _push_back(Queue, char*, int, float);
bool _pop_front(Queue, char*);
bool _print(Queue);
void _erase_queue(Queue*);