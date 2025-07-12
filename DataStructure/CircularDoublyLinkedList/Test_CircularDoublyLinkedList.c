#include "CircularDoublyLinkedList.h"

int main()
{
	int i = 0;
	int count = 0;
	Node* mList = NULL;
	Node* newNode = NULL;
	Node* mCurrent = NULL;

	//  ��� 5�� �߰� 
	for (i = 0; i < 5; i++)
	{
		newNode = CreateNode(i);
		AppendNode(&mList, newNode);
	}


    //  ����Ʈ ��� 
    count = GetNodeCount(mList);
    for (i = 0; i < count; i++)
    {
        mCurrent = GetNodeAt(mList, i);
        printf("List[%d] : %d\n", i, mCurrent->mData);
    }

    //  ����Ʈ�� ����° ĭ �ڿ� ��� ���� 
    printf("\nInserting 3000 After [2]...\n\n");

    mCurrent = GetNodeAt(mList, 2);
    newNode = CreateNode(3000);
    InsertAfter(mCurrent, newNode);

    printf("\nRemoving Node at 2...\n");
    mCurrent = GetNodeAt(mList, 2);
    RemoveNode(&mList, mCurrent);
    DestroyNode(mCurrent);

    //  ����Ʈ ���  
    //  (��� ���� 2�踸ŭ ������ ���� ȯ������ Ȯ���Ѵ�.) 
    count = GetNodeCount(mList);
    for (i = 0; i < count * 2; i++)
    {
        if (i == 0)
            mCurrent = mList;
        else
            mCurrent = mCurrent->mNextNode;

        printf("List[%d] : %d\n", i, mCurrent->mData);
    }

    //  ��� ��带 �޸𸮿��� ����     
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