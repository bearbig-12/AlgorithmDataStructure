#include <stdio.h>
#include <stdlib.h>

int** CreateMatrix(int col, int row) {
    int** matrix = (int**)malloc(sizeof(int*) * col);

    for (int i = 0; i < row; i++) {
        matrix[i] = (int*)malloc(sizeof(int) * row);
    }

    for (int i = 0; i < col; i++) {
        for (int j = 0; j < row; j++) {
            matrix[i][j] = 0;
        }
    }

    return matrix;
}

void RemoveMatrix(int** Matrix, int col)
{
    // 먼저 각 행(row 배열)을 free
    for (int i = 0; i < col; ++i)
    {
        free(Matrix[i]);
    }

    // 마지막으로 행 포인터 배열 자체를 free
    free(Matrix);
}
void AddEdge(int** M, int Vertext , int Target)
{
    M[Vertext - 1][Target - 1] = 1;
    // 무방향 이므로 쌍방향 연결
    M[Target - 1][Vertext - 1] = 1;

}

void PrintMatrix(int** M, int col, int row) 
{
    for (int i = 0; i < col; i++) {
        printf("%d : ", i + 1);        

        for (int j = 0; j < row; j++) {
            if (M[i][j] == 1)		
                printf("%d ", j + 1);  
        }
        printf("\n");
    }
}
int main(void)
{
    // 388페이지 그래프를 인접행렬 방식으로 구현한후
        // graph의 정점과 간선 정보를 388페이지 프린트 방식으로 출력해보시오..
    int MSize = 5;
    int** matrix = CreateMatrix(MSize,MSize);

    AddEdge(matrix, 1, 2);
    AddEdge(matrix, 1, 3);
    AddEdge(matrix, 1, 4);
    AddEdge(matrix, 1, 5);

    AddEdge(matrix, 2, 1);
    AddEdge(matrix, 2, 3);
    AddEdge(matrix, 2, 5);

    AddEdge(matrix, 3, 1);
    AddEdge(matrix, 3, 2);

    AddEdge(matrix, 4, 1);
    AddEdge(matrix, 4, 5);

    AddEdge(matrix, 5, 1);
    AddEdge(matrix, 5, 2);
    AddEdge(matrix, 5, 4);

    PrintMatrix(matrix, 5, 5);

    RemoveMatrix(matrix, 5);

    return 0;
}
