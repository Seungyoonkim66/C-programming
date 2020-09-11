#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef int datatype;

typedef struct node {
	struct node* left;
	datatype data;
	struct node* right;
} Node;

typedef struct Tree {
	Node* root;
}Tree;

void initNode(Node* node) {
	node->left = NULL;
	node->right = NULL;
	node->data = NULL;
}

 Tree* tree (void){

	 Node* F8 = (Node*)malloc(sizeof(Node));
	 Node* F7 = (Node*)malloc(sizeof(Node));
	 Node* F6 = (Node*)malloc(sizeof(Node));
	 Node* F5 = (Node*)malloc(sizeof(Node));
	 Node* F4 = (Node*)malloc(sizeof(Node));
	 Node* F3 = (Node*)malloc(sizeof(Node));
	 Node* F2 = (Node*)malloc(sizeof(Node));
	 Node* F1 = (Node*)malloc(sizeof(Node));

	 initNode(F8);
	 initNode(F7);
	 initNode(F6);
	 initNode(F5);
	 initNode(F4);
	 initNode(F3);
	 initNode(F2);
	 initNode(F1);

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

	 Tree* tree = (Tree*)malloc(sizeof(Tree*));
	 tree->root = F1;

	 return tree;
} 

 int main(void) {
	 int num;
	 scanf("%d", &num);
	 
	 Tree* tr = tree();

	 
	 Node* F1 = tr->root;
	 Node* F2 = F1->left;
	 Node* F3 = F1->right;
	 Node* F4 = F2->left;
	 Node* F5 = F2->right;
	 Node* F6 = F3->right;
	 Node* F7 = F6->left;
	 Node* F8 = F6->right;

	 switch (num) {
	 case 1:
		 printf("%d %d %d", F1->data, F1->left->data, F1->right->data);
		 break;
	 case 2:
		 printf("%d %d %d", F2->data, F2->left->data, F2->right->data);
		 break;
	 case 3:
		 printf("%d %d", F3->data, F3->right->data);
		 break;
	 case 4:
		 printf("%d", F4->data);
		 break;
	 case 5:
		 printf("%d", F5->data);
		 break;
	 case 6:
		 printf("%d %d %d", F6->data, F6->left->data, F6->right->data);
		 break;
	 case 7:
		 printf("%d", F7->data);
		 break;
	 case 8:
		 printf("%d", F8->data);
		 break;
	 default :
		 printf("-1");
		 break;
	 }
	 return 0;

 }