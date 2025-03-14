//{ Driver Code Starts

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution {
public:
    void dfs(int node, vector<vector<int>>& paths, vector<bool>& visited) {
        visited[node] = true;
        int n = paths.size();
        for (int i = 0; i < n; i++) {
            if (paths[node][i] == 1 && !visited[i]) {
                dfs(i, paths, visited);
            }
        }
    }

    int isPossible(vector<vector<int>> paths) {
        int n = paths.size();
        
        // Check if all vertices have even degree
        for (int i = 0; i < n; i++) {
            int degree = accumulate(paths[i].begin(), paths[i].end(), 0);
            if (degree % 2 != 0) return 0;  // Odd degree, no Eulerian circuit possible
        }

        // Check connectivity using DFS
        vector<bool> visited(n, false);
        int startNode = -1;

        // Find a vertex with at least one edge to start DFS
        for (int i = 0; i < n; i++) {
            if (accumulate(paths[i].begin(), paths[i].end(), 0) > 0) {
                startNode = i;
                break;
            }
        }

        if (startNode == -1) return 1; // No edges in the graph, trivial Eulerian circuit

        dfs(startNode, paths, visited);

        // Check if all vertices with edges were visited
        for (int i = 0; i < n; i++) {
            if (accumulate(paths[i].begin(), paths[i].end(), 0) > 0 && !visited[i]) {
                return 0; // Disconnected graph
            }
        }

        return 1; // Eulerian circuit exists
    }
};


//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<vector<int>>paths(n, vector<int>(n, 0));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++)
				cin >> paths[i][j];
		}
		Solution obj;
		int ans = obj.isPossible(paths);
		cout << ans <<"\n";
	
cout << "~" << "\n";
}
	return 0;
}
// } Driver Code Ends