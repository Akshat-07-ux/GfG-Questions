//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

// User Function Template
class Solution {
  public:
    vector<int> dijkstra(int V, vector<vector<int>> &edges, int src) {
        // Step 1: Create an adjacency list
        vector<pair<int, int>> adj[V];
        for (auto &edge : edges) {
            int u = edge[0], v = edge[1], w = edge[2];
            adj[u].push_back({v, w});
            adj[v].push_back({u, w}); // since graph is undirected
        }

        // Step 2: Min-heap for storing (distance, node)
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

        // Step 3: Distance vector, initialized to INF
        vector<int> dist(V, INT_MAX);
        dist[src] = 0;
        pq.push({0, src});

        // Step 4: Dijkstra's algorithm core loop
        while (!pq.empty()) {
            int d = pq.top().first;
            int node = pq.top().second;
            pq.pop();

            for (auto &nbr : adj[node]) {
                int nextNode = nbr.first;
                int weight = nbr.second;

                if (d + weight < dist[nextNode]) {
                    dist[nextNode] = d + weight;
                    pq.push({dist[nextNode], nextNode});
                }
            }
        }

        return dist;
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
        int src;
        cin >> src;
        cin.ignore();

        Solution obj;
        vector<int> res = obj.dijkstra(V, edges, src);

        for (int i = 0; i < V; i++)
            cout << res[i] << " ";
        cout << endl;

        cout << "~"
             << "\n";
    }

    return 0;
}
// } Driver Code Ends