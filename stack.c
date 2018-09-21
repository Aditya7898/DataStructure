#include<stdio.h>

struct ArrayStack{
	int top;
	int capacity;
	int * array;
};

struct ArrayStack* createStack(int cap){
	struct ArrayStack *stack;
	stack = malloc(sizeof(struct ArrayStack));
	stack->capacity = cap;
	stack->top = -1;
	// !!!!!!!!!!!
	stack->array = malloc(sizeof(int)*stack->capacity);
	return stack;
}

int isfull(struct ArrayStack *stack){
	if(stack->capacity-1 == stack->top){
		return 1;
	}else{
		return 0;
	}
}

int isEmpty(struct ArrayStack *stack){
	if(stack->top == -1){
		return 1;
	}else{
		return 0;
	}
}

void push(struct ArrayStack *stack, int data){
	if(isfull(stack)){
		printf("\n Stack is already full.\n");
		return;
	}
	stack->top++;
	stack->array[stack->top] = data;
}

int pop(struct ArrayStack *stack){
	int item;
	if(isEmpty(stack)){
		printf("\n  Stack is Empty.\n");
		return -1;
	}
	item = stack->array[stack->top];
	stack->top--;
	return item;
}

void viewStack(struct ArrayStack *stack){
	    int i;
   		if(isEmpty(stack)){
		    printf("\n Stack is Empty.\n");
		    return;
		}
	    for(i=stack->top; i>=0; i--){
			printf("\n %d", stack->array[i]);
		}
}


int menu(){
	int choice;
	printf("\n 1.Push into the stack.");
	printf("\n 2.Pop from stack.");
	printf("\n 3.View stack values.");
	printf("\n 4.Exit");
	printf("\n Enter your choice.");
	scanf("%d", &choice);
	return choice;
}
int main(){
    int num, item;
	struct ArrayStack *stack;
	stack = createStack(4);
	while(1){
		switch(menu()){
			case 1:
				printf("\n Enter a number.");
				scanf("%d", &num);
				push(stack, num);
				break;
			case 2:
				item = pop(stack);
				if(item != -1){
					printf("\n Popped value is %d", item);
				}
				break;
			case 3:
				viewStack(stack);
				break;
			case 4:
				exit(0);
			default:
				printf("**** Invalid Choice ****");
		}
	}
	return 0;
}





