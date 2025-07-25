#include <stdio.h>
#include "DisjointSet.h"

int main(void)
{
	int a = 1, b = 2, c = 3, d = 4;
	DisjointSet* Set1 = MakeSet(&a);
	DisjointSet* Set2 = MakeSet(&b);
	DisjointSet* Set3 = MakeSet(&c);
	DisjointSet* Set4 = MakeSet(&d);

	printf("Set1 == Set2 : %d \n", FindSet(Set1) == FindSet(Set2));

	UnionSet(Set1, Set3);
	printf("Set1 == Set3 : %d \n", FindSet(Set1) == FindSet(Set3));

	UnionSet(Set3, Set4);
	printf("Set3 == Set4 : %d \n", FindSet(Set3) == FindSet(Set4));

	return 0;
}
