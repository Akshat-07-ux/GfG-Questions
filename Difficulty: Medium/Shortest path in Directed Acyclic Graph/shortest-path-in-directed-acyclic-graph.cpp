//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
public:
    // Function to perform topological sort using DFS
    void topologicalSort(int node, vector<pair<int, int>> adj[], vector<bool> &visited, stack<int> &topoStack) {
        visited[node] = true;
        
        // Visit all adjacent nodes
        for (auto it : adj[node]) {
            int adjNode = it.first;
            if (!visited[adjNode]) {
                topologicalSort(adjNode, adj, visited, topoStack);
            }
        }
        
        // Push the current node to the stack after all its neighbors are visited
        topoStack.push(node);
    }

    vector<int> shortestPath(int N, int M, vector<vector<int>>& edges) {
        // Create an adjacency list for the graph
        vector<pair<int, int>> adj[N];
        for (int i = 0; i < M; i++) {
            int u = edges[i][0];
            int v = edges[i][1];
            int weight = edges[i][2];
            adj[u].push_back({v, weight});
        }
        
        // Step 1: Perform topological sort
        vector<bool> visited(N, false);
        stack<int> topoStack;
        
        // Run topological sort for all nodes
        for (int i = 0; i < N; i++) {
            if (!visited[i]) {
                topologicalSort(i, adj, visited, topoStack);
            }
        }
        
        // Step 2: Initialize distances from the source (0) to all nodes as infinity
        vector<int> dist(N, INT_MAX);
        dist[0] = 0;  // Distance to the source is 0
        
        // Step 3: Process nodes in topological order and relax the edges
        while (!topoStack.empty()) {
            int node = topoStack.top();
            topoStack.pop();
            
            // If the current node has been reached (dist[node] != INT_MAX)
            if (dist[node] != INT_MAX) {
                for (auto it : adj[node]) {
                    int adjNode = it.first;
                    int weight = it.second;
                    
                    // Relax the edge
                    if (dist[node] + weight < dist[adjNode]) {
                        dist[adjNode] = dist[node] + weight;
                    }
                }
            }
        }
        
        // Step 4: Replace all unreachable nodes' distances with -1
        for (int i = 0; i < N; i++) {
            if (dist[i] == INT_MAX) {
                dist[i] = -1;
            }
        }
        
        return dist;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> edges;
        for(int i=0; i<m; ++i){
            vector<int> temp;
            for(int j=0; j<3; ++j){
                int x; cin>>x;
                temp.push_back(x);
            }
            edges.push_back(temp);
        }
        Solution obj;
        vector<int> res = obj.shortestPath(n, m, edges);
        for (auto x : res) {
            cout << x << " ";
        }
        cout << "\n";
    }
}

// } Driver Code Ends