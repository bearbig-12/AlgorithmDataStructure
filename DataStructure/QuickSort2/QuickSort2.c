#include <stdlib.h> 
#include <stdio.h> 
#include <string.h> 
#include "Score.h"

//  리턴값이 
//  < 0 이면, _elem1이 _elem2보다 작다. 
//  = 0   이면, _elem1이 _elem2와 같다.  
//  > 0 이면, _elem1이 _elem2보다 크다.
int ComparePoint(const void* _elem1, const void* _elem2)
{
    int* elem1 = (int*)_elem1;
    int* elem2 = (int*)_elem2;

    if (*elem1 > *elem2)
        return 1;
    else if (*elem1 < *elem2)
        return -1;
    else
        return 0;
}


int ComparePointF(const void* _elem1, const void* _elem2) {
    float* elem1 = (float*)_elem1;
    float* elem2 = (float*)_elem2;

    if (*elem1 < *elem2) {
        return 1;
    }
    else if (*elem1 > *elem2) {
        return -1;
    }
    else {
        return 0;
    }
}

int ComparePointScore(Score _elem1, Score _elem2) {
    Score elem1 = _elem1;
    Score elem2 = _elem2;

    if (elem1.score > elem2.score) {
        return 1;
    }
    else if (elem1.score < elem2.score) {
        return -1;
    }
    else {
        return 0;
    }
}


int main(void)
{
    //int DataSet[] = { 6, 4, 2, 3, 1, 5 };

    //float DataSetFloat[] = { 11.2f, 8.9f, 5.4f, 3.4f, 9.9f, 1.2f, 7.8f };


   // int Length = sizeof DataSet / sizeof DataSet[0];
    int i = 0;

    //int Lengthf = sizeof DataSetFloat / sizeof(float);

    int arraySize = sizeof DataSet / sizeof DataSet[0];

    //qsort((void*)DataSet, Length, sizeof(int), ComparePoint);


  /*  for (i = 0; i < Length; i++)
    {
        printf("%d ", DataSet[i]);
    }

    printf("\n");




    for (int i = 0; i < Lengthf; i++) {
        printf("%.2f ", DataSetFloat[i]);
    }

    printf("\n");
    qsort((void*)DataSetFloat, Lengthf, sizeof(float), ComparePointF);
    for (int i = 0; i < Lengthf; i++) {
        printf("%.2f ", DataSetFloat[i]);
    }*/


    qsort((void*)DataSet, arraySize, sizeof(DataSet[0]), ComparePointScore);

    for (int i = 0; i < 10; ++i)
    {
        printf("Number: %d, Score: %3f\n", DataSet[i].number, DataSet[i].score);

    }


    for (int i = arraySize - 10; i < arraySize; ++i)
    {
        printf("Number: %d, Score: %3f\n", DataSet[i].number, DataSet[i].score);
    }

    return 0;
}
