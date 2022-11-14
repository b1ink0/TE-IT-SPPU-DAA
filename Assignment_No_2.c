#include <stdio.h>
int I = 1000;

void BF(int g[][3], int v, int e)
{
    int d[v];
    d[0] = 0;
    for (int i = 1; i < v; i++)
        d[i] = I;

    for (int i = 0; i < v - 1; i++)
    {
        for (int j = 0; j < e; j++)
        {
            int u = g[j][0];
            int v = g[j][1];
            int w = g[j][2];
            if (d[u] != I && d[u] + w < d[v])
                d[v] = d[u] + w;
        }
    }

    printf("Vertice    Shortest Distance\n");
    for(int i = 0; i < v; i++)
        printf("%d       %d\n", i,d[i]);
}

int main()
{
    int V; // Number of vertices in graph
    int E; // Number of edges in graph
    int graph[E][3];

    printf("Number of Vertices: ");
    scanf("%d", &V);
    printf("Number of Edges: ");
    scanf("%d", &E);

    for(int i = 0; i < E; i++){
        printf("SRC NODE: ");
        scanf("%d", &graph[i][0]);
        printf("DEST NODE: ");
        scanf("%d", &graph[i][1]);
        printf("WEIGHT OF EDGE: ");
        scanf("%d", &graph[i][2]);
    }
    // // add edge 0-1 (or A-B in above figure)
    // graph[0][0] = 0;
    // graph[0][1] = 1;
    // graph[0][2] = -1;

    // // add edge 0-2 (or A-C in above figure)
    // graph[1][0] = 0;
    // graph[1][1] = 2;
    // graph[1][2] = 4;

    // // add edge 1-2 (or B-C in above figure)
    // graph[2][0] = 1;
    // graph[2][1] = 2;
    // graph[2][2] = 3;

    // // add edge 1-3 (or B-D in above figure)
    // graph[3][0] = 1;
    // graph[3][1] = 3;
    // graph[3][2] = 2;

    // // add edge 1-4 (or B-E in above figure)
    // graph[4][0] = 1;
    // graph[4][1] = 4;
    // graph[4][2] = 2;

    // // add edge 3-2 (or D-C in above figure)
    // graph[5][0] = 3;
    // graph[5][1] = 2;
    // graph[5][2] = 5;

    // // add edge 3-1 (or D-B in above figure)
    // graph[6][0] = 3;
    // graph[6][1] = 1;
    // graph[6][2] = 1;

    // // add edge 4-3 (or E-D in above figure)
    // graph[7][0] = 4;
    // graph[7][1] = 3;
    // graph[7][2] = -3;

    BF(graph, V, E);

    return 0;
}