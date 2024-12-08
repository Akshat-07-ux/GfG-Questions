//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
/*You are required to complete this method*/

class Solution {
 public:
    int subsequenceCount(string& txt, string& pat) {
        int n = txt.length();
        int m = pat.length();

        // If pat is empty, there is exactly one way to form it (do nothing)
        if (m == 0) return 1;

        // If txt is empty, we can't form any subsequence
        if (n == 0) return 0;

        // Create a DP table
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

        // Fill the first row (empty pattern)
        for (int j = 0; j <= n; ++j) {
            dp[0][j] = 1;
        }

        // Fill the DP table
        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
                // If characters match, include both options:
                // 1. Include this character (dp[i-1][j-1])
                // 2. Exclude this character (dp[i][j-1])
                if (pat[i - 1] == txt[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1] + dp[i][j - 1];
                } else {
                    // Otherwise, exclude this character
                    dp[i][j] = dp[i][j - 1];
                }
            }
        }

        // The answer is in dp[m][n]
        return dp[m][n];
    }
};


//{ Driver Code Starts.

//  Driver code to check above method
int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        string tt;
        cin >> s;
        cin >> tt;

        Solution ob;
        cout << ob.subsequenceCount(s, tt) << endl;

        cout << "~"
             << "\n";
    }
}
// } Driver Code Ends