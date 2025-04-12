//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

//User function Template for C++

class Solution {
public:
    // Dijkstra’s helper function
    vector<long long> dijkstra(int src, int n, vector<pair<int, int>> adj[]) {
        vector<long long> dist(n + 1, LLONG_MAX);
        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;

        dist[src] = 0;
        pq.push(make_pair(0LL, src));

        while (!pq.empty()) {
            pair<long long, int> curr = pq.top();
            pq.pop();
            long long d = curr.first;
            int u = curr.second;

            if (d > dist[u]) continue;

            for (size_t i = 0; i < adj[u].size(); ++i) {
                int v = adj[u][i].first;
                int w = adj[u][i].second;

                if (dist[v] > dist[u] + w) {
                    dist[v] = dist[u] + w;
                    pq.push(make_pair(dist[v], v));
                }
            }
        }

        return dist;
    }

    int shortestPath(int n, int m, int a, int b, vector<vector<int>> &edges) {
        vector<pair<int, int>> adj[n + 1];

        // Build graph using only straight edges
        for (int i = 0; i < m; ++i) {
            int u = edges[i][0];
            int v = edges[i][1];
            int w1 = edges[i][2];
            adj[u].push_back(make_pair(v, w1));
            adj[v].push_back(make_pair(u, w1));
        }

        // Dijkstra from a and from b
        vector<long long> distFromA = dijkstra(a, n, adj);
        vector<long long> distFromB = dijkstra(b, n, adj);

        long long ans = distFromA[b];  // initial path using only straight edges

        // Try adding one curved edge in between
        for (int i = 0; i < m; ++i) {
            int u = edges[i][0];
            int v = edges[i][1];
            int curved = edges[i][3];

            if (distFromA[u] != LLONG_MAX && distFromB[v] != LLONG_MAX) {
                ans = min(ans, distFromA[u] + curved + distFromB[v]);
            }

            if (distFromA[v] != LLONG_MAX && distFromB[u] != LLONG_MAX) {
                ans = min(ans, distFromA[v] + curved + distFromB[u]);
            }
        }

        return (ans == LLONG_MAX ? -1 : (int)ans);
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n,m,a,b;
        cin>>n>>m;
        cin>>a>>b;
        
        vector<vector<int>> edges;
        
        for(int i=0; i<m; i++)
        {
            int u,v,x,y;
            cin>>u>>v>>x>>y;
            edges.push_back({u,v,x,y});
        }

        Solution ob;
        cout << ob.shortestPath(n,m,a,b,edges) << endl;
    
cout << "~" << "\n";
}
    return 0;
}
// } Driver Code Ends