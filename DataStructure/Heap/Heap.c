#include "Heap.h"

Heap* Create(int init)
{
	Heap* NewHeap = (Heap*)malloc(sizeof(Heap));
	NewHeap->Capacity = init;
	NewHeap->UsedSize = 0;
	NewHeap->Nodes = (HeapNode*)malloc(sizeof(HeapNode) * NewHeap->Capacity);

	printf("size : %d\n", sizeof(HeapNode));

	return NewHeap;
}

void Destory(Heap* H)
{
	free(H->Nodes);
	free(H);
}

void Insert(Heap* H, ElementType NewData)
{
	int CurrentPosition = H->UsedSize;
	int ParentPosition = GetParent(CurrentPosition);

	if (H->UsedSize == H->Capacity)
	{
		H->Capacity *= 2;
		H->Nodes = (HeapNode*)realloc(H->Nodes, sizeof(HeapNode) * H->Capacity);
	}

	H->Nodes[CurrentPosition].Data = NewData;

	// 후속 처리
	while (CurrentPosition > 0 && H->Nodes[CurrentPosition].Data < H->Nodes[ParentPosition].Data)
	{
		SwapNodes(H, CurrentPosition, ParentPosition);

		CurrentPosition = ParentPosition;
		ParentPosition = GetParent(CurrentPosition);
	}

	H->UsedSize++;
}

void  SwapNodes(Heap* H, int Index1, int Index2)
{
	int CopySize = sizeof(HeapNode);
	HeapNode* Temp = (HeapNode*)malloc(CopySize);

	memcpy(Temp, &H->Nodes[Index1], CopySize);
	memcpy(&H->Nodes[Index1], &H->Nodes[Index2], CopySize);
	memcpy(&H->Nodes[Index2], Temp, CopySize);

	free(Temp);
}

void DeleteMin(Heap* H, HeapNode* Root)
{
	int ParentPosition = 0;
	int LeftPosition = 0;
	int RightPosition = 0;

	memcpy(Root, &H->Nodes[0], sizeof(HeapNode));
	memset(&H->Nodes[0], 0, sizeof(HeapNode));

	H->UsedSize--;
	SwapNodes(H, 0, H->UsedSize);

	LeftPosition = GetLeftChild(0);
	RightPosition = LeftPosition + 1;

	while(1)
	{
		int SelectedChild = 0;

		if (LeftPosition >= H->UsedSize)
		{
			break;
		}
		if (RightPosition >= H->UsedSize)
		{
			SelectedChild = LeftPosition;
		}
		else {
			if (H->Nodes[LeftPosition].Data > H->Nodes[RightPosition].Data)
				SelectedChild = RightPosition;
			else
				SelectedChild = LeftPosition;
		}

		if (H->Nodes[SelectedChild].Data < H->Nodes[ParentPosition].Data)
		{
			SwapNodes(H, ParentPosition, SelectedChild);
			ParentPosition = SelectedChild;
		}
		else
			break;

		LeftPosition = GetLeftChild(ParentPosition);
		RightPosition = LeftPosition + 1;
	}

	if (H->UsedSize < (H->Capacity / 2))
	{
		H->Capacity /= 2;
		H->Nodes =
			(HeapNode*)realloc(H->Nodes, sizeof(HeapNode) * H->Capacity);
	}
}

int GetParent(int Index)
{
	return (int)((Index - 1) / 2);
}

int GetLeftChild(int Index)
{
	return (2 * Index) + 1;
}

void PrintNodes(Heap* H)
{

	int i = 0;
	for (i = 0; i < H->UsedSize; i++)
	{
		printf("%d ", H->Nodes[i].Data);
	}
	printf("\n");
}
