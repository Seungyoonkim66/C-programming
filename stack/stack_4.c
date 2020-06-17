/*
[ 문제 4 ] 
후위로 변환된 수식을 입력받아 스택을 사용하여 계산한 후 결과 값을 출력하는 
프로그램을 작성하시오

◦ 스택은 배열이나 연결리스트로 구현함
◦ 수식의 피연산자는 0에서 9사이의 정수이고, 각 수식의 최대길이는 100으로 함
◦ 수식의 연산자는 곱하기, 나누기, 더하기, 빼기로 구성되며, 정수 연산 수행
  - 즉, 나누기의 경우, 몫 계산

◦ 입출력에 대한 설명 (아래 입출력 예시 참조)
1) 첫 번째 라인 : 수식의 개수
2) 두 번째 라인 :
     - 하나의 줄에 후위수식이 공백 없이 입력됨

  (↦ 기호 이후는 입력 또는 출력의 설명)

입력예시1
4                     ↦ 수식의 개수
53*2+63+2*+  ↦ 첫 번째 수식
234*+              ↦ 두 번째 수식
72/3-42*+21*- ↦ 세 번째 수식
923*1+2*+      ↦ 네 번째 수식

출력예시1
35 ↦ 5*3+2+(6+3)*2의 결과
14 ↦ 2+3*4의 결과
6  ↦ 7/2-3+4*2-2*1의 결과
23 ↦ 9+(2*3+1)*2의 결과
*/
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
	int output[100]; //°á°ú °Ş ŔúŔĺ
	
	int N; // źö˝ÄŔÇ °łźö
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
