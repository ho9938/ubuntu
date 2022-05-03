#include <stdio.h>
#include <limits.h>

#define ARRAY_SIZE 4

int ABS (int n) { return n>0? n : -n; }

int main ()
{
	int A[ARRAY_SIZE] = {5, 40, 56, 100};
	int D[ARRAY_SIZE] = {0};
	int sum, k;
	int min = INT_MAX;
	for (int i=0; i<=100; i++) {
		printf ("When i=%d, ", i);
		sum = 0;
		for (int j=0; j<ARRAY_SIZE; j++) {
			D[j] = ABS (A[j] - i);
			printf ("%d ", D[j]);
			sum += D[j];
		}
		printf ("sum: %d\n", sum);
		if (sum < min) {
		       	min = sum;
			k = i;
		}
	}		
	printf ("When k=%d, min(sum)=%d", k, min);
	return 0;
}
