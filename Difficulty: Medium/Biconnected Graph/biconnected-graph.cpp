//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
   public:
    bool isArticulation(int u, int parent, vector<int> adj[], vector<bool>& visited,
                        vector<int>& disc, vector<int>& low, int& time, int n) {
        visited[u] = true;
        disc[u] = low[u] = ++time;
        int children = 0;

        for (int v : adj[u]) {
            if (!visited[v]) {
                children++;
                if (isArticulation(v, u, adj, visited, disc, low, time, n))
                    return true;

                low[u] = min(low[u], low[v]);

                // articulation point condition
                if (parent != -1 && low[v] >= disc[u])
                    return true;
            }
            else if (v != parent) {
                low[u] = min(low[u], disc[v]);
            }
        }

        // root node special case
        if (parent == -1 && children > 1)
            return true;

        return false;
    }

    int biGraph(int arr[], int n, int e) {
        vector<int> adj[n];
        for (int i = 0; i < 2 * e; i += 2) {
            int u = arr[i];
            int v = arr[i + 1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<bool> visited(n, false);
        vector<int> disc(n, -1), low(n, -1);
        int time = 0;

        // start DFS from node 0
        if (isArticulation(0, -1, adj, visited, disc, low, time, n))
            return 0;

        // check if all nodes are visited (connected check)
        for (int i = 0; i < n; ++i) {
            if (!visited[i])
                return 0;
        }

        return 1; // biconnected
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n,e;
        cin>>n>>e;
        
        int arr[2*e];
        for(int i=0; i<2*e; i++)
            cin>>arr[i];

        Solution ob;
        cout << ob.biGraph(arr,n,e) << endl;
    
cout << "~" << "\n";
}
    return 0;
}
// } Driver Code Ends