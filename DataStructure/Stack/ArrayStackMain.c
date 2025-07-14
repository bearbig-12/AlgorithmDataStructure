#include "ArrayStack.h"
/*
// 문제 1. 스택이 가득찼는지 판단하는 함수를 만드세요.
int AS_IsFull() {

}

// 문제 2. 스택의 Capacity를 50개로 설정하고 while문으로 Stack이 가득 찰때까지 100처음 값을
// 증가시키면서 저장하고 스택이 빌때까지 값을 출력해보세요..

// 문제 3. 스택에 값을 Push 하다 용량이 부족하면 동적배열의 용량을 2배 늘려서 값을 저장하도록 만들어보기

*/




int main()
{
	int i = 100;
	ArrayStack* stack = NULL;

	/*CreateStack(&stack, 4);

	Push(stack, 3);
	Push(stack, 37);
	Push(stack, 11);
	Push(stack, 12);

	printf("Capacity: %d, Size: %d, Top: %d\n\n",
		stack->mCapacity, GetSize(stack), Top(stack));

    IsFull(stack);


    for (i = 0; i < 4; i++)
    {
        if (IsEmpty(stack))
            break;

        printf("Popped: %d, ", Pop(stack));

        if (!IsEmpty(stack))
            printf("Current Top: %d\n", Top(stack));
        else
            printf("Stack Is Empty.\n");
    }*/

    CreateStack(&stack, 50);
    
    for (i = 0; i <= 50; i++)
    {
        Push(stack, i);
        printf("Pushed: %d\n", i);
    }

    while (!IsFull(stack))
    {
        Push(stack, i);
        printf("Pushed: %d\n", i);
        ++i;
    }

    DestroyStack(stack);
}