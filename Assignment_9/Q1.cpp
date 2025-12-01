#include <bits/stdc++.h>
using namespace std;

void bfs(int start, vector<vector<int>>& adj) {
    int n = adj.size();
    vector<string> color(n, "WHITE");
    vector<int> dist(n, -1);
    vector<int> parent(n, -1);

    queue<int> q;

    color[start] = "GRAY";
    dist[start] = 0;
    q.push(start);

    while (!q.empty()) {
        int u = q.front();
        q.pop();

        for (int v : adj[u]) {
            if (color[v] == "WHITE") {
                color[v] = "GRAY";
                dist[v] = dist[u] + 1;
                parent[v] = u;
                q.push(v);
            }
        }

        color[u] = "BLACK";
    }

    cout << "Distances:\n";
    for (int i = 0; i < n; i++) cout << i << ": " << dist[i] << "\n";

    cout << "\nParents:\n";
    for (int i = 0; i < n; i++) cout << i << " <- " << parent[i] << "\n";
}