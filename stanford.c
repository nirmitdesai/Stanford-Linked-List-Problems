#include<string.h>
#include<stdlib.h>
#include<stdio.h>
#include<math.h>
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

void sortedInsert(List *list , Node *newNode)
{
	Node *temp;
	
	for(temp = list->head;temp->next != NULL && temp->next->data <= newNode->data; temp = temp->next)	
		;
	
	newNode->next = temp->next;
	temp->next = newNode;	

	if(newNode->next == NULL)
		list->tail = newNode;

	list->size++;
}

void append(List *list , List *list_a)
{
	if(list_a->size == 0)
	{
		printf("The list to be appened is empty so this is same as original list!\n");
		memset(list_a, 0, sizeof(List));
		return;
	}
	if(list->size==0)
	{
		list->head = list_a->head;
	}
	else
	{
		list->tail->next = list_a->head;
	}
	
	list->size = list_a->size + list->size;
	list->tail = list_a->tail;
	list_a->head = list_a->tail = NULL;
	list_a->size=0;
	memset(list_a, 0, sizeof(List));
}

void frontBackSplit(List *list , List *list1)
{
	
	if(list->size <2)
	{
		printf("Cannot split list of size 0 or 1!");
		exit(1);
	}	
	
	int nosInList = (int)ceil(list->size/2.0);
	int i;
	Node *temp = list->head;
	
	for(i=1;i<nosInList;i++,temp=temp->next)
		;

	list1->head = temp->next;
	list1->tail = list->tail;
	list->tail = temp;
	list->tail->next = NULL;
	list1->size = list->size - nosInList;
	list->size = nosInList;

	
}

void removeDuplicates(List *list)
{

	if(list->size==0 || list->size==1)
	{
		printf("Can't remove duplicates from list of size 0 or 1!\n");
		exit(1);
	}
	Node *temp = list->head;
	while(temp->next!=NULL)
	{
		if(temp->data == temp->next->data)
		{
			Node *newNext = temp->next->next;
			free(temp->next);
			list->size--;
			temp->next = newNext;
			if(temp->next == NULL)
				list->tail = temp;

			temp = temp->next;		
		}
		else
			temp = temp->next;
	}
}

void moveNode(List *list, List *list1)
{
	if(list1->size == 0 )
	{
		printf("Can't call moveNode when size of source list is 0!\n");
		exit(1);
	}
	
	Node *temp = list1->head;
	list1->head = list1->head->next;	
	temp->next = list->head;
	list->head = temp;
	list->size++;
	list1->size--;
}

void alternatingSplit(List *list, List *list_a , List *list_b)
{
	int i, k = list->size;
	Node *temp = list->head;
	
	for(i=1;i<=(int)ceil(k/2.0);i++)
	{
		moveNode(list_a,list);
		
		if(list->head!=NULL)
			moveNode(list_b,list);
	}
}


void shuffleMerge(List *list, List *list_a , List *list_b)
{
	Node *aHead = list_a->head;
	Node *bHead = list_b->head;
	Node *temp;
	list->head = list_a->head;

	if(list_a->size > list_b->size)
		list->tail = list_a->tail;
	else
		list->tail = list_b->tail;


	list->size = list_a->size + list_b->size;
	while(aHead != NULL && bHead !=NULL)
	{
		temp=aHead;
		aHead = aHead->next;
		temp->next = bHead;
		
		temp = bHead;
		bHead = bHead->next;
		temp->next = aHead;
	}

	list_a->head = list_a->tail = NULL;
	list_b->head = list_b->tail = NULL;
	list_a->size = list_b->size = 0;
	

}

void sortedMerge(List *list , List *list_a , List *list_b)
{
	

	while(list_a->head != NULL && list_b->head != NULL)
	{
		if(list_a->head->data 	<= list_b->head->data)
			moveNode(list,list_a);
		else
			moveNode(list,list_b);		
	}
	while(list_a->head != NULL)
		moveNode(list,list_a);
	while(list_b->head != NULL)
		moveNode(list,list_b);

	
	
}


void sortedIntersect(List *list , List *list_a , List *list_b)
{
	Node *aHead = list_a->head;
	Node *bHead = list_b->head;
		
	while( aHead !=NULL && bHead!= NULL)
	{
		if(aHead->data == bHead->data)
		{
			addAtTail(list,aHead->data);
			aHead = aHead->next;
			bHead = bHead->next;
		}
		else if ( aHead->data < bHead->data)
			aHead = aHead->next;
		else
			bHead = bHead->next;
	}

}











