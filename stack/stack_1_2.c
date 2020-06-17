#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

typedef struct stack {
	char * data;
	int size;
	int top;
} Stack;

typedef Stack* Pstack;

char pop(Pstack pstack) {
	if (pstack->top == -1) {
		printf("Stack Empty\n");
		return 0;
	}
	char temp = pstack->data[pstack->top];
	pstack->top--;
	return temp;
}

void push(Pstack pstack, char s) {
	if (pstack->top == (pstack->size - 1)) {
		printf("Stack FULL\n");
		return;
	}
	pstack->top++;
	pstack->data[pstack->top] = s;
}

void peek(Pstack pstack) {

	if (pstack->top == -1) {
		printf("Stack Empty\n");
		return;
	}
	printf("%c\n", pstack->data[pstack->top]);
}

void print(Pstack pstack) {
	if (pstack->top == -1) {
		printf("\n");
		return;
	}
	for (int i = pstack->top; i >= 0; i--) {
		printf("%c", pstack->data[i]);
	}
	printf("\n");
}

void duplicate(Pstack pstack) {
	if (pstack->top == -1) {
		printf("Stack Empty");
		return;
	}

	char p = pop(pstack);

	if (pstack->top >= pstack->size - 2) {
		printf("Stack FULL\n");
		return;
	}

	push(pstack, p);
	push(pstack, p);
}

void upRotate(Pstack pstack, int n) {
	int num = pstack->top + 1;
	if (num < n) {
		return;
	}
	if (n == 0) {
		return;
	}

	char temp = pstack->data[pstack->top];
	int i = pstack->top;
	int count = n - 1;
	while (count != 0) {
		pstack->data[i] = pstack->data[i - 1];
		i--;
		count--;
	}

	pstack->data[pstack->top - n + 1] = temp;
}

void downRotate(Pstack pstack, int n) {
	int num = pstack->top + 1;
	if (num < n) {
		return;
	}
	if (n == 0) {
		return;
	}

	int count = n - 1;
	int i = pstack->top-n+1;
	char temp = pstack->data[i];
	while (count != 0) {
		pstack->data[i] = pstack->data[i + 1];
		i++;
		count--;
	}
	pstack->data[pstack->top] = temp;
}

int main(void) {
	Stack stack;
	char op[MAX];
	int N;
	char item;
	int count, rotateN;

	stack.top = -1;
	scanf("%ud", &(stack.size));
	stack.data = (char*)malloc(sizeof(char) * stack.size);

	scanf("%ud", &N);
	getchar();  //scanf의 enter 없애기 위한 것 
	count = N;
	while (count != 0) {
		scanf("%s", op);
		getchar();

		if (strcmp(op, "POP") == 0) {
			pop(&stack);
		}
		else if (strcmp(op, "PUSH") == 0) {
			scanf("%c", &item);
			getchar();
			push(&stack, item);
		}
		else if (strcmp(op, "PEEK") == 0) {
			peek(&stack);
		}
		else if (strcmp(op, "DUP") == 0) {
			duplicate(&stack);
		}
		else if (strcmp(op, "UpR") == 0) {
			scanf("%ud", &rotateN);
			getchar();
			upRotate(&stack, rotateN);
		}
		else if (strcmp(op, "DownR") == 0) {
			scanf("%ud", &rotateN);
			getchar();
			downRotate(&stack, rotateN);
		}
		else if (strcmp(op, "PRINT") == 0) {
			print(&stack);
		}
		else if (strcmp(op, "EXIT") == 0) {
			break;
		}
		count--;
	}

}
