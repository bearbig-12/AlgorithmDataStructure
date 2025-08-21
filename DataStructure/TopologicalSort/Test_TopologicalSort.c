#include "Graph.h"
#include "TopologicalSort.h"
#define _CRT_SECURE_NO_WARNNINGS

int main( void )
{
    Node* SortedList  = NULL;
    Node* CurrentNode = NULL;

    //  그래프 생성     
    Graph* graph = CreateGraph();
    
    //  정점 생성 
    
    Vertex* A = CreateVertex( "C++");
    Vertex* B = CreateVertex( "C#");
    Vertex* C = CreateVertex( "Algorithm");
    Vertex* D = CreateVertex( "DataStructure");
    Vertex* E = CreateVertex( "CodingTest");
    Vertex* F = CreateVertex( "Unity");
    Vertex* G = CreateVertex( "Unreal");
    Vertex* H = CreateVertex( "Job");
    
    //  그래프에 정점을 추가 
    AddVertex( graph, A );
    AddVertex( graph, B );
    AddVertex( graph, C );
    AddVertex( graph, D );
    AddVertex( graph, E );
    AddVertex( graph, F );
    AddVertex( graph, G );
    AddVertex( graph, H );

    //  정점과 정점을 간선으로 잇기 
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


    //  위상 정렬 
    TopologicalSort( graph->Vertices, &SortedList );

 
    printf("Topological Sort Result : ");

    CurrentNode = SortedList;

    while ( CurrentNode != NULL )
    {
        // 문자열 출력으로 변경
        printf("%s ", CurrentNode->Data->Data);
        CurrentNode = CurrentNode->NextNode;
    }
    printf("\n");
    

    //  그래프 소멸 
    DestroyGraph( graph );

    return 0;
}
