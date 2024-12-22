//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int countPaths(int n, vector<vector<int>>& roads) {
        const int MOD = 1e9 + 7;

        // Graph representation using adjacency list
        vector<vector<pair<int, int>>> graph(n);
        for (const auto& road : roads) {
            int u = road[0], v = road[1], time = road[2];
            graph[u].emplace_back(v, time);
            graph[v].emplace_back(u, time);
        }

        // Min-heap priority queue for Dijkstra's algorithm
        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<>> pq;

        // Distance and ways arrays
        vector<long long> dist(n, LLONG_MAX);
        vector<int> ways(n, 0);

        // Initialize the source node
        dist[0] = 0;
        ways[0] = 1;
        pq.emplace(0, 0);

        while (!pq.empty()) {
            pair<long long, int> curr = pq.top(); // Replace structured binding
            pq.pop();
            long long currDist = curr.first;
            int node = curr.second;

            if (currDist > dist[node]) continue;

            for (const auto& neighbor : graph[node]) {
                int nextNode = neighbor.first;
                long long time = neighbor.second;
                long long newDist = currDist + time;

                // Found a shorter path
                if (newDist < dist[nextNode]) {
                    dist[nextNode] = newDist;
                    ways[nextNode] = ways[node];
                    pq.emplace(newDist, nextNode);
                } else if (newDist == dist[nextNode]) {
                    // Found another shortest path
                    ways[nextNode] = (ways[nextNode] + ways[node]) % MOD;
                }
            }
        }

        return ways[n - 1];
    }
};

//{ Driver Code Starts.

int main() {
    int T;
    cin >> T;
    while (T--) {
        int n, m;
        cin >> n >> m;
        int u, v;

        vector<vector<int>> adj;

        for (int i = 0; i < m; ++i) {
            vector<int> temp;
            for (int j = 0; j < 3; ++j) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            adj.push_back(temp);
        }

        Solution obj;
        cout << obj.countPaths(n, adj) << "\n";
    
cout << "~" << "\n";
}

    return 0;
}
// } Driver Code Ends