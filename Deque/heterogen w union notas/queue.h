typedef struct node* Queue;

void _alloc_check(const void*, char*);
Queue _create_queue();
bool _empty_queue(Queue);
bool _full_queue(Queue);
bool _push_back(Queue, char, float, bool);
bool _pop_back(Queue, char*, float*);
bool _push_front(Queue, char, float, bool);
bool _pop_front(Queue, char*, float*);
void _print(Queue);
void _print_float(float*);
void _print_char(char*);