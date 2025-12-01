#include <bits/stdc++.h>
using namespace std;

class Graph {
public:
    int V;
    vector<vector<pair<int,int>>> adj; // node -> {neighbor, weight}

    Graph(int v) {
        V = v;
        adj.resize(V);
    }

    void addEdge(int u, int v, int w) {
        adj[u].push_back({v, w});
        adj[v].push_back({u, w}); // remove if directed
    }

    void dijkstra(int src) {
        vector<int> dist(V, INT_MAX);
        dist[src] = 0;

        // min-heap : {distance, node}
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        pq.push({0, src});

        while (!pq.empty()) {
            int d = pq.top().first;
            int node = pq.top().second;
            pq.pop();

            // Skip outdated entries
            if (d != dist[node]) continue;

            for (auto &edge : adj[node]) {
                int next = edge.first;
                int wt = edge.second;

                if (dist[node] + wt < dist[next]) {
                    dist[next] = dist[node] + wt;
                    pq.push({dist[next], next});
                }
            }
        }

        cout << "\nShortest distances from source " << src << ":\n";
        for (int i = 0; i < V; i++)
            cout << "Node " << i << " -> " << dist[i] << "\n";
    }
};