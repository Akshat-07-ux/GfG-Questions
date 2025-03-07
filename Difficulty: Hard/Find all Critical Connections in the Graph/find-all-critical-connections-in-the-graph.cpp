//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

// User function Template for C++

class Solution {
 public:
    vector<vector<int>> criticalConnections(int v, vector<vector<int>>& edges) {
        vector<vector<int>> adj(v);
        for (auto& edge : edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }

        vector<int> disc(v, -1), low(v, -1);
        vector<vector<int>> result;
        int time = 0;

        function<void(int, int)> dfs = [&](int u, int parent) {
            disc[u] = low[u] = time++;
            for (int v : adj[u]) {
                if (v == parent) continue; // Ignore the edge to parent
                if (disc[v] == -1) { // If v is not visited
                    dfs(v, u);
                    low[u] = min(low[u], low[v]);
                    if (low[v] > disc[u]) {
                        result.push_back({u, v});
                    }
                } else {
                    low[u] = min(low[u], disc[v]);
                }
            }
        };

        for (int i = 0; i < v; i++) {
            if (disc[i] == -1) {
                dfs(i, -1);
            }
        }

        return result;
    }
};


//{ Driver Code Starts.

int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int v, e;
        cin >> v >> e;
        vector<vector<int>> edges;
        for (int i = 0; i < e; i++) {
            int u, v;
            cin >> u >> v;
            edges.push_back({u, v});
        }
        Solution obj;
        vector<vector<int>> ans = obj.criticalConnections(v, edges);
        for (int i = 0; i < ans.size(); i++) {
            if (ans[i][0] > ans[i][1])
                swap(ans[i][0], ans[i][1]);
        }

        sort(ans.begin(), ans.end());
        for (int i = 0; i < ans.size(); i++)
            cout << ans[i][0] << " " << ans[i][1] << endl;
        cout << "~\n";
    }
    return 0;
}
// } Driver Code Ends