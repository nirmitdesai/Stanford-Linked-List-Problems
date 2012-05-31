#include<string.h>
#include<stdlib.h>
#include<stdio.h>
#include "list.h"

int count_int(List *list , int searchFor)
{
	Node *temp;
	int count=0;
	
	for(temp=list->head ; temp!=NULL;temp=temp->next)
		if(searchFor == temp->data)
			count++;

	return count;
}

int getNth(List *list , int index)
{
	if(index < 0 )
	{
		printf("You cannot specify a negative index\n");
		exit(1);
	}
	else if(index>list->size-1)
	{
		printf("Index specified is out of range\n");
		exit(1);
	}
	else
	{
		int i;
		Node *temp = list->head;
		for(i=0;i!=index;i++)
			temp=temp->next;

		return temp->data;
	}
}

void destroy_list(List *list)
{
	Node *temp = list->head;
	Node *prev = list->head;

	if(temp==NULL)
	{
		printf("cannot destroy empty list !! ");
		return;
	}
	
	while(temp!=NULL)
	{
		
		temp=temp->next;
		free(prev);
		prev= temp;
	}
	list->head = list->tail = NULL;
	list->size=0;
	memset(list, 0, sizeof(List));
}

int pop(List *list)
{
	if(list->size == 0)
	{
		printf("Cannot pop from an empty list !\n");
		exit(1);
	}

	int data = list->head->data;
	Node *temp = list->head;
	list->head = list->head->next;
	free(temp);
	list->size--;

	return data;

}

int insertAtAnyPosition(List *list , int data,int count)
{
	Node *temp = list->head;
	Node *prev = list->head;
	Node *newNode;
	
	if(count == 0) //insertion at 0th position a.k.a head , 
		addAtHead(list,data);	
	else if(count == list->size) 
		addAtTail(list,data);
	else
	{
		if (  (newNode = (Node *)malloc(sizeof(Node))) == NULL  )	
		{
			perror("malloc memory error!");
			return -1;
		}
		newNode->data = data;
		while(count)
		{
			temp = temp->next;
			count=count-1;
		}
		
		while(prev->next!=temp)
			prev = prev->next;
		
		prev->next = newNode;
		newNode->next = temp;
		
	}
	list->size++;
	return 0;

}
