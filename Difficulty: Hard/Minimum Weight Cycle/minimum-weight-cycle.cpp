//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
public:
    int findMinCycle(int V, vector<vector<int>>& edges) {
        // Create adjacency list representation of the graph
        vector<vector<pair<int, int>>> adj(V);
        for (auto& edge : edges) {
            int u = edge[0], v = edge[1], w = edge[2];
            adj[u].push_back({v, w});
            adj[v].push_back({u, w});
        }
        
        int minCycle = INT_MAX;
        
        // Try removing each edge and find shortest path between its endpoints
        for (auto& edge : edges) {
            int u = edge[0], v = edge[1], w = edge[2];
            
            // Find shortest path from u to v without this edge
            vector<int> dist(V, INT_MAX);
            priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
            pq.push({0, u});
            dist[u] = 0;
            
            while (!pq.empty()) {
                int currDist = pq.top().first;
                int node = pq.top().second;
                pq.pop();
                
                if (currDist > dist[node]) continue;
                
                for (auto& neighbor : adj[node]) {
                    int nextNode = neighbor.first;
                    int edgeWeight = neighbor.second;
                    
                    // Skip the edge we're currently considering to be removed
                    if ((node == u && nextNode == v) || (node == v && nextNode == u)) {
                        continue;
                    }
                    
                    if (dist[nextNode] > dist[node] + edgeWeight) {
                        dist[nextNode] = dist[node] + edgeWeight;
                        pq.push({dist[nextNode], nextNode});
                    }
                }
            }
            
            // If there's a path from u to v, then adding this edge creates a cycle
            if (dist[v] != INT_MAX) {
                minCycle = min(minCycle, dist[v] + w);
            }
        }
        
        // If no cycle found, return -1
        return minCycle == INT_MAX ? -1 : minCycle;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> edges;
        int i = 0;
        while (i++ < E) {
            int u, v, w;
            cin >> u >> v >> w;
            edges.push_back({u, v, w});
            edges.push_back({v, u, w});
        }

        Solution obj;
        int res = obj.findMinCycle(V, edges);

        cout << res << endl;
    }

    return 0;
}
// } Driver Code Ends