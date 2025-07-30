#pragma once
#ifndef ARRAYSTACK_H
#define ARRAYSTACK_H

#include <Stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef int ElementType;

typedef struct Node
{
	ElementType mData;
}Node;

typedef struct ArrayStack
{
	int mCapacity;
	int mTop;
	Node* Nodes;
}ArrayStack;

void CreateStack(ArrayStack** stack, int capacity);
void DestroyStack(ArrayStack* stack);
void Push(ArrayStack* stack, ElementType data);
ElementType Pop(ArrayStack* stack);
ElementType Top(ArrayStack* stack);
int GetSize(ArrayStack* stack);
int IsEmpty(ArrayStack* stack);
bool IsFull(ArrayStack* stack);
void Resize(ArrayStack* stack);




#endif // !ARRAYSTACK_H
