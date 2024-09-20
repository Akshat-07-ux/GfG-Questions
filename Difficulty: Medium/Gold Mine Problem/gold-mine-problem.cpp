//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int maxGold(int n, int m, vector<vector<int>> M)
    {
        // Create a DP table to store the maximum gold collected
        vector<vector<int>> dp(n, vector<int>(m, 0));

        // Iterate from the last column to the first
        for (int col = m - 1; col >= 0; col--) {
            for (int row = 0; row < n; row++) {
                // Gold collected on going to the cell on the right (same row)
                int right = (col == m - 1) ? 0 : dp[row][col + 1];

                // Gold collected on going to the cell on the right-up diagonal
                int right_up = (row == 0 || col == m - 1) ? 0 : dp[row - 1][col + 1];

                // Gold collected on going to the cell on the right-down diagonal
                int right_down = (row == n - 1 || col == m - 1) ? 0 : dp[row + 1][col + 1];

                // Update dp[row][col] to the maximum gold collectible from this cell
                dp[row][col] = M[row][col] + max(right, max(right_up, right_down));
            }
        }

        // The answer is the maximum value in the first column
        int max_gold = 0;
        for (int i = 0; i < n; i++) {
            max_gold = max(max_gold, dp[i][0]);
        }

        return max_gold;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, m;
        cin>>n>>m;
        vector<vector<int>> M(n, vector<int>(m, 0));
        for(int i = 0;i < n;i++){
            for(int j = 0;j < m;j++)
                cin>>M[i][j];
        }
        
        Solution ob;
        cout<<ob.maxGold(n, m, M)<<"\n";
    }
    return 0;
}
// } Driver Code Ends