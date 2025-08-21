#include "Graph.h"
#define _CRT_SECURE_NO_WARNNINGS

Graph* CreateGraph()
{
    Graph* graph = (Graph*)malloc( sizeof( Graph ) );
    graph->Vertices = NULL;
    graph->VertexCount = 0;

    return graph;
}

void DestroyGraph( Graph* G )
{
    while ( G->Vertices != NULL )
    {
        Vertex* Vertices = G->Vertices->Next;        
        DestroyVertex( G->Vertices );
        G->Vertices = Vertices;        
    }

    free( G );
}

Vertex* CreateVertex( VElementType Data )
{
    // 1. Vertex 구조체에 필요한 메모리를 할당합니다.
    Vertex* V = (Vertex*)malloc(sizeof(Vertex));

    // malloc 실패 시 예외 처리
    if (V == NULL) {
        return NULL;
    }

    // 2. V->Data가 가리킬 문자열을 위한 메모리를 할당합니다.
    // strlen(Data)로 문자열 길이를 얻고, 널 종단 문자(\0)를 위해 +1을 더해줍니다.
    size_t len = strlen(Data);
    V->Data = (char*)malloc(sizeof(char) * (len + 1));
    // malloc 실패 시 예외 처리
    if (V->Data == NULL) {
        free(V); // Vertex 구조체에 할당한 메모리를 해제합니다.
        return NULL;
    }

    // 3. strcpy를 사용하여 Data의 내용을 V->Data로 복사합니다.
    strcpy_s(V->Data, len + 1, Data);

    // 나머지 멤버 변수들을 초기화합니다.
    V->Next = NULL;
    V->AdjacencyList = NULL;
    V->Visited = NotVisited;
    V->Index = -1;

    return V;
}

void DestroyVertex( Vertex* V )
{
    while ( V->AdjacencyList != NULL )
    {
        Edge* Edge = V->AdjacencyList->Next;

        DestroyEdge ( V->AdjacencyList );

        V->AdjacencyList = Edge;
    }

    free( V );    
}

Edge*   CreateEdge( Vertex* From, Vertex* Target, int Weight )
{
    Edge* E   = (Edge*)malloc( sizeof( Edge ) );
    E->From   = From;
    E->Target = Target;
    E->Next   = NULL;
    E->Weight = Weight;

    return E;
}

void    DestroyEdge( Edge* E )
{
    free( E );
}

void AddVertex( Graph* G, Vertex* V )
{
    Vertex* VertexList = G->Vertices;

    if ( VertexList == NULL ) 
    {
        G->Vertices = V;
    } 
    else 
    {
        while ( VertexList->Next != NULL )
            VertexList = VertexList->Next;

        VertexList->Next = V;
    }

    V->Index = G->VertexCount++;
}

void AddEdge( Vertex* V, Edge* E )
{
    if ( V->AdjacencyList == NULL ) 
    {
        V->AdjacencyList = E;
    } 
    else
    {
        Edge* AdjacencyList = V->AdjacencyList;

        while ( AdjacencyList->Next != NULL )
            AdjacencyList = AdjacencyList->Next;

        AdjacencyList->Next = E;
    }
}

void PrintGraph ( Graph* G )
{
    Vertex* V = NULL;
    Edge*   E = NULL;

    if ( ( V = G->Vertices ) == NULL )
        return;

    while ( V != NULL )
    {
        printf("%s : ", V->Data);

        if ( (E = V->AdjacencyList) == NULL ) {
            V = V->Next;
            printf("\n");
            continue;
        }

        while ( E != NULL )
        {
            printf("%s[%d] ", E->Target->Data, E->Weight);
            E = E->Next;
        }

        printf("\n");

        V = V->Next;    
    }   

    printf("\n");
}
