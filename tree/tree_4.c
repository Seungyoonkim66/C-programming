#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node {
	int data;
	struct node* left;
	struct node* right;
} Node;

typedef struct Tree {
	Node* root;
}Tree;


Node* initNode(int data) {

	Node* node = (Node*)malloc(sizeof(Node));
	node->left = NULL;
	node->right = NULL;
	node->data = data;

	return node;
}

Tree* insertTree(Node* x, Node* y, Node* z, Tree* tr, int cnt) {


	Tree* subtr = (Tree*)malloc(sizeof(Tree));

	if (cnt != 0) {

		subtr->root = x;
		subtr->root->left = y;
		subtr->root->right = z;
		cnt--;
	}
	return tr;
}


void preorder(Node* root) {

	if (root != NULL) {
		
		printf("%d ", root -> data);
		preorder(root->left);
		preorder(root->right);

	}
}


int main(void) {

	Tree* tree = (Tree*)malloc(sizeof(Tree));
	tree->root = NULL;

	int node_n, search_n;
	char* search = (char*)malloc(sizeof(char));

	scanf("%d", &node_n);

	for (int i = 0; i < node_n; i++) {
		int x, y, z;
		scanf("%d %d %d", &x, &y, &z);
		Node* xnode = initNode(x);
		Node* ynode = initNode(y);
		Node* znode = initNode(z);

		if (tree->root == NULL) {
			tree->root = xnode;
			tree = insertTree(xnode, ynode, znode, tree, node_n);
		}
		else if (tree->root->right->data == xnode->data && tree->root != NULL) {
			xnode = tree->root->right;
			tree = insertTree(xnode, ynode, znode, tree, node_n);
		}
		else if (tree->root->left->data == xnode->data && tree->root != NULL) {
			xnode = tree->root->left;
			tree = insertTree(xnode, ynode, znode, tree, node_n);
		}
	}
	preorder(tree->root);

	scanf("%d", &search_n);
	for (int i = 0; i < search_n; i++) {
		scanf("%s", search);
		int len = strlen(search);

		if (tree->root != NULL) {
			Node* cur = initNode(0);
			cur = tree->root;
			printf(" %d", cur->data);
			for (int j = 0; j < len; j++) {

				char ch = search[j];
				switch (ch) {
				case'R':
					cur = cur->right;
					if (cur->data != 0)
						printf(" %d", cur->data);
					break;
				case'L':
					cur = cur->left;
					if (cur->data != 0)
						printf(" %d", cur->data);
					break;
				default:
					printf("-1");
					break;
				}
			}
		}
		
	}
	return 0;
}