#include<stdio.h>

int sum(int N) {
    if (N == 1) {
        return 1;
    }
    else {
        return N + sum(N - 1);
    }

}

int main() {

    int N;
    int result = 0;
    scanf("%d", &N);

    result = sum(N);


    printf("%d", result);



    return 0;
}