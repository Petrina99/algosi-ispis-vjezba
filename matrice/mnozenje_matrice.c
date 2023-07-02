#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void) {

	// da bi mogli mnozit matrice prva matrica(a) mora imat isti broj stupaca kao druga matrica(b) redaka

	srand((unsigned)time(NULL));

	int a[5][3], b[3][9], c[5][9];
	
	int i, j, p;
	for (i = 0; i < 5; i++) {
		for (j = 0; j < 3; j++) {
			a[i][j] = rand() % 10 + 1;
		}
	}

	for (i = 0; i < 3; i++) {
		for (j = 0; j < 9; j++) {
			b[i][j] = rand() % 10 + 1;
		}
	}

	// p je broj stupaca prve matrice tj. broj redaka druge
	for (i = 0; i < 5; i++) {
		for (j = 0; j < 9; j++) {
			c[i][j] = 0;

			for (p = 0; p < 3; p++) {
				c[i][j] += a[i][p] * b[p][j];
			}
		}
	}

	for (i = 0; i < 5; i++) {
		for (j = 0; j < 9; j++) {
			printf("%d ", c[i][j]);
		}

		printf("\n");
	}

	return 0;
}