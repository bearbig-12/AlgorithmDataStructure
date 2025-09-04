#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>


int a = 0;	//500
int b = 0;	//100
int c = 0;	//50
int d = 0;	//10
int e = 0;	//5
int f = 0;	//1


// 500, 100, 50, 10, 5, 1
void GreedyCoin(int money)
{
	if (money == 0)
	{
		return;
	}
	if (money >= 500)
	{
		money -= 500;
		++a;
		GreedyCoin(money);
	}
	else if (money >= 100)
	{
		money -= 100;
		++b;
		GreedyCoin(money);
	}
	else if (money >= 50)
	{
		money -= 50;
		++c;
		GreedyCoin(money);
	}
	else if (money >= 10)
	{
		money -= 10;
		++d;
		GreedyCoin(money);
	}
	else if (money >= 5)
	{
		money -= 5;
		++e;
		GreedyCoin(money);
	}
	else
	{
		money -= 1;
		++f;
		GreedyCoin(money);
	}
}

int main()
{
	int money;
	printf("금액을 입력하세요: ");
	scanf("%d", &money);

	GreedyCoin(money);

	int total = a + b + c + d + e + f;

	if (a > 0) printf("500원: %d개\n", a);
	if (b > 0) printf("100원: %d개\n", b);
	if (c > 0) printf("50원: %d개\n", c);
	if (d > 0) printf("10원: %d개\n", d);
	if (e > 0) printf("5원: %d개\n", e);
	if (f > 0) printf("1원: %d개\n", f);

	printf("최소 동전 개수: %d\n", total);
}