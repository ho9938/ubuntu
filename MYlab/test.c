#include <stdio.h>
#include <limits.h>

struct heap {
	int* array;
	int length;
	int heap_size;
};

/* this is the function you can use
 * because there was any test case as standard,
 * it was so amgiguous to make function.
 * so please give us one test case next at least,
 * so that we can write code fit to it.
 * Anyway, I assumed that valid value is
 * inside from A[1] to A[n] according to the
 * assignment handout... So you must declare A[n+1]
 * and pass valid value from A[1], not A[0]
 * to use this function. */
int min_sum (int *A, int n);

void max_heapify (struct heap *hA, int i);
void build_max_heap (struct heap *hA);
void heapsort (struct heap *hA);
int ABS (int n);
void exchange (int *x, int *y);

int min_sum (int *A, int n)
{
	// generate heap with A
	struct heap hA;
	hA.array = A;
	hA.length = n;
	hA.heap_size = n;

	heapsort (&hA);

	int k = A[n/2];
	int sum = 0;
	for (int i=1; i<=n; i++)
		sum += ABS (A[i] - k);
	return sum;
}
	
void max_heapify (struct heap *hA, int i)
{
	int l = 2*i; 
	int r = 2*i + 1;
	int largest = i;
	if (l <= hA->heap_size && hA->array[l] > hA->array[i])
		largest = l;
	if (r <= hA->heap_size && hA->array[r] > hA->array[largest])
		largest = r;
	if (largest != i) {
		exchange (&hA->array[i], &hA->array[largest]);
		max_heapify (hA, largest);
	}
}

void build_max_heap (struct heap *hA)
{
	hA->heap_size = hA->length;
	for (int i = hA->length/2; i>0; i--)
		max_heapify (hA, i);
}

void heapsort (struct heap *hA)
{
	build_max_heap (hA);
	for (int i = hA->length; i>1; i--) {
		exchange (&hA->array[1], &hA->array[i]);
		hA->heap_size = hA->heap_size - 1;
		max_heapify (hA, 1);
	}	
}

int ABS (int n) { return n>0? n : -n; }

void exchange (int *x, int *y)
{
	int tmp;
	tmp = *x;
	*x = *y;
	*y = tmp;
}

#define size 12
int main ()
{
	int A[size+1] = {0, 5, 56, 40, 100, 54, 32, 12, 75, 80, 80, 34, 57};
	printf ("sum = %d\n", min_sum (A, size));
	for (int i=0; i<size; i++)
		printf ("%d ", A[i+1]);
	return 0;
}
