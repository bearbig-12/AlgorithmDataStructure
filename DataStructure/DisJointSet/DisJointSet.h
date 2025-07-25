#ifndef DISJOINTSET_H
#define DISJOINTSET_H

#include <stdio.h>
#include <stdlib.h>

// �и�����(�� ���տ� �������� ���� ����)
typedef struct tageDisjointSet
{
	struct tagDisjointSet* Parent;
	void* mData;

}DisjointSet;

void UnionSet(DisjointSet* set1, DisjointSet* set2);
DisjointSet* FindSet(DisjointSet* set);
DisjointSet* MakeSet(void* newData);
void DestroySet(DisjointSet* set);


#endif
