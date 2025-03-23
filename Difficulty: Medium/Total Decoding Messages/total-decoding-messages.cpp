//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
 public:
    int countWays(string &digits) {
        int n = digits.size();
        if (n == 0 || digits[0] == '0') return 0; // Edge case: leading zero is invalid

        vector<int> dp(n + 1, 0);
        dp[0] = 1; // Base case: empty string has one way to decode
        dp[1] = 1; // Single character (if not '0') has one way to decode

        for (int i = 2; i <= n; i++) {
            int oneDigit = digits[i - 1] - '0'; // Last single digit
            int twoDigit = (digits[i - 2] - '0') * 10 + oneDigit; // Last two digits

            if (oneDigit >= 1) {
                dp[i] += dp[i - 1]; // Single digit decoding
            }
            if (twoDigit >= 10 && twoDigit <= 26) {
                dp[i] += dp[i - 2]; // Two digit decoding
            }
        }
        return dp[n];
    }
};


//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    cin.ignore();
    while (tc--) {
        string digits;
        getline(cin, digits);
        Solution obj;
        int ans = obj.countWays(digits);
        cout << ans << "\n";

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends