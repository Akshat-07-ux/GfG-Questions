#include <bits/stdc++.h>
using namespace std;

// Helper function: BFS for Edmonds-Karp
bool bfs(vector<vector<int>>& rGraph, int s, int t, vector<int>& parent, int N) {
    vector<bool> visited(N, false);
    queue<int> q;
    q.push(s);
    visited[s] = true;
    parent[s] = -1;

    while (!q.empty()) {
        int u = q.front(); q.pop();
        for (int v = 0; v < N; ++v) {
            if (!visited[v] && rGraph[u][v] > 0) {
                q.push(v);
                parent[v] = u;
                visited[v] = true;
            }
        }
    }
    return visited[t];
}

// Helper function: DFS on residual graph
void dfs(vector<vector<int>>& rGraph, int s, vector<bool>& visited, int N) {
    visited[s] = true;
    for (int v = 0; v < N; ++v) {
        if (rGraph[s][v] > 0 && !visited[v]) {
            dfs(rGraph, v, visited, N);
        }
    }
}

// Target function: Minimum s-t Cut
vector<int> minimumCut(vector<vector<int>> &A, int S, int T, int N) {
    vector<vector<int>> rGraph = A;
    vector<int> parent(N);

    // Edmonds-Karp Algorithm to compute max flow
    while (bfs(rGraph, S, T, parent, N)) {
        int path_flow = INT_MAX;
        for (int v = T; v != S; v = parent[v]) {
            int u = parent[v];
            path_flow = min(path_flow, rGraph[u][v]);
        }
        for (int v = T; v != S; v = parent[v]) {
            int u = parent[v];
            rGraph[u][v] -= path_flow;
            rGraph[v][u] += path_flow;
        }
    }

    // Find reachable vertices from S in residual graph
    vector<bool> visited(N, false);
    dfs(rGraph, S, visited, N);

    // Collect edges from reachable to unreachable (min cut)
    vector<int> result;
    for (int u = 0; u < N; ++u) {
        for (int v = 0; v < N; ++v) {
            if (visited[u] && !visited[v] && A[u][v] > 0) {
                result.push_back(u);
                result.push_back(v);
            }
        }
    }

    if (result.empty()) return {-1};
    return result;
}
