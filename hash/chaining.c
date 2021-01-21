#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct Node {
	int key;
	int value;
	struct Node* next;
} Node;

typedef struct listItem {
	Node* head;
	Node* tail;
	int length;
} ListItem;

int hashFunction(int key, int N) {
	return (key % N);
}

Node* initNode(int key, int value) {
	Node* newnode = malloc(sizeof(Node));
	newnode->key = key;
	newnode->value = value;
	newnode->next = NULL;
	return newnode;
}
int k = 0;
void insertToHash(ListItem* hashTable, Node* newnode, int N) {

	int i;
	int valueIndex = 0;
	for (i = 0; i < N; i++) {
		if (newnode->value == i) {
			valueIndex = i;
		}
	}
	if (hashTable[valueIndex].head->next == hashTable[valueIndex].tail) {
		newnode->next = hashTable[valueIndex].head->next;
		hashTable[valueIndex].head->next = newnode;
		hashTable[valueIndex].length++;
	}
	else {
		Node* temp = hashTable[valueIndex].head;
		while (temp->next != hashTable[valueIndex].tail) {
			temp = temp->next;
		}
		temp->next = newnode;
		newnode->next = hashTable[valueIndex].tail;
		hashTable[valueIndex].length++;
	}
}

void printTable(ListItem* hashTable, int N) {
	int i;
	int min = 50, max = 0, sum = 0;
	for (i = 0; i < N; i++) {
		printf("Hash Value: %d\n", i);
		Node* temp = hashTable[i].head;
		while (temp->next != hashTable[i].tail) {
			printf("%d ->", temp->next->key);
			temp = temp->next;
		}
		printf("end of the chain");
		printf("\nlength of the chain: %d\n\n", hashTable[i].length);
		if (min >= hashTable[i].length) min = hashTable[i].length;
		if (max <= hashTable[i].length) max = hashTable[i].length;
		sum += hashTable[i].length;
	}

	printf("min length: %d\n", min);
	printf("max length: %d\n", max);
	printf("average length: %d\n", sum / N);

}

void insert(ListItem* hashTable, int N) {
	int i;
	srand(time(NULL));
	for (i = 0; i < 50; i++) {
		int k = 0;
		int key = rand() % 1000;
		int hashValue = hashFunction(key, N);
		Node* newnode = initNode(key, hashValue);

		insertToHash(hashTable, newnode, N);
	}
	printTable(hashTable, N);
}



int main(void) {
	int a = 7;
	int b = 13;
	int c = 17;

	ListItem* hashTableA = malloc(sizeof(ListItem) * a);
	ListItem* hashTableB = malloc(sizeof(ListItem) * c);
	ListItem* hashTableC = malloc(sizeof(ListItem) * c);

	for (int i = 0; i < a; i++) {
		hashTableA[i].length = 0;
		hashTableA[i].head = i;
		hashTableA[i].head = initNode(0, 0);
		hashTableA[i].head->next = hashTableA[i].tail;
	}
	printf("h(k) = k mode %d\n", a);
	insert(hashTableA, a);
	printf("\n******************************************************************************************\n");
	
	for (int i = 0; i < b; i++) {
		hashTableB[i].length = 0;
		hashTableB[i].head = i;
		hashTableB[i].head = initNode(0, 0);
		hashTableB[i].head->next = hashTableB[i].tail;
	}
	printf("h(k) = k mode %d\n", b);
	insert(hashTableB, b);
	printf("\n******************************************************************************************\n");

	for (int i = 0; i < c; i++) {
		hashTableC[i].length = 0;
		hashTableC[i].head = i;
		hashTableC[i].head = initNode(0, 0);
		hashTableC[i].head->next = hashTableC[i].tail;
	}
	printf("h(k) = k mode %d\n", c);
	insert(hashTableC, c);
	printf("\n******************************************************************************************\n");


	return;

}