//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution {
 public:
    void dfs(int u, int parent, vector<int> adj[], vector<bool>& visited, vector<int>& disc, vector<int>& low, vector<bool>& isArticulation, int& timer) {
        visited[u] = true;
        disc[u] = low[u] = timer++;
        int children = 0; // Count of children in the DFS tree

        for (int v : adj[u]) {
            if (!visited[v]) { // If v is not visited, it’s a child
                children++;
                dfs(v, u, adj, visited, disc, low, isArticulation, timer);

                // Update the low value of u for parent function calls
                low[u] = min(low[u], low[v]);

                // Articulation point case 1: u is the root of DFS tree and has two or more children
                if (parent == -1 && children > 1) {
                    isArticulation[u] = true;
                }

                // Articulation point case 2: u is not the root and low[v] >= disc[u]
                if (parent != -1 && low[v] >= disc[u]) {
                    isArticulation[u] = true;
                }
            } else if (v != parent) { // Update low[u] for back edge
                low[u] = min(low[u], disc[v]);
            }
        }
    }

    vector<int> articulationPoints(int V, vector<int> adj[]) {
        vector<bool> visited(V, false);
        vector<int> disc(V, -1), low(V, -1);
        vector<bool> isArticulation(V, false);
        int timer = 0;

        // Perform DFS for each unvisited node (in case the graph is disconnected)
        for (int i = 0; i < V; i++) {
            if (!visited[i]) {
                dfs(i, -1, adj, visited, disc, low, isArticulation, timer);
            }
        }

        // Collect all articulation points
        vector<int> result;
        for (int i = 0; i < V; i++) {
            if (isArticulation[i]) {
                result.push_back(i);
            }
        }

        // If no articulation points, return {-1}
        if (result.empty()) {
            return {-1};
        }

        return result;
    }
};

//{ Driver Code Starts.

int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int V, E;
		cin >> V >> E;
		vector<int>adj[V];
		for(int i = 0; i < E; i++){
			int u, v;
			cin >> u >> v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		Solution obj;
		vector<int> ans = obj.articulationPoints(V, adj);
		for(auto i: ans)cout << i << " ";
		cout << "\n";
	
cout << "~" << "\n";
}
	return 0;
}
// } Driver Code Ends