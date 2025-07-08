#include <stdio.h>

float add(int, int);
float divide(int, int);
float threeMul(int, int, int);
float Calculator(float(*)(int, int), int, int);
float Calculator2(float(*)(int, int, int), int, int, int);

void Swap(int, int);
void Swap2(int*, int*);
void Swap3(int**, int**);

int main()
{

	int a = 20;
	int b = 30;
	int c = 10;
	float d = 0.0;


	// Add
	d = Calculator(add, a, b);
	printf("%d + %d = %f\n", a, b, d);
	// Div
	d = Calculator(divide, a, c);
	printf("%d / %d = %f\n", a, c, d);
	// ThreeMul
	d = Calculator2(threeMul, a, b, c);
	printf("%d * %d * %d = %f\n", a, b, c, d);


	float(*pFunptr1)(int, int); // 함수 포인터

	pFunptr1 = add;
	d = pFunptr1(a, b);
	//std::cout << d << std::endl;
	printf("%d + %d = %f\n", a, b, d);


	pFunptr1 = divide;
	d = pFunptr1(a, c);
	//std::cout << d << std::endl;
	printf("%d / %d = %f\n", a, c, d);


	float(*pFunptr)(int, int, int);
	pFunptr = threeMul;
	d = pFunptr(a, b, c);
	printf("%d * %d * %d = %f\n", a, b, c, d);
}

float add(int a, int b)
{
	return a + b;
}

float divide(int a, int b)
{
	return a / b;
}

float threeMul(int a, int b, int c)
{
	return a * b * c;
}

float Calculator(float(*pFuncPtr)(int, int), int a, int b)
{
	return pFuncPtr(a, b);
}

float Calculator2(float(*pFuncPtr)(int, int, int), int a, int b, int c)
{
	return pFuncPtr(a, b, c);
}

