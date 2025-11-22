// 6. Write a program to implement Dijkstra's shortest path algorithm.

#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;

void dijkstra(int n, vector<pair<int, int>> adj[], int src) {
    vector<int> dist(n, INT_MAX);
    dist[src] = 0;

    // Min-heap : {distance, node}
    priority_queue<pair<int, int>,
                   vector<pair<int, int>>,
                   greater<pair<int, int>>> pq;

    pq.push({0, src});

    while (!pq.empty()) {
        int d = pq.top().first;
        int u = pq.top().second;
        pq.pop();

        // Skip outdated entry
        if (d > dist[u])
            continue;

        // Relax edges
        for (auto edge : adj[u]) {
            int v = edge.first;
            int w = edge.second;

            if (dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                pq.push({dist[v], v});
            }
        }
    }

    cout << "\nShortest distances from node " << src << ":\n";
    for (int i = 0; i < n; i++) {
        if (dist[i] == INT_MAX)
            cout << "Node " << i << " : Unreachable\n";
        else
            cout << "Node " << i << " : " << dist[i] << "\n";
    }
}

int main() {
    int n, m;
    cout << "Enter number of vertices: ";
    cin >> n;

    cout << "Enter number of edges: ";
    cin >> m;

    vector<pair<int, int>> adj[n];

    cout << "Enter edges (u v weight):\n";
    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});  // directed edge
    }

    int src;
    cout << "Enter source node: ";
    cin >> src;

    dijkstra(n, adj, src);

    return 0;
}
