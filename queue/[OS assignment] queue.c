#include <stdio>

typedef struct Node {
    int data;
    Node* next;
}

typedef struct Queue {
    Node* front;
    Node* back;
    int count;
}

void InitQueue(Queue **queue){
    (*queue) = (Queue*)malloc(sizeof(Queue));
    (*queue)->front = (*queue)->back = NULL;
    (*queue)->count = 0;
}

Node* CreateNode(int data){
    Node* node = (Node*)malloc(sizeof(Node));
    node->data =data;
    node->next = NULL;
    return node;
}

void EnQueue(QUeue **queue, Node *node){
    if((*queue->count) == 0){
        (*queue)->front = (*queue)->back = node;
    }
    else{
        (*queue)->back->next = node;
        (*queue)->back = node;
    }
    (*queue)->count++;
}

Node* DeQueue(Queue **queue){
    Node * n = (*queue)->front;
    (*queue)->front = n->next;
    (*queue)->count--;
    return n;
}

int getNodeCount(Queue **queue){
    return (*queue)->count;
}

void DestroyQueue(Queue** queue){
    int cnt = getNodeCount(queue);
    for(int i=0; i<cnt; i++){
        Node * n = DeQueue(queue);
        free(n);
    }
    (*queue)->front = (*queue)->back = NULL;
    (*queue)->count = 0;
    free(*queue);
}

void PrintAllNode(Queue** queue){
    int cnt = getNodeCount(queue);
    for(int i=0; i<cnt; i++){
        Node * n = DeQueue(queue);
        cout << n->data <<endl;
        free(n);
    }
}

int main(){

    Queue *queue1 = NULL;
    Queue *queue2 = NULL;
    Queue *queue3 = NULL;
    Queue *queue4 = NULL;

}