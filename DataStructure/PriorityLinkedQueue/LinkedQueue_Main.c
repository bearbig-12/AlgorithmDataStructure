
#define _CRT_SECURE_NO_WARNINGS
#include "LinkedQueue.h"

int main(void)
{
    Node* Popped;
    LinkedQueue* Queue;

    CreateQueue(&Queue);

    char Data[100]; // 문자열 입력 공간
    int priority = 0;

    while (1)
    {
        printf("우선 순위 큐에 저장할 데이터를 입력하세요 : ");
        scanf("%d, %s", &priority, Data);

        if (priority <= -1) // 입력 중단
        {
            break;
        }
        // 입력받은 데이터를 큐에 저장한다.
        Enqueue(Queue, CreateNode(priority, Data));

        // 큐에 입력된 데이터를 출력
        Node* Current = Queue->mFront;  //헤드 노드의 주소값을 current에 저장

        while (Current != NULL)
        {
            printf("[Priority : %d, Data : %s]\n", Current->priority, Current->mData);

            Current = Current->mNextNode;
        }
    }

   
    printf("Queue Size : %d\n", Queue->mCount);

    while (IsEmpty(Queue) == 0)
    {
        Popped = Dequeue(Queue);

        printf("Dequeue: %s \n", Popped->mData);

        DestroyNode(Popped);
    }

    DestroyQueue(Queue);

    return 0;
}
