#include <stdio.h> 
#include <string.h> 
#include "Score.h"


//void InsertionSort(int DataSet[], int Length)
//{
//    int i = 0;
//    int j = 0;
//    int value = 0;
//
//    for (i = 1; i < Length; i++)
//    {
//        if (DataSet[i - 1] <= DataSet[i])
//            continue;
//
//        value = DataSet[i];
//
//        for (j = 0; j < i; j++)
//        {
//            if (DataSet[j] > value)
//            {
//                memmove(&DataSet[j + 1], &DataSet[j], sizeof(DataSet[0]) * (i - j));
//                DataSet[j] = value;
//                break;
//            }
//        }
//    }
//}


void InsertionSort(Score DataSet[], int Length)
{
    int i = 0;
    int j = 0;
    Score value;

    for (i = 1; i < Length; i++)
    {
        if (DataSet[i - 1].score <= DataSet[i].score)
            continue;

        value = DataSet[i];

        for (j = 0; j < i; j++)
        {
            if (DataSet[j].score > value.score)
            {
                memmove(&DataSet[j + 1], &DataSet[j], sizeof(DataSet[0]) * (i - j));
                DataSet[j] = value;
                break;
            }
        }
    }
}

int main(void)
{
    //int DataSet[] = { 6, 4, 2, 3, 1, 5 };
    int arraySize = sizeof DataSet / sizeof DataSet[0];
    int i = 0;

    InsertionSort(DataSet, arraySize);

    //for (i = 0; i < Length; i++)
    //{
    //    printf("%d ", DataSet[i]);
    //}


    for (int i = 0; i < 10; ++i)
    {
        printf("Number: %d, Score: %3f\n", DataSet[i].number, DataSet[i].score);

    }


    for (int i = arraySize - 10; i < arraySize; ++i)
    {
        printf("Number: %d, Score: %3f\n", DataSet[i].number, DataSet[i].score);
    }

    printf("\n");

    return 0;
}
