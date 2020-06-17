#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 1000

typedef struct stack {
	char* data;
	int size;
	int top;
} Stack;

typedef Stack* Pstack;

char pop(Pstack pstack) {
	if (pstack->top == -1) {
		//printf("Stack Empty\n");
		return 0;
	}
	char temp = pstack->data[pstack->top];
	pstack->top--;
	return temp;
}

void push(Pstack pstack, char s) {
	if (pstack->top == (pstack->size - 1)) {
		//printf("Stack FULL\n");
		return;
	}
	pstack->top++;
	pstack->data[pstack->top] = s;
}

void peek(Pstack pstack) {

	if (pstack->top == -1) {
		//printf("Stack Empty\n");
		return;
	}
	printf("%c\n", pstack->data[pstack->top]);
}

void print(Pstack pstack) {
	if (pstack->top == -1) {
		//printf("\n");
		return;
	}
	for (int i = pstack->top; i >= 0; i--) {
		printf("%c", pstack->data[i]);
	}
	printf("\n");
}

int check(Pstack pstack, char* exp) {
	int len = strlen(exp);
	char ch;
	char left;
	int count = 0;

	for (int i = 0; i < len; i++) {
		ch = exp[i];

		switch (ch) {
		case '(':
		case '{':
		case '[':
			push(pstack, ch);
			break;
		case ')':
		case '}':
		case ']':
			if (pstack->top == -1)
				return 0;
			else {
				left = pop(pstack);
				if ((left == '(' && ch != ')')
					|| (left == '[' && ch != ']')
					|| (left == '{' && ch != '}'))
					return 0;
			}
			break;
		}
	}
	if (pstack->top == -1) 
		return 1;
	else
		return 0;
}

int main(void) {
	Stack stack;
	stack.top = -1;
	stack.size = 1000;
	stack.data = (char*)malloc(sizeof(char) * stack.size);
	char exp[MAX];
	int N = 0;
	int len = strlen(exp);
	scanf("%[^\n]s", exp);

	for (int i = 0; i < len; i++) {
		if (exp[i] == ')' || exp[i] == '(' ||
			exp[i] == '}' || exp[i] == '{' ||
			exp[i] == ']' || exp[i] == '[')
			N++;
	}


	if (check(&stack, exp) == 1)
		printf("OK_%d", N);
	else
		printf("Wrong_%d", N);

	free(stack.data);

	return 0;

}