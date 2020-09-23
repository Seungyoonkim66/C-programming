/*Demand paging system을 가정하고 이를 위한 페이지 교체 기법을 구현하는 코드를 C언어로 작성하였습니다. 
  page reference string을 사용자에게 입력 받아 MIN, FIFO, LRU, LFU, Working set 기법으로 처리했을 경우 
  메모리 내부 변화 과정과 page fault 발생 과정을 추적 및 출력하는 프로그램*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef struct page {
    int page;
    int flag;
    int count;
} Page;

void MIN(Page prs[], int k, int m) {

    printf("\n========== MIN Algorithm ========== \n\n");

    Page *pf = (Page*)malloc(sizeof(Page) * m);
    Page *prs_min = (Page*)malloc(sizeof(Page) * m);
    int page_fault_min = 0;
    int max = 0;
    for (int i = 0; i < k; i++) {
        prs_min[i].count = 0;
        prs_min[i].flag = 0;
        prs_min[i].page = prs[i].page;
    }

    if (m >= k) {
        printf("총 page fault 발생 횟수: %d\n", page_fault_min);
        printf("no page fault occur\n");
        return;
    }

    // page frame이 page reference string 보다 작은 경우 replacement 기법 필요 
    else {
        for (int i = 0; i < k; i++) {
            // pf가 full될때까지 page 넣기
            if (i < m) {
                page_fault_min++;
                pf[i].page = prs_min[i].page; // page frame에 해당 page 넣기 
                prs_min[i].flag = 1; // i번째 page refernece는 page fault가 발생했음을 표시       
            }

            if (i >= m) { // page frame full 이후 작업 

                int match = -1;
                int prsi = prs_min[i].page;

                //match = 1 이면 page hit, 0 이면 page fault
                for (int j = 0; j < m; j++) { 
                    if (prsi == pf[j].page) {
                        match = 1; 
                        break;
                    }
                    else
                        match = 0;
                }

                if (match == 0) {
                    page_fault_min++;
                    prs_min[i].flag = 1;

                    // page frame에 있는 페이지들의 forward distance 계산 
                    for (int j = 0; j < m; j++) {
                        int p = i + 1;
                        while ((pf[j].page != prs_min[p].page) && (p < k)) {
                            p++;
                        }
                        pf[j].count = p - i;
                    }

                    //page frame에서 forward distance가 가장 큰 page 고르기 
                    max = pf[0].count;
                    int temp = 0;
                    for (int j = 0; j < m; j++) {
                        if (pf[j].count > max) {
                            max = pf[j].count;
                        }
                    }
                    for (int j = 0; j < m; j++) {
                        if (pf[j].count == max) {
                            temp = j;
                        }
                    }

                    // victim 페이지와 현재 참조 페이지 swap
                    Page temp2 = prs_min[i];
                    prs_min[i] = pf[temp];
                    pf[temp] = temp2;
                    prs_min[i].flag = 1;
                }
                else if (match == 1) {
                    continue;
                }
            }
        }
    }
    printf("총 page fault 발생 횟수: %d\n", page_fault_min);
    printf("page fault가 발생하는 page reference string의 index: ");
    for (int i = 0; i < k; i++) {
        if (prs_min[i].flag == 1) {
            printf("%d ", i);
        }
    }
    printf("\n");
}

void FIFO(Page prs[], int k, int m) {
    printf("\n========== FIFO Algorithm ========== \n\n");

    Page* pf = (Page*)malloc(sizeof(Page) * m);
    Page* prs_fifo = (Page*)malloc(sizeof(Page) * m);;
    for (int i = 0; i < k; i++) {
        prs_fifo[i].count = 0;
        prs_fifo[i].flag = 0;
        prs_fifo[i].page = prs[i].page;
    }
    int page_fault_fifo = 0;

    if (m >= k) {
        printf("총 page fault 발생 횟수: %d\n", page_fault_fifo);
        printf("no page fault occur\n");
        return;
    }
    // page frame이 page reference string 보다 작은 경우 replacement 기법 필요 
    else {
        for (int i = 0; i < k; i++) {
            int prsi = prs_fifo[i].page;
            //page frame 채우기 
            if (i < m) {
                page_fault_fifo++;
                pf[i].page = prsi;
                prs_fifo[i].flag = 1;
            }

            //after pageframe full
            if (i >= m) {
                int match = -1;
                for (int j = 0; j < m; j++) {
                    if (prsi == pf[j].page) {
                        match = 1; 
                        break;
                    }
                    else
                        match = 0;
                }
                if (match == 0) {
                    page_fault_fifo++;
                    prs_fifo[i].flag = 1;

                    for (int j = 0; j < m - 1; j++) {
                        Page temp = pf[j];
                        pf[j] = pf[j + 1];
                    }
                    pf[m - 1] = prs_fifo[i];

                }
                else if (match == 1) {
                    continue;
                }
            }
        }
    }
    printf("총 page fault 횟수 : %d\n", page_fault_fifo);
    printf("page fault가 발생하는 page reference string의 index: ");
    for (int i = 0; i < k; i++) {
        if (prs_fifo[i].flag == 1) {
            printf("%d ", i);
        }
    }
    printf("\n");
}

void LRU(Page prs[], int k, int m) {
    printf("\n========== LRU Algorithm ========== \n\n");

    Page* pf = (Page*)malloc(sizeof(Page) * m);
    Page* prs_lru = (Page*)malloc(sizeof(Page) * m);;
    for (int i = 0; i < k; i++) {
        prs_lru[i].count = 0;
        prs_lru[i].flag = 0;
        prs_lru[i].page = prs[i].page;
    }
    int page_fault_lru = 0;


    if (m >= k) {
        printf("총 page fault 발생 횟수: %d\n", page_fault_lru);
        printf("no page fault occur\n");
        return;
    }
    // page frame이 page reference string 보다 작은 경우 replacement 기법 필요 
    else {
        for (int i = 0; i < k; i++) {
            if (i < m) {
                // pf가 full될때까지 page 넣기
                page_fault_lru++;
                pf[i].page = prs_lru[i].page;
                prs_lru[i].flag = 1;
            }
            // page frame full 이후 작업 
            if (i >= m) {
                int match = -1;
                int prsi = prs_lru[i].page;

                for (int j = 0; j < m; j++) { 
                    if (prsi == pf[j].page) {
                        match = 1; 
                        break;
                    }
                    else
                        match = 0;
                }

                // page fault 발생
                if (match == 0) {
                    page_fault_lru++;
                    prs_lru[i].flag = 1;
                    int prsi = prs_lru[i].page;

                    // page frame에 있는 페이지들의 forward distance 계산 
                    for (int j = 0; j < m; j++) {
                        int p = i;
                        while ((pf[j].page != prs_lru[p].page) && (p >= 1)) {
                            p--;
                        }
                        pf[j].count = i - p;
                    }

                    //page frame에서 backward distance가 가장 큰 page 고르기 
                    int max = pf[0].count;
                    int temp = 0;
                    for (int j = 0; j < m; j++) {
                        if (pf[j].count > max) {
                            max = pf[j].count;
                        }
                    }
                    for (int j = 0; j < m; j++) {
                        if (pf[j].count == max) {
                            temp = j;
                        }
                    }

                    // pf에 있는 페이지와 현재 페이지 swap
                    Page temp2 = prs[i];
                    pf[temp] = temp2;
                    prs_lru[i].flag = 1;
                }
                else if (match == 1) {
                    continue;
                }

            }
        }
    }
    printf("총 page fault 발생 횟수: %d\n", page_fault_lru);
    printf("page fault가 발생하는 page reference string의 index: ");
    for (int i = 0; i < k; i++) {
        if (prs_lru[i].flag == 1) {
            printf("%d ", i);
        }
    }
    printf("\n");
}

void LFU(Page prs[], int k, int m) {
    printf("\n========== LFU Algorithm ========== \n\n");

    Page* pf = (Page*)malloc(sizeof(Page) * m);
    Page* prs_lfu = (Page*)malloc(sizeof(Page) * m);;
    for (int i = 0; i < k; i++) {
        prs_lfu[i].count = 0;
        prs_lfu[i].flag = 0;
        prs_lfu[i].page = prs[i].page;
    }
    int page_fault_lfu = 0;

    if (m >= k) {
        printf("총 page fault 발생 횟수: %d\n", page_fault_lfu);
        printf("no page fault occur\n");
        return;
    }
    // page frame이 page reference string 보다 작은 경우 replacement 기법 필요 
    else {
        for (int i = 0; i < k; i++) {
            int prsi = prs_lfu[i].page;
            // until page frame full
            if (i < m) {
                page_fault_lfu++;
                pf[i].page = prs_lfu[i].page; 
                prs_lfu[i].flag = 1;
                prs_lfu[i].count++; // 참조할때마다 count++

            }

            // after page frame full
            if (i >= m) {
                int match = -1;

                // page frame에 참조할 page 여부 확인 
                for (int j = 0; j < m; j++) {
                    if (prsi == pf[j].page) {
                        match = 1;
                        break;
                    }
                    else
                        match = 0;
                }

                // page hit
                if (match == 1) {
                    prs_lfu[i].count++;
                    continue;
                }
                // page fault 
                else if (match == 0) {
                    page_fault_lfu++;
                    prs_lfu[i].flag = 1;
                    prs_lfu[i].count++;

                    int min = pf[0].count;
                    int temp = 0;
                    // 참조 횟수가 가장 적은 pf[j]이 victim 
                    for (int j = 0; j < m; j++) {
                        if (pf[j].count < min) {
                            min = pf[j].count;
                        }
                        else if (pf[j].count == min) {
                            min = pf[0].count; // 최소 참조 횟수가 겹치면 pf[0]을 victim으로 선택 
                        }
                    }
                    for (int j = 0; j < m; j++) {
                        if (pf[j].count == min) {
                            temp = j;
                        }
                    }

                    Page temp2 = prs_lfu[i];
                    pf[temp] = temp2;
                    prs_lfu[i].flag = 1;
                }
            }
        }
    }
    printf("총 page fault 발생 횟수: %d\n", page_fault_lfu);
    printf("page fault가 발생하는 page reference string의 index: ");
    for (int i = 0; i < k; i++) {
        if (prs_lfu[i].flag == 1) {
            printf("%d ", i);
        }
    }
    printf("\n");
}


void WS(Page prs[], int k, int m, int w) {
    printf("\n========== WS Algorithm ========== \n\n");

    Page* pf = (Page*)malloc(sizeof(Page) * m);
    Page* prs_ws = (Page*)malloc(sizeof(Page) * m);;
    for (int i = 0; i < k; i++) {
        prs_ws[i].count = 0;
        prs_ws[i].flag = 0;
        prs_ws[i].page = prs[i].page;
    }
    int page_fault_ws = 0;

    if (m >= k) {
        printf("총 page fault 발생 횟수: %d\n", page_fault_ws);
        printf("no page fault occur\n");
        return;
    }
    // page frame이 page reference string 보다 작은 경우 replacement 기법 필요 
    else {
        for (int i = 0; i < k; i++) {
            int prsi = prs_ws[i].page;
            if (i < w) {
                page_fault_ws++;
                pf[i].page = prsi;
                prs_ws[i].flag = 1;
            }
            else if (i >= w) {
                for (int j = i - w, k = 0; k < w; j++, k++) {
                    pf[k].page = prs_ws[j].page;
                }
                int match = -1;
                for (int j = 0; j < w; j++) {
                    if (prs_ws[i].page == pf[j].page) {
                        match = 1;
                        break;
                    }
                    else
                        match = 0;
                }

                if (match == 0) {
                    page_fault_ws++;
                    prs_ws[i].flag = 1;
                }
                else if (match == 1) {
                    continue;

                }
            }
        }
    }
    printf("총 page fault 발생 횟수 : %d\n", page_fault_ws);
    printf("page reference string에서 page fault가 발생한 index : ");
    for (int i = 0; i < k; i++) {
        if (prs_ws[i].flag == 1) {
            printf("%d ", i);
        }
    }
    printf("\n");
}


int main(void) {

    Page* prs;

    int n; // 프로세스가 갖는 page 개수
    int m; // page frame 개수
    int w; // window size
    int k; // page reference string 길이 

    scanf("%d %d %d %d", &n, &m, &w, &k);

    prs = (Page*)malloc(sizeof(Page) * k);
    prs->count = 0;
    prs->flag = 0;

    // pfs를 배열로 입력받기
    for (int i = 0; i < k; i++) {
        scanf("%1d", &prs[i].page);
    }

    MIN(prs, k, m);
    FIFO(prs, k, m);
    LRU(prs, k, m);
    LFU(prs, k, m);
    WS(prs, k, m, w);
}
