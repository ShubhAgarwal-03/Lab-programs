#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

int adj[MAX][MAX];
int visited[MAX];
int stack[MAX];
int top = -1;

void dfs(int v, int n)
{
    visited[v] = 1;
    for (int i = 0; i < n; i++) 
    {
        if (adj[v][i] && !visited[i]) 
        {
            dfs(i, n);
        }
    }
    stack[++top] = v;
}

void topologicalSortDFS(int n) 
{
    memset(visited, 0, sizeof(visited));
    top = -1;

    for (int i = 0; i < n; i++) 
    {
        if (!visited[i]) 
        {
            dfs(i, n);
        }
    }

    printf("Topological order using DFS:\n");
    for (int i = top; i >= 0; i--) 
    {
        printf("%d ", stack[i] + 1);  // convert to 1-based
    }
    printf("\n");
}

void topologicalSortSourceRemoval(int n) 
{
    int in_degree[MAX] = {0};

    // Calculate in-degrees
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            if (adj[i][j])
                in_degree[j]++;

    int queue[MAX], front = 0, rear = 0;

    // Enqueue all vertices with in-degree 0
    for (int i = 0; i < n; i++) 
    {
        if (in_degree[i] == 0)
            queue[rear++] = i;
    }

    printf("Topological order using Source Removal:\n");
    while (front < rear) 
    {
        // Always dequeue the smallest available node for consistent order
        // Sort the queue segment
        for (int i = front; i < rear - 1; i++) 
        {
            for (int j = i + 1; j < rear; j++) 
            {
                if (queue[i] > queue[j]) 
                {
                    int temp = queue[i];
                    queue[i] = queue[j];
                    queue[j] = temp;
                }
            }
        }

        int u = queue[front++];
        printf("%d ", u + 1);

        for (int v = 0; v < n; v++) 
        {
            if (adj[u][v]) 
            {
                in_degree[v]--;
                if (in_degree[v] == 0)
                    queue[rear++] = v;
            }
        }
    }
    printf("\n");
}

int main() 
{
    int n;
    scanf("%d", &n);

    // Input adjacency matrix
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &adj[i][j]);
        }
    }

    topologicalSortDFS(n);
    topologicalSortSourceRemoval(n);

    return 0;
}
