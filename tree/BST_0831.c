/*[ 문제 ] 이전에 설명한 방식대로 트리 정보와 탐색 정보가 주어졌을 때, 
트리를 생성하고 탐색 도중 방문하는 노드의 번호를 차례로 출력하는 프로그램을 작성하시오.

입력 예시 1 
9 ↦ 노드 개수
5 3 9 (preorder - VLR)
3 8 15
8 0 2
2 0 0
15 0 0
9 7 10
7 12 0
12 0 0
10 0 0
3 ↦ 탐색 횟수
RLL
LL
LR

출력 예시 1 (□는 공백)
□5 9 7 12 ↦ 첫 번째 탐색 결과
□5 3 8 ↦ 두 번째 탐색 결과
□5 3 15 ↦ 두 번째 탐색 결과*/

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

typedef struct node {
	int data;
	struct node* left;
	struct node* right;
} Node;

typedef struct tree {
	Node* root;
	Node* arr;
}Tree;

Node* makeNode(int data) {
	Node* node = (Node*)malloc(sizeof(Node));
	node->data = data;
	node->left = NULL;
	node->right = NULL;

	return node;
}

Tree* makeSubtree(Node* xnode, Node* ynode, Node* znode) {
	Tree* subtree = (Tree*)malloc(sizeof(Tree));

	xnode->left = ynode;
	xnode->right = znode;
	subtree->root = xnode;

	return subtree;
}


Tree* makeTree(int node_n) {
	Tree* tree = (Tree*)malloc(sizeof(Tree));
	tree->arr = (Node*)malloc(sizeof(Node) * node_n * 2);

	Tree* subtree;

	tree->root = makeNode(NULL);
	tree->root->left = makeNode(NULL);
	tree->root->right = makeNode(NULL);
	
	int i, x, y, z;

	scanf("%d %d %d", &x, &y, &z);
	Node* xnode = makeNode(x);
	Node* ynode = makeNode(y);
	Node* znode = makeNode(z);

	tree->root = xnode;
	xnode->left = ynode;
	ynode->right = znode;

	tree->arr[0].left = xnode->left;
	tree->arr[0].right = xnode->right;

	for (i = 0; i < node_n-1; i++) {

		scanf("%d %d %d", &x, &y, &z);
		xnode = makeNode(x);
		ynode = makeNode(y);
		znode = makeNode(z);

		tree->arr[i + 1].left = xnode->left;
		tree->arr[i + 1].right = xnode->right;

		subtree = makeSubtree(xnode, ynode, znode);
		printf("subtree = %d %d %d\n", xnode->data, ynode->data, znode->data);

		int k = 1;
		Node* ch = tree->arr[0].left;
		while (tree->arr[k].left != NULL && tree->arr[k].right ) {
			ch = tree->arr[k].left;
			if (ch == NULL) break;
			else if (ch->data == xnode->data) break;
			else { 
				ch = tree->arr[k].right;
				if (ch->data == xnode->data) break;
			}
			k++;
		}

	}

	return tree;
}

int main() {
	
	Tree* tree;

	int node_n;
	scanf("%d", &node_n);

	tree = makeTree(node_n);

	printf("%d %d %d", tree->root->data, tree->root->left->data, tree->root->right->data);


	return 0;
}