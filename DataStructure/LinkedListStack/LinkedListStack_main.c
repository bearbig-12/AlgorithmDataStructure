#include "LinkedListStack.h"
#include <time.h>

int main()
{
    clock_t start, end;
    float processTime;

    int i = 0;
    int Count = 0;
    Node* Popped;

    LinkedListStack* Stack;

    CreateStack(&Stack);

    start = clock(); // 시작시간

    for (int i = 0; i < 10000; i++) {
        Push(Stack, CreateNode("abc"));
        Push(Stack, CreateNode("def"));
        Push(Stack, CreateNode("efg"));
        Push(Stack, CreateNode("hij"));
        Push(Stack, CreateNode("klm"));
    }

    Count = GetSize(Stack);
    printf("Size: %d, Top: %s\n\n",
        Count, FindTop(Stack)->mData);


    for (i = 0; i < Count; i++)
    {
        if (IsEmpty(Stack))
            break;

        Popped = Pop(Stack);

        printf("Popped: %s, ", Popped->mData);

        DestroyNode(Popped);

        if (!IsEmpty(Stack))
        {
            printf("Current Top: %s\n", FindTop(Stack)->mData);
        }
        else
        {
            printf("Stack Is Empty.\n");
        }
    }

    DestroyStack(Stack);

    end = clock();

    processTime = (float)(end - start) / CLOCKS_PER_SEC;

    printf("처리시간: %lf\n", processTime);

    return 0;
}