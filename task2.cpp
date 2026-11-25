#include <iostream>
#include <string>
using namespace std;

const int MAXN = 100;

void dfs(int u, int adj[MAXN][MAXN], int deg[MAXN], bool visited[MAXN]) {
    visited[u] = true;
    cout << u << " ";
    for (int i = 0; i < deg[u]; ++i) {
        int v = adj[u][i];
        if (!visited[v]) {
            dfs(v, adj, deg, visited);
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
    bool visited[MAXN] = {false};

    addEdge(0, 1, adj, deg);
    addEdge(0, 2, adj, deg);
    addEdge(1, 3, adj, deg);
    addEdge(1, 4, adj, deg);

    string label = "DFS:";
    cout << label << " ";
    dfs(0, adj, deg, visited);

    return 0;
}
