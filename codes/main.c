#include <stdio.h>
#include <stdlib.h>

struct node {
    int vertex;
    struct node* next;
};
    struct node* createnode(int v);
    struct Graph {
    int num;
    int* visited;
  // We need int** to store a two dimensional array.
  // Similary, we need struct node** to store an array of Linked lists
    struct node** adj;
};
// DFS algo
void DFS(struct Graph* graph, int vertex)
{
    struct node* adjList = graph->adj[vertex];
    struct node* temp = adjList;
    graph->visited[vertex]=1;
    printf("%d \n", vertex);
    while (temp != NULL)
    {
        int connectedVertex = temp->vertex;
        if (graph->visited[connectedVertex] == 0)
    {
        DFS(graph, connectedVertex);
    }
    temp = temp->next;
    }
}
// Create a node
struct node* createnode(int v)
{
    struct node* newnode = malloc(sizeof(struct node));
    newnode->vertex = v;
    newnode->next = NULL;
    return newnode;
}
// Create graph
struct Graph* newgraph(int vertices)
{
    struct Graph* graph = malloc(sizeof(struct Graph));
    graph->num = vertices;
    graph->adj = malloc(vertices * sizeof(struct node*));
    graph->visited = malloc(vertices * sizeof(int));
    int i;
    for (i = 0; i < vertices; i++)
    {
        graph->adj[i] = NULL;
        graph->visited[i] = 0;
    }
    return graph;
}
// Add edge
void addedge(struct Graph* graph, int src, int dest)
{
    // Add edge from src to dest
    struct node* newnode = createnode(dest);
    newnode->next = graph->adj[src];
    graph->adj[src] = newnode;
    // Add edge from dest to src
    newnode = createnode(src);
    newnode->next = graph->adj[dest];
    graph->adj[dest] = newnode;
}
/*void printGraph(struct Graph* graph)
{
    int v;
    printf("The graph is\n");
    for (v=0;v<graph->num;v++)
    {
        struct node* temp = graph->adj[v];
        printf("\nneighbours of %d\n ", v);
        while(temp)
        {
            printf("%d ", temp->vertex);
            temp = temp->next;
        }
    }
    printf("\n\n");
}*/
// Print the graph
int n,i,s,d,start;
int main()
{
    printf("Enter the number of edges\n");
    scanf("%d",&n);
    struct Graph* graph = newgraph(n);
    for(i=1;i<=n;i++)
    {
        printf("Enter the source and destination vertex of edge %d\n",i);
        scanf("%d %d",&s,&d);
        addedge(graph, s, d);
    }
    printf("Enter the start vertex\n");
    scanf("%d",&start);
    printf("\n");
    //printGraph(graph);
    printf("The order of traversal\n");
    DFS(graph, start);
  return 0;
}
