typedef struct queue* Queue;
typedef struct node Node;
typedef unsigned int ui;
typedef long long ll;

Queue _create_queue();
bool _is_empty(Queue);
bool _push_back(Queue, char, float, bool);
bool _push_front(Queue, char, float, bool);
bool _pop_front(Queue, char*, float*);
bool _pop_back(Queue, char*, float*);
bool _get_elem(Queue, int, char*, float*);
bool _remove_elem(Queue, char, float, bool);
void _print(Queue);
void _print_float_char(void*, int);
void _print_empty_msg();
void _remove_elem_front(Queue, Node**);
void _remove_elem_back(Queue, Node**);