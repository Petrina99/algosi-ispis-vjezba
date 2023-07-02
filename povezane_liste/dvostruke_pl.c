#include <stdio.h>
#include <stdlib.h>

struct element{
    int x;
    struct element* prev;
    struct element* next;
} typedef oe;

oe* dodaj_na_pocetak(oe* glava, int b);
void ispis(oe* glava);

int main(void) {

    oe* glava = (oe*) malloc(sizeof(oe));
    glava->x = 50;

    glava = dodaj_na_pocetak(glava, 32);
    glava = dodaj_na_pocetak(glava, 32);
    glava = dodaj_na_pocetak(glava, 32);
    glava = dodaj_na_pocetak(glava, 32);

    ispis(glava);
    return 0;
}

oe* dodaj_na_pocetak(oe* glava, int b) {
    if (glava != NULL) {
        oe* temp = (oe*) malloc(sizeof(oe));
        temp->prev = NULL;
        temp->next = glava;
        temp->x = b;
        return temp;
    }
}

void ispis(oe* glava) {

    oe* p = glava;

   while (p != NULL) {
        printf("%d ", p->x);
        p = p->next;
    }
}

void dodaj_na_kraj(oe* glava, int b) {
    oe* tmp = glava;

    while (tmp->next != NULL) {
        tmp = tmp->next;
    }

    oe* tmp2 = (oe*) malloc(sizeof(oe));
    tmp2->x = b;
    tmp2->prev = tmp;
    tmp2->next = NULL;
    tmp->next = tmp2;
}

void ubaci(oe* glava, int index, int b) {

    oe* tmp = glava;
    int brojac = 1;

    if (index == 1) {
        oe* novi = (oe*) malloc(sizeof(oe));
        novi->next = glava->next;
        novi->prev = glava;
        glava->next = novi;
    } else {
        while (tmp->next != NULL) {
            if (brojac == index) {
                oe* novi = (oe*) malloc(sizeof(oe));
                novi->x = b;
                novi->next = tmp->next;
                novi->prev = tmp;
                tmp->next = novi;
                break;
            } else {
                tmp = tmp->next;
                brojac++;
            }
        }
    }
}