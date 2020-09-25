/*
- Test the function with the following three types of integer inputs.
 1) int A[100] : filled with rand()%1000, execute srand(time(NULL)) first, (stdlib.h, time.h should be included)
 (Duplicate keys are ignored.)
 2) int A[100] : already sorted (Write a function for filling in A[])
 3) int A[100] : reversely sorted “
 - For the inputs of 2) and 3), A[] can be filled with the integers from
 100 ~ 1 (from 100 down to 1) and 1 ~ 100 (from 1 to 100) respectively. 
 - Print A[], before and after sorting for each case of above inputs. 
 - Print the number of comparisons for each case of above inputs.
*/

#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int merge(int* A, int start, int mid, int end, int c) {

    int i = start;
    int j = mid + 1;
    int k = start;
    int B[100];

    while (i <= mid && j <= end) {
        if (A[i] <= A[j])
            B[k++] = A[j++];
        else
            B[k++] = A[i++];
        c++;
    }

    if (i > mid) {
        for (int t = j; t <= end; t++) {
            B[k++] = A[t];
        }
    }
    else {
        for (int t = i; t <= mid; t++)
            B[k++] = A[t];
    }

    for (int t = start; t <= end; t++) {
        A[t] = B[t];
    }


}

int merge_sort(int* A, int start, int end, int c) {
    c = 0;
    int middle;
    if (start < end) {
        middle = (start + end) / 2;
        merge_sort(A, start, middle, c);
        merge_sort(A, middle+1, end, c);
        c = merge(A, start, middle, end, c);
    }
    return c;
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
    int count = 0;
    int A[100];

    printf("=============================================MERGE SORT=====================================================\n");

    /* (a) random */
    printf("(1) randomly filled array\n\n");
    srand(time(NULL));
    for (i = 0; i < 100; i++) {
        A[i] = rand() % 1000;
    }
    print(A);
    count = merge_sort(A, 0, 99, count);
    printf("after merge sorted\n\n");
    print(A);
    printf("number of comparison: %d\n", count);
    printf("============================================================================================================\n");

    /* (b) sorted */
    printf("(2) sorted array\n\n");
    for (i = 0; i < 100; i++) {
        A[i] = i+1;
    }
    print(A);
    count = merge_sort(A, 0, 99, count);
    printf("after merge sorted\n\n");
    print(A);
    printf("number of comparison: %d\n", count);
    printf("============================================================================================================\n");


    /* (c) reversly sorted */
    printf("(2) reversly sorted array\n\n");
    for (i = 0; i < 100; i++) {
        A[i] = 99 - i+1;
    }
    print(A);
    count = merge_sort(A, 0, 99, count);
    printf("after merge sorted\n\n");
    print(A);
    printf("number of comparison: %d\n", count);



    return 0;
}
