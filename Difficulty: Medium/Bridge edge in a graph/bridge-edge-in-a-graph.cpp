//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    void dfs(int node, vector<int> adj[], vector<bool>& visited) {
        visited[node] = true;
        for (int neighbor : adj[node]) {
            if (!visited[neighbor]) {
                dfs(neighbor, adj, visited);
            }
        }
    }
    
    // Function to find if the given edge is a bridge in graph.
    int isBridge(int V, vector<int> adj[], int c, int d) {
        vector<bool> visited(V, false);
        
        // Perform DFS from any vertex before removing the edge
        dfs(c, adj, visited);
        
        // If d is not reachable from c before removing the edge, return 0
        if (!visited[d]) return 0;
        
        // Remove the edge (c, d)
        adj[c].erase(remove(adj[c].begin(), adj[c].end(), d), adj[c].end());
        adj[d].erase(remove(adj[d].begin(), adj[d].end(), c), adj[d].end());
        
        // Reset visited array and perform DFS again
        fill(visited.begin(), visited.end(), false);
        dfs(c, adj, visited);
        
        // Restore the edge
        adj[c].push_back(d);
        adj[d].push_back(c);
        
        // If d is not reachable from c after removing the edge, it's a bridge
        return (!visited[d]) ? 1 : 0;
    }
};

//{ Driver Code Starts.


int main()
{
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<int> adj[V];
        int i=0;
        while (i++<E) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back (v);
            adj[v].push_back (u);
        }
        
        int c,d;
        cin>>c>>d;
        
        Solution obj;
    	cout << obj.isBridge(V, adj, c, d) << "\n";
    
cout << "~" << "\n";
}

    return 0;
}


// } Driver Code Ends