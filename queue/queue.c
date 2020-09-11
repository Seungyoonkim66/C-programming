#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef struct queue {
	int rear;
	int front;
	int *data;
}Queue;

void initQueue(Queue *queue, int q) {
	queue->front = queue->rear =0;
	queue->data = (int*)malloc(sizeof(int) * q);
	for (int i = 0; i < q; i++) {
		queue->data[i] = 0;
	}
}

int underflow(Queue *queue) {
	if (queue->front == queue->rear)
		return 1;
	else return 0;
}
//1을 반환하면 공백상태이므로 underflow / dequeue denied

int overflow(Queue *queue, int q) {
	if (((queue->rear + 1) % q) == queue->front)
		return 1;
	else return 0;
}
// 1을 반환하면 full이므로 overflow / enqueue denied

void enqueue(Queue *queue, int data, int q) {
	//if (overflow(&queue, q) == 1) {
	//	printf("overflow");

	//	for (int i = 0; i < q; i++) {
	//		printf(" %d", queue->data[i]);
	//	}
	//	printf("\n");
	//	return;
	//}
	//else {
		queue->rear = (queue->rear + 1) % q;
		queue->data[queue->rear] = data;
	//}
	return;
}

void print(Queue *queue, int q) {
	int i = queue->front;
	//if (underflow(queue) == 1) {
	//	return;
	//}

	for (int i = 0; i < q; i++) {
		printf(" %d", queue->data[i]);
	}
	printf("\n");

	return;
	
}

void dequeue(Queue *queue, int q) {
	//if (underflow(queue) == 1) {
	//	printf("underflow\n");
	//	return;
	//}
	//else {
		queue->data[queue->front+1] = 0;
		queue->front = (queue->front + 1) % q;
		return;
	//}
}


int main (void){

	Queue queue;
	int q, n;
	char op;

	scanf("%d", &q); // 원형 큐의 크기
	scanf("%d", &n); // 연산의 개수 

	initQueue(&queue, q);


	for (int i = 0; i < n;) {

		int data;
		
		scanf(" %c", &op);
		
		

		if (overflow(&queue, q) == 1) {
			printf("overflow");

			for (int i = 0; i < q; i++) {
				printf(" %d", queue.data[i]);
			}
			printf("\n");

			return;
		}
		else if (underflow(&queue, q) == 1) {
			printf("underflow");
			return;
		}

		else {
			switch (op) {
			case 'I':
				scanf(" %d", &data);
				enqueue(&queue, data, q);
				break;
			case 'D':
				dequeue(&queue, q);
				break;
			case 'P':
				print(&queue, q);
				break;
			default:
				printf("\n");
			}

		}
		

		i++;
	}

	return 0;

}