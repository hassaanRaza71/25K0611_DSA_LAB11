#include <iostream>
#include <string>
using namespace std;
const int MAXN = 100;
void addEdge(int u, int v, int adj[MAXN][MAXN], int deg[MAXN]) {
    adj[u][deg[u]++] = v;
    adj[v][deg[v]++] = u;
}
bool hasCycleDfs(int u, int parent, int adj[MAXN][MAXN], int deg[MAXN], bool visited[MAXN]) {
    visited[u] = true;
    for (int i = 0; i < deg[u]; ++i) {
        int v = adj[u][i];
        if (!visited[v]) {
            if (hasCycleDfs(v, u, adj, deg, visited)) {
                return true;
            }
        } else if (v != parent) {
            return true;
        }
    }
    return false;
}
bool hasCycle(int n, int adj[MAXN][MAXN], int deg[MAXN]) {
    bool visited[MAXN] = {false};
    for (int i = 0; i < n; ++i) {
        if (!visited[i]) {
            if (hasCycleDfs(i, -1, adj, deg, visited)) {
                return true;
            }
        }
    }
    return false;
}
int main() {
    int n = 5;
    int adj[MAXN][MAXN] = {0};
    int deg[MAXN] = {0};
    addEdge(0, 1, adj, deg);
    addEdge(1, 2, adj, deg);
    addEdge(2, 0, adj, deg);
    addEdge(1, 3, adj, deg);
    addEdge(3, 4, adj, deg);
    string result = hasCycle(n, adj, deg) ? "Cycle found" : "No cycle";
    cout << result << endl;
    return 0;
}
