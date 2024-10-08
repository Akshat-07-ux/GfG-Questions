//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++


class Solution
{
public:
    // Function to find the length of the shortest common supersequence of two strings.
    int shortestCommonSupersequence(string X, string Y, int m, int n) {
        // DP table to store lengths of longest common subsequence.
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

        // Fill the DP table for the LCS.
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                if (X[i - 1] == Y[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1] + 1;  // If characters match
                } else {
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);  // Take max of ignoring last character of X or Y
                }
            }
        }

        // The length of the SCS is the total length of X and Y minus the length of their LCS.
        int lcsLength = dp[m][n];
        return m + n - lcsLength;
    }
};

//{ Driver Code Starts.

int main()
{   
    
    int t;
    
    //taking total testcases
    cin >> t;
    while(t--){
    string X, Y;
    //taking String X and Y
	cin >> X >> Y;
	
	//calling function shortestCommonSupersequence()
	Solution obj;
	cout << obj.shortestCommonSupersequence(X, Y, X.size(), Y.size())<< endl;
    }
	return 0;
}


// } Driver Code Ends