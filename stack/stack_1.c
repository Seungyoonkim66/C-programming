#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>



typedef struct stack {
	char data[100];
	int top;
} Stack;

void init(Stack* stack) {
	stack->top = -1;
}

int IsEmpty(Stack* stack) {
	if (stack->top < 0)
		return 1;
	else
		return 0;
}

int IsFull(Stack* stack) {
	if (stack->top > 1000 - 1)
		return 1;
	else
		return 0;
}

void push(Stack* stack, char data) {
	if (IsFull(stack) == 1)
		return 0;
	else
		stack->data[++(stack->top)] = data;
}

char pop(Stack* stack) {
	if (IsEmpty(stack) == 1)
		return 0;
	else
		return stack->data[stack->top--];
}

char peek(Stack* stack) {
	if (IsEmpty(stack) == 1) printf("Stack Empty\n");
	else return stack->data[stack->top];
}

void duplicate(Stack* stack) {
	char temp;
	if (IsFull(stack) == 1) printf("Stack Full\n");
	else {
		temp = stack->data[stack->top--];
		push(&stack, temp);
		if (IsFull(stack) == 1) printf("Stack Full\n");
		else push(&stack, temp);
	}
}

void upRotate(Stack* stack, int n) {
	int size = 0;
	int idx = 0;

	for (int i = stack->top; i >= 0; i--) {
		size++;
	}
	if (n > size) return;
	else {
		char top = stack->data[stack->top];
		for (int i = 1; i < n; i++) {
			char temp = stack->data[stack->top - (n - i) + 1];
			stack->data[stack->top - (n - i) + 1] = stack->data[stack->top - (n - i)];
		}
		top = stack->data[stack->top - (n - 1)];

	}
}

void downRotate(Stack* stack, int n) {
	int size = 0;
	int idx = 0;

	for (int i = stack->top; i >= 0; i--) {
		size++;
	}
	if (n > size) return;
	else {
		char bottom = stack->data[stack->top - n + 1];
		for (int i = 0; i < n - 1; i++) {
			char temp = stack->data[stack->top - i];
			stack->data[stack->top - i] = stack->data[stack->top - (i + 1)];
		}
		bottom = stack->data[stack->top];
	}
}

void print(Stack* stack) {
	int size = 0;
	int idx = 0;

	for (int i = stack->top; i >= 0; i--) {
		size++;
	}
	for (int i = 0; i < size; i++) {
		printf("%c", stack->data[stack->top]);
		stack->top--;
	}
}



int main() {

	int N; // 스택의 크기
	int op_num; // 연산의 개수 
	scanf("%d", &N);
	scanf("%d", &op_num);

	//printf("%d %d \n", N, op_num);

	Stack stack;
	init(&stack);

	for (int i = 0; i < op_num; i++) {
		char op;
		char item;
		char res;
		int n;
		scanf("%s", &op);

		switch (op) {
		case 'POP':
			pop(&stack);
			break;
		case 'PUSH':
			scanf("%c", &item);
			push(&stack, item);
			break;
		case 'PEEK':
			res = peek(&stack);
			printf("%c\n", res);
			break;
		case 'DUP':
			duplicate(&stack);
			break;
		case 'UpR':
			scanf("%d", &n);
			upRotate(&stack, n);
			break;
		case 'DoR':
			scanf("%d", n);
			downRotate(&stack, n);
			break;
		case 'PNT':
			print(&stack);
			break;
		}

	}

	return 0;

}