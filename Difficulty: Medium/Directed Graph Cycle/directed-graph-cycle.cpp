//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to detect cycle in a directed graph.
    bool isCyclic(int V, vector<int> adj[]) {
        vector<bool> visited(V, false);
        vector<bool> recStack(V, false);
        
        for(int i = 0; i < V; i++) {
            if(dfs(i, adj, visited, recStack))
                return true;
        }
        
        return false;
    }

private:
    bool dfs(int v, vector<int> adj[], vector<bool>& visited, vector<bool>& recStack) {
        if(!visited[v]) {
            visited[v] = true;
            recStack[v] = true;
            
            for(int neighbor : adj[v]) {
                if(!visited[neighbor] && dfs(neighbor, adj, visited, recStack))
                    return true;
                else if(recStack[neighbor])
                    return true;
            }
        }
        recStack[v] = false;
        return false;
    }
};

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        cout << obj.isCyclic(V, adj) << "\n";
    }

    return 0;
}

// } Driver Code Ends