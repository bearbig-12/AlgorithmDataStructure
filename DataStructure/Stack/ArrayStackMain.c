#include "ArrayStack.h"
/*
// ���� 1. ������ ����á���� �Ǵ��ϴ� �Լ��� ���弼��.
int AS_IsFull() {

}

// ���� 2. ������ Capacity�� 50���� �����ϰ� while������ Stack�� ���� �������� 100ó�� ����
// ������Ű�鼭 �����ϰ� ������ �������� ���� ����غ�����..

// ���� 3. ���ÿ� ���� Push �ϴ� �뷮�� �����ϸ� �����迭�� �뷮�� 2�� �÷��� ���� �����ϵ��� ������

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