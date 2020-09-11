/*
(문제3)
양의 정수를 입력 받아, 각 자리의 수를 낮은 자릿수부터 차례로 출력하는 프로그램을 작성하시오.
(나머지 조건은 문제 2와 동일)

입력 예시
3408		↦  입력 정수

출력 예시
8
0
4
3

힌트: 출력순서에 차이가 있음에 주목하고, 이 차이점이 재귀 함수에 어떻게 반영되는지를 파악하라.
*/

#include<stdio.h>
int func(int n) {

    int a = n % 10;
    int b = n / 10;

    if (n == 0) {
        return;
    }
    else {
        printf("%d\n", a);
        func(b);
    }
}

int main() {

    int n;
    scanf("%d", &n);

    func(n);

    return 0;
}
