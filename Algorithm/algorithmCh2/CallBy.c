#include <stdio.h>

void Swap(int, int);
void Swap2(int*, int*);
void Swap3(int**, int**);

int main()
{

	int a = 20;
	int b = 30;
	int c = 10;
	float d = 0.0;

	int* pA = &a;
	int* pB = &b;
	
	// Call by Value
	/*printf("before a = %d, b = %d\n", a, b);
	Swap(a, b);
	printf("after a = %d, b = %d\n", a, b);*/

	// Call by Address / Call by reference
	/*printf("before a = %d, b = %d\n", a, b);
	Swap2(&a, &b);
	printf("after a = %d, b = %d\n", a, b);*/

	printf("before a = %d, b = %d\n", a, b);
	Swap3(&pA, &pB);
	printf("after a = %d, b = %d\n", a, b);

}


void Swap(int a, int b)
{
	int temp = 0;

	temp = a;
	a = b;
	b = temp;
}

void Swap2(int* a, int* b)
{
	int temp = 0;

	temp = *a;
	*a = *b;
	*b = temp;
}

void Swap3(int** a, int** b)
{
	int temp = 0;

	temp = **a;
	**a = **b;
	**b = temp;
}

