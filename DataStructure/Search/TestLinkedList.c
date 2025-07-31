#include "LinkedList.h"
#include "Score.h"
#include "ScoreData.h"

// 1. ����Ž��
// �̱۸�ũ�� ����Ʈ�� ����� 3������ ����Ÿ �ȿ��� Target�Ű������� ���޵� ���� ���� ��带 ã��
// �ش� ����� �ּҰ��� �����Ѵ�.
Node* SequentialSearch(Node* Head, double Target) {
	Node* node = Head;
	
	if (node == NULL)
	{
		return NULL;
	}
	while (node != NULL)
	{
		if (node->Data.score == Target)
		{
			return node;
		}
		node = node->NextNode;
	}
	return NULL;
}


// 2. �����̵���
// Target �Ű������� ���޵� ���� ���� ��带 ã�� �ش� ��带 �̱۸�ũ�� ����Ʈ�� �Ǿ����� �̵���Ų��(������ �����.)
Node* MoveToFront(Node** Head, double Target) {
	Node* prev = NULL;
	Node* node = *Head;

	if (*Head == NULL)
	{
		return NULL;
	}
	while (node != NULL)
	{
		if (node->Data.score == Target)
		{
			if (node == *Head)
			{
				return node;
			}
			if (prev != NULL)
			{
				prev->NextNode = node->NextNode;
				node->NextNode = *Head;
				*Head = node;
				return node;
			}
		}
		prev = node;
		node = node->NextNode;
	}


	return NULL;
}

// 3. ������
// Target �Ű������� ���޵� ���� ���� ��带 ã�� �ش� ��带 �̱۸�ũ�� ����Ʈ����
// ã�� ��带 ��ĭ �������� �̵���Ų��.
Node* Transpose(Node** Head, double Target) {
	return NULL;
}


// 4. �����
// Node�� �󵵼�(Frequency)�� �����ϴ� ������ �����
// Target�� ���޵� ���� ���� ��带 ã�� �� �󵵼��� ������Ű��
// �󵵼��� ũ�⸦ ���Ͽ� �ش� ��带 ��ġ ��Ų��.
Node* FrequencyMethod(Node** Head, double Target) {
	return NULL;
}

int main(void)
{
	int   i = 0;
	int   Count = 0;
	Node* List = NULL;  // ������ּҰ��� ����
	Node* Current = NULL;
	Node* NewNode = NULL;

	double InputValue = 0.0;	// ã�� ���� �����ϴ� ����

	int Length = sizeof(DataSet) / sizeof(Score);	// DataSet �迭����� ���� (30000��)

	//  ��� 30000�� �߰� 
	for (i = 0; i < Length; i++)
	{
		NewNode = CreateNode(DataSet[i]);
		AppendNode(&List, NewNode);
	}

	// ã�� ���� ã�� �ݺ�����
	while (1) {
		printf("\nã�� score���� �Է��ϼ���: ");
		scanf_s("%lf", &InputValue);

		if (InputValue <= 0.0) {
			printf("ã�� �۾��� �ߴ��ϰ� ���α׷��� �����մϴ�.\n");
			break;
		}

		Node* targetNode = MoveToFront(&List, InputValue);

		if (targetNode != NULL) {	// ã�� score���� ���� ��带 ã�� ���
			printf("MATCH!!!! searchValue  number: %d, score: %lf\n",
				 targetNode->Data.number, targetNode->Data.score);
		}
		//if (targetNode != NULL) {	// ã�� score���� ���� ��带 ã�� ���
		//	printf("MATCH!!!! searchValue Frequency: %d, number: %d, score: %lf\n",
		//		targetNode->Frequency, targetNode->Data.number, targetNode->Data.score);
		//}
		else {	// ã�� score���� ���� ��带 �� ã�� ���
			printf("ã�� ���� ���� ��尡 ����!!!!\n");
		}

		// �տ� 10��
		for (int i = 0; i < 10; i++) {
			Current = GetNodeAt(List, i);
			printf("DataSet[%d] , Number: %d, Score: %.4lf\n",
				i, Current->Data.number, Current->Data.score);
		}

		//// �տ� 10��
		//for (int i = 0; i < 10; i++) {
		//	Current = SLL_GetNodeAt(List, i);
		//	printf("DataSet[%d] Frequency: %d, Number: %d, Score: %.4lf\n",
		//		i, Current->Frequency, Current->Data.number, Current->Data.score);
		//}

		printf("===============================================\n");

		/*for (int i = Length - 10; i < Length; i++) {
			Current = SLL_GetNodeAt(List, i);
			printf("DataSet[%d] Frequency: %d, Number: %d, Score: %.4lf\n",
				i, Current->Frequency, Current->Data.number, Current->Data.score);
		}*/

		// �տ� 10��
		for (int i = 0; i < 10; i++) {
			Current = GetNodeAt(List, i);
			printf("DataSet[%d] , Number: %d, Score: %.4lf\n",
				i,  Current->Data.number, Current->Data.score);
		}

	}



	//  ��� ��带 �޸𸮿��� ����     
	printf("\nDestroying List...\n");

	for (i = 0; i < Count; i++)
	{
		Current = GetNodeAt(List, 0);

		if (Current != NULL)
		{
			RemoveNode(&List, Current);
			DestroyNode(Current);
		}
	}

	return 0;
}
