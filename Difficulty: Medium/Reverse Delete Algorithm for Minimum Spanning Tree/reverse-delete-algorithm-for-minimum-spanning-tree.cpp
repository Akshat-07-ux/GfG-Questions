

class Solution {
  public:
    struct Edge {
        int u, v, w;
        Edge(int u, int v, int w): u(u), v(v), w(w) {}
    };

    // DFS to check connectivity
    void dfs(int node, vector<vector<int>>& adj, vector<bool>& visited) {
        visited[node] = true;
        for (int neighbor : adj[node]) {
            if (!visited[neighbor]) {
                dfs(neighbor, adj, visited);
            }
        }
    }

    bool isConnected(int V, vector<Edge>& edges, Edge& skipEdge) {
        // Build adjacency list without skipEdge
        vector<vector<int>> adj(V);
        for (Edge& e : edges) {
            if (!(e.u == skipEdge.u && e.v == skipEdge.v && e.w == skipEdge.w) &&
                !(e.u == skipEdge.v && e.v == skipEdge.u && e.w == skipEdge.w)) {
                adj[e.u].push_back(e.v);
                adj[e.v].push_back(e.u);
            }
        }

        vector<bool> visited(V, false);
        dfs(0, adj, visited);  // start DFS from node 0

        // Check if all nodes were visited
        for (bool v : visited) {
            if (!v) return false;
        }
        return true;
    }

    int RevDelMST(int Arr[], int V, int E) {
        vector<Edge> edges;
        int totalWeight = 0;

        // Step 1: Build edge list and compute total weight
        for (int i = 0; i < 3 * E; i += 3) {
            int u = Arr[i];
            int v = Arr[i + 1];
            int w = Arr[i + 2];
            edges.push_back(Edge(u, v, w));
            totalWeight += w;
        }

        // Step 2: Sort edges in decreasing order of weight
        sort(edges.begin(), edges.end(), [](Edge& a, Edge& b) {
            return a.w > b.w;
        });

        // Step 3: Try removing edges if graph remains connected
        for (int i = 0; i < edges.size(); ++i) {
            if (isConnected(V, edges, edges[i])) {
                totalWeight -= edges[i].w;
                edges.erase(edges.begin() + i);
                i--;  // adjust index after removal
            }
        }

        return totalWeight;
    }
};