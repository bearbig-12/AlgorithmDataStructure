#include "LinkedList2.h"

//  ��� ���� 
Node* CreateNode(ElementType NewData)
{
    Node* NewNode = (Node*)malloc(sizeof(Node));

    NewNode->Data = NewData;  //  �����͸� �����Ѵ�. 
    NewNode->NextNode = NULL; //  ���� ��忡 ���� �����ʹ� NULL�� �ʱ�ȭ �Ѵ�. 

    return NewNode;//  ����� �ּҸ� ��ȯ�Ѵ�. 
}

//  ��� �Ҹ� 
void DestroyNode(Node* Node)
{
    free(Node);
}

//  ��� �߰� 
void AppendNode(Node** Head, Node* NewNode)
{
    //  ��� ��尡 NULL�̶�� ���ο� ��尡 Head 
    if ((*Head) == NULL)
    {
        *Head = NewNode;
    }
    else
    {
        //  ������ ã�� NewNode�� �����Ѵ�. 
        Node* Tail = (*Head);
        while (Tail->NextNode != NULL)
        {
            Tail = Tail->NextNode;
        }

        Tail->NextNode = NewNode;
    }
}

//  ��� ���� 
void InsertAfter(Node* Current, Node* NewNode)
{
    NewNode->NextNode = Current->NextNode;
    Current->NextNode = NewNode;
}

void InsertBefore(Node* Current, Node* NewNode, Node** Head)
{
    Node* previous = (*Head);

    if ((*Head) == NULL)
    {
        (*Head) = NewNode;
    }
    if (Current != (*Head))
    {
        while (previous->NextNode != Current)
        {
            previous = previous->NextNode;
        }
        previous->NextNode = NewNode;
        NewNode->NextNode = Current;
    }
    else
    {
        NewNode->NextNode = (*Head);
        (*Head) = NewNode;
    }




}

void  InsertNewHead(Node** Head, Node* NewHead)
{
    if (Head == NULL)
    {
        (*Head) = NewHead;
    }
    else
    {
        NewHead->NextNode = (*Head);
        (*Head) = NewHead;
    }
}

//  ��� ���� 
void RemoveNode(Node** Head, Node* Remove)
{
    if (*Head == Remove)
    {
        *Head = Remove->NextNode;
    }
    else
    {
        Node* Current = *Head;
        while (Current != NULL && Current->NextNode != Remove)
        {
            Current = Current->NextNode;
        }

        if (Current != NULL)
            Current->NextNode = Remove->NextNode;
    }
}

//  ��� Ž�� 
Node* GetNodeAt(Node* Head, int Location)
{
    Node* Current = Head;

    while (Current != NULL && (--Location) >= 0)
    {
        Current = Current->NextNode;
    }

    return Current;
}

//  ��� �� ���� 
int GetNodeCount(Node* Head)
{
    int   Count = 0;
    Node* Current = Head;

    while (Current != NULL)
    {
        Current = Current->NextNode;
        Count++;
    }

    return Count;
}