#include "Heap.h"

int main(void)
{
    Heap* H = Create(3);
    HeapNode MinNode;

    Insert(H, 12);
    Insert(H, 87);
    Insert(H, 111);
    Insert(H, 34);
    Insert(H, 16);
    Insert(H, 75);
    PrintNodes(H);

    DeleteMin(H, &MinNode);
    PrintNodes(H);

    DeleteMin(H, &MinNode);
    PrintNodes(H);

    DeleteMin(H, &MinNode);
    PrintNodes(H);

    DeleteMin(H, &MinNode);
    PrintNodes(H);

    DeleteMin(H, &MinNode);
    PrintNodes(H);

    DeleteMin(H, &MinNode);
    PrintNodes(H);

    return 0;
}
