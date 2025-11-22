// 5. Program to implement Prim's Minimum Spanning Tree Algorithm

#include <iostream>
#include <vector>
#include <climits>
using namespace std;

// Function to find the vertex with the minimum key value
int minKey(vector<int> &key, vector<bool> &mstSet, int n) {
    int minVal = INT_MAX, minIndex = -1;

    for (int i = 0; i < n; i++) {
        if (!mstSet[i] && key[i] < minVal) {
            minVal = key[i];
            minIndex = i;
        }
    }
    return minIndex;
}

// Prim's MST Algorithm
int spanningTree(int n, vector<vector<int>> &adj) {
    vector<int> key(n, INT_MAX);
    vector<bool> mstSet(n, false);

    key[0] = 0;  // Start from vertex 0
    int totalWeight = 0;

    for (int i = 0; i < n; i++) {
        int u = minKey(key, mstSet, n);
        mstSet[u] = true;
        totalWeight += key[u];

        for (int v = 0; v < n; v++) {
            if (adj[u][v] != 0 && !mstSet[v] && adj[u][v] < key[v]) {
                key[v] = adj[u][v];
            }
        }
    }
    return totalWeight;
}

int main() {
    int n, m;
    cout << "Enter number of vertices: ";
    cin >> n;

    cout << "Enter number of edges: ";
    cin >> m;

    vector<vector<int>> adj(n, vector<int>(n, 0));

    cout << "Enter edges (u v weight):" << endl;
    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u][v] = w;
        adj[v][u] = w; // Undirected graph
    }

    int ans = spanningTree(n, adj);
    cout << "Total weight of MST = " << ans << endl;

    return 0;
}
