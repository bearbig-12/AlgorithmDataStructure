#include "DoubleLinkedList.h"


// 문제 1
/*
	insert new head함수 만들고 값 6000 대입하여 새 노드 만들기
*/
// 문제 2
/*
	GetNodeCount은 헤드에서 테일까지 계속 돈다 이걸 효율적으로 
*/


int main()
{
	int i = 0;
	int count = 0;
	Node* mList = NULL;
	Node* mNewNode = NULL;
	Node* mCurrent = NULL;

	for (i = 0; i < 5; i++)
	{
		mNewNode = CreateNode(i);
		AppendNode(&mList, mNewNode);
	}

	//  리스트 출력 
	count = GetNodeCount();
	for (i = 0; i < count; ++i)
	{
		mCurrent = GetNodeAt(mList, i);
		printf("List[%d] : %d\n", i, mCurrent->Data);
	}

	//  리스트의 세번째 칸 뒤에 노드 삽입 
	printf("\nInserting 3000 After [2]...\n\n");

	mCurrent = GetNodeAt(mList, 2);
	mNewNode = CreateNode(3000);
	InsertAfter(mCurrent, mNewNode);

	//  리스트 출력 
	count = GetNodeCount(mList);
	for (i = 0; i < count; ++i)
	{
		mCurrent = GetNodeAt(mList, i);
		printf("List[%d] : %d\n", i, mCurrent->Data);
	}

	//  리스트의 새로운 헤드 삽입 
	printf("\nInserting 6000 Before current Head(0)...\n\n");

	mCurrent = GetNodeAt(&mList, 0);
	mNewNode = CreateNode(6000);
	InsertNewHead(mCurrent, mNewNode);

	//  리스트 출력 
	count = GetNodeCount(mList);
	for (i = 0; i < count; ++i)
	{
		mCurrent = GetNodeAt(mList, i);
		printf("List[%d] : %d\n", i, mCurrent->Data);
	}


	//  모든 노드를 메모리에서 제거     
	printf("\nDestroying List...\n");

	count = GetNodeCount(mList);

	for (i = 0; i < count; i++)
	{
		mCurrent = GetNodeAt(mList, 0);

		if (mCurrent != NULL)
		{
			RemoveNode(&mList, mCurrent);
			DestroyNode(mCurrent);
		}
	}

	return 0;

}

