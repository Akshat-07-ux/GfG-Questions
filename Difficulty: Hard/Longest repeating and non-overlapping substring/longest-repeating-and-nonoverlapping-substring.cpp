//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    string longestSubstring(string& s) {
        int n = s.size();
        int maxLen = 0, endIndex = -1;

        vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));

        for (int i = 1; i <= n; ++i) {
            for (int j = i + 1; j <= n; ++j) {
                if (s[i - 1] == s[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1] + 1;

                    // Check non-overlapping condition
                    if (dp[i][j] > maxLen && abs(i - j) >= dp[i][j]) {
                        maxLen = dp[i][j];
                        endIndex = i;
                    }
                }
            }
        }

        return (maxLen > 0) ? s.substr(endIndex - maxLen, maxLen) : "-1";
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string S;
        cin >> S;

        Solution ob;
        cout << ob.longestSubstring(S) << endl;
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends