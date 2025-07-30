#include <stdio.h>
#include "Score.h"

//void Swap(int* a, int* b)
//{
//	int temp = *a;
//	*a = *b;
//	*b = temp;
//}

void Swap(Score* a, Score* b)
{
	Score temp = *a;
	*a = *b;
	*b = temp;
}

//int Partition(int DataSet[], int left, int right)
//{
//	int first = left;
//	int Pivot = DataSet[first];
//
//	++left;
//
//
//	while (left <= right)
//	{
//		while (DataSet[left] <= Pivot && left < right)
//		{
//			++left;
//		}
//		while (DataSet[left] >= Pivot && left <= right)
//		{
//			--right;
//		}
//
//		if (left < right)
//		{
//			Swap(&DataSet[left], &DataSet[right]);
//		}
//		else
//			break;
//	}
//
//	Swap(&DataSet[first], &DataSet[right]);
//
//	return right;
//}

int Partition(Score DataSet[], int Left, int Right)
{
	int First = Left;
	Score Pivot = DataSet[First];

	++Left;

	while (Left <= Right)
	{
		while (DataSet[Left].score <= Pivot.score && Left < Right)
			++Left;

		while (DataSet[Right].score >= Pivot.score && Left <= Right)
			--Right;

		if (Left < Right)
			Swap(&DataSet[Left], &DataSet[Right]);
		else
			break;
	}

	Swap(&DataSet[First], &DataSet[Right]);

	return Right;
}

//void QuickSort(int DataSet[], int left, int right)
//{
//	if (left < right)
//	{
//		int Index = Partition(DataSet, left, right);
//
//		QuickSort(DataSet, left, Index - 1);
//		QuickSort(DataSet, Index + 1, right);
//	}
//}

void QuickSort(Score DataSet[], int left, int right)
{
	if (left < right)
	{
		int Index = Partition(DataSet, left, right);

		QuickSort(DataSet, left, Index - 1);
		QuickSort(DataSet, Index + 1, right);
	}
}


int main(void)
{
	//int DataSet[] = { 6, 4, 2, 3, 1, 5 };
	int arraySize = sizeof DataSet / sizeof DataSet[0];
	int i = 0;


	QuickSort(DataSet, 0, arraySize - 1);

	for (int i = 0; i < 10; ++i)
	{
		printf("Number: %d, Score: %3f\n", DataSet[i].number, DataSet[i].score);

	}


	for (int i = arraySize - 10; i < arraySize; ++i)
	{
		printf("Number: %d, Score: %3f\n", DataSet[i].number, DataSet[i].score);
	}

	//for (i = 0; i < Length; i++)
	//{
	//	printf("%d ", DataSet[i]);
	//}

	printf("\n");

	return 0;
}
