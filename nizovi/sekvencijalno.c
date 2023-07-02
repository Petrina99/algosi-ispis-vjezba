#include <stdio.h>

// O(n)
int main(void) {

    int p[] = {51, 52, 22, 33, 67, 12, 67, 99, -5, 23 };
    int trazeni, i, n = 10, status = 0;

    printf("Unesite trazeni broj: ");

    scanf("%d", &trazeni);

    for (i = 0; i < n; i++) {
        if (p[i] == trazeni) {
            printf("Broj pronaden na %d mjestu u nizu", i + 1);
            status = 1;
            break;
        }
    }

    if (!status) {
        printf("Trazeni broj nije pronaden u nizu");
    }

    return 0;
}