#include <stdio.h>
#include <stdbool.h>
#include "Score.h"
#include <time.h>

int main()
{
	//int DataSet[] = { 1,2,3,4,6, 5 };
	//int arraySize = sizeof(DataSet) / sizeof(int);
	int arraySize = sizeof(DataSet) / sizeof(DataSet[0]);
	Score temp;

	double startTime = 0.0, endTime = 0.0;


	startTime = (double)clock() / CLOCKS_PER_SEC;

	/*for (int i = 0; i < arraySize; ++i)
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
	}*/

	for (int i = 0; i < arraySize; ++i)
	{
		bool isSorted = true;

		for (int j = 0; j < arraySize - 1 - i; ++j)
		{
			if (DataSet[j].score > DataSet[j + 1].score)
			{
				temp = DataSet[j + 1];
				DataSet[j + 1] = DataSet[j];
				DataSet[j] = temp;
				isSorted = false;

			}
		}
		if (isSorted == true)
		{
			break;
		}
	}

	endTime = (double)clock() / CLOCKS_PER_SEC;


	for (int i = 0; i < 10; ++i) 
	{
		printf("Number: %d, Score: %3f\n", DataSet[i].number, DataSet[i].score);

	}


	for (int i = arraySize - 10; i < arraySize; ++i) 
	{
		printf("Number: %d, Score: %3f\n", DataSet[i].number, DataSet[i].score);
	}

	printf("\n");
	printf("버블소트 3만개 데이타 소팅 시간: %lf sec\n", endTime - startTime);

}

