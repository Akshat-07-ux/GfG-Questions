//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
public:
    int minOperations(string str1, string str2) 
    { 
        int n = str1.length();
        int m = str2.length();
        
        // Step 1: Create a DP table to store lengths of LCS
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
        
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (str1[i - 1] == str2[j - 1]) {
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                } else {
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }
        
        int lcsLength = dp[n][m];
        
        // Step 2: Calculate the minimum operations
        int deletions = n - lcsLength;
        int insertions = m - lcsLength;
        
        return deletions + insertions;
    } 
};

//{ Driver Code Starts.
int main() 
{
   	
   
   	int t;
    cin >> t;
    while (t--)
    {
        string s1, s2;
        cin >> s1 >> s2;

	    Solution ob;
	    cout << ob.minOperations(s1, s2) << "\n";
	     
    }
    return 0;
}


// } Driver Code Ends