//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function template for C++
class Solution{
 public:
    bool match(string wild, string pattern) {
        int m = wild.size();
        int n = pattern.size();

        // DP table: dp[i][j] represents if wild[0...i-1] matches pattern[0...j-1]
        vector<vector<bool>> dp(m + 1, vector<bool>(n + 1, false));

        // Empty wild and pattern match
        dp[0][0] = true;

        // Handle cases where wild starts with '*'
        for (int i = 1; i <= m; ++i) {
            if (wild[i - 1] == '*') {
                dp[i][0] = dp[i - 1][0];
            } else {
                break;
            }
        }

        // Fill the DP table
        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
                if (wild[i - 1] == pattern[j - 1] || wild[i - 1] == '?') {
                    dp[i][j] = dp[i - 1][j - 1];  // Characters match or '?' matches one character
                } else if (wild[i - 1] == '*') {
                    dp[i][j] = dp[i - 1][j] || dp[i][j - 1];  // '*' matches zero or more characters
                }
            }
        }

        return dp[m][n];
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t-->0)
    {
        string wild, pattern;
        cin>>wild>>pattern;
        
        Solution ob;
        bool x=ob.match(wild, pattern);
        if(x)
        cout<<"Yes\n";
        else
        cout<<"No\n";
    
cout << "~" << "\n";
}
    return 0;
}
// } Driver Code Ends