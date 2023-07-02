#include <stdio.h>

// O(n)
void insertionSort(int p[], int n) {
    int i, tmp, j;

    for (i = 1; i < n; i++) {
        tmp = p[i];
        j = i - 1;

        while (j >= 0 && p[j] > tmp) {
            p[j + 1] = p[j];
            j = j - 1;
        }
        p[j + 1] = tmp;
    }
} 

int main(void) {

    int p[] = { 12, 11, 13, 5, 6};

    insertionSort(p, 5);

    for (int i = 0; i < 5; i++) {
        printf("%d ", *(p + i));
    }

    return 0;
}