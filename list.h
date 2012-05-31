#ifndef LIST_H
#define LIST_H
#include<stdlib.h>

typedef struct node_
{
	int data;	
	struct node_ *next;
}Node;

typedef struct list_
{
	int size;
	Node *head;
	Node *tail;
}List;

void list_init(List *list);

#define list_size(list) ((list)->size)

#endif
