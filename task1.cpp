#include <iostream>
#include <string>
using namespace std;
const int MAXN = 100;
void addEdge(int u, int v, int adj[MAXN][MAXN], int deg[MAXN], int inDegree[MAXN]) {
    adj[u][deg[u]++] = v;
    inDegree[v]++;
}
void kahnSort(int n, int adj[MAXN][MAXN], int deg[MAXN], int inDegree[MAXN]) {
    int q[MAXN];
    int front = 0, rear = 0;
    int topo[MAXN];
    int count = 0;
    for (int i = 0; i < n; ++i) {
        if (inDegree[i] == 0) {
            q[rear++] = i;
        }
    }
    while (front < rear) {
        int u = q[front++];
        topo[count++] = u;
        for (int i = 0; i < deg[u]; ++i) {
            int v = adj[u][i];
            inDegree[v]--;
            if (inDegree[v] == 0) {
                q[rear++] = v;
            }
        }
    }
    if (count != n) {
        string msg = "Cycle detected, no topological sort";
        cout << msg << endl;
        return;
    }
    string label = "Topological Sort:";
    cout << label;
    for (int i = 0; i < count; ++i) {
        cout << " " << topo[i];
    }
    cout << endl;
}
int main() {
    int n = 6;
    int adj[MAXN][MAXN] = {0};
    int deg[MAXN] = {0};
    int inDegree[MAXN] = {0};
    addEdge(5, 2, adj, deg, inDegree);
    addEdge(5, 0, adj, deg, inDegree);
    addEdge(4, 0, adj, deg, inDegree);
    addEdge(4, 1, adj, deg, inDegree);
    addEdge(2, 3, adj, deg, inDegree);
    addEdge(3, 1, adj, deg, inDegree);
    kahnSort(n, adj, deg, inDegree);
    return 0;
}
