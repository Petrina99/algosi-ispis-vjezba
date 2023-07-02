#include <stdio.h>
#include <stdlib.h>


int n,sp = -1;
int *stack;

void push();
void pop();
void clear();
void peek();
int isEmpty();
void printStack();

int main(void) {

    printf("Odaberite maksimalnu veličinu stoga: ");
    scanf("%d", &n);

    stack = (int*) malloc(n * sizeof(int));

    printf("Dodavanje 3 elementa: \n");
    push();
    push();
    push();

    printf("Ispis stoga: \n");
    printStack();

    // izbacit ce se zadnja 2 koja smo unjeli
    printf("\nIzbacivanje 2 elementa\n");
    pop();
    pop();

    printStack();

    printf("\nDodavanje nova 2 elementa: \n");
    push();
    push();

    printf("\nRezultat funkcije peek: ");
    peek();



    return 0;
}

void push() {
    int x;

    if (sp == n - 1) {
        printf("Stack overflow\n");
    } else {
        scanf("%d", &x);
        sp++;
        stack[sp] = x;
    }
}

void pop() {
    if (isEmpty()) {
        printf("Stack underflow\n");
    } else {
        sp--;
    }
}

void clear() {
    sp = 0;
}

void peek() {
    if (isEmpty()) {
        printf("Stack underflow\n");
    } else {
        printf("%d ", stack[sp]);
    }
}

int isEmpty() {
    if (sp == -1) {
        return 1;
    } else {
        return 0;
    }
}

void printStack() {
    for (int i = sp; i > -1; i--) {
        printf("%d ", stack[i]);
    }
}