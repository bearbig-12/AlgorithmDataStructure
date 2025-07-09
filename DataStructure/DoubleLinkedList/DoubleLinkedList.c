#include "DoubleLinkedList.h"

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

    }
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
int GetNodeCount(Node* head)
{
    unsigned int  count = 0;
    Node* current = head;

    while (current != NULL)
    {
        current = current->nextNode;
        count++;
    }

    return count;
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
