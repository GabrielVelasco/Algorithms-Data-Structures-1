typedef struct node* Stack;

void _alloc_check(const void*, char*);
Stack _create_stack();
int _empty_stack(Stack);
int _full_stack(Stack);
int _push(Stack*, char, float, int);
int _pop(Stack*, char*, float*);
int _get_top(Stack*, char*);
int _is_valid(Stack*, char*);
int _preced_op(char);
int _solve_post_fix(Stack*, char*, float*);
void _print(Stack);
void _clean(Stack*);
void _infix_to_post(Stack*, char*);
void _print_elem(char, float, int);
void _empty_msg();