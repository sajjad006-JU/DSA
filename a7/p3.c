#include <stdio.h>
#include <stdlib.h>

#define MAXV 100

typedef struct Node {
    int v;
    struct Node *next;
} Node;

typedef struct Graph {
    int V;
    Node *adj[MAXV];
} Graph;

Graph* createGraph(int V) {
    Graph *g = (Graph*)malloc(sizeof(Graph));
    g->V = V;
    for (int i = 0; i < V; i++)
        g->adj[i] = NULL;
    return g;
}

void addEdge(Graph *g, int u, int v) {
    Node *n1 = (Node*)malloc(sizeof(Node));
    n1->v = v;
    n1->next = g->adj[u];
    g->adj[u] = n1;

    Node *n2 = (Node*)malloc(sizeof(Node));
    n2->v = u;
    n2->next = g->adj[v];
    g->adj[v] = n2;
}

void bfs(Graph *g, int start, int dist[], int parent[]) {
    int queue[MAXV], front = 0, rear = 0;

    for (int i = 0; i < g->V; i++) {
        dist[i] = -1;
        parent[i] = -1;
    }

    dist[start] = 0;
    queue[rear++] = start;

    while (front < rear) {
        int u = queue[front++];

        Node *temp = g->adj[u];
        while (temp != NULL) {
            int v = temp->v;
            if (dist[v] == -1) {
                dist[v] = dist[u] + 1;
                parent[v] = u;
                queue[rear++] = v;
            }
            temp = temp->next;
        }
    }
}

int distance(Graph *g, int v1, int v2) {
    int dist[MAXV], parent[MAXV];
    bfs(g, v1, dist, parent);
    return dist[v2];
}

int connected(Graph *g, int u, int v) {
    return distance(g, u, v) != -1;
}

void dfsUtil(Graph *g, int u, int visited[], int dist[], int parent[]) {
    visited[u] = 1;

    Node *temp = g->adj[u];
    while (temp != NULL) {
        int v = temp->v;
        if (!visited[v]) {
            dist[v] = dist[u] + 1;
            parent[v] = u;
            dfsUtil(g, v, visited, dist, parent);
        }
        temp = temp->next;
    }
}

void dfs(Graph *g, int start, int dist[], int parent[]) {
    int visited[MAXV];

    for (int i = 0; i < g->V; i++) {
        visited[i] = 0;
        dist[i] = -1;
        parent[i] = -1;
    }

    dist[start] = 0;
    dfsUtil(g, start, visited, dist, parent);
}

int main() {
    Graph *g = createGraph(6);

    addEdge(g, 0, 1);
    addEdge(g, 1, 2);
    addEdge(g, 2, 3);
    addEdge(g, 3, 4);
    addEdge(g, 4, 5);

    int dist[MAXV], parent[MAXV];

    printf("BFS from vertex 0:\n");
    bfs(g, 0, dist, parent);
    for (int i = 0; i < g->V; i++)
        printf("Vertex %d: dist = %d, parent = %d\n", i, dist[i], parent[i]);

    printf("\nDistance between 0 and 5 = %d\n", distance(g, 0, 5));

    printf("\nConnected(0, 5)? %s\n", connected(g, 0, 5) ? "YES" : "NO");

    printf("\nDFS from vertex 0:\n");
    dfs(g, 0, dist, parent);
    for (int i = 0; i < g->V; i++)
        printf("Vertex %d: dist = %d, parent = %d\n", i, dist[i], parent[i]);

    return 0;
}
