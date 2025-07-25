#include <stdio.h>
#include <stdbool.h>


int main()
{
	int DataSet[] = { 1,2,3,4,6, 5 };
	int arraySize = sizeof(DataSet) / sizeof(int);
	int temp;

	for (int i = 0; i < arraySize; ++i)
	{
		bool isSorted = true;

		for (int j = 0; j < arraySize - 1 - i; ++j)
		{
			if (DataSet[j] > DataSet[j + 1])
			{
				temp = DataSet[j];
				DataSet[j] = DataSet[j+1];
				DataSet[j + 1] = temp;
				bool isSorted = false;

			}
		}
		if (isSorted == true)
		{
			break;
		}
	}


	for (int i = 0; i < arraySize; i++) 
	{
		printf("numbers[%d]: %d\n", i, DataSet[i]);
	}

}

