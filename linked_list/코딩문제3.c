#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

typedef struct node {
	char item;
	struct node* prev;
	struct node* next;
}Node;

int size;

void initList(Node *h, Node *t) {
	h->prev = NULL;
	h->next = t;
	t->prev = h;
	t->next = NULL;
	size = 0; // 노드 개수 
}

int insert(Node *h, int e){
	Node* newnode = (Node*)malloc(sizeof(Node));
	newnode->item = e;
	newnode->next = h->next;
	newnode->prev = h;
	h->next->prev = newnode;
	h->next = newnode;
	size ++;

	return 0;
}

int print(Node *h){
	int i, j;

	for (j = 0; j < 3; j++) {
		printf("line %d : ", j);
		for (i = 0; i < size/3; i++) {
			if (h->next == NULL)break;
			else {
				printf(" %d", h->next->item);
				h = h->next;
			}
		}
		printf("\n");
	}	
	return 0;
}

int delete(Node* h, int k) {
	int i;
	Node* temp = h->next;
	

	while (temp->item != k) {
		if (temp->next == NULL) {
			printf("There is no %d in the list\n", k);
			return 0;
		}
		else {
			temp = temp->next;
		}
	}
	printf("삭제할 노드 : %d\n", temp->item);

	
	(temp->prev)->next = temp->next;
	(temp->next)->prev = temp->prev;

	free(temp);

	size--;
	return 0;
}

int main() {
	int i;
	int item, k;
	int op;

	Node* h = (Node*)malloc(sizeof(Node));
	Node* t = (Node*)malloc(sizeof(Node));

	initList(h, t);
	
	srand(time(NULL));
	for (i = 0; i < 60; i++) {
		item = rand() % 1000;
		insert(h, item);
	}

	print(h);
	printf("the number of nodes in the list : %d\n", size);

	printf("enter delete number among the list:");
	scanf("%d", &k); 
	
	delete(h, k);

	print(h);
	printf("the number of nodes in the list : %d\n", size);

	return 0;


}