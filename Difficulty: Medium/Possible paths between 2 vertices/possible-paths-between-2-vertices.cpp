//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
public:
    // Function to count paths between two vertices in a directed graph.
    int countPaths(int V, vector<int> adj[], int source, int destination) {
        int pathCount = 0;
        vector<bool> visited(V, false); // To keep track of visited nodes
        
        dfs(source, destination, adj, visited, pathCount);
        return pathCount;
    }

  private:
    void dfs(int node, int destination, vector<int> adj[], vector<bool>& visited, int& pathCount) {
        // If we reach the destination, increment the path count
        if (node == destination) {
            pathCount++;
            return;
        }

        // Mark the current node as visited
        visited[node] = true;

        // Recur for all the neighbors of the current node
        for (int neighbor : adj[node]) {
            if (!visited[neighbor]) {
                dfs(neighbor, destination, adj, visited, pathCount);
            }
        }

        // Backtrack and mark the current node as unvisited
        visited[node] = false;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;
        vector<int> adj[V];
        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            // adj[v].push_back(u);
        }
        int source, destination;
        cin >> source >> destination;
        Solution obj;
        cout << obj.countPaths(V, adj, source, destination) << endl;
    
cout << "~" << "\n";
}
    return 0;
}
// } Driver Code Ends