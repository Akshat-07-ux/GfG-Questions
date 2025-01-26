//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
public:
    // Function to find the level of node X.
    int nodeLevel(int V, vector<int> adj[], int X) {
        if (X >= V) return -1; // If the target node X is outside the valid range

        // Perform BFS starting from node 0
        vector<bool> visited(V, false);
        queue<pair<int, int>> q; // Pair of (node, level)

        q.push({0, 0}); // Start BFS from node 0 at level 0
        visited[0] = true;

        while (!q.empty()) {
            int node = q.front().first;
            int level = q.front().second;
            q.pop();

            if (node == X) {
                return level; // If we reach the target node X, return its level
            }

            for (int neighbor : adj[node]) {
                if (!visited[neighbor]) {
                    visited[neighbor] = true;
                    q.push({neighbor, level + 1}); // Add the neighbor to the queue with incremented level
                }
            }
        }

        return -1; // If we cannot reach node X
    }
};

//{ Driver Code Starts.


int main()
{
    
    int t;
    cin >> t;
    while(t--)
    {
    	int V, E, X;
    	cin >> V >> E;

    	vector<int> adj[V];

    	for(int i = 0; i < E; i++)
    	{
    		int u, v;
    		cin >> u >> v;
    		adj[u].push_back(v);
    		adj[v].push_back(u);
    	}
    	cin>>X;

    	Solution obj;
    	cout << obj.nodeLevel(V, adj, X) << "\n";
    
cout << "~" << "\n";
}

    return 0;
}


// } Driver Code Ends