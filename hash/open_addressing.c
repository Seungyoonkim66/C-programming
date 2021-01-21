#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct Node {
	int key;
	int value;
	int flag;
} Node;

int m = 37;

int hashFunction(int key) {
	return (key % m);
}
int hashFunction2(int key) {
	return (1 + key % (m-1));
}



void insert_linear_probing(Node* hashTable) {
	int i;
	double probe_sum = 0;
	srand(time(NULL));
	for (i = 0; i < 30; i++) {
		int j = 0;
		int probe = 0;
		int key = rand() % 1000;
		int hashValue = hashFunction(key);
		if (hashTable[hashValue].flag == 0) {
			probe++;
			hashTable[hashValue].key = key;
			hashTable[hashValue].value = hashValue;
		}
		else if (hashTable[hashValue].flag == 1) {
			probe++;
			while (hashTable[hashValue].flag == 1) {
				j++;
				hashValue = (hashValue + j) % m;
			}
			hashTable[hashValue].key = key;
			hashTable[hashValue].value = hashValue;
		}
		hashTable[hashValue].flag = 1;
		probe_sum += probe;
	}
	printf("average # of probes: %f\n", probe_sum / 30);
}

void insert_quadratic_probing(Node* hashTable) {
	int i;
	int c1 = 1;
	int c2 = 3;
	double probe_sum = 0;
	srand(time(NULL));
	for (i = 0; i < 30; i++) {
		int j = 0;
		int probe = 0;
		int key = rand() % 1000;
		int hashValue = hashFunction(key);
		if (hashTable[hashValue].flag == 0) {
			probe++;
			hashTable[hashValue].key = key;
			hashTable[hashValue].value = hashValue;
		}
		else if (hashTable[hashValue].flag == 1) {
			probe++;
			while (hashTable[hashValue].flag == 1) {
				j++;
				hashValue = (hashValue + j*c1 + c2*(j^2)) % m;
			}
			hashTable[hashValue].key = key;
			hashTable[hashValue].value = hashValue;
		}
		hashTable[hashValue].flag = 1;
		probe_sum += probe;
	}
	printf("average # of probes: %f\n", probe_sum / 30);
}

void insert_double_hashing(Node* hashTable) {
	int i;
	double probe_sum = 0;
	srand(time(NULL));
	for (i = 0; i < 30; i++) {
		int j = 0;
		int probe = 0;
		int key = rand() % 1000;
		int hashValue = hashFunction(key);
		if (hashTable[hashValue].flag == 0) {
			probe++;
			hashTable[hashValue].key = key;
			hashTable[hashValue].value = hashValue;
		}
		else if (hashTable[hashValue].flag == 1) {
			probe++;
			while (hashTable[hashValue].flag == 1) {
				j++;
				hashValue = (hashValue + j*hashFunction2(hashValue)) % m;
			}
			hashTable[hashValue].key = key;
			hashTable[hashValue].value = hashValue;
		}
		hashTable[hashValue].flag = 1;
		probe_sum += probe;
	}
	printf("average # of probes: %f\n", probe_sum / 30);
}



void printTable(Node* hashTable) {
	int i;
	int p_cluster = 1;
	int cluster = 0;
	for (i = 0; i < 30; i++) {
		if (hashTable[i].key == -1) {
			if (cluster >= p_cluster) {
				int temp = cluster;
				cluster = 0;
				p_cluster = temp;
			}
			cluster = 0;
			printf("hash value: %d key: empty \n", i);
		}
		else {
			printf("hash value: %d key: %d \n", i, hashTable[i].key); 
			cluster++;
		}
	}
	if (cluster >= p_cluster) {
		p_cluster = cluster;
	}
	printf("primary cluster : %d\n", p_cluster);
}


void main() {
	int i;
	Node HashTable_linear[32];
	for (i = 0; i < 30; i++) {
		HashTable_linear[i].key = -1;
		HashTable_linear[i].value = -1;
		HashTable_linear[i].flag = 0;
	}
	printf("linear probing\n");
	insert_linear_probing(HashTable_linear);
	printTable(HashTable_linear);

	Node HashTable_quad[32];
	for (i = 0; i < 30; i++) {
		HashTable_quad[i].key = -1;
		HashTable_quad[i].value = -1;
		HashTable_quad[i].flag = 0;
	}
	printf("quadratic probing\n");
	insert_quadratic_probing(HashTable_quad);
	printTable(HashTable_quad);

	Node HashTable_double[32];
	for (i = 0; i < 30; i++) {
		HashTable_double[i].key = -1;
		HashTable_double[i].value = -1;
		HashTable_double[i].flag = 0;
	}
	printf("double hashing\n");
	insert_double_hashing(HashTable_double);
	printTable(HashTable_double);

}