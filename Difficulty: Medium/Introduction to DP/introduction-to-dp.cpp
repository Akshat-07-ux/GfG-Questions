//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
    const int MOD = 1e9 + 7;

  public:
    // Top-Down Approach
    long long int topDown(int n) {
        vector<long long> dp(n + 1, -1);
        return fib(n, dp);
    }

    long long int fib(int n, vector<long long>& dp) {
        if (n == 0) return 0;
        if (n == 1) return 1;

        // If already computed, return the stored result
        if (dp[n] != -1) return dp[n];

        // Compute and store the result
        dp[n] = (fib(n - 1, dp) + fib(n - 2, dp)) % MOD;
        return dp[n];
    }

    // Bottom-Up Approach
    long long int bottomUp(int n) {
        if (n == 0) return 0;
        if (n == 1) return 1;

        vector<long long> dp(n + 1);
        dp[0] = 0;
        dp[1] = 1;

        for (int i = 2; i <= n; ++i) {
            dp[i] = (dp[i - 1] + dp[i - 2]) % MOD;
        }

        return dp[n];
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        Solution obj;
        long long int topDownans = obj.topDown(n);
        long long int bottomUpans = obj.bottomUp(n);
        if (topDownans != bottomUpans) cout << -1 << "\n";
        cout << topDownans << "\n";
    
cout << "~" << "\n";
}
}
// } Driver Code Ends