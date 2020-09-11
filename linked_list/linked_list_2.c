#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int coef;
    int exp;
    struct node* next;
} Node;


Node* newNode(int c, int e) {
    Node* p = (Node*)malloc(sizeof(Node));
    p->coef = c;
    p->exp = e;
    p->next = NULL;
    return p;
}


Node* appendTerm(Node *k, int c, int e) { //k는 마지막항
    Node* t = newNode(c, e);
    Node* khead = newNode(NULL, NULL);
    khead->next = k;

    while ((khead->next) != NULL) {
        khead = khead->next;
    }
    khead->next= t;

    return k;
}

Node* addPoly(Node *x, Node *y) {

    printf("i = %d\nj = %d \n", (x->next)->coef, (y->next)->coef);

    Node *i = x->next;
    Node *j = y->next;
    Node *k = newNode(NULL, NULL);
    Node *khead = newNode(NULL, NULL);;
    khead->next = k;

    while ((i!= NULL) && (j!= NULL)) {

        if (i->exp > j->exp) {
            printf("x차수가 큰 경우\n");
            k = appendTerm(khead, i->coef, i->exp);
            i = i->next;
        }
        else if (i->exp < j->exp) {
            printf("y차수가 큰 경우\n");
            k = appendTerm(khead, j->coef, j->exp);
            j = j->next;
        }
        else if (i->exp == j->exp) {
            printf("x y차수가 같은 경우\n");
            int sum = i->coef + j->coef;
            if (sum != 0)
                k = appendTerm(khead, sum, i->exp);
            i = i->next;
            j = j->next;
        }
    }

    while (i != NULL) {
        k = appendTerm(khead, i->coef, i->exp);
        i = i->next;
    }

    while (j != NULL) {
        k = appendTerm(khead, j->coef, j->exp);
        j = j->next;
    }

    return k;
}


int main(void) {

    Node *x = newNode(NULL, NULL);
    Node *y = newNode(NULL, NULL);
    Node *result;

    Node* xhead = newNode(NULL, NULL);
    Node* yhead = newNode(NULL, NULL);

    xhead->next = x;
    yhead->next = y;
 
    int x_num, y_num;

    scanf_s("%d", &x_num);

    for (int i = 0; i < x_num; i++) {
        int c;
        int e;
        scanf_s("%d %d", &c, &e);

        if (i == 0) {
            x->coef = c;
            x->exp = e;
        }
        else {
            x = appendTerm(x, c, e);
            x = x->next;
        }
    }

    scanf_s("%d", &y_num);

    for (int i = 0; i < y_num; i++) {
        int c;
        int e;
        scanf_s("%d %d", &c, &e);
   
        if (i == 0) {
            y->coef = c;
            y->exp = e;
        }
        else {
            y = appendTerm(y, c, e);
            y = y->next;
        }
    }  

    result = addPoly(xhead, yhead);

    result = result->next;
    result = result->next;

    while (result != NULL) {
        printf(" %d %d", result->coef, result->exp);
        result = result->next;
    }

    return 0;

}