#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct Node {
	int key;
	int value;
} Node;

int m = 37;

void initTable(Node* hashTable) {
	for (int i = 0; i < m; i++) {
		hashTable[i].key = 0;
		hashTable[i].value = 0;
	}
}

int hashFunction(int key) {
	return (key % m);
}

Node* linear_probing(int key, int i) {
	return ((hashFunction(key) + 1) % m);
}

void insert(Node* hashTable) {
	int i;
	srand(time(NULL));
	for (i = 0; i < 50; i++) {
		int k = 0;
		int key = rand() % 1000;
		int hashValue = linear_probing(key, 0);
		if (hashTable[hashValue].key == 0) {
			printf("empty");
		}
	}
}


void main() {
	Node* HashTable_linear = malloc(sizeof(Node*) * 30);
	initTable(HashTable_linear);
	/*Node* HashTable_quadratic = malloc(sizeof(Node*) * 30);
	Node* HashTable_double = malloc(sizeof(Node*) * 30);*/
}