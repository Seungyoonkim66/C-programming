#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node {
    char data;
    struct node* prev;
    struct node* next;
} Node;

typedef struct list{
    Node* head;
    Node* tail;
    int size;
} List;

Node* initNode(char data) {
    Node* newnode = (Node*)malloc(sizeof(Node));

    newnode->data = data;
    newnode->next = NULL;
    newnode->prev = NULL;

    return newnode;
}

List* initList(){

    List* list = (List*)malloc(sizeof(List));
    list->head = initNode('h');
    list->tail = initList('t');
    list->head->next = list->tail;
    list->tail->prev = list->head;
    list->size = 0;
  
    return list;
}

void add(List* list, int position, char data){
    Node* newnode = initNode(data);
    Node* temp = list->head;
    int i;

    if (position <= 0) {
        printf("invalid position\n");
    }

    if (list->head->next == list->tail) { //리스트에 처음 노드 삽입 
        list->head->next = newnode;
        list->tail->prev = newnode;
        newnode->prev = list->head;
        newnode->next = list->tail;
    }
    else {
        for (i = 0; i < position; i++) temp = temp->next;
        if (temp->next == list->tail) {
            temp->next = newnode;
            list->tail->prev = newnode;
            newnode->prev = temp;
            newnode->next = list->tail;
        }
        else {
            newnode->next = temp->next;
            temp->next->prev = newnode;
            temp->next = newnode;
            newnode->prev = temp;
            
        }
    }
   
    (list->size)++;
}

void delete(List* list, int position){
    Node* temp = list->head;
    int i;

    if (position <= 0 || position > list->size) {
        printf("invalid position\n");
    }

    for (i = 0; i < position; i++) {
        temp = temp->next;
    }

    Node* prenode = temp->prev;
    Node* nextnode = temp->next;
    temp->prev = NULL;
    temp->next = NULL;

    prenode->next = nextnode;
    nextnode->prev = prenode;

    (list->size)--;

    if (list->size == 0) {
        initList(list);
    }
}

void get(List* list, int position){

    Node* temp = list->head;
    int i;

    if (position <= 0 || position > list->size) {
        printf("invalid position\n");
    }
    
    for (i = 0; i < position; i++) {
        temp = temp->next;
    }
    
    if (temp != list->tail) {
        printf("%c\n", temp->data);
    }
    
    
}

void print(List* list){
    Node* temp = list->head->next;

    while (temp != list->tail) {
        printf("%c", temp->data);
        temp = temp->next;
    }

    printf("\n");
    return;
}


int main() {
    List* list = initList();

    int N; // 연산 개수
    int i;

    scanf("%d", &N);

    for (i = 0; i < N; i++) {
        char op, data; 
        int position;

        scanf(" %c", &op);

        switch (op) {
        case 'A':
            scanf(" %d %c", &position, &data);
            add(&list, position, data);
            break;
        case 'D':
            scanf(" %d", &position);
            delete(&list, position);
            break;
        case 'G':
            scanf(" %d", &position);
            get(&list, position);;
            break;
        case 'P':
            print(&list);
            break;
        }
    }

    return 0;
}

