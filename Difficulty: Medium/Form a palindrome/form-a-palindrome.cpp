//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution{
 public:
    int countMin(string str) {
        int n = str.size();
        // Create a DP table to store results of subproblems
        vector<vector<int>> dp(n, vector<int>(n, 0));
        
        // Every single character is a palindrome of length 1
        for (int i = 0; i < n; ++i) {
            dp[i][i] = 1;
        }
        
        // Fill the table
        for (int length = 2; length <= n; ++length) {
            for (int i = 0; i < n - length + 1; ++i) {
                int j = i + length - 1;
                if (str[i] == str[j]) {
                    dp[i][j] = dp[i + 1][j - 1] + 2;
                } else {
                    dp[i][j] = max(dp[i + 1][j], dp[i][j - 1]);
                }
            }
        }
        
        // The minimum number of insertions required is the difference
        // between the length of the string and the length of the longest palindromic subsequence
        return n - dp[0][n - 1];
    }
};

//{ Driver Code Starts.
int main(){
    int t;
    cin >> t;
    while(t--){
        string str;
        cin >> str;
        Solution ob;
        cout << ob.countMin(str) << endl;
    }
return 0;
}


// } Driver Code Ends