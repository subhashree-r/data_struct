// A C / C++ program for Dijkstra's single source shortest path algorithm.
// The program is for adjacency matrix representation of the graph

#include <stdio.h>
#include <limits.h>

// Number of vertices in the graph
#define V 9

// A utility function to find the vertex with minimum distance value, from
// the set of vertices not yet included in shortest path tree
int minDistance(int dist[], bool sptSet[])
{
    //function to return the index with minimum distance
    int min=INT_MAX, min_ind;
    for(int i=0;i<V;i++)
    {
        if(sptSet[v]==false&&dist[v]<=min)
        {
            min_ind=v;
            min=dist[v];
        }
    }
    return min_ind
}
int printSolution(int dist[], int n)
{
printf("VertexDistance from Source\n");
for (int i = 0; i < V; i++)
printf("%d \t\t %d\n", i, dist[i]);
}
void dijkstra(int graph[V][V],src)
{
    int dist[V];
    bool visited[V];
    for (int i = 0; i < V; i++)
        dist[i] = INT_MAX, visited[i] = false;

    dist[src]=0;
    for(int count=0;count<V-1;count++)
    {

        // return the vertex with least distance and check if the sum of distance to this and to dest from here is lesser than total
        //distance to the destination
        int u= minDistance(dist,visited);
        visited[u]=true;
        for(int i=0;i<V; i++)
        {
            if(!visited[u]&&graph[u][v]&&dist[u]+graph[u][v]<dist[v])
            {
                dist[v]=dist[u]+graph[u][v];
            }
        }
    }
}
// driver program to test above function
int main()
{
/* Let us create the example graph discussed above */
int graph[V][V] = {{0, 4, 0, 0, 0, 0, 0, 8, 0},
					{4, 0, 8, 0, 0, 0, 0, 11, 0},
					{0, 8, 0, 7, 0, 4, 0, 0, 2},
					{0, 0, 7, 0, 9, 14, 0, 0, 0},
					{0, 0, 0, 9, 0, 10, 0, 0, 0},
					{0, 0, 4, 14, 10, 0, 2, 0, 0},
					{0, 0, 0, 0, 0, 2, 0, 1, 6},
					{8, 11, 0, 0, 0, 0, 1, 0, 7},
					{0, 0, 2, 0, 0, 0, 6, 7, 0}
					};

	dijkstra(graph, 0);

	return 0;
}
