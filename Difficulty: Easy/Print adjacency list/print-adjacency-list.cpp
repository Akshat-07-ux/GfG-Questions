//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
 public:
    // Function to return the adjacency list for each vertex.
    vector<vector<int>> printGraph(int V, vector<pair<int,int>> edges) {
        // Initialize an adjacency list of size V
        vector<vector<int>> adjList(V);
        
        // Traverse the list of edges
        for (auto edge : edges) {
            int u = edge.first;
            int v = edge.second;
            
            // Add the edge to both u's and v's list (since the graph is undirected)
            adjList[u].push_back(v);
            adjList[v].push_back(u);
        }
        
        // Return the adjacency list
        return adjList;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;
        vector<pair<int,int>>edges;
        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            edges.push_back({u,v});
        }
        Solution obj;
        vector<vector<int>> adj = obj.printGraph(V, edges);
        for(int i=0;i<V;i++)
        {
            sort(adj[i].begin(),adj[i].end());
            for(auto it:adj[i])
                cout<<it<<" ";
            cout<<endl;
        }
    }
    return 0;
}
// } Driver Code Ends