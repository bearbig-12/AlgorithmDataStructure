﻿#include "LinkedList.h"
#include "Score.h"
#include "ScoreData.h"

// 1. 순차탐색
// 싱글링크드 리스트에 저장된 3만개의 데이타 안에서 Target매개변수에 전달된 값을 가진 노드를 찾고
// 해당 노드의 주소값을 전달한다.
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


// 2. 전진이동법
// Target 매개변수에 전달된 값을 가진 노드를 찾고 해당 노드를 싱글링크드 리스트의 맨앞으로 이동시킨다(헤드노드로 만들다.)
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

// 3. 전위법
// Target 매개변수에 전달된 값을 가진 노드를 찾고 해당 노드를 싱글링크드 리스트에서
// 찾는 노드를 한칸 앞쪽으로 이동시킨다.
Node* Transpose(Node** Head, double Target) {
	Node* prevPrev = NULL;
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
			// 찾은 노드가 헤드 다음 노드
			if (prevPrev == NULL )
			{
				prev->NextNode = node->NextNode;
				node->NextNode = *Head;
				*Head = node;
			}
			// 그 이후부터
			else
			{
				prevPrev->NextNode = node;
				prev->NextNode = node->NextNode;
				node->NextNode = prev;
				prev = node;
			}
			return node;
		}
		prevPrev = prev;
		prev = node;
		node = node->NextNode;
	}


	return NULL;
}


// 4. 계수법
// Node에 빈도수(Frequency)를 저장하는 변수를 만들고
// Target에 전달된 값을 가진 노드를 찾은 후 빈도수를 증가시키고
// 빈도수에 크기를 비교하여 해당 노드를 위치 시킨다.
Node* FrequencyMethod(Node** Head, double Target) {
	Node* targetNode = *Head;
	Node* targetNodePrev = NULL;

	Node* node = *Head;
	Node* nodePrev = NULL;

	if (*Head == NULL)
	{
		return NULL;
	}
	while (targetNode != NULL)
	{
		if (targetNode->Data.score == Target)
		{
			targetNode->Frequency += 1;
			break;
		}
		targetNodePrev = targetNode;
		targetNode = targetNode->NextNode;
	}

	if (targetNode == NULL)
	{
		return NULL;
	}

	while (node != NULL)
	{
		if (node == targetNode)
		{
			break;
		}
		if (node->Frequency < targetNode->Frequency && targetNode != NULL)
		{
			
			if (nodePrev == NULL && node != NULL)
			{
				targetNodePrev->NextNode = targetNode->NextNode;
				targetNode->NextNode = node;
				*Head = targetNode;
			}
			else			
			{
				targetNodePrev->NextNode = targetNode->NextNode;
				nodePrev->NextNode = targetNode;
				targetNode->NextNode = node;
				targetNode = nodePrev;

			}
			break;
			
		}
		nodePrev = node;
		node = node->NextNode;
	}
	return targetNode;
}

int main(void)
{
	int   i = 0;
	int   Count = 0;
	Node* List = NULL;  // 헤드노드주소값을 저장
	Node* Current = NULL;
	Node* NewNode = NULL;

	double InputValue = 0.0;	// 찾는 값을 저장하는 변수

	int Length = sizeof(DataSet) / sizeof(Score);	// DataSet 배열요소의 갯수 (30000개)

	//  노드 30000개 추가 
	for (i = 0; i < Length; i++)
	{
		NewNode = CreateNode(DataSet[i]);
		AppendNode(&List, NewNode);
	}

	// 찾는 값을 찾는 반복연산
	while (1) {
		printf("\n찾는 score값을 입력하세요: ");
		scanf_s("%lf", &InputValue);

		if (InputValue <= 0.0) {
			printf("찾는 작업을 중단하고 프로그램을 종료합니다.\n");
			break;
		}

		Node* targetNode = FrequencyMethod(&List, InputValue);

		//if (targetNode != NULL) {	// 찾는 score값을 가진 노드를 찾은 경우
		//	printf("MATCH!!!! searchValue  number: %d, score: %lf\n",
		//		 targetNode->Data.number, targetNode->Data.score);
		//}
		if (targetNode != NULL) {	// 찾는 score값을 가진 노드를 찾은 경우
			printf("MATCH!!!! searchValue Frequency: %d, number: %d, score: %lf\n",
				targetNode->Frequency, targetNode->Data.number, targetNode->Data.score);
		}
		else {	// 찾는 score값을 가진 노드를 못 찾은 경우
			printf("찾는 값을 가진 노드가 없음!!!!\n");
		}

		// 앞에 10개
		/*for (int i = 0; i < 10; i++) {
			Current = GetNodeAt(List, i);
			printf("DataSet[%d] , Number: %d, Score: %.4lf\n",
				i, Current->Data.number, Current->Data.score);
		}*/

		// 앞에 10개
		for (int i = 0; i < 10; i++) {
			Current = GetNodeAt(List, i);
			printf("DataSet[%d] Frequency: %d, Number: %d, Score: %.4lf\n",
				i, Current->Frequency, Current->Data.number, Current->Data.score);
		}

		printf("===============================================\n");

		for (int i = Length - 10; i < Length; i++) {
			Current = GetNodeAt(List, i);
			printf("DataSet[%d] Frequency: %d, Number: %d, Score: %.4lf\n",
				i, Current->Frequency, Current->Data.number, Current->Data.score);
		}

		// 뒤에 10개
		/*for (int i = Length-10; i < Length; i++) {
			Current = GetNodeAt(List, i);
			printf("DataSet[%d] , Number: %d, Score: %.4lf\n",
				i,  Current->Data.number, Current->Data.score);
		}*/

	}



	//  모든 노드를 메모리에서 제거     
	printf("\nDestroying List...\n");

	for (i = 0; i < Length; i++)
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
