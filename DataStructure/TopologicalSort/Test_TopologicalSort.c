#include "Graph.h"
#include "TopologicalSort.h"
#define _CRT_SECURE_NO_WARNNINGS

int main( void )
{
    Node* SortedList  = NULL;
    Node* CurrentNode = NULL;

    //  �׷��� ����     
    Graph* graph = CreateGraph();
    
    //  ���� ���� 
    
    Vertex* A = CreateVertex( "C++");
    Vertex* B = CreateVertex( "C#");
    Vertex* C = CreateVertex( "Algorithm");
    Vertex* D = CreateVertex( "DataStructure");
    Vertex* E = CreateVertex( "CodingTest");
    Vertex* F = CreateVertex( "Unity");
    Vertex* G = CreateVertex( "Unreal");
    Vertex* H = CreateVertex( "Job");
    
    //  �׷����� ������ �߰� 
    AddVertex( graph, A );
    AddVertex( graph, B );
    AddVertex( graph, C );
    AddVertex( graph, D );
    AddVertex( graph, E );
    AddVertex( graph, F );
    AddVertex( graph, G );
    AddVertex( graph, H );

    //  ������ ������ �������� �ձ� 
    AddEdge( A, CreateEdge( A, B, 0 ) );

    AddEdge( B, CreateEdge( B, D, 0 ) );
    AddEdge( B, CreateEdge( B, C, 0 ) );
    AddEdge( B, CreateEdge(B, G, 0));
    AddEdge( B, CreateEdge(B, F, 0));

    AddEdge( C, CreateEdge( C, E, 0 ) );
    
    AddEdge( D, CreateEdge( D, E, 0 ) );

    AddEdge( E, CreateEdge( E, H, 0 ) );

    AddEdge( F, CreateEdge( F, H, 0 ) );
    
    AddEdge( G, CreateEdge( G, H, 0 ) );

   // PrintGraph(graph);


    //  ���� ���� 
    TopologicalSort( graph->Vertices, &SortedList );

 
    printf("Topological Sort Result : ");

    CurrentNode = SortedList;

    while ( CurrentNode != NULL )
    {
        // ���ڿ� ������� ����
        printf("%s ", CurrentNode->Data->Data);
        CurrentNode = CurrentNode->NextNode;
    }
    printf("\n");
    

    //  �׷��� �Ҹ� 
    DestroyGraph( graph );

    return 0;
}
