#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct stack {
	char* data;
	int size;
	int top;
} Stack;

typedef Stack* Pstack;

char pop(Pstack pstack) {
	if (pstack->top == -1) {
		return 0;
	}
	char temp = pstack->data[pstack->top];
	pstack->top--;
	return temp;
}

void push(Pstack pstack, char s) {
	if (pstack->top == (pstack->size - 1)) {
		return;
	}
	pstack->top++;
	pstack->data[pstack->top] = s;
}

void peek(Pstack pstack) {

	if (pstack->top == -1) {
		return;
	}
	printf("%c\n", pstack->data[pstack->top]);
}

void print(Pstack pstack) {
	if (pstack->top == -1) {
		return;
	}
	for (int i = pstack->top; i >= 0; i--) {
		printf("%c", pstack->data[i]);
	}
	printf("\n");
}

int eval(char* exp) {
	int op1, op2, value, i = 0;
	int len = strlen(exp);
	char ch;

	Stack stack;
	stack.top = -1;
	stack.size = 100;
	stack.data = (char*)malloc(sizeof(char) * stack.size);

	for (i = 0; i < len; i++) {
		ch = exp[i];
		if (ch != '+' && ch != '-' && ch != '*' && ch != '/') {
			value = ch - '0';
			push(&stack, value);
		}
		else {
			op2 = pop(&stack);
			op1 = pop(&stack);
			switch (ch) {
			case '+': push(&stack, op1 + op2); break;
			case '-': push(&stack, op1 - op2); break;
			case '*': push(&stack, op1 * op2); break;
			case '/': push(&stack, op1 / op2); break;
			}
		}
	}
	return pop(&stack);
}

	

int main(void) {

	char exp[100];
	int output[100]; //결과 값 저장
	
	int N; // 수식의 개수
	scanf("%d", &N);

	for (int i = 0; i < N; i++) {
		scanf("%s", &exp);
		output[i]=eval(exp);
	}

	for (int i = 0; i < N; i++) {
		printf("%d\n", output[i]);
	}

	return 0;
}
