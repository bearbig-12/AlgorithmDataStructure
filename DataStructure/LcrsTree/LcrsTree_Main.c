#include "LcrsTree.h"


int main()
{
	// 노드 생성
	LCRSNode* RootNode = CreateNode('A');

	LCRSNode* B = CreateNode('B');
	LCRSNode* C = CreateNode('C');
	LCRSNode* D = CreateNode('D');
	LCRSNode* E = CreateNode('E');
	LCRSNode* F = CreateNode('F');
	LCRSNode* G = CreateNode('G');
	LCRSNode* H = CreateNode('H');
	LCRSNode* I = CreateNode('I');
	LCRSNode* J = CreateNode('J');
	LCRSNode* K = CreateNode('K');

	//  트리에 노드 추가 
	AddChildNode(RootNode, B);
		AddChildNode(B, C);
		AddChildNode(B, D);
			AddChildNode(D, E);
			AddChildNode(D, F);

	AddChildNode(RootNode, G);
		AddChildNode(G, H);

	AddChildNode(RootNode, I);
		AddChildNode(I, J);
			AddChildNode(J, K);

	//  트리 출력 
	PrintTree(RootNode, 0);

	PrintLevel(RootNode, 2);

	//  트리 소멸시키기 
	DestroyTree(RootNode);
	
	return 0;
}