#include "LinkedList2.h"

int main(void)
{
    int   i = 0;
    int   Count = 0;
    Node* List = NULL;
    Node* Current = NULL;
    Node* NewNode = NULL;

    //  ��� 5�� �߰� 
    for (i = 0; i < 5; i++)
    {
        NewNode = CreateNode(i);
        AppendNode(&List, NewNode);
    }

    NewNode = CreateNode(-1);
    InsertNewHead(&List, NewNode);

    NewNode = CreateNode(-2);
    InsertNewHead(&List, NewNode);

    //  ����Ʈ ��� 
    Count = GetNodeCount(List);
    for (i = 0; i < Count; i++)
    {
        Current = GetNodeAt(List, i);
        printf("List[%d] : %d\n", i, Current->Data);
    }

    //  ����Ʈ�� ����° ��� �ڿ� �� ��� ���� 
    printf("\nInserting 3000 After [2]...\n\n");

    Current = GetNodeAt(List, 2);
    NewNode = CreateNode(3000);

    InsertAfter(Current, NewNode);

    //  ����Ʈ ��� 
    Count = GetNodeCount(List);
    for (i = 0; i < Count; i++)
    {
        Current = GetNodeAt(List, i);
        printf("List[%d] : %d\n", i, Current->Data);
    }


    //  ����Ʈ�� ����° ��� �ڿ� �� ��� ���� 
    printf("\nInserting 6000 Before [0]...\n\n");

    Current = GetNodeAt(List, 1);
    NewNode = CreateNode(5000);
    InsertBefore(Current, NewNode, &List);

    //  ����Ʈ ��� 
    Count = GetNodeCount(List);
    for (i = 0; i < Count; i++)
    {
        Current = GetNodeAt(List, i);
        printf("List[%d] : %d\n", i, Current->Data);
    }







    //  ��� ��带 �޸𸮿��� ����     
    printf("\nDestroying List...\n");

    for (i = 0; i < Count; i++)
    {
        Current = GetNodeAt(List, 0);

        if (Current != NULL)
        {
            RemoveNode(&List, Current);
            DestroyNode(Current);
        }
    }

    return 0;
}