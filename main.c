#include<stdio.h>
#include "list.h"

int main()
{

	int i,count;
	List list,list_a,list_b;

	
	list_init(&list);
	list_init(&list_a);
	list_init(&list_b);


	for(i=1;i<6;i=i+2)
		if(addAtTail(&list_a,i)!=0)
			return 1;
	for(i=2;i<=6;i=i+2)
		if(addAtTail(&list_b,i)!=0)
			return 1;
	
	
	print_list(&list_a);
	print_list(&list_b);


	/*if(addAtTail(&list,2)!=0)
			return 1;
	  count = count_int(&list,2);
	  printf("2 occurs %d times\n",count);*/


	/*if((count = GetNth(&list,4))==1)
			return 1;
	else
		printf("the value at index 1 is %d\n",count);*/
	
	/*
	for(i=0;i<3;i++)
	{
		printf("the value at popping is %d\n",pop(&list));
		print_list(&list);
	}*/

	/*6th test
	Node *newNode;
	if (  (newNode = (Node *)malloc(sizeof(Node))) == NULL  )	
	{
		perror("malloc memory error! ");
		return 1;
	}
	newNode->data = 3;
	newNode->next=NULL;
	sortedInsert(&list,newNode);
	print_list(&list);

	*/

	/* 8th test
	append(&list, &list1);
	print_list(&list);
	*/
	/* 9 th test
	FrontBackSplit(&list, &list1);
	print_list(&list);
	print_list(&list1);
	
	10th test
	removeDuplicate(&list);

	moveNode(&list,&list1);
	print_list(&list);
	print_list(&list1);*/
	shuffleMerge(&list , &list_a , &list_b);
	print_list(&list);
	
	

	
	destroy_list(&list);
	

	return 0;
}


