#include "CircularQueue.h"

int main(void)
{
    int i;
    CircularQueue* Queue;

    CreateQueue(&Queue, 10);

    EnQueue(Queue, 1);
    EnQueue(Queue, 2);
    EnQueue(Queue, 3);
    EnQueue(Queue, 4);

    for (i = 0; i < 3; i++)
    {
        printf("Dequeue: %d, ", DeQueue(Queue));
        printf("Front:%d, Rear:%d\n", Queue->mFront, Queue->mRear);
    }

    i = 100;
    while (IsFull(Queue) == 0)
    {
        EnQueue(Queue, i++);
    }

    printf("Capacity: %d, Size: %d\n\n",
        Queue->mCapacity, GetSize(Queue));

    while (IsEmpty(Queue) == 0)
    {
        printf("Dequeue: %d, ", DeQueue(Queue));
        printf("Front:%d, Rear:%d\n", Queue->mFront, Queue->mRear);
    }

    DestroyQueue(Queue);

    return 0;
}
