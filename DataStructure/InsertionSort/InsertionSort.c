#include <stdio.h>
#include <stdbool.h>


int main()
{
	int DataSet[] = { 6, 4, 2, 3, 1, 5 };
	int arraySize = sizeof(DataSet) / sizeof(int);
	int temp = 0;
	for (int i = 1; i < arraySize; ++i)
	{
		if (DataSet[temp] > DataSet[temp + 1])
		{
			break;
		}
		int key = DataSet[i];
		int j;
		for (j = i-1; j >= 0 && key < DataSet[j]; --j)
		{
			DataSet[j + 1] = DataSet[j];
		}
		DataSet[j + 1] = key;
		temp = j + 1;
	}


	for (int i = 0; i < arraySize; i++)
	{
		printf("numbers[%d]: %d\n", i, DataSet[i]);
	}

}

void InsertionSort(int DataSet[], int length)
{
	int i = 0; 
	int j = 0;
	int value = 0;


	for (int i = 1; i < length; ++i)
	{
		if (DataSet[i - 1] <= DataSet[i])
		{
			continue;
		}

		value = DataSet[i];

		for (j = 0; j < i; ++j)
		{
			memmove(&DataSet[j + 1], &DataSet[j], sizeof(DataSet[0] * (i - j)));
			DataSet[i] = value;
			break;
		}
	}
}

