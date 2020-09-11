/*
(문제6)
두 개의 양의 정수를 입력받아,
이 두 정수의 최대공약수(gcd)를 유클리드 호제법으로 계산하여 출력하는 프로그램을 작성하시오.

입력 예시
12 8		↦ 두 양의 정수

출력 예시
4		↦ 12와 8의 최대공약수
*/

#include<stdio.h>

int gcd(int a, int b) {
    if (b == 0) {
        return a;
    }
    else {
        return gcd(b, a % b);
    }
}

int main() {

    int a, b;
    scanf("%d %d", &a, &b);

    int result = gcd(a, b);

    printf("%d", result);

    return 0;
}
