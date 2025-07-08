#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <stdio.h>
#include <stdlib.h>

#define NAME_MAX_LEN 100


typedef struct Node
{
	char name[NAME_MAX_LEN];
	int Hp;
	struct Node* pNext;

} Node;

//typedef struct tagNode
//{
//    ElementType Data;
//    struct tagNode* NextNode;
//} Node;

typedef struct LinkedList
{
	Node* pHead;
	Node* pTail;
} LinkedList;




// 함수 원형 선언 
Node* CreateNode(LinkedList* list, const char* name, int hp);
void  PrintNode(const LinkedList* list);
void  DestroyList(LinkedList* list);
void  Insert(LinkedList* list, Node* target, const char* name, int hp);
void  RemoveNode(LinkedList* list, Node* target);
Node* FindNode(LinkedList* list, const char* name);
int GetNodeCount(LinkedList* list);

#endif
