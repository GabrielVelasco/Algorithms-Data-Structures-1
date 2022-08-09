typedef struct node_doadores* Qu_don;

Qu_don _create_list_d();
int _push_back_donator(Qu_don*, char*, char[][300], int);
int _print_donator_queue(Qu_don*);
int _clean_don_queue(Qu_don*);
void _print_don_node(char*, char[][300]);