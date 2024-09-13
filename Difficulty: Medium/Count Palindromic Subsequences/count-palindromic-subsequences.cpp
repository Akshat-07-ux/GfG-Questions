//{ Driver Code Starts
// Counts Palindromic Subsequence in a given String
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
public:
    long long int countPS(string str) {
        int n = str.length();
        const int MOD = 1000000007;
        vector<vector<long long int>> dp(n, vector<long long int>(n, 0));
        
        // Single characters are palindromic subsequences
        for (int i = 0; i < n; ++i) {
            dp[i][i] = 1;
        }
        
        // Fill the table for substrings of length 2 to n
        for (int len = 2; len <= n; ++len) { // length of the substring
            for (int i = 0; i <= n - len; ++i) {
                int j = i + len - 1;
                if (str[i] == str[j]) {
                    dp[i][j] = (dp[i + 1][j] + dp[i][j - 1] + 1) % MOD;
                } else {
                    dp[i][j] = (dp[i + 1][j] + dp[i][j - 1] - dp[i + 1][j - 1] + MOD) % MOD;
                }
            }
        }
        
        return dp[0][n - 1];
    }
};

//{ Driver Code Starts.
// Driver program
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        string str;
        cin>>str;
        Solution ob;
        long long int ans = ob.countPS(str);
        cout<<ans<<endl;
    } 
}
// } Driver Code Ends