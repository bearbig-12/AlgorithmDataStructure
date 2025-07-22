#include "BinaryTree.h"


int main()
{
    SBTNode* A = CreateNode('A');
    SBTNode* B = CreateNode('B');
    SBTNode* C = CreateNode('C');
    SBTNode* D = CreateNode('D');
    SBTNode* E = CreateNode('E');
    SBTNode* F = CreateNode('F');
    SBTNode* G = CreateNode('G');


    //  트리에 노드 추가 
    A->Left = B;
    B->Left = C;
    B->Right = D;

    A->Right = E;
    E->Left = F;
    E->Right = G;

    //  트리 출력 
    printf("Preorder ...\n");
    PreOrderPrintTree(A);
    printf("\n\n");

    printf("Inorder ... \n");
    InOrderPrintTree(A);
    printf("\n\n");

    printf("Postorder ... \n");
    PostOrderPrintTree(A);
    printf("\n");

    //  트리 소멸시키기 
    DestroyTree(A);
}