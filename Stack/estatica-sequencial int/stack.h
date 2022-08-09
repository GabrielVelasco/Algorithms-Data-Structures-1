typedef struct stack* Stack;

void _alloc_check(const void*, char*);
Stack _create_stack();
int _empty_stack(Stack);
int _full_stack(Stack);
int _push(Stack, int);
int _pop(Stack, int*);
int _get_top(Stack, int*);
void _print(Stack);