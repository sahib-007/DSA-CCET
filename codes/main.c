// BFS algorithm in C

#include <stdio.h>
#include <stdlib.h>
#define SIZE 40

struct queue {
  int items[SIZE];
  int front;
  int rear;
};

struct queue* newqueue();
void enqueue(struct queue* q, int);
int dequeue(struct queue* q);
void display(struct queue* q);
int empty(struct queue* q);
void print(struct queue* q);

struct node {
    int vertex;
    struct node* next;
};

struct node* createnode(int);

struct Graph {
    int numVertices;
    struct node** adj;
    int* visited;
};

// BFS algorithm
void bfs(struct Graph* graph, int startVertex, int k)
{
    int n,j=0, arr[SIZE];
    struct queue* q = newqueue();
    graph->visited[startVertex] = 1;
    enqueue(q, startVertex);
    while (!empty(q))
    {
        print(q);
        int currentVertex = dequeue(q);
        printf("\nVertex traversed is %d\n", currentVertex);
        {
            arr[j]=currentVertex;
            j++;
        }
        struct node* temp = graph->adj[currentVertex];
        while (temp)
        {
            int adjVertex = temp->vertex;
            if (graph->visited[adjVertex] == 0)
            {
                graph->visited[adjVertex] = 1;
                enqueue(q, adjVertex);
            }
            temp = temp->next;
        }
    }
    printf("The order of traversal is\n");
    for(n=0;n<j;n++)
    {
        printf("%d\n",arr[n]);
    }
}
// Creating a node
struct node* createnode(int v)
{
    struct node* newnode = malloc(sizeof(struct node));
    newnode->vertex = v;
    newnode->next = NULL;
    return newnode;
}

// Creating a graph
struct Graph* creategraph(int vertices)
{
    struct Graph* graph = malloc(sizeof(struct Graph));
    graph->numVertices = vertices;
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

// Create a queue
struct queue* newqueue()
{
    struct queue* q = malloc(sizeof(struct queue));
    q->front = -1;
    q->rear = -1;
    return q;
}
// Check if the queue is empty
int empty(struct queue* q)
{
    if (q->rear == -1)
        return 1;
    else
        return 0;
}

// Adding elements into queue
void enqueue(struct queue* q, int value)
{
    // if queue is full
    if (q->rear == SIZE - 1)
        printf("\nQueue is Full!!");
    else
    {
        //queue has space
        if (q->front == -1)
            q->front = 0;
        q->rear++;
        q->items[q->rear] = value;
    }
}
// Removing elements from queue
int dequeue(struct queue* q)
{
    int item;
    if (empty(q))
    {
        printf("Queue is empty");
        item = -1;
    }
    else
    {
        item = q->items[q->front];
        q->front++;
        if (q->front > q->rear)
        {
            q->front = q->rear = -1;
        }
  }
  return item;
}

// Print the queue
void print(struct queue* q)
{
    int i = q->front;
    if (empty(q))
    {
        printf("Queue is empty");
    }
    else
    {
        printf("\nQueue contains \n");
        for (i = q->front; i < q->rear + 1; i++)
        {
            printf("%d ", q->items[i]);
        }
    }
}
int a,b,c,d=0,e,j;
int main()
{
    printf("Enter the number of edges in the graph\n");
    scanf("%d",&a);
    struct Graph* graph = creategraph(a);
    for(d=0;d<a;d++)
    {
        printf ("Enter vertices which are connect edge %d\n",d+1);
        scanf("%d  %d",&b,&c);
        addedge(graph, b, c);
    }
    printf("Enter the start vertex\n");//Enter the vertex from which the traversal is to be started
    scanf("%d",&e);
    bfs(graph, e, a);
    return 0;
}
