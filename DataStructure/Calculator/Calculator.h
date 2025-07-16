#ifndef CALCULATOR_H
#define CALCULATOR_H

#define _CRT_SECURE_NO_WARNINGS


#include <stdlib.h>
#include "LinkedListStack.h"

typedef enum
{
	LEFT_PARENTHESIS = '(', RIGHT_PARENTHESIS = ')',
	PLUS = '+' , MINUS = '-',
	MULTIPLY = '*', DIVIDE = '/',
	SPACE = ' ', OPERAND

} SYMBOL;

int IsNumber(char cipher);
unsigned int GetNextToken(char* expression, char* token, int* type);
int IsPrior(char operator1, char operator2);
void GetPostFix(char* infixExpression, char* postfixExpression);
double Calculate(char* posfixExpression);


#endif // !CALCULATOR_H
