/*
[ 문제 2 ] 
스택의 응용으로 키보드로부터 입력된 한 줄의 수식문장에서 괄호 짝의 유효성을 검사하는 
프로그램을 작성하세요. 괄호짝은 { }, [ ] , ( ) 의 3 종류를 갖는다.

주의: 수식문장은 1000개의 문자를 넘지 않는다. 수식문장은 공백문자를 포함할 수 있다.
         출력은 유효하지 않으면 ‘Wrong_N’. 유효하면 ‘OK_N’를 출력한다. 
         여기서 N은 문장안의 괄호의 개수이다.

입력예시1
(3+40*(2+(30-7)*2133)

출력예시1
Wrong_5

입력예시2
3*{4+(2-792)/1} + [3*{4-2* (100 -7)}]

출력예시2
OK_10

입력예시3
301*{4+(2101-7)/1} + 9*{4-2* (10108-7)}}

출력예시3
Wrong_9

입력예시4
(3*{4001+(2-7)/1} + [3*{4-2* (1-7)}])

출력예시4
OK_12
*/
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
