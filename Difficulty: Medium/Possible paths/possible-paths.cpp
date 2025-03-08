//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

//User function template for C++

class Solution {
public:
    const int MOD = 1e9 + 7;

    int MinimumWalk(vector<vector<int>>& graph, int u, int v, int k) {
        int n = graph.size();
        
        // DP Table: dp[i][j][steps] -> No. of walks from i to j with exactly 'steps' edges
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(n, vector<int>(k+1, 0)));

        // Base case: For 0 edges, the only way to reach is if i == j
        for (int i = 0; i < n; i++) {
            dp[i][i][0] = 1;
        }

        // Fill DP Table for steps from 1 to k
        for (int steps = 1; steps <= k; steps++) {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    dp[i][j][steps] = 0;
                    for (int m = 0; m < n; m++) {
                        if (graph[i][m] == 1) {
                            dp[i][j][steps] = (dp[i][j][steps] + dp[m][j][steps-1]) % MOD;
                        }
                    }
                }
            }
        }

        return dp[u][v][k];
    }
};


//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<vector<int>>graph(n, vector<int>(n,0));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				cin >> graph[i][j];
			}
		}
		int u, v, k;
		cin >> u >> v >> k;
		Solution obj;
		int ans = obj.MinimumWalk(graph, u, v, k);
		cout << ans << "\n";
	
cout << "~" << "\n";
}
	return 0;
}
// } Driver Code Ends