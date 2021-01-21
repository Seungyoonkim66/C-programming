#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>

// int pthread_create(pthread_t *thread, const pthread_attr_t *attr, void *(*start_routine)(void*), void *arg)
// 1. thread : 생성된 thread의 ID
// 2. att : thread의 특성 (default = NULL) 
// >> thread 속성 지정하려면 pthread_attr_init으로 초기화해야 한다.
// 3. start_routine : 어떤 로직을 할지 함수 포인터를 매개변수로 받는다.
// 4. arg : start_routine에 전달될 인자 
// thread 생성 성공시 0 반환 실패시 1 반환  

void* thread_routine(void* arg) {
    pthread_t tid;

    tid = pthread_self();

    int i = 0;
    printf("\ttid:%x\n", tid);
    while (i < 10) {
        printf("\tnew thread:%d\n", i);
        i++;
        sleep(1);
    }
}

int main() {
    pthread_t thread;

    thread = pthread_create(&thread, NULL, thread_routine, NULL);

    int i = 0;
    printf("tid:%x\n", pthread_self());
    while (i < 5) {
        printf("main:%d\n", i);
        i++;
        sleep(1);
    }
}
