#include <stdio.h>
#include "LinkedListC.h"


int main(void)
{
	int Count = 0;
	LinkedList* list = (LinkedList*)malloc(sizeof(LinkedList));
	list->pHead = NULL;
	list->pTail = NULL;


	Node* Current = NULL;

 	CreateNode(list, "Bear", 100);
	CreateNode(list, "Dog", 50);
	CreateNode(list, "Chicken", 10);
	CreateNode(list, "Slime", 200);

	
	Current = FindNode(list, "Bear");
	Insert(list, Current, "Zombie", 200);


	PrintNode(list);

	printf("\n");


	Count = GetNodeCount(list);
	printf("Node Count : %d\n", Count);

	Current = FindNode(list, "Slime");
	RemoveNode(list, Current);
	PrintNode(list);



	Count = GetNodeCount(list);
	printf("Node Count : %d\n", Count);

	printf("\n");

	DestroyList(list);
	Count = GetNodeCount(list);
	printf("Node Count : %d\n", Count);
	PrintNode(list);





}
