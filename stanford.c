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
