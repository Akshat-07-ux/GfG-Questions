//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    int isNegativeWeightCycle(int n, vector<vector<int>> edges) {
        // Initialize distances for all nodes
        vector<int> dist(n, INT_MAX);

        // Loop through all nodes as possible starting points
        for (int start = 0; start < n; start++) {
            if (dist[start] == INT_MAX) {
                dist[start] = 0;

                // Relax all edges (n-1) times
                for (int i = 0; i < n - 1; i++) {
                    for (auto edge : edges) {
                        int u = edge[0];
                        int v = edge[1];
                        int weight = edge[2];

                        if (dist[u] != INT_MAX && dist[u] + weight < dist[v]) {
                            dist[v] = dist[u] + weight;
                        }
                    }
                }

                // Check for negative weight cycles
                for (auto edge : edges) {
                    int u = edge[0];
                    int v = edge[1];
                    int weight = edge[2];

                    if (dist[u] != INT_MAX && dist[u] + weight < dist[v]) {
                        return 1; // Negative weight cycle detected
                    }
                }
            }
        }

        return 0; // No negative weight cycle found
    }
};


//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>edges;
		for(int i = 0; i < m; i++){
			int x, y, z;
			cin >> x >> y >> z;
			edges.push_back({x,y,z});
		}
		Solution obj;
		int ans = obj.isNegativeWeightCycle(n, edges);
		cout << ans <<"\n";
	
cout << "~" << "\n";
}
	return 0;
}
// } Driver Code Ends