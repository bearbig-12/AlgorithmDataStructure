#ifndef HEAP_H
#define HEAP_H

#include <stdio.h>
#include <memory.h>
#include <stdlib.h>

typedef int ElementType;

typedef struct tagHeapNode {
	ElementType Data;
}HeapNode;

typedef struct tagHeap {
	HeapNode* Nodes;
	int Capacity;
	int UsedSize;
}Heap;

Heap* Create(int init);
void Destory(Heap* H);
void Insert(Heap* H, ElementType NewData);
void DeleteMin(Heap* H, HeapNode* Root);
int GetParent(int Index);
int GetLeftChild(int Index);
void SwapNodes(Heap* H, int Index1, int Indext2);
void PrintNodes(Heap* H);


#endif
