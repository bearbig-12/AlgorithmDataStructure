#include "ExpressionTree.h"

ETNode* CreateNode(ElementType newData)
{
    ETNode* NewNode = (ETNode*)malloc(sizeof(ETNode));
    NewNode->Left = NULL;
    NewNode->Right = NULL;
    NewNode->mData = newData;

    return NewNode;
}

void DestroyNode(ETNode* node)
{
    free(node);
}

void DestroyTree(ETNode* root)
{
    if (root == NULL)
        return;

    DestroyTree(root->Left);
    DestroyTree(root->Right);
    DestroyNode(root);

}

void PreorderPrintTree(ETNode* node)
{
    if (node == NULL)
        return;

    printf(" %c", node->mData);

    PreorderPrintTree(node->Left);
    PreorderPrintTree(node->Right);

}

void InorderPrintTree(ETNode* node)
{
    if (node == NULL)
        return;

    printf("(");

    InorderPrintTree(node->Left);

    printf("%c", node->mData);

    InorderPrintTree(node->Right);
    printf(")");
}

void PostorderPrintTree(ETNode* node)
{
    if (node == NULL)
        return;

    PostorderPrintTree(node->Left);
    PostorderPrintTree(node->Right);
    printf("%c", node->mData);

}

void BuildExpressionTree(char* postFixExpression, ETNode** node)
{
    int len = strlen(postFixExpression);
    char token = postFixExpression[len - 1];
    postFixExpression[len - 1] = '\0';

    switch (token)
    {
        // 연산자인 경우
    case '+':
    case '-':
    case '*':
    case '/':
        (*node) = CreateNode(token);
        BuildExpressionTree(postFixExpression, &(*node)->Right);
        BuildExpressionTree(postFixExpression, &(*node)->Left);
        break;


        // 피연자인 경우
    default :
        (*node) = CreateNode(token);
        break;
    }

}

double Evaluate(ETNode* tree)
{
    char Temp[2];

    double Left = 0;
    double Right = 0;
    double Result = 0;

    if (tree == NULL)
        return 0;


    switch (tree->mData)
    {
        //  연산자인 경우 
    case '+': case '-': case '*': case '/':
        Left = Evaluate(tree->Left);
        Right = Evaluate(tree->Right);

        if (tree->mData == '+') Result = Left + Right;
        else if (tree->mData == '-') Result = Left - Right;
        else if (tree->mData == '*') Result = Left * Right;
        else if (tree->mData == '/') Result = Left / Right;

        break;

        //  피연산자인 경우 
    default:
        memset(Temp, 0, sizeof(Temp));
        Temp[0] = tree->mData;
        Result = atof(Temp);
        break;
    }
    return Result;
}