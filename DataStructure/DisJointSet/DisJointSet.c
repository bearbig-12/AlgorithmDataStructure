#include "DisJointSet.h"

void UnionSet(DisjointSet* set1, DisjointSet* set2)
{
	set2 = FindSet(set2);
	set2->Parent = set1;
}

DisjointSet* FindSet(DisjointSet* set)
{
	while (set->Parent != NULL)
	{
		set = set->Parent;
	}

	return set;
}

DisjointSet* MakeSet(void* newData)
{
	DisjointSet* NewNode = (DisjointSet*)malloc(sizeof(DisjointSet));
	NewNode->mData = newData;
	NewNode->Parent = NULL;

	return NewNode;
}

void DestroySet(DisjointSet* set)
{
	free(set);
}
