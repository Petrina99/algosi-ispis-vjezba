#include <stdio.h>
#include <stdlib.h>

struct oeent {
    int x;
    struct oeent *next;
} typedef oe;

oe* stvori_list() {
    int i, n;
    oe *p, *glava;

    printf("Koliko zelite oeenata liste: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        if (i == 0) {
            glava = (oe*) malloc(sizeof(oe));
            p = glava;
        } else {
            p->next = (oe*) malloc(sizeof(oe));
            p = p->next;
        }

        printf("Unesite vrijednost: ");
        scanf("%d", &p->x);
    }

    p->next = NULL;
    return glava;
}

oe* stvori_listu_niz(int niz[], int n) {

    int i;

    oe *p, *glava;

    for (i = 0; i < n; i++) {
        if (i == 0) {
            glava = (oe*) malloc(sizeof(oe));
            p = glava;
        } else {
            p->next = (oe*) malloc(sizeof(oe));
            p = p->next;
        }

        p->x = niz[i];
    }

    p->next = NULL;
    return glava;
}

void ispis(oe* glava) {

    oe* p = glava;
    while (p != NULL) {
        printf("%d ", p->x);
        p = p->next;
    }

    printf("\n");
}

void dodaj_na_kraj(oe* glava) {

    oe* tmp1;
    tmp1 = (oe*) malloc(sizeof(oe));
    tmp1 = glava;

    //odlazimo na kraj
    while (tmp1->next != NULL) {
        tmp1 = tmp1->next;
    }

    oe* tmp;

    tmp = (oe*) malloc(sizeof(oe));
    printf("Unesi broj za dodat na kraj: ");
    scanf("%d", &tmp->x);
    tmp->next = NULL;
    tmp1->next = tmp;
}

void obrisi_kraj(oe* glava) {
    oe* tmp;

    tmp = (oe*) malloc(sizeof(oe));

    tmp = glava;

    oe* otmp;
    otmp = (oe*) malloc(sizeof(oe));

    while (tmp->next != NULL) {
        otmp = tmp;
        tmp = tmp->next;
    }

    otmp->next = NULL;
    free(tmp);
}

void ubaci(oe* glava, int index, int b) {
    oe* novi = (oe*) malloc(sizeof(oe));
    oe* tmp = glava;

    int brojac = 1;

    novi->x = b;

    if (index == 1) {
        novi->next = glava->next;
        glava->next = novi;
    } else {
        while (tmp->next != NULL) {
            if (brojac == index) {
                novi->next = tmp->next;
                tmp->next = novi;
                break;
            } else {
                tmp = tmp->next;
                brojac++;
            }
        }
    }
}

oe* dodaj_na_pocetak(oe* glava, int b) {
    if (glava != NULL) {
        oe* tmp = (oe*) malloc(sizeof(oe));
        tmp->x = b;
        tmp->next = glava;
        return tmp;
    }
}

int main(void) {

    // ako hocemo stvorit listu tako da korisnik unosi redom brojeve
    oe* glava1 = stvori_list();

    ispis(glava1);

    // ako hocemo stvorit listu od postojeceg niza
    int niz[] = {31, 56, 12, 15, 99, 321, 32, 22};
    int n = sizeof(niz) / sizeof(int);

    oe* glava2 = stvori_listu_niz(niz, n);

    ispis(glava2);

    dodaj_na_kraj(glava2);
    dodaj_na_kraj(glava2);

    ispis(glava2);

    //brisanje kraja liste
    obrisi_kraj(glava2);

    ispis(glava2);

    ubaci(glava2, 5, 1000);

    ispis(glava2);

    glava2 = dodaj_na_pocetak(glava2, 50);

    ispis(glava2);

    return 0;
}