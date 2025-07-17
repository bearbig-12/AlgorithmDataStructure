#define _CRT_SECURE_NO_WARNINGS

#include "Calculator.h"


char NUMBER[] = { '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', '.' };


int IsNumber(char cipher)
{
	int i = 0;
	int arrayLength = sizeof(NUMBER);

	for ( i = 0; i < sizeof(NUMBER); ++i)
	{
		if (cipher == NUMBER[i])
		{
			return 1;
		}
	}
	return 0;
}

unsigned int GetNextToken(char* expression, char* token, int* type)
{
	unsigned int i = 0;
	for (i = 0; 0 != expression[i]; ++i)
	{
		token[i] = expression[i];

		if (IsNumber(expression[i]) == 1)
		{
			*type = OPERAND;
			if (IsNumber(expression[i + 1]) != 1)
			{
				break;
			}
		}
		else
		{
			*type = expression[i];
			break;
		}
	}
	token[++i] = '\0';
	return i;
}

int GetPriority(char Operator, int inStack)
{
	int priority = -1;
	
	switch (Operator)
	{
	case LEFT_PARENTHESIS:
		if (inStack)
			priority = 3;
		else
			priority = 0;
		break;
	case MULTIPLY:
	case DIVIDE:
		priority = 1;
		break;

	case PLUS:
	case MINUS:
		priority = 2;
		break;
	}
	return priority;
}

int IsPrior(char OperatorInStack, char OperatorInToken)
{
	return (GetPriority(OperatorInStack, 1) > GetPriority(OperatorInToken, 0));
}

// Token은 의미단위소
void GetPostFix(char* InfixExpression, char* PostfixExpression)
{
	LinkedListStack* Stack;

	char Token[32];		// InfixExpression 에서 분리해낸 토큰 저장
	int  Type = -1;
	unsigned int Position = 0;
	unsigned int Length = strlen(InfixExpression);

	CreateStack(&Stack);

	while (Position < Length)
	{
		Position += GetNextToken(&InfixExpression[Position], Token, &Type);

		if (Type == OPERAND)
		{
			strcat(PostfixExpression, Token);
			strcat(PostfixExpression, " ");
		}
		else if (Type == RIGHT_PARENTHESIS)
		{
			while (!IsEmpty(Stack))
			{
				Node* Popped = Pop(Stack);

				if (Popped->mData[0] == LEFT_PARENTHESIS)
				{
					DestroyNode(Popped);
					break;
				}
				else
				{
					strcat(PostfixExpression, Popped->mData);
					DestroyNode(Popped);
				}
			}
		}
		else
		{
			while (!IsEmpty(Stack) &&
				!IsPrior(FindTop(Stack)->mData[0], Token[0]))
			{
				Node* Popped = Pop(Stack);

				if (Popped->mData[0] != LEFT_PARENTHESIS)
					strcat(PostfixExpression, Popped->mData);

				DestroyNode(Popped);
			}

			Push(Stack, CreateNode(Token));
		}
	}

	while (!IsEmpty(Stack))
	{
		Node* Popped = Pop(Stack);

		if (Popped->mData[0] != LEFT_PARENTHESIS)
			strcat(PostfixExpression, Popped->mData);

		DestroyNode(Popped);
	}

	DestroyStack(Stack);

}

double Calculate(char* PostfixExpression)
{
	LinkedListStack* Stack;
	Node* ResultNode;

	double Result;
	char Token[32];
	int  Type = -1;
	unsigned int Read = 0;
	unsigned int Length = strlen(PostfixExpression);

	CreateStack(&Stack);

	while (Read < Length)
	{
		Read += GetNextToken(&PostfixExpression[Read], Token, &Type);

		if (Type == SPACE)
			continue;

		if (Type == OPERAND)
		{
			Node* NewNode = CreateNode(Token);
			Push(Stack, NewNode);
		}
		else
		{
			char   ResultString[32];
			double Operator1, Operator2, TempResult;
			Node* OperatorNode;

			OperatorNode = Pop(Stack);
			Operator2 = atof(OperatorNode->mData);
			DestroyNode(OperatorNode);

			OperatorNode = Pop(Stack);
			Operator1 = atof(OperatorNode->mData);
			DestroyNode(OperatorNode);

			switch (Type)
			{
			case PLUS:     TempResult = Operator1 + Operator2; break;
			case MINUS:    TempResult = Operator1 - Operator2; break;
			case MULTIPLY: TempResult = Operator1 * Operator2; break;
			case DIVIDE:   TempResult = Operator1 / Operator2; break;
			}

			_gcvt(TempResult, 10, ResultString);
			Push(Stack, CreateNode(ResultString));
		}
	}

	ResultNode = Pop(Stack);
	Result = atof(ResultNode->mData);
	DestroyNode(ResultNode);

	DestroyStack(Stack);

	return Result;
}
