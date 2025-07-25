#ifndef DISJOINTSET_H
#define DISJOINTSET_H

#include <stdio.h>
#include <stdlib.h>

// 분리집합(두 집합에 교집합이 없는 집합)
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
