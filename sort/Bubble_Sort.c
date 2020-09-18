/*
- Test the function with the following three types of inputs.
 1) int A[100] : filled by rand()%1000, execute srand(time(NULL)) first, (stdlib.h, time.h should be included)
 (Duplicate keys are ignored.)
 2) int A[100] : already sorted (Write a function for filling in A[])
 3) int A[100] : reversely sorted “
 - Print A, before and after sorting for each case of input. - Give the number of comparisons for each case of input
*/

#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int bubble_sort(int* A) {
    int i, j;
    int count = 0;
    for (i = 0; i < 100; i++) {
        for (j = 0; j < 99 - i; j++) {
            if (A[j] > A[j + 1]) {
                int temp = A[j];
                A[j] = A[j + 1];
                A[j + 1] = temp;
                count++;
            }
        }
    }
    return count;
}

int print(int* A) {
    int i;
    for (i = 0; i < 100; i++) {
        printf(" %d", A[i]);
    }
    printf("\n");
    printf("\n");
    return 0;
}

int main() {
    int i;
    int A[100];

    printf("=========================================BUBBLE SORT=================================================\n");

    /* (a) random */
    printf("(1) randomly filled array\n\n");
    srand(time(NULL));
    for (i = 0; i < 100; i++) {
        A[i] = rand()%1000;
    }
    print(A);
    int count = bubble_sort(A);
    printf("after bubble sorted\n\n");
    print(A);
    printf("number of comparison: %d\n", count);
    printf("============================================================================================================\n");

    /* (b) sorted */
    printf("(2) sorted array\n\n");
    for (i = 0; i < 100; i++) {
        A[i] = i;
    }
    print(A);
    count = bubble_sort(A);
    printf("after bubble sorted\n\n");
    print(A);
    printf("number of comparison: %d\n", count);
    printf("============================================================================================================\n");


    /* (c) reversly sorted */
    printf("(2) reversly sorted array\n\n");
    for (i = 0; i < 100; i++) {
        A[i] = 99-i;
    }
    print(A);
    count = bubble_sort(A);
    printf("after bubble sorted\n\n");
    print(A);
    printf("number of comparison: %d\n", count);
    


    return 0;
}
