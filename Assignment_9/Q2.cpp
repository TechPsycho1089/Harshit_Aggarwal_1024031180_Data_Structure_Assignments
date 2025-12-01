#include <bits/stdc++.h>
#include<vector>
using namespace std;

void dfs(int start, vector<vector<int>>& adj) {
    int n = adj.size();            
    vector<int> visited(n, 0);
    stack<int> st;

    st.push(start);
    while (!st.empty()) {
        int u = st.top(); st.pop();
        if (visited[u]) continue;
        cout << "visiting: " << u << "\n";
        visited[u] = 1;
       
        // push neighbours in reverse so first neighbour is visited first
        for (int i = (int)adj[u].size() - 1; i >= 0; --i) {
            int v = adj[u][i];
            if (!visited[v]) st.push(v);
        }
    }
}