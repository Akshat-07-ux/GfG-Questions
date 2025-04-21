//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

// User function Template for C++

class Solution {
  public:
    long long int luckyPermutations(int N, int M, vector<int> arr,
                                    vector<vector<int>> graph) {
        vector<vector<int>> adj(N + 1, vector<int>(N + 1, 0));

        // Build adjacency matrix
        for (auto& edge : graph) {
            int u = edge[0], v = edge[1];
            adj[u][v] = 1;
            adj[v][u] = 1;
        }

        int sz = arr.size();
        vector<vector<long long>> dp(1 << sz, vector<long long>(sz, 0));

        // Base case: single elements
        for (int i = 0; i < sz; ++i) {
            dp[1 << i][i] = 1;
        }

        for (int mask = 1; mask < (1 << sz); ++mask) {
            for (int last = 0; last < sz; ++last) {
                if (!(mask & (1 << last))) continue;

                for (int next = 0; next < sz; ++next) {
                    if (mask & (1 << next)) continue; // already used

                    if (arr[last] != arr[next] && adj[arr[last]][arr[next]]) {
                        dp[mask | (1 << next)][next] += dp[mask][last];
                    }
                }
            }
        }

        long long result = 0;
        int full_mask = (1 << sz) - 1;
        for (int i = 0; i < sz; ++i) {
            result += dp[full_mask][i];
        }

        return result;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, M;
        cin >> N >> M;
        vector<int> arr(N);
        vector<vector<int>> graph(M, vector<int>(2));
        for (int i = 0; i < N; i++) {
            cin >> arr[i];
        }
        for (int i = 0; i < M; i++) {
            for (int j = 0; j < 2; j++) {
                cin >> graph[i][j];
            }
        }
        Solution obj;
        cout << obj.luckyPermutations(N, M, arr, graph) << endl;
    
cout << "~" << "\n";
}
}

// } Driver Code Ends