//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    bool bfsCheck(int src, vector<int> adj[], vector<int>& color) {
        queue<int> q;
        q.push(src);
        color[src] = 0; // Assign the first color (0) to the source vertex
        
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            
            // Traverse all adjacent vertices of the current node
            for (auto neighbor : adj[node]) {
                // If the adjacent node is not colored, assign it the opposite color
                if (color[neighbor] == -1) {
                    color[neighbor] = 1 - color[node];
                    q.push(neighbor);
                } 
                // If the adjacent node is already colored and has the same color, the graph is not bipartite
                else if (color[neighbor] == color[node]) {
                    return false;
                }
            }
        }
        return true;
    }
    
    bool isBipartite(int V, vector<int> adj[]){
        // Create a color array to store colors of vertices, initialize to -1 (uncolored)
        vector<int> color(V, -1);
        
        // Check for every vertex because the graph could be disconnected
        for (int i = 0; i < V; i++) {
            // If the vertex is uncolored, perform a BFS to check bipartiteness
            if (color[i] == -1) {
                if (!bfsCheck(i, adj, color)) {
                    return false;
                }
            }
        }
        
        return true; // If no conflicts were found, the graph is bipartite
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
		bool ans = obj.isBipartite(V, adj);    
		if(ans)cout << "1\n";
		else cout << "0\n";  
	}
	return 0;
}
// } Driver Code Ends