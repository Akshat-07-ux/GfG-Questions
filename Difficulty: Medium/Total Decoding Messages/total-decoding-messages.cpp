//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    int CountWays(std::string str) {
        const int MOD = 1e9 + 7;
        int n = str.size();
        if (n == 0 || str[0] == '0') return 0; // Edge case: empty string or starting with '0'

        // Initialize dp array
        std::vector<int> dp(n + 1, 0);
        dp[0] = 1; // There's one way to decode an empty string
        dp[1] = str[0] != '0' ? 1 : 0; // There's one way to decode if the first character is not '0'

        for (int i = 2; i <= n; ++i) {
            // Check if single digit decoding is possible
            if (str[i - 1] != '0') {
                dp[i] = dp[i - 1];
            }

            // Check if two digit decoding is possible
            int twoDigit = (str[i - 2] - '0') * 10 + (str[i - 1] - '0');
            if (twoDigit >= 10 && twoDigit <= 26) {
                dp[i] = (dp[i] + dp[i - 2]) % MOD;
            }
        }

        return dp[n];
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string str;
		cin >> str;
		Solution obj;
		int ans = obj.CountWays(str);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends