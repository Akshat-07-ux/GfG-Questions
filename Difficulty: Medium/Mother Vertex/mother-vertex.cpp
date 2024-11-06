//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution 
{
public:
    // Helper function to perform DFS and mark visited vertices
    void dfs(int v, vector<int> adj[], vector<bool>& visited) {
        visited[v] = true;
        for (int neighbor : adj[v]) {
            if (!visited[neighbor]) {
                dfs(neighbor, adj, visited);
            }
        }
    }
    
    // Function to find a Mother Vertex in the Graph.
    int findMotherVertex(int V, vector<int> adj[]) {
        vector<bool> visited(V, false);
        int lastFinishedVertex = 0;

        // First DFS to find the last finished vertex
        for (int i = 0; i < V; i++) {
            if (!visited[i]) {
                dfs(i, adj, visited);
                lastFinishedVertex = i;
            }
        }

        // Reset visited array for the second DFS
        fill(visited.begin(), visited.end(), false);
        
        // Second DFS from the last finished vertex to check if it can reach all vertices
        dfs(lastFinishedVertex, adj, visited);
        
        // Check if all vertices were visited
        for (int i = 0; i < V; i++) {
            if (!visited[i]) {
                return -1;  // If any vertex is not reachable, there's no Mother Vertex
            }
        }
        
        return lastFinishedVertex;  // Return the Mother Vertex
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
		}
		Solution obj;
		int ans = obj.findMotherVertex(V, adj);
		cout << ans <<"\n";
	
cout << "~" << "\n";
}
	return 0;
}
// } Driver Code Ends