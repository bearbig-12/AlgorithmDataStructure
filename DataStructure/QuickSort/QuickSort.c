#include <stdio.h>

void Swap(int* a, int* b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

int Partition(int DataSet[], int left, int right)
{
	int first = left;
	int Pivot = DataSet[first];

	++left;


	while (left <= right)
	{
		while (DataSet[left] <= Pivot && left < right)
		{
			++left;
		}
		while (DataSet[left] >= Pivot && left <= right)
		{
			--right;
		}

		if (left < right)
		{
			Swap(&DataSet[left], &DataSet[right]);
		}
		else
			break;
	}

	Swap(&DataSet[first], &DataSet[right]);

	return right;
}

void QuickSort(int DataSet[], int left, int right)
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
	int DataSet[] = { 6, 4, 2, 3, 1, 5 };
	int Length = sizeof DataSet / sizeof DataSet[0];
	int i = 0;

	QuickSort(DataSet, 0, Length - 1);

	for (i = 0; i < Length; i++)
	{
		printf("%d ", DataSet[i]);
	}

	printf("\n");

	return 0;
}
