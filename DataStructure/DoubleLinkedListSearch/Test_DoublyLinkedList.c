﻿#include "DoublyLinkedList.h"
#include "Score.h"
#include "ScoreData.h"

//1. 순차탐색
//순서대로 탐색
//#작동 순서
//탐색할 노드 NULL 확인
//Target Match 되는지 확인
//안되면 다음 -> 찾았으면 return
//끝까지 못 찾았으면 NULL일테니 위에서 거르기
Node* SequntialSearch(Node** Head, double Target)
{
	Node* current = *Head;

	if (current == NULL)
	{
		return NULL;
	}
	while (current != NULL)
	{
		
		if (current->Data.score == Target)
		{
			return current;
		}
		current = current->NextNode;
	}

}

// 2. 전진이동법
// Target 매개변수에 전달된 값을 가진 노드를 찾고 해당 노드를 더블링크드 리스트의 맨앞으로 이동시킨다(헤드노드로 만들다.)
Node* MoveToFront(Node** Head, double Target) {

	Node* current = *Head;

	if (current == NULL)
	{
		return NULL;
	}
	
	while (current != NULL)
	{

		if (current->Data.score == Target)
		{
			// 헤드인 경우
			if (current == *Head)
			{
				return current;
			}
			// 꼬리인 경우
			if (current->NextNode == NULL)
			{
				current->PrevNode->NextNode = NULL;
				current->PrevNode = NULL;

				current->NextNode = *Head;

				*Head = current;

				return current;
			
			}
			current->PrevNode->NextNode = current->NextNode;
			current->NextNode->PrevNode = current->PrevNode;

			current->NextNode = *Head;
			current->PrevNode = NULL;



			*Head = current;

			return current;
		}
		current = current->NextNode;
	}

}



//3. 전위법
//한 칸 앞으로
Node* Transpose(Node** Head, double Target)
{
	return NULL;

}


//4. 계수법
//조회수(탐색횟수)에 따른 이동
Node* FrequencyMethod(Node** Head, double Target)
{


	return NULL;
}



int main(void)
{
	int   i = 0;
	int   Count = 0;
	Node* List = NULL;
	Node* NewNode = NULL;
	Node* Current = NULL;
	

	double InputValue = 0.0;	// 찾는 값(lf)을 저장하는 변수

	int Length = sizeof(DataSet) / sizeof(Score);	// DataSet 배열요소의 갯수 (30000개)

	/*  노드 30,000개 추가 */
	for (i = 0; i < Length; i++)
	{
		NewNode = CreateNode(DataSet[i]);
		AppendNode(&List, NewNode);
	}

	//Current = CreateNode(8000);     // 8000값을 현재 노드로 만든다.
	//InsertNewHead(&List, Current);  //헤드 노드를 바꾼다.


	while (1) {
		printf("\n찾는 score값을 입력하세요: ");
		scanf_s("%lf", &InputValue);

		if (InputValue <= 0.0) {
			printf("찾는 작업을 중단하고 프로그램을 종료합니다.\n");
			break;
		}

		Node* targetNode = MoveToFront(&List, InputValue);

		if (targetNode != NULL) {	//찾는 Score값을 가진 노드를 찾은 경우
			printf("MATCH!!! searchValue: number:%d, score: %lf, Frequency: %d\n", targetNode->Data.number, targetNode->Data.score, targetNode->Frequency);
		}
		else {	// 찾는 score값을 가진 노드를 찾지 못함 (값이 없는 경우)
			printf("찾는 값을 가진 노드가 없음!!!\n");
		}

		// 앞에 10개
		for (int i = 0; i < 10; i++) {
			Current = GetNodeAt(List, i);
			printf("DataSet[%d] number:%d, score: %.4lf, Frequency: %d\n", i, Current->Data.number, Current->Data.score, Current->Frequency);
		}

		printf("===============================================================================\n");

		// 뒤에 10개
		for (int i = Length - 10; i < Length; i++) {
			Current = GetNodeAt(List, i);
			printf("DataSet[%d] number:%d, score: %.4lf, Frequency: %d\n", i, Current->Data.number, Current->Data.score, Current->Frequency);
		}

	}



	/*  모든 노드를 메모리에서 제거     */
	printf("\nDestroying List...\n");

	Count = GetNodeCount(List);

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