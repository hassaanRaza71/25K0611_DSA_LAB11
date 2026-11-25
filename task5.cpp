#include <iostream>
#include <string>
using namespace std;
const int MAXN = 100;
const int INF = 1000000000;
void addEdge(int u, int v, int w, int adj[MAXN][MAXN], int weight[MAXN][MAXN], int deg[MAXN]) {
    adj[u][deg[u]] = v;
    weight[u][deg[u]] = w;
    deg[u]++;
}
void dijkstra(int start, int n, int adj[MAXN][MAXN], int weight[MAXN][MAXN], int deg[MAXN]) {
    int dist[MAXN];
    bool visited[MAXN];
    for (int i = 0; i < n; ++i) {
        dist[i] = INF;
        visited[i] = false;
    }
    dist[start] = 0;
    for (int count = 0; count < n; ++count) {
        int u = -1;
        int minDist = INF;
        for (int i = 0; i < n; ++i) {
            if (!visited[i] && dist[i] < minDist) {
                minDist = dist[i];
                u = i;
            }
        }
        if (u == -1) {
            break;
        }
        visited[u] = true;
        for (int i = 0; i < deg[u]; ++i) {
            int v = adj[u][i];
            int w = weight[u][i];
            if (!visited[v] && dist[u] != INF && dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
            }
        }
    }
    string label = "Shortest distances from";
    cout << label << " " << start << ":" << endl;
    for (int i = 0; i < n; ++i) {
        cout << i << ": " << dist[i] << endl;
    }
}
int main() {
    int n = 5;
    int adj[MAXN][MAXN] = {0};
    int weight[MAXN][MAXN] = {0};
    int deg[MAXN] = {0};
    addEdge(0, 1, 10, adj, weight, deg);
    addEdge(0, 2, 3, adj, weight, deg);
    addEdge(2, 1, 1, adj, weight, deg);
    addEdge(1, 3, 2, adj, weight, deg);
    addEdge(2, 3, 8, adj, weight, deg);
    addEdge(3, 4, 7, adj, weight, deg);
    dijkstra(0, n, adj, weight, deg);
    return 0;
}
