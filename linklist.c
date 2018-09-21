#include<stdio.h>
#include<string.h>
#include<conio.h>
struct node
{
	int info;
	struct node *link;
};

struct node *start = NULL; // NULL ko stdio.h me declare kia hai.

struct node* createNode(){
	struct node *p;        // p me node type ka address hoga
	p = (struct node *)malloc(sizeof(struct node));
	return (p);              // node type ka address return hoga.
}

// Insert node at last
void insertNodeAtLast()
{
	struct node *temp, *t;
	temp = createNode();
	printf("\n Enter number ");
	scanf("\n %d", &temp->info);
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

// Insert node at start
void insertNodeAtStart(){
	struct node *t;
	t = createNode();
	printf("\n Enter number");
	scanf("%d", &t->info);
	t->link = NULL;
	
	if(start == NULL){
		start = t;
	}else{
		struct node *p;
		p = start;
		start = t;
		start->link = p;
	}
}

// Insert at position
void insertAtPosition(int val, int pos){
	struct node *t, *p, *temp;
	int count = 0;
	t = start;
	temp = createNode();
	temp->info = val;
	temp->link = NULL;
	
	if(start == NULL && pos>0){
		printf("Invalid position.");
		return;
	}
	if(start == NULL && pos==0){
		start = temp;
		return;
	}
	if(start != NULL && pos == 0){
		p = start;
		start = temp;
		start->link = p;
		return;
	}
	while(count != pos){
		p = t;
		t = t->link;
		count++;
	}
	temp->link = p->link;
	p->link = temp;
}

// Delete Top Node 
void deleteNode(){ 
	struct node *r;
	if(start == NULL){
		printf("\n List is empty.");
	}else{
    	r = start;
		start = start->link;
		free(r);	
	}
}

// Delete last Node 
void deleteLastNode(){
	if(start == NULL){
		printf("\n List is empty.");
	}
	else if(start-> link == NULL){
		free(start);
		start = NULL;
	}
	else{
		struct node *t = start;
		struct node *p;
		
		while(t->link != NULL){
			p = t;
			t = t->link;
		}
		free(t);
		p->link = NULL;
	}
}
// Delete by value
void deleteByValue(int val){
	struct node *p, *q;
	p = start;
	
	if(p == NULL){
		printf("Empty List....");
		return;
	}
	if(p->info == val && p != NULL){
		start = p->link;
		free(q);
		return;
	}
	
	while(p != NULL && p->info != val){
		q = p;
		p = p->link;
	}
	if(p == NULL){
		printf("NOT FOUND");
		return;
	}else{
		q->link = p->link;
		free(p);
	}
}

// Delete All
void deleteAll(){
	struct node *p, *q;
	p = start;
	
	if(start == NULL){
		printf("Empty list.");
		return;
	}
	while(p != NULL){
		q = p->link;
		free(p);
		p = q;
	}
	start = NULL;
}
// traverse 
void traverse(){
	struct node *s;
	
	if(start==NULL){
		printf("\n List is Empty.");
	}else{
		s = start;
		while(s != NULL){
		   printf("\t %d ", s->info);
		   s = s->link;
	    }	
	}
}

int menu(){
	int ch;
	
	printf("\n 1. Insert value at last position ? ");
	printf("\n 2. Insert value at first position ?");
	printf("\n 3. Insert value at specific position..?");
	printf("\n 4. View list? ");
	printf("\n 5. Delete first value?");
	printf("\n 6. Delete last value?");
	printf("\n 7. Delete By Value.. ");
	printf("\n 8. Delete all values.");
	printf("\n 9. exit ");
	printf("Enter your choice.");
	scanf("%d", &ch);
	
	return ch;
}

void main(){
	int num, pos;
	while(1){
		switch(menu()){
			case 1:
				insertNodeAtLast();
				break;
				
			case 2:
				insertNodeAtStart();
				break;

			case 3:
				printf("Enter value: ");
				scanf("%d", &num);
				printf("Enter position: ");
				scanf("%d", &pos);
				insertAtPosition(num, pos);
				break;

				
			case 4:
				traverse();
				break;
				
			case 5:
				deleteNode();
				break;
				
			case 6:
				deleteLastNode();
		        break;
		        
		    case 7:
		    	printf("Enter value to delete: ");
		    	scanf("%d",&num);
		    	deleteByValue(num);
		    	break;
		    case 8:
		    	deleteAll();	
		    	break;
			case 9:
				exit(0);
				
			default: 
			    printf("Invalid Choice.");
		}
	}
}

