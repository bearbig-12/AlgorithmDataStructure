#include "DoubleLinkedList.h"

static int mCount = 0;

//  노드 생성 
Node* CreateNode(ElementType newData)
{
    Node* newNode = (Node*)malloc(sizeof(Node));

    newNode->Data = newData;
    newNode->prevNode = NULL;
    newNode->nextNode = NULL;
    return newNode;
}

//  노드 소멸 
void DestroyNode(Node* node)
{
    free(node);
}

//  노드 추가 
void AppendNode(Node** head, Node* newNode)
{
    //  헤드 노드가 NULL이라면 새로운 노드가 Head 
    if ((*head) == NULL)
    {
        *head = newNode;

    }
    else
    {
        Node* tail = (*head);
        while (tail->nextNode != NULL)
        {
            tail = tail->nextNode;
        }
        tail->nextNode = newNode;
        newNode->prevNode = tail;


    }
    mCount++;

}

//  노드 삽입 
void InsertAfter(Node* current, Node* newNode)
{
    newNode->nextNode = current->nextNode;
    newNode->prevNode = current;

    // 중간 삽입
    if (current->nextNode != NULL)
    {
        current->nextNode->prevNode = newNode;
        current->nextNode = newNode;

    }
    mCount++;

}

//  노드 제거 
void RemoveNode(Node** head, Node* remove)
{
    if (*head == remove)
    {
        *head = remove->nextNode;
        if ((*head) != NULL)
        {
            (*head)->prevNode = NULL;
        }
        remove->nextNode = NULL;
        remove->prevNode = NULL;
        mCount--;

    }
    else
    {
        Node* temp = remove;
        if (remove->prevNode != NULL)
        {
            remove->prevNode->nextNode = temp->nextNode;
        }
        if (remove->nextNode != NULL)
        {
            remove->nextNode->prevNode = temp->prevNode;
        }

        remove->prevNode = NULL;
        remove->nextNode = NULL;
        mCount--;

    }
    mCount--;

}

//  노드 탐색 
Node* GetNodeAt(Node* head, int location)
{
    Node* current = head;

    while (current != NULL && (--location) >= 0)
    {
        current = current->nextNode;
    }

    return current;
}

//  노드 개수 세기 
int GetNodeCount()
{
    return mCount;
}

// 노드 출력
void PrintNode(Node* _node)
{
    if (_node->prevNode == NULL)
        printf("Prev: NULL");
    else
        printf("Prev: %d", _node->prevNode->Data);

    printf(" Current: %d ", _node->Data);

    if (_node->nextNode == NULL)
        printf("Next: NULL\n");
    else
        printf("Next: %d\n", _node->nextNode->Data);
}

void InsertNewHead(Node** head, Node* newNode)
{
    if ((*head) == NULL)
    {
        (*head) = newNode;

        newNode->nextNode = NULL;
        newNode->prevNode = NULL;
    }
    else
    {
        newNode->nextNode = (*head);
        (*head)->prevNode = newNode;
        (*head) = newNode;
        newNode->prevNode = NULL;

    }
    mCount++;

}

/*
void InsertNewHead2(Node** Head, Node* NewHead) {

    // 경우 1: 헤드노드가 없는 경우
    if ((*Head) == NULL) {
        *Head = NewHead;

        NewHead->nextNode = NULL;
        NewHead->prevNode = NULL;
    }
    else { // 경우 2. 헤드노드가 있는 경우
        NewHead->nextNode = (*Head);   // NewHead의 다음노드로 현재의 헤드노드를 연결한다.
        (*Head)->prevNode = NewHead;   // 현재의 헤드노드의 이전노드로 NewHead의 주소값을 연결한다.

        (*Head) = NewHead; // NewHead를 헤드 노드로 만든다.

        NewHead->prevNode = NULL;
    }

    mCount++;
}
*/



void InsertBefore(Node** Head, Node* Current, Node* NewNode) 
{
    if (Current == (*Head)) 
    { // 헤드노드인 경우
        NewNode->nextNode = (*Head);
        (*Head)->prevNode = NewNode;

        (*Head) = NewNode;
    }
    else
    {
        NewNode->prevNode = Current->prevNode;
        NewNode->nextNode = Current;

        NewNode->prevNode->nextNode = NewNode;
        NewNode->nextNode->prevNode = NewNode;
    }
}
