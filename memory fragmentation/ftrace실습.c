#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>

// int pthread_create(pthread_t *thread, const pthread_attr_t *attr, void *(*start_routine)(void*), void *arg)
// 1. thread : ������ thread�� ID
// 2. att : thread�� Ư�� (default = NULL) 
// >> thread �Ӽ� �����Ϸ��� pthread_attr_init���� �ʱ�ȭ�ؾ� �Ѵ�.
// 3. start_routine : � ������ ���� �Լ� �����͸� �Ű������� �޴´�.
// 4. arg : start_routine�� ���޵� ���� 
// thread ���� ������ 0 ��ȯ ���н� 1 ��ȯ  

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
