#include "CircularDoublyLinkedList.h"

Node* CreateNode(ElementType newData)
{
	Node* newNode = (Node*)malloc(sizeof(Node));
	newNode->mData = newData;
	newNode->mNextNode = NULL;
	newNode->mPreNode = NULL;

	return newNode;
}
void DestroyNode(Node* node)
{
	free(node);
}
void AppendNode(Node** head, Node* newNode)
{
	if ((*head) == NULL)
	{
		*head = newNode;
		(*head)->mNextNode = *head;
		(*head)->mPreNode = *head;
	}
	//  테일과 헤드 사이에 NewNode를 삽입한다. 
	else
	{
		Node* tail = (*head)->mPreNode;

		tail->mNextNode->mPreNode = newNode;
		tail->mNextNode = newNode;
		
		newNode->mNextNode = (*head);
		newNode->mPreNode = tail;
		// 기존의 테일을 새로운 테일의 prev가 가리킴
	}
}
void InsertAfter(Node* current, Node* newNode)
{
	newNode->mNextNode = current->mNextNode;
	newNode->mPreNode = current;

	if (current->mNextNode != NULL)
	{
		current->mNextNode->mPreNode = newNode;
		current->mNextNode = newNode;
	}
}
void RemoveNode(Node** head, Node* remove)
{
	if (*head == remove)
	{
		(*head)->mPreNode->mNextNode = remove->mNextNode;
		(*head)->mNextNode->mPreNode = remove->mPreNode;

		*head = remove->mNextNode;
		
		remove->mNextNode = NULL;
		remove->mPreNode = NULL;
	}
	else
	{
		remove->mNextNode->mPreNode = remove->mPreNode;
		remove->mPreNode->mNextNode = remove->mNextNode;

		remove->mNextNode = NULL;
		remove->mPreNode = NULL;
	}
}
Node* GetNodeAt(Node* head, int location)
{
	Node* Current = head;

	while (Current != NULL && (--location) >= 0)
	{
		Current = Current->mNextNode;
	}

	return Current;
}
int GetNodeCount(Node* head)
{
	unsigned int  Count = 0;
	Node* Current = head;

	while (Current != NULL)
	{
		Current = Current->mNextNode;
		Count++;

		if (Current == head)
			break;
	}

	return Count;
}

void PrintNode(Node* _Node)
{
	if (_Node->mPreNode == NULL)
		printf("Prev: NULL");
	else
		printf("Prev: %d", _Node->mPreNode->mData);

	printf(" Current: %d ", _Node->mData);

	if (_Node->mNextNode == NULL)
		printf("Next: NULL\n");
	else
		printf("Next: %d\n", _Node->mNextNode->mData);
}