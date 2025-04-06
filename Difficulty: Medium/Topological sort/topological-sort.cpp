//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
public:
    vector<int> topoSort(int V, vector<vector<int>>& edges) {
        // Create adjacency list
        vector<vector<int>> adj(V);
        for (auto &edge : edges) {
            adj[edge[0]].push_back(edge[1]);
        }
        
        // Compute indegree of each vertex
        vector<int> indegree(V, 0);
        for (int u = 0; u < V; ++u) {
            for (int v : adj[u]) {
                indegree[v]++;
            }
        }

        // Queue for BFS
        queue<int> q;
        // Push all nodes with indegree 0
        for (int i = 0; i < V; ++i) {
            if (indegree[i] == 0) q.push(i);
        }

        vector<int> topoOrder;

        while (!q.empty()) {
            int node = q.front();
            q.pop();
            topoOrder.push_back(node);

            for (int neighbor : adj[node]) {
                indegree[neighbor]--;
                if (indegree[neighbor] == 0) q.push(neighbor);
            }
        }

        // Optional: check if topological sort includes all nodes
        // (i.e., to ensure it's a valid DAG with no cycle)
        if (topoOrder.size() != V) {
            return {}; // Not a DAG, return empty list
        }

        return topoOrder;
    }
};


//{ Driver Code Starts.

int check(int V, vector<int> &res, vector<vector<int>> adj) {

    if (V != res.size())
        return 0;

    vector<int> map(V, -1);
    for (int i = 0; i < V; i++) {
        map[res[i]] = i;
    }
    for (int i = 0; i < V; i++) {
        for (int v : adj[i]) {
            if (map[i] > map[v])
                return 0;
        }
    }
    return 1;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        int V, E;
        cin >> V >> E;

        vector<vector<int>> adj(V);
        vector<vector<int>> edges;

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            edges.push_back({u, v});
        }

        Solution obj;
        vector<int> res = obj.topoSort(V, edges);
        bool ans = check(V, res, adj);
        if (ans)
            cout << "true\n";
        else
            cout << "false\n";
        cout << "~"
             << "\n";
    }

    return 0;
}
// } Driver Code Ends