//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
public:
    long long int numberOfPaths(int m, int n) {
        const int MOD = 1e9 + 7;
        vector<vector<long long int>> dp(m, vector<long long int>(n, 0));
        
        // Initialize the base cases
        for (int i = 0; i < m; i++) dp[i][0] = 1; // First column
        for (int j = 0; j < n; j++) dp[0][j] = 1; // First row

        // Fill the dp table
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                dp[i][j] = (dp[i-1][j] + dp[i][j-1]) % MOD;
            }
        }
        
        return dp[m-1][n-1];
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> m >> n;
        Solution ob;
        cout<<ob.numberOfPaths(m,n)<<endl;
    
cout << "~" << "\n";
}
    return 0;
}

// } Driver Code Ends