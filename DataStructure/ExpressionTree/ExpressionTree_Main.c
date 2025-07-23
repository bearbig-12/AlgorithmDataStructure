#include "ExpressionTree.h"


int main()
{
	ETNode* Root = NULL;

	char PostfixExpression[20] = "71*52-/";
	BuildExpressionTree(PostfixExpression, &Root);

	// 트리 출력
    printf("Preorder ...\n");
    PreorderPrintTree(Root);
    printf("\n\n");

    printf("Inorder ... \n");
    InorderPrintTree(Root);
    printf("\n\n");

    printf("Postorder ... \n");
    PostorderPrintTree(Root);
    printf("\n");


    printf("Evaulation Result : %f \n", Evaluate(Root));

    //  트리 소멸
    DestroyTree(Root);

}

