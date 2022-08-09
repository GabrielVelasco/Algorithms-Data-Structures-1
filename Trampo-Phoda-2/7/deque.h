typedef struct node* Deque;

void _alloc_check(const void*, char*);
Deque _create_deque();
bool _empty_deque(Deque);
bool _full_deque(Deque);
bool _push_back(Deque, int);
bool _pop_back(Deque, int*);
bool _push_front(Deque, int);
bool _pop_front(Deque, int*);
void _print(Deque);
void _print_node(int);
void _delete_deque(Deque*);