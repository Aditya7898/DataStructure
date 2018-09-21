#include<stdio.h>

struct node{
	int info;
	struct node *prev, *next;
};

struct node *start = NULL;

void insertNodeAsFirst(){
	struct node *p;
	p = (struct node*)malloc(sizeof(struct node));
	printf("Enter a number.");
	scanf("%d", &p->info);
	p->prev = NULL;
	p->next = NULL;
	
	if(start == NULL){
		start = p;
	}else{
		start->prev = p;
		p->next = start;
		start = p;
	}
}

void deleteFirstNode(){
	if(start == NULL){
		printf("List is empty");
	}else{
		struct node *r;
		r = start;
		start = start->next;
		start->prev = NULL;
		free(r);
	}
}

void traverse(){
	struct node *t;
	
	if(start == NULL){
		printf("List is empty.");
	}else{
		t = start;
		while(t != NULL){
	       printf("%d \t", t->info);
		   t = t->next;	
		}
	}
}

int menu(){
	int ch;
	
	printf("\n 1. Insert value to list? ");
	printf("\n 2. Delete first value? ");
	printf("\n 3. View list? ");
	printf("\n 4. Exit ");
	printf("Enter your choice.");
	scanf("%d", &ch);
	
	return ch;
}


void main(){
	while(1){
		switch(menu()){
			case 1:
				insertNodeAsFirst();
				break;
			case 2:
				deleteFirstNode(); 
				break;
			case 3:
				traverse();
				break;
			case 4:
				exit(0);
			default: 
			    printf("Invalid Choice.");
		}
	}
}

