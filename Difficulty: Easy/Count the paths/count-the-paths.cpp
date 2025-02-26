//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
public:
    int countPaths(int node, int destination, vector<vector<int>> &adj) {
        if (node == destination) return 1; // Reached destination, count this path
        
        int count = 0;
        for (int neighbor : adj[node]) {
            count += countPaths(neighbor, destination, adj); // Recursively explore paths
        }
        return count;
    }

    int possible_paths(vector<vector<int>> &edges, int n, int start, int destination) {
        vector<vector<int>> adj(n); // Adjacency list representation

        // Build graph adjacency list
        for (auto &edge : edges) {
            adj[edge[0]].push_back(edge[1]);
        }

        // Perform DFS from start to count paths
        return countPaths(start, destination, adj);
    }
};


//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, m, s, d;
        cin >> n >> m >> s >> d;
        vector<vector<int>> edges;
        for (int i = 0; i < m; i++) {
            int u, v;
            cin >> u >> v;
            edges.push_back({u, v});
        }
        Solution obj;
        int ans = obj.possible_paths(edges, n, s, d);
        cout << ans << "\n";

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends