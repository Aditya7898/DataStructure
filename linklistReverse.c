#include<stdio.h>

void insertNodeAtLast(int val)
{
	struct node *temp, *t;
	temp = createNode();
    temp->info = val;
	temp->link = NULL;
	if(start == NULL){
		start = temp;
	}else{
		t = start;
		while(t->link != NULL){
			t = t->link;
		}
		t->link = temp;
	}
}

