

#include <stdio.h>
#include <stdlib.h>

#define MAX_V 100

typedef struct {
    int Matrix[MAX_V][MAX_V];
    int numVer;
} Graph;

void initGraph(Graph* g, int n) {
    g->numVer = n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            g->Matrix[i][j] = 0;
        }
    }
}

void addEdge(Graph* g, int src, int dest) {
    g->Matrix[src][dest] = 1;
}

void dfsUtil(Graph* g, int node, int visited[]) {
    visited[node] = 1; // Mark the current node as visited
    printf("%d ", node); // Print the current node

    // Recur for all the vertices adjacent to this vertex
    for (int i = 0; i < g->numVer; i++) {
        if (g->Matrix[node][i] == 1 && !visited[i]) {
            dfsUtil(g, i, visited);
        }
    }
}

void dfs(Graph* g, int startNode) {
    int visited[MAX_V] = {0}; // Initialize visited array
    printf("The DFS order is:\n");
    dfsUtil(g, startNode, visited);
    printf("\n");
}

void bfs(Graph* g, int startNode) {
    int visited[MAX_V] = {0}; // Initialize visited array
    int queue[MAX_V], front = 0, rear = 0;

    visited[startNode] = 1; // Mark the starting node as visited
    queue[rear++] = startNode; // Enqueue the starting node

    printf("The BFS order is:\n");
    while (front < rear) {
        int node = queue[front++]; // Dequeue a vertex
        printf("%d ", node); // Print the current node

        // Check all adjacent nodes
        for (int i = 0; i < g->numVer; i++) {
            if (g->Matrix[node][i] == 1 && !visited[i]) {
                visited[i] = 1; // Mark as visited
                queue[rear++] = i; // Enqueue the adjacent node
            }
        }
    }
    printf("\n");
}

int main() {
    Graph g;
    int n, src;

    // Read number of vertices
    scanf("%d", &n);
    initGraph(&g, n);

    // Read adjacency matrix
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &g.Matrix[i][j]);
        }
    }

    // Read starting node
    scanf("%d", &src);

    // Perform DFS and BFS
    dfs(&g, src);
    bfs(&g, src);

    return 0;
}
