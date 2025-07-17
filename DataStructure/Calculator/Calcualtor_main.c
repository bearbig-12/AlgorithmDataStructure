#define _CRT_SECURE_NO_WARNINGS


#include <stdio.h>
#include <string.h>
#include "Calculator.h"

// 1 + 2 * 3
// (117.32 + 83) * 49
int main(void)
{
    char InfixExpression[100];      // 중위식 문장 저장
    char PostfixExpression[100];    // 후위식 문장 저장

    double Result = 0.0;

    // memset 함수는 메모리의 내용(값)을 원하는 크기만큼 특정 값으로 세팅할 수 있는 함수.
    // memory + setting 메모리를 (특정 값으로) 세팅한다
    memset(InfixExpression, 0, sizeof(InfixExpression));
    memset(PostfixExpression, 0, sizeof(PostfixExpression));

    printf("Enter Infix Expression:");
    scanf("%s", InfixExpression);

    GetPostFix(InfixExpression, PostfixExpression);

    printf("Infix:%s\nPostfix:%s\n",
        InfixExpression,
        PostfixExpression);

    Result = Calculate(PostfixExpression);

    printf("Calculation Result : %f\n", Result);

    return 0;
}
