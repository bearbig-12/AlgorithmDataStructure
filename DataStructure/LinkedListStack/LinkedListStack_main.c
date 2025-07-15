#include "LinkedListStack.h"


int main()
{
    int i = 0;
    int Count = 0;
    Node* Popped;

    LinkedListStack* Stack;

    CreateStack(&Stack);

    Push(Stack, CreateNode("abc"));
    Push(Stack, CreateNode("def"));
    Push(Stack, CreateNode("efg"));
    Push(Stack, CreateNode("hij"));
    Push(Stack, CreateNode("klm"));


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

    return 0;
}