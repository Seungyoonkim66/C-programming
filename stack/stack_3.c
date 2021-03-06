/*
[ 문제 3 ] 
스택을 이용하여 중위수식을 후위수식으로 변환하는 프로그램을 작성하시오.

◦ 스택은 배열이나 연결리스트로 구현함
◦ 수식의 피연산자는 영문자(대문자)로 나타내고, 각 수식의 최대길이는 100으로 함
◦ 수식은 아래 우선순위를 갖는 연산자들을 포함함 (숫자가 높을수록 우선순위가 높음)

입력토큰      연산자      우선순위
    ! + -       단항연산자       6
    *            곱셈                 5
    /            나눗셈              5
    +           덧셈                 4
     -           뺄셈                 4
    >           관계연산자      3
    <           관계연산자      3
   &&         논리연산자(AND) 2
    ||           논리연산자(OR)   1

◦ 같은 우선순위를 갖는 연산자들은 왼쪽에서 오른쪽으로 계산하도록 함
◦ 입출력에 대한 설명 (아래 입출력 예시 참조)

  1) 첫 번째 라인 : 수식의 개수
  2) 두 번째 라인 :
       - 하나의 줄에 수식이 공백 없이 입력됨

  (↦ 기호 이후는 입력 또는 출력의 설명)

입력예시1
5                         ↦ 수식의 개수
A*B+C+(D+E)*F ↦ 첫 번째 수식
A+B*C                ↦ 두 번째 수식
A/B-C+D*E-F*G ↦ 세 번째 수식
A+(B*C+D)*E     ↦ 네 번째 수식
A&&B||C||!(E>F) ↦ 다섯 번째 수식

출력예시1
AB*C+DE+F*+
ABC*+
AB/C-DE*+FG*-
ABC*D+E*+
AB&&C||EF>!||
*/


#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100


typedef struct node {  // 연결리스트 노드 
	char data;
	struct node *link;
} Node;

typedef struct stack {
	Node *top;
} Stack;

void initStack(Stack *s) {
	s->top = NULL;
}

int isEmpty(Stack *s) {
	return (s->top == NULL);
}

void push(Stack *s, char elem) {
	Node *temp = (Node*)malloc(sizeof(Node));
	temp->data = elem;
	temp->link = s->top;
	s->top = temp;
}

char pop(Stack *s) {
	if (isEmpty(s)) {
		printf("stack underflow\n");
		exit(1);
	}
	else {
		Node *temp = s->top;
		char elem = temp->data;
		s->top = s->top->link;
		free(temp);
		return(elem);
	}
}

int peek(Stack *s) {
	if (isEmpty(s)) {
		printf("stack underflow\n");
		exit(1);
	}
	else {
		return s->top->data;
	}
}

int trans(char op) {
	switch (op) {
	case '(': case ')': return 0;
	case '|': return 1;
	case '&': return 2;
	case '<': case '>': return 3;
	case '+': case '-': return 4;
	case '*': case '/': return 5;
	case '!': case '^': case '$': return 6;
	}
	return -1;
}

void convert(char elem) {
	switch (elem) {
	case '&': 
		printf("%c&", elem);
		break;
	case '|':
		printf("%c|", elem);
		break;
	case '^':
		printf("+");
		break;
	case '$':
		printf("-");
		break;
	default :
		printf("Error");
		exit(1);
	}
}

void postfix(char exp[]) {
	int i, len;
	char op, ch;
	Stack s;

	initStack(&s);
	len = strlen(exp);

	for (i = 0; i < len; i++) {
		ch = exp[i];
		switch (ch) {
		case '!': case '^': case '$':
		case '*': case '/':
		case '+': case '-':
		case '>': case '<':
		case '&': case '|':
			while (!isEmpty(&s) && (trans(ch) <= trans(peek(&s)))) {
				op = pop(&s);
				switch (op) {
				case '&': case '|': case '^': case '$':
					convert(op);
					break;
				default:
					printf("%c", op);
				}
			}
			push(&s, ch);
			break;
		case '(':
			push(&s, ch);
			break;
		case ')':
			op = pop(&s);
			while (op != '(') {
				switch (op) {
				case '&': case '|': case '^': case '$':
					convert(op);
					break;
				default:
					printf("%c", op);
				}
				op = pop(&s);
			}
			break;
		default:
			printf("%c", ch);
		}
	}

	while (!isEmpty(&s)) {
		op = pop(&s); 
		switch (op) {
		case '&': case '|': case '^': case '$':
			convert(op);
			break;
		default:
			printf("%c", op);
		}
	}
	printf("\n");
}

int main() {

	int i, j, len, idx, N;
	char inexp[MAX], exp[MAX];

	scanf("%d", &N);
	for (i = 0; i < N; i++) {

		memset(inexp, 0, sizeof(inexp)); //배열초기화 
		memset(exp, 0, sizeof(exp));

		while (getchar() != '\n');
		scanf("%s", &inexp);  //문자열 입력받기 
		len = strlen(inexp);

		idx = 0;
		for (j = 0; j < len; j++) {
			switch (inexp[j]) {
			case '&':
			case '|':
				exp[idx] = inexp[j];
				idx++;
				j++;
				break;
			case '+':
				if ((j == 0) || (j > 0 && (inexp[j - 1] == '+' || inexp[j - 1] == '-' || inexp[j - 1] == '!' || inexp[j - 1] == '*'))) {
					exp[idx] = '^';
					idx++;
				}
				else {
					exp[idx] = inexp[j];
					idx++;
				}
				break;
			case '-':
				if ((j == 0) || (j > 0 && (inexp[j - 1] == '+' || inexp[j - 1] == '-' || inexp[j - 1] == '!' || inexp[j - 1] == '*'))) {
					exp[idx] = '$';
					idx++;
				}
				else {
					exp[idx] = inexp[j];
					idx++;
				}
				break;
			default:
				exp[idx] = inexp[j];
				idx++;
			}
		};
		postfix(exp);
	}
}
