//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    void dfs(int node, vector<vector<int>>& adj, vector<bool>& visited) {
        visited[node] = true;
        for (int j = 0; j < adj.size(); j++) {
            if (adj[node][j] == 1 && !visited[j]) {
                dfs(j, adj, visited);
            }
        }
    }

    int numProvinces(vector<vector<int>> adj, int V) {
        vector<bool> visited(V, false);
        int provinces = 0;

        for (int i = 0; i < V; i++) {
            if (!visited[i]) {
                // If the node is not visited, it's a new province
                dfs(i, adj, visited);
                provinces++;
            }
        }
        return provinces;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int V,x;
        cin>>V;
        
        vector<vector<int>> adj;
        
        for(int i=0; i<V; i++)
        {
            vector<int> temp;
            for(int j=0; j<V; j++)
            {
                cin>>x;
                temp.push_back(x);
            }
            adj.push_back(temp);
        }
        

        Solution ob;
        cout << ob.numProvinces(adj,V) << endl;
    }
    return 0;
}
// } Driver Code Ends