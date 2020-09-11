#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct node {
	char item;
	struct node *next;
	struct node *prev;
} Node;

typedef struct list {
	Node *head;
	Node *tail;
	int n;
}List;

typedef List *Plist;

void initList(Plist list){
	list->head = NULL;
	list->tail = NULL;
	list->n = 0;
	printf("initlist success\n");
}

Node* newNode(char item) {
	Node *node = (Node*)malloc(sizeof(Node));
	node->item = item;
	node->prev = NULL;
	node->next = NULL;
	return node;
}

void add(Plist list, int position, char item) {

	printf("add\n");
	Node *newnode = newNode(item);

	(list->n)++;

	if (position <= 0 || list->n < position) {
		printf("invalid position\n");
	}
	// 리스트 처음 위치에 item 추가할 경우 
	if (position == 1) {
		if (list->head == 0) {
			list->head = newnode;
			list->tail = newnode;
		}
		else {
			Node *cur = list->head;
			list->head = newnode;
			cur->prev = newnode;
			newnode->next = cur;
		}
	}
	//마지막 위치에 item 추가할 경우 
	else if (position == list->n) {
		Node *cur = list->tail;
		list->tail = newnode;
		cur->next = newnode;
		newnode->prev = cur;
	}
	// 리스트 중간에 item 추가할 경우 
	else {
		Node *cur = list->head;
		for (int i = 0; i < position; i++) {
			cur = cur->next;
		}

		Node *prenode = cur->prev;

		newnode->prev = prenode;
		newnode->next = cur;
		prenode->next = newnode;
		cur->prev = newnode;
	}
}

void delete(Plist list, int position) {
	if (position <= 0 || list->n < position) {
		printf("invalid position\n");
		return;
	}

	Node* cur = list->head;
	for (int i = 0; i < position; i++) {
		cur = cur->next;
	}

	if (position == 1) {
		list->head = list->head->next;
		list->head->prev = NULL;
	}
	else if (position = list->n) {
		list->tail = cur->prev;
		list->tail->next = NULL;
	}
	else {
		Node* prenode = cur->prev;
		Node* nextnode = cur->next;
		prenode->next = nextnode;
		nextnode->prev = prenode;
	}
	list->n--;
	
	if (list->n == 0) {
		initList(list);
	}

	return;
}


char get(List *list, int position) {

	if (position <= 0 || list->n < position) {
		printf("invalid position\n");
		return 0;
	}

	Node* cur = list->head;

	for (int i = 0; i < position; i++) {
		cur = cur->next;
	}
	return cur->item;
}

void print(Plist list) {
	printf("print\n");
	Node *cur = list->head;

	while (cur != NULL) {
		printf("%c", cur->item);
		cur = cur->next;
	}
	printf("\n");
	return;

}

int main() {

	List list;
	initList(&list);

	int N, i;
	//char item, ch;
	//int position;
	
	scanf("%d", &N);

	for (i = 0; i < N; i++) {
		char op, item, ch;
		int position;
		
		printf("%d 번째 연산 ", i);
		scanf(" %c ", &op);

		switch (op) {
		case 'A':
			scanf(" %d %c", &position, &item);
			add(&list, position, item);
			break;
		case 'D':
			scanf(" %d", &position);
			delete(&list, position);
			break;
		case 'G':
			scanf(" %d", &position);
			ch = get(&list, position);
			printf(" %c\n", ch);
			break;
		case 'P':
			printf("\n");
			print(&list);
			break;
		}
	}	
	return 0;
}
