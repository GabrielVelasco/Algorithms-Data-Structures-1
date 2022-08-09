#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "queue.h"

struct queue{
    //int count; /// salva quantidade de node na minha queue
    struct node* front;
    struct node* back;

};

struct node{
    char name[50];
    float prc;
    int vol;
    struct node* next;

};

void _alloc_check(const void* p, char msg[]){
    if(p == NULL){
        perror(msg);
        exit(EXIT_FAILURE);
    }
}

Queue _create_queue(){
    Queue qu = (Queue) malloc(sizeof(struct queue));
    _alloc_check(qu, "Error while allocating queue");
    qu->front = NULL;
    qu->back = NULL; 
    //qu->count = 0; /// inicialmente lista vazia

    return qu;
}

bool _empty_queue(Queue qu){ if(qu->front == NULL) return true; else return false; }

bool _push_back(Queue qu, char name[], int vol, float prc){
    /// Node == ponteiro para struct node
    Node node = (Node) malloc(sizeof(struct node));
    _alloc_check(node, "Error while allocating node");

    /// instancia valores para nova bebibda(node)
    strcpy(node->name, name);
    node->vol = vol;
    node->prc = prc;
    node->next = NULL; /// add final, logo node nao tem node sucessor

    if(_empty_queue(qu))
        qu->front = node; /// 
    else
        (qu->back)->next = node;

    qu->back = node;
    return true;
}

bool _pop_front(Queue qu, char data[]){
    if(_empty_queue(qu)) return false;

    Node tmp = qu->front; /// aponta para node a ser excluido
    strcpy(data, tmp->name); /// copia informacao do elemento a ser removido
    if(qu->front == qu->back)
        qu->back = NULL; /// queue so tem um node e ele sera removido
    qu->front = tmp->next;
    free(tmp);
    return true;
}

void _erase_queue(Queue *qu){
    char *data;
    while(_pop_front(*qu, data)) /// primeiro libera node por node

    free(*qu); /// libera ponteiro para struct queue
    *qu = NULL;
}

bool _print(Queue qu){
    if(qu == NULL || _empty_queue(qu)) return false;
    Node tmp = qu->front;
    while(tmp->next != NULL){
        printf("[%s %d %.2f] ", tmp->name, tmp->vol, tmp->prc);
        tmp = tmp->next;
    }
    printf("[%s %d %.2f]\n", tmp->name, tmp->vol, tmp->prc);
    return true;
}