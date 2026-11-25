#include <iostream>
#include <string>
using namespace std;

const int MAXN = 100;

void bfs(int start, int n, int adj[MAXN][MAXN], int deg[MAXN]) {
    bool visited[MAXN] = {false};
    int q[MAXN];
    int front = 0, rear = 0;
    
    visited[start] = true;
    q[rear++] = start;
    
    while (front < rear) {
        int u = q[front++];
        cout << u << " ";
        for (int i = 0; i < deg[u]; ++i) {
            int v = adj[u][i];
            if (!visited[v]) {
                visited[v] = true;
                q[rear++] = v;
            }
        }
    }
}

void addEdge(int u, int v, int adj[MAXN][MAXN], int deg[MAXN]) {
    adj[u][deg[u]++] = v;
    adj[v][deg[v]++] = u;
}

int main() {
    int n = 5;
    int adj[MAXN][MAXN] = {0};
    int deg[MAXN] = {0};

    addEdge(0, 1, adj, deg);
    addEdge(0, 2, adj, deg);
    addEdge(1, 3, adj, deg);
    addEdge(1, 4, adj, deg);

    string label = "BFS:";
    cout << label << " ";
    bfs(0, n, adj, deg);
    
    return 0;
}
