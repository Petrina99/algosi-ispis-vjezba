#include <stdio.h>

// O(n*n)

int main(void) {
    int polje[] = {5123, 54, 23, 12, 1, 6, 6, 232, 3267, 23123, 3235, 0, 4, 5, 3232}; 
    int n = sizeof(polje) / sizeof(int), index, brojac = 0;

    printf("Pocetno polje\n");

    for (int i = 0; i < n; i++) {
        printf("%d ", polje[i]);
    }

    printf("\n");

    for (int i = 0; i < (n - 1); i++) {
        index = i;

        for (int j = i + 1; j < n; j++) {
            if(polje[index] > polje[j]) {
                index = j;
            }
        }

        if (index != i) {
            int tmp = polje[i];
            polje[i] = polje[index];
            polje[index] = tmp;
            brojac++;
        }
    }

    printf("Soritirano polje: \n");

    for (int i = 0; i < n; i++) {
        printf("%d ", polje[i]);
    }

    printf("\n\nUkupan broj zamjena: %d", brojac);
    return 0;
}