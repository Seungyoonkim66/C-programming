/*
[ 문제 1 ] 
다음의 스택 ADT를 배열로 구현하고 테스트하는 프로그램을 작성하세요

◦ 데이터: 영문자
◦ 다음의 연산을 지원해야 함

- push(stack, ‘c’) : 
  stack의 top에 데이터를 추가한다. 
  stack이 이미 꽉 차있으면 해당 데이터는 스택에 저장하지 않고 “Stack FULL”을 출력한다.

- pop (stack) : 
  stack의 top에 있는 데이터를 반환하고 stack에서 제거한다. 
  stack이 비어 있으면 “Stack Empty”를 출력한다.

- peek(stack): 
  stack의 top에 있는 데이터를 화면에 출력한다. stack은 변화하지 않는다.
  stack이 비어 있으면 “Stack Empty”를 출력한다.

- duplicate(stack): 
  stack의 top에 있는 데이터를 pop해서 두 번 push 한다. 
stack이 이미 꽉 차있으면 “Stack FULL”을 출력한다.

- upRotate(stack, n): 
  stack의 맨 위 n 개의 데이터를 회전시킨다. 
  예를 들면 n 이 3이고 stack의 top에서부터 elem1, elem2, elem3, .... 이 저장되어 있으면 
  데이터를 하나씩 위쪽으로 이동시킨다. 맨 위쪽 (top)의 std1은 n-1번 아래쪽으로 이동해서 
  스택의 결과는 elem2, elem3, elem1, ...이 된다.
  단, n이 데이터의 개수보다 큰 경우에는 아무 작업을 하지 않는다.

- downRotate(stack, n): 
  stack의 맨 위 n 개의 데이터를 회전시킨다. 
  예를 들면 n 이 3이고 stack의 top에서부터 elem1, elem2, elem3, .... 이 저장되어 있으면 
  데이터를 하나씩 d 아래쪽으로 이동시킨다. top에서부터 n번째의 데이터는 top으로 이동해서, 
  스택의 결과는 elem3, elem1, elem2, ...이된다.
  단, n이 데이터의 개수보다 큰 경우에는 아무 작업을 하지 않는다.

- print(stack) : 
  stack의 모든 데이터를 top에서부터 순서대로 공간없이 출력한다.


◦ 입력에 대한 설명 (아래 입출력 예시 참조)

- 각 연산의 내용이 한 줄에 하나씩 입력되고, 
  하나의 줄에는 연산의 종류와 그에 필요한 데이터가 입력된다.

- 연산의 종류: 각 연산 이름은 POP, PUSH , PEEK, DUP, UpR, DownR, PRINT로 주어진다.

  (↦ 기호 이후는 입력 또는 출력에 대한 설명)

입력예시1
4                  ↦ stack의 크기 N
10                ↦ 연산의 개수
POP            ↦ pop(stack)
PUSH s       ↦ push(stack, ‘s’)
PUSH t       ↦ push(stack, ‘t’)
PUSH a      ↦ push(stack, ‘a’)
PUSH r       ↦ push(stack, ‘r’)
PRINT        ↦ print(stack)
UpR 3         ↦ upRotate(stack, 3)
PRINT        ↦ print(stack)
PUSH s      ↦ push(stack, ‘s’)
PEEK         ↦ push(stack)

출력예시1
Stack Empty   ↦ 1번 POP 연산의 결과
rats                 ↦ 6번 PRINT 연산의 결과
atrs                 ↦ 8번 PRINT 연산의 결과
Stack FULL    ↦ 9번 PUSH 연산의 결과
a                     ↦ 10번 PEEK 연산의 결과

입력예시2
5                    ↦ stack의 크기 N
11                  ↦ 연산의 개수
PUSH s         ↦ push(stack, ‘s’)
PUSH r         ↦ push(stack, ‘r’)
PUSH a        ↦ push(stack, ‘a’)
PUSH t         ↦ push(stack, ‘t’)
PUSH s        ↦ push(stack, ‘s’)
PRINT          ↦ print(stack)
DownR 4      ↦ downRotate(stack, 4)
PRINT          ↦ print(stack)
POP             ↦ pop(stack)
POP             ↦ pop(stack)
PRINT          ↦ print(stack)

출력예시2
stars ↦ 6번 PRINT 연산의 결과
rstas ↦ 8번 PRINT 연산의 결과
tas    ↦ 11번 PRINT 연산의 결과

입력예시3
3                ↦ stack의 크기 N
5                ↦ 연산의 개수
PUSH d     ↦ push(stack,‘d‘)
DUP          ↦ duplicate(stack)
PUSH a    ↦ push(stack, ‘a’)
PRINT      ↦ print(stack)
PUSH s    ↦ push(stack, ‘s’)

출력예시3
add              ↦ 4번 PRINT 연산의 결과
Stack FULL ↦ 5번 PRINT 연산의 결과
*/

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
	getchar();  //scanfŔÇ enter žřžÖąâ Ŕ§ÇŃ °Í 
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
