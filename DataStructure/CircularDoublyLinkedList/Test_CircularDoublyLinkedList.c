#include "CircularDoublyLinkedList.h"

int main()
{
	int i = 0;
	int count = 0;
	Node* mList = NULL;
	Node* newNode = NULL;
	Node* mCurrent = NULL;

	//  노드 5개 추가 
	for (i = 0; i < 5; i++)
	{
		newNode = CreateNode(i);
		AppendNode(&mList, newNode);
	}


    //  리스트 출력 
    count = GetNodeCount(mList);
    for (i = 0; i < count; i++)
    {
        mCurrent = GetNodeAt(mList, i);
        printf("List[%d] : %d\n", i, mCurrent->mData);
    }

    //  리스트의 세번째 칸 뒤에 노드 삽입 
    printf("\nInserting 3000 After [2]...\n\n");

    mCurrent = GetNodeAt(mList, 2);
    newNode = CreateNode(3000);
    InsertAfter(mCurrent, newNode);

    printf("\nRemoving Node at 2...\n");
    mCurrent = GetNodeAt(mList, 2);
    RemoveNode(&mList, mCurrent);
    DestroyNode(mCurrent);

    //  리스트 출력  
    //  (노드 수의 2배만큼 루프를 돌며 환형임을 확인한다.) 
    count = GetNodeCount(mList);
    for (i = 0; i < count * 2; i++)
    {
        if (i == 0)
            mCurrent = mList;
        else
            mCurrent = mCurrent->mNextNode;

        printf("List[%d] : %d\n", i, mCurrent->mData);
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