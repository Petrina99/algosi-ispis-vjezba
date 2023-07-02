#include <stdio.h>

// O(log n)
int main(void) {

    // polje mora biti soritirano za binarno pretrazivanje
    int p[] = {1, 15, 25, 35, 55, 59, 61, 82, 99, 10000};
    int dg, gg, sredina, trazeni;

    printf("Unesite trazeni broj: ");
    scanf("%d", &trazeni);

    dg = 0;
    gg = 10 - 1;

    while (gg >= dg) {
        sredina = (gg + dg) / 2;

        if(p[sredina] == trazeni) {
            printf("Pronaden broj na %d. mjestu u nizu.", sredina + 1);
            break;
        } 

        if (trazeni > p[sredina]) {
            dg = sredina + 1;
        }

        if (trazeni < p[sredina]) {
            gg = sredina - 1;
        }

        if (dg > gg) {
            printf("Trazeni broj ne postoji u polju.");
            break;
        }
    }

    return 0;
}