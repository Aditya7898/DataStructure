#include<stdio.h>

struct ArrayQueue{
	int front, rear;
	int capacity;
	int *array;
};

struct ArrayQueue* createQueue(int cap){

	struct ArrayQueue *queue = malloc(sizeof(struct ArrayQueue));
	queue->front = queue->rear = -1;
	queue->capacity = cap;
	queue->array = malloc(sizeof(int)*queue->capacity);
	if(!queue->array){
		return;
	}else{
	    return (queue);
	}
}

int isEmpty(struct ArrayQueue *queue){
    return(queue->front == -1);
}

int isFull(struct ArrayQueue *queue){
	return ((queue->rear+1) % (queue->capacity) == (queue->front));
}

int size(struct ArrayQueue *queue){
	return((queue->capacity - queue->front + queue->rear+1)%queue->capacity);
}

void enQueue(struct ArrayQueue *queue, int data){
	if(isFull(queue)){
		printf("\n Overflow");
	}else{
		queue->rear = (queue->rear+1) % queue->capacity;
		queue->array[queue->rear]=data;
		if(queue->front == -1){
			queue->front = queue->rear;
		}
	}
}

int deQueue(struct ArrayQueue *queue){
	int data=-1;
	if(isEmpty(queue)){
		printf("Queue is empty.");
		return -1;
	}else{
		data = queue->array[queue->front];
		if(queue->front == queue->rear){
			queue->front = queue->rear = -1;
		}else{
			queue->front = (queue->front+1)% (queue->capacity);
		}
		return data;
	}
}


void deleteQueue(struct ArrayQueue *queue){
	if(queue){
		if(queue->array){
			free(queue->array);
		}
		free(queue);
	}
}

int menu(){
	int choice;
	printf("\n 1.Enqueue ");
	printf("\n 2.Dequeue ");
	printf("\n 3.Size of queue ");
	printf("\n 4.Delete queue ");
	printf("\n 5.Exit");

	printf("\n Enter your choice ");
	scanf("%d", &choice);
	return choice;
}
int main(){
    int num, item;
	struct ArrayQueue *queue;
	queue = createQueue(4);

	while(1){
		switch(menu()){
			case 1:
			    printf("\n Enter a number: ");
			    scanf("%d", &num);
				enQueue(queue, num);
				break;
			case 2:
				item = deQueue(queue);
				if(item != -1){
                    printf("\n Dequeue Item is: %d", item);
				}
				break;
			case 3:
				item = size(queue);
				printf("\n size of queue is:  %d", item);
				break;
			case 4:
				deleteQueue(queue);
				break;
			case 5:
				exit(0);
			default:
				printf("\n ***** Invalid Choice *****");
		}
	}
}

















