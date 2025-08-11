
#define _CRT_SECURE_NO_WARNINGS
#include "LinkedQueue.h"

int main(void)
{
    enum Option
    {
        NodeEnqueue = 1,
        NodeDequeue = 2,
        Stop = 0
    };
    Node* Popped;
    LinkedQueue* Queue;

    CreateQueue(&Queue);

    char Data[100]; // 문자열 입력 공간
    int priority = 0;
    int Option = 0;
    int target;

    while (1)
    {
        printf("옵션을 선택하여 주세요 : ");
        printf("1 : Enqueue, 2 : Dequeue, 3 : Stop : \n");
        scanf("%d", &Option);
        switch (Option)
        {
        case NodeEnqueue:
        {
            printf("우선 순위 큐에 저장할 데이터를 입력하세요 : ");
            scanf("%d %s", &priority, Data);

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
            break;
        }
        case NodeDequeue:
        {
            printf("우선 순위 큐에서 뺄 노드 값을 입력하세요 : ");
            scanf("%d", &target);
            Node* Popped = Dequeue2(Queue, target);
            if (Popped == NULL)
            {
                printf("해당 노드 값은 큐에 존재하지 않습니다 \n");
                break;

            }
            else
            {
                printf("Dequeue: %d \n", Popped->priority);
                DestroyNode(Popped);
            }
       
            Node* Current = Queue->mFront;  //헤드 노드의 주소값을 current에 저장

            while (Current != NULL)
            {
                printf("[Priority : %d, Data : %s]\n", Current->priority, Current->mData);

                Current = Current->mNextNode;
            }
            break;
        }
        case Stop:
        {
            break;
        }
        default:
            return;
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
