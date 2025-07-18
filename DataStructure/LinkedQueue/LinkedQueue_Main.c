#include "LinkedQueue.h"

int main(void)
{
    Node* Popped;
    LinkedQueue* Queue;

    CreateQueue(&Queue);

    Enqueue(Queue, CreateNode("abc"));
    Enqueue(Queue, CreateNode("def"));
    Enqueue(Queue, CreateNode("efg"));
    Enqueue(Queue, CreateNode("hij"));

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
