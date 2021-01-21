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


Node* appendTerm(Node* k, int c, int e) { 
    Node* t = newNode(c, e);
    Node* khead = newNode(0, 0);
    khead->next = k;

    while ((khead->next) != NULL) {
        khead = khead->next;
    }
    khead->next = t;

    return k;
}

Node* subPoly(Node* x, Node* y) {


    Node* i = x->next;
    Node* j = y->next;
    Node* k = newNode(0, 0);
    Node* khead = newNode(0, 0);;
    khead->next = k;

    while ((i != NULL) && (j != NULL)) {

        if (i->exp > j->exp) {

            k = appendTerm(khead, i->coef, i->exp);
            i = i->next;
        }
        else if (i->exp < j->exp) {

            k = appendTerm(khead, -(j->coef), j->exp);
            j = j->next;
        }
        else if (i->exp == j->exp) {

            int diff = i->coef - j->coef;
            if (diff != 0) {
                    k = appendTerm(khead, diff, i->exp);
            }
                
            i = i->next;
            j = j->next;
        }
    }

    while (i != NULL) {
        k = appendTerm(khead, i->coef, i->exp);
        i = i->next;
    }

    while (j != NULL) {
        k = appendTerm(khead, -(j->coef), j->exp);
        j = j->next;
    }

    return k;
}


int main(void) {

    Node* x = newNode(0, 0);
    Node* y = newNode(0, 0);
    Node* result;

    Node* xhead = newNode(0, 0);
    Node* yhead = newNode(0, 0);

    xhead->next = x;
    yhead->next = y;

    int x_num, y_num;

    scanf("%d", &x_num);

    for (int i = 0; i < x_num; i++) {
        int c;
        int e;
        scanf("%d %d", &c, &e);

        if (i == 0) {
            x->coef = c;
            x->exp = e;
        }
        else {
            x = appendTerm(x, c, e);
            x = x->next;
        }
    }

    scanf("%d", &y_num);

    for (int i = 0; i < y_num; i++) {
        int c;
        int e;
        scanf("%d %d", &c, &e);

        if (i == 0) {
            y->coef = c;
            y->exp = e;
        }
        else {
            y = appendTerm(y, c, e);
            y = y->next;
        }
    }

    result = subPoly(xhead, yhead);

    result = result->next;
    result = result->next;

    while (result != NULL) {
        if (result->exp == 0) {
            printf(" %d", result->coef);
        }
        else {
            printf(" %d %d", result->coef, result->exp);
        }  
        result = result->next;
    }

    return 0;

}