#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef struct node {
	int data;
	int id;
	struct node* left;
	struct node* right;
} Node;

typedef struct Tree {
	Node* root;
}Tree;

void initNode(Node* node, int id) {
	node->left = NULL;
	node->right = NULL;
	node->data = NULL;
	node->id = id;
}

void preorder(Node* root) {
	//root -> left -> right
	if (root != NULL) {
		printf(" %d", root->data);
		preorder(root->left);
		preorder(root->right);
	}
}

void inorder(Node* root) {
	//left -> root -> right
	if (root != NULL) {
		inorder(root->left);
		printf(" %d", root->data);
		inorder(root->right);
	}

}

void postorder(Node* root) {
	//left -> right -> root
	if (root != NULL) {
		postorder(root->left);
		postorder(root->right);
		printf(" %d", root->data);
	}
}



int main(void) {

	int method, nodeID;
	scanf("%d %d", &method, &nodeID);

	Tree* tr = (Tree*)malloc(sizeof(Tree*));

	Node* F8 = (Node*)malloc(sizeof(Node));
	Node* F7 = (Node*)malloc(sizeof(Node));
	Node* F6 = (Node*)malloc(sizeof(Node));
	Node* F5 = (Node*)malloc(sizeof(Node));
	Node* F4 = (Node*)malloc(sizeof(Node));
	Node* F3 = (Node*)malloc(sizeof(Node));
	Node* F2 = (Node*)malloc(sizeof(Node));
	Node* F1 = (Node*)malloc(sizeof(Node));

	initNode(F8, 8);
	initNode(F7, 7);
	initNode(F6, 6);
	initNode(F5, 5);
	initNode(F4, 4);
	initNode(F3, 3);
	initNode(F2, 2);
	initNode(F1, 1);

	F8->data = 80;
	F7->data = 130;
	F6->left = F7;
	F6->right = F8;
	F6->data = 120;
	F3->right = F6;
	F3->data = 50;
	F4->data = 70;
	F5->data = 90;
	F2->left = F4;
	F2->right = F5;
	F2->data = 30;
	F1->left = F2;
	F1->right = F3;
	F1->data = 20;

	switch (nodeID) {
	case 1:
		tr->root = F1;
		break;
	case 2:
		tr->root = F2;
		break;
	case 3:
		tr->root = F3;
		break;
	case 4:
		tr->root = F4;
		break;
	case 5:
		tr->root = F5;
		break;
	case 6:
		tr->root = F6;
		break;
	case 7:
		tr->root = F7;
		break;
	case 8:
		tr->root = F8;
		break;
	default:
		printf("-1");
		break;
	}

	switch (method) {
	case 1:
		preorder(tr->root);
		break;
	case 2:
		inorder(tr->root);
		break;
	case 3:
		postorder(tr->root);
		break;
	default:
		printf("-1");
		break;

	}

	return 0;
}
