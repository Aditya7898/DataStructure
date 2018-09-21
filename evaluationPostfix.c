#include<stdio.h>
#include<string.h>

struct Stack{
	int top;
	unsigned capacity;
	int* array;
};

// Stack operations -
struct Stack* createStack(unsigned cap){
    struct Stack* stack = (struct Stack*) malloc(sizeof(struct Stack));
	
	if(!stack){
		return NULL;
	}
	stack->top = -1; stack->capacity = cap;
	stack->array = (int*)malloc(sizeof(int) * (stack->capacity));
	
	if(!stack->array){
		return NULL;
	}
	return stack;
}

int isEmpty(struct Stack* stack){
	return stack->top ==-1 ;
}

char peek(struct Stack* stack){
		return stack->array[stack->top];
}

char pop(struct Stack* stack){
	if(!isEmpty(stack)){
		return stack->array[stack->top--];
	}
	return '$';
}

void push(struct Stack* stack, char ch){
	stack->array[++stack->top] = ch;
}

// The main function that returns value of a given postfix expression;
int evaluatePostfix(char* exp){
	int i;
	// create stack of capacity equal to expression size;
	struct Stack* stack = createStack(strlen(exp));
	
	// see if stack was created successfully:
	if(!stack){
		return -1;
	}
	
	// scan all the char one by one:
	for(i=0; exp[i]; ++i){
		
		// if scanned char are operand then
	    if(isdigit(exp[i])){                    // <<<<<<======== *******imp*******
	    	push(stack, exp[i]-'0');
		}
		
		// if scanned char is operator
		else{
			int val1 = pop(stack);
			int val2 = pop(stack);
			switch(exp[i]){
				case '+':
					push(stack, val2+val1);
					break;
				case '-':
					push(stack, val2-val1);
					break;
				case '*':
					push(stack, val2*val1);
					break;
				case '/':
					push(stack, val2/val1);
					break;
			}
		}	
	}
	return pop(stack);
}

int main(){
	char exp[]="231*+9-";
	printf("Value of %s is %d", exp, evaluatePostfix(exp));
	return 0;
}










