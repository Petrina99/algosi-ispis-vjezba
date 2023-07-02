#include <stdio.h>
#include <stdlib.h>

void printStack();
void push();
void pop();

typedef struct cvor {
    int x;
    struct cvor *next;
}CV;

CV *head;

int main(void) {

    push();
    push();
    push();

    printStack();

    pop();

    printStack();

    return 0;
}

void push() {
    int x;

    CV *p = (CV*) malloc(sizeof(CV));

    if (p == NULL) {
        printf("Greska u pushu\n");
    } else {
        printf("Unesite broj koji zelite dodat: ");
        scanf("%d", &x);

        if (head == NULL) {
            p->x = x;
            p->next = NULL;
            head = p;
        } else {
            p->x = x;
            p->next = head;
            head = p;
        }
    }
}

void pop() {

    CV *p = (CV*)malloc(sizeof(CV));
    if (head == NULL) {
        printf("Stack underflow");
    } else {
        p = head;
        head = head->next;
        printf("Pop izvrsen: %d\n", p->x);
        free(p);
    }
}

void printStack() {
    CV* p = head;

    if (p == NULL) {
        printf("Stack is empty");
    } else {
        printf("Trenutno stanje stoga: \n");
        while (p != NULL) {
            printf("%d ", p->x);
            p = p->next;
        }
    }
}