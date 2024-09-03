//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {

  public:
    int minCoins(vector<int> &coins, int sum) {
        int n = coins.size();
        vector<int> dp(sum + 1, INT_MAX);
        dp[0] = 0; // base case: 0 coins needed to make sum 0
        
        // Fill the dp array
        for (int coin : coins) {
            for (int i = coin; i <= sum; i++) {
                if (dp[i - coin] != INT_MAX) {
                    dp[i] = min(dp[i], dp[i - coin] + 1);
                }
            }
        }
        
        return dp[sum] == INT_MAX ? -1 : dp[sum];
    }
};

//{ Driver Code Starts.
int main() {

    int t;
    cin >> t;
    while (t--) {
        int v, m;
        cin >> v >> m;

        vector<int> coins(m);
        for (int i = 0; i < m; i++)
            cin >> coins[i];

        Solution ob;
        cout << ob.minCoins(coins, v) << "\n";
    }
    return 0;
}

// } Driver Code Ends