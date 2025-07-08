#include "LinkedListC.h"
#include <stdio.h>

// 노드 추가시 자동으로 Apppend
Node* CreateNode(LinkedList* list, const char* name, int hp)
{
    Node* NewNode = (Node*)malloc(sizeof(Node));
    strcpy_s(NewNode->name, NAME_MAX_LEN, name);
    NewNode->Hp = hp; 
    NewNode->pNext = NULL;

    if (list->pTail == NULL)    // 리스트가 비었을 경우 head = tail
    {
        list->pHead = NewNode;
        list->pTail = NewNode;
    }
    else
    {
        list->pTail->pNext = NewNode;
        list->pTail = NewNode;
    }
    return NewNode;
}

void PrintNode(const LinkedList* list)
{
    Node* element = list->pHead;

    if (element == NULL)
    {
        printf("The list is empty");
    }

    while (element != NULL)
    {
        printf("%s : %d\n", element->name, element->Hp);
        element = element->pNext;
    }
}


//  노드 소멸 
void DestroyList(LinkedList* list)
{
    Node* element = list->pHead;

    while (element != NULL)
    {
        Node* mNext = element->pNext;
        free(element);

        element = mNext;
    }
    list->pHead = NULL;
    list->pTail = NULL;
}


//  노드 삽입 
void  Insert(LinkedList* list, Node* target, char* name, int hp)
{
    Node* element = list->pHead;
    Node* previous = NULL;

    
    while (element != NULL)
    {
        if (element == target)
        {
            break;
        }
        previous = element;
        element = element->pNext;
    }

    Node* NewNode = (Node*)malloc(sizeof(Node));
    strcpy_s(NewNode->name, NAME_MAX_LEN, name);
    NewNode->Hp = hp;

    if (previous == NULL)
    {
        // Head 앞에 새 노드 삽입
        previous = NewNode;
        list->pHead = previous;

        NewNode->pNext = element;
    }
    else
    {
        // 중간 삽입
        previous->pNext = NewNode;
        NewNode->pNext = element;
    }

}


//  노드 제거 
void RemoveNode(LinkedList* list, Node* target)
{
    Node* elemet = list->pHead;
    Node* previous = NULL;

    while (elemet != NULL)
    {
        if (elemet == target)
        {
            break;
        }
        previous = elemet;
        elemet = elemet->pNext;
    }
    // 못 찾음
    if (elemet == NULL)
    {
        return;
    }
    // head
    else if (elemet == list->pHead)
    {
        list->pHead = elemet->pNext;
        // 만약에 타겟이 head이자 tail 이면
        if (elemet == list->pTail)
        {
            list->pHead == NULL;
            list->pTail == NULL;
        }
    }
    // tail
    else if (elemet == list->pTail)
    {
        list->pTail = previous;
        previous->pNext = NULL;
    }
    // 중간
    else
    {
        previous->pNext = elemet->pNext;
    }
    free(elemet);
}

//  노드 탐색 
Node* FindNode(LinkedList* list, const char* name)
{
    Node* element = list->pHead;
    while (element != NULL)
    {
        if (strcmp(element->name, name) == 0)
        {
            return element;
        }
        element = element->pNext;
    }
    return NULL;

}

//  노드 수 세기 
int GetNodeCount(LinkedList* list)
{
    int count = 0;
    Node* element = list->pHead;
    while (element != NULL)
    {
        element = element->pNext;
        count++;
    }
    return count;
}
