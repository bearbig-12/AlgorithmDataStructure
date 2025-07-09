#include "DoubleLinkedList.h"


int main()
{
	int i = 0;
	int mCount = 0;
	Node* mList = NULL;
	Node* mNewNode = NULL;
	Node* mCurrent = NULL;

	for (i = 0; i < 5; i++)
	{
		mNewNode = CreateNode(i);
		AppendNode(&mList, mNewNode);
	}

	//  리스트 출력 
	mCount = GetNodeCount(mList);
	for (i = 0; i < 5; ++i)
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
	mCount = GetNodeCount(mList);
	for (i = 0; i < 5; ++i)
	{
		mCurrent = GetNodeAt(mList, i);
		printf("List[%d] : %d\n", i, mCurrent->Data);
	}


	//  모든 노드를 메모리에서 제거     
	printf("\nDestroying List...\n");

	mCount = GetNodeCount(mList);

	for (i = 0; i < mCount; i++)
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

