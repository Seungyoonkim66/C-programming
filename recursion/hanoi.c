/*
(문제4)
정수 N ≤ 20을 입력 받아 최댓값을 구하는 프로그램을 작성하시오.

입력 예시
5					↦  N = 5
4 1 8 3 7 				↦  입력 정수

출력 예시
8					↦  최댓값

다음 예에서 보여주는 재귀 관계를 이용하여 구현하시오(재귀 함수 사용).
- 예: (4, 1, 8, 3, 7)의 최댓값 ⇒ (4, 1, 8, 3)의 최댓값과 7 중 큰 값
*/

#include<stdio.h>

int compare(int a[], int n) {

    int* ptr = a;
    int max = *(ptr + (n - 1));

    if (n == 0) {
        return 0;
    }
    else {
        if (max > compare(a, n - 1))
            return max;
        else {
            return compare(a, n - 1);
        }

    }

}

int main() {

    int n;
    scanf("%d", &n);

    int a = malloc(sizeof(int)*n);

    for (int i = 0; i < n; i++) {
        scanf("%d ", &a[i]);
    }

    printf("%d", compare(a, n));

    return 0;
}
