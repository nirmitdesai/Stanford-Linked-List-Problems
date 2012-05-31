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
