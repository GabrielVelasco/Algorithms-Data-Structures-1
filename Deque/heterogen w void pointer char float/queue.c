#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "queue.h"

struct node{
    bool key; /// se key == true node armazena float, se key == false armazena char
	void* info; /// item armazenado pelo node
	struct node* next;
	struct node* prev;

};

struct queue{
    int size;
    struct node* front;
    struct node* back;

};

void _alloc_check(const void* p, char msg[]){
    if(p == NULL){
        perror(msg);
        exit(EXIT_FAILURE);
    }
}

Queue _create_queue(){
    Queue qu = (Queue) malloc(sizeof(struct queue));
    _alloc_check(qu, "Error while allocating queue!");

    qu->front = NULL;
    qu->back = NULL;
    qu->size = 0;

    return qu;
}

bool _is_empty(Queue qu){
	// lst == no cabecalho
	if(qu->front == NULL)
		return 1;
	else
		return 0;
}

bool _push_back(Queue qu, char c_grade, float f_grade, bool key){
	Node* node = (Node*) malloc(sizeof(Node));
	_alloc_check(node, "Error while allocating node!");
    node->key = key;

	if(key){
        /// add um float
        float *p = (float*) malloc(sizeof(float));
        _alloc_check(p, "Error while allocating float pointer!");
        *p = f_grade;
        node->info = p;
    }else{
        /// add um char
        char *p = (char*) malloc(sizeof(char));
        _alloc_check(p, "Error while allocating char pointer!");
        *p = c_grade;
        node->info = p;
    }

	// node vai na ultima posicao
	node->next = NULL;
	node->prev = qu->back; /// novo ultimo node aponta para penultimo
	if(_is_empty(qu)) 
        qu->front = node;
    else 
        qu->back->next = node; /// penultimo node aponta para novo ultimo
	qu->back = node; /// novo ultimo node
    qu->size ++;

	return 1;
}

bool _pop_back(Queue qu, char* c_grade, float* f_grade){
    if(_is_empty(qu)) return 0;

    Node* tmp = qu->back; /// aponta p/ node a ser deletado
    /// copia a informacao a ser excluida
    if(tmp->key){
        /// vai remover um float
        *f_grade = *((float*)tmp->info);
    }else{
        /// vai remover um char
        *c_grade = *((char*)tmp->info);
    }

    qu->back = tmp->prev; /// aponta para novo ultimo node
    if(tmp == qu->front)
        qu->front = NULL;
    else
        qu->back->next = NULL;
    free(tmp->info);
    free(tmp);
    qu->size --;

    return 1;
}

bool _push_front(Queue qu, char c_grade, float f_grade, bool key){
    Node* node = (Node*) malloc(sizeof(Node));
    _alloc_check(node, "Error while allocating node!");
    node->key = key;

    if(key){
        /// add um float
        float *p = (float*) malloc(sizeof(float));
        _alloc_check(p, "Error while allocating float pointer!");
        *p = f_grade;
        node->info = p;
    }else{
        /// add um char
        char *p = (char*) malloc(sizeof(char));
        _alloc_check(p, "Error while allocating char pointer!");
        *p = c_grade;
        node->info = p;
    }

    // node vai na primeira pos
    node->next = qu->front;
    node->prev = NULL; /// novo primeiro node nao tem antecessor
    if(_is_empty(qu)) 
        qu->back = node;
    else 
        qu->front->prev = node; /// atual primeiro node aponta de volta para node
    qu->front = node; /// novo primeiro node
    qu->size ++;

    return 1;
}

bool _pop_front(Queue qu, char* c_grade, float* f_grade){
    if(_is_empty(qu)) return 0;

    Node* tmp = qu->front; /// aponta p/ node a ser deletado
    /// copia a informacao a ser excluida
    if(tmp->key){
        /// vai remover um float
        *f_grade = *((float*)tmp->info);
    }else{
        /// vai remover um char
        *c_grade = *((char*)tmp->info);
    }

    qu->front = tmp->next; /// aponta para novo primeiro node
    if(tmp == qu->back)
        qu->back = NULL;
    else
        qu->front->prev = NULL;
    free(tmp->info);
    free(tmp);
    qu->size --;

    return 1;
}

bool _get_elem(Queue qu, int idx, char *c_grade, float* f_grade){
	if(_is_empty(qu) || idx >= qu->size || idx < 0) return 0; // pos n existe

    Node* tmp = qu->front; /// ponteiro para o primeiro node
	while(idx --)
		tmp = tmp->next;

    if(tmp->key)
        *f_grade = *((float*)tmp->info);
    else
        *c_grade = *((char*)tmp->info);

	return 1;
}

void _remove_elem_front(Queue qu, Node** node){
    /// se elemento a ser removido estiver no primeiro node
    /// conteudo dentro deste endereco de mem eh um ponteiro para o node
    /// a ser removido
    qu->front = (*node)->next; /// aponta para novo primeiro node
    if(*node == qu->back)
        qu->back = NULL;
    else
        qu->front->prev = NULL; /// nao tem node antecessor (primeiro node)
    free((*node)->info);
    free(*node);
    qu->size --;
}

void _remove_elem_back(Queue qu, Node** node){
    /// se elemento a ser removido estiver no ultimo node
    /// conteudo dentro deste endereco de mem eh um ponteiro para o node
    /// a ser removido
    qu->back = (*node)->prev; /// aponta para novo ultimo node
    if(*node == qu->front)
        qu->front = NULL;
    else
        qu->back->next = NULL;
    free((*node)->info);
    free(*node);
    qu->size --;
}

bool _remove_elem(Queue qu, char c_grade, float f_grade, bool rem_float){
    if(_is_empty(qu)) return 0;

    Node* tmp = qu->front;
    int ch = 0;
    float f;
    char c;
    /// optimizar esta parte!
    while(tmp != NULL){
        if(tmp->key && rem_float){
            f = *((float*)tmp->info);
            if(f == f_grade){
                /// entrou aqui, este node sera removido
                if(tmp == qu->front){
                    /// elemento a ser removido esta no primeiro node
                    /// passa end de mem do node a ser removido
                    _remove_elem_front(qu, &tmp);
                    return 1;

                }else if(tmp == qu->back){
                    /// elemento esta no ultimo node
                    _remove_elem_back(qu, &tmp);
                    return 1;
                }else
                    ch = 1; /// elemento a ser removido esta entre o 1 e ultimo node.
            }

        }else if(!tmp->key && !rem_float){
            c = *((char*)tmp->info);
            if(c == c_grade){
                /// node sera removido
                if(tmp == qu->front){
                    /// elemento a ser removido esta no primeiro node
                    _remove_elem_front(qu, &tmp);
                    return 1;

                }else if(tmp == qu->back){
                    /// elemento esta no ultimo node
                    _remove_elem_back(qu, &tmp);
                    return 1;
                }else
                    ch = 1;
            }
        }

        if(ch){
            /// elemento a ser removido esta entre o 1 e ultimo node.
            if(tmp->next != NULL) tmp->next->prev = tmp->prev;
            if(tmp->prev != NULL) tmp->prev->next = tmp->next;
             
            free(tmp->info);
            free(tmp);
            qu->size --;

            return 1;
        }

        tmp = tmp->next;
    }

    return 0; /// nao existe na lista
}

void _print(Queue qu){
    Node* tmp = qu->front;
    if(tmp == NULL)
        _print_empty_msg();
    while(tmp != NULL){
        if(tmp->key)
            _print_float_char(tmp->info, 1);
        else
            _print_float_char(tmp->info, 0);
        tmp = tmp->next;
    }
}