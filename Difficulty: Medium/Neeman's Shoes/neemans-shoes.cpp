// User function Template for C++

class Solution {
    public:
    string exercise(int N, int M, vector<vector<int>> A, int src, int dest, int X) {
        // Create adjacency list
        vector<vector<pair<int, int>>> adj(N);
        for (int i = 0; i < M; ++i) {
            int u = A[i][0];
            int v = A[i][1];
            int wt = A[i][2];
            adj[u].push_back(make_pair(v, wt));
            adj[v].push_back(make_pair(u, wt)); // bidirectional
        }

        // Dijkstra's algorithm
        vector<long long> dist(N, 1e18);
        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;
        
        dist[src] = 0;
        pq.push(make_pair(0, src));
        
        while (!pq.empty()) {
            pair<long long, int> p = pq.top();
            pq.pop();
            long long d = p.first;
            int node = p.second;
            
            if (d > dist[node]) continue;
            
            for (int i = 0; i < adj[node].size(); ++i) {
                int nbr = adj[node][i].first;
                int wt = adj[node][i].second;
                
                if (dist[nbr] > d + wt) {
                    dist[nbr] = d + wt;
                    pq.push(make_pair(dist[nbr], nbr));
                }
            }
        }
        
        if (dist[dest] <= X)
            return "Neeman's Cotton Classics";
        else
            return "Neeman's Wool Joggers";
    }
};