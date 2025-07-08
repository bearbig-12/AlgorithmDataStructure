#include <stdio.h>
void SetArray(int*, int);
void PrintArray(int*, int);

int main()
{
	int array[100];
	// 배열의 칸은 주소값이며, Int형 배열이므로 한 칸당 4byte이다.
	// 위 array의 데이터 타입은 int* 이다.
	// 배열명은 주소상수 이므로 array = 10; 과 같은 값을 넣을 수 없다.
	SetArray(array, 100);

	PrintArray(array, 100);


}

void SetArray(int* parray, int size) {
	for (int i = 0; i < size; i++) {
		parray[i] = i;
	}
}


void PrintArray(int* parray, int size) {
	for (int i = 0; i < size; i++) {
		printf("parray[%d] = %d\n", i, parray[i]);
	}
}