//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    int LongestRepeatingSubsequence(string str){
        int n = str.length();
        // Create a dp array of size (n+1)x(n+1)
        vector<vector<int>> dp(n+1, vector<int>(n+1, 0));

        // Fill the dp table
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= n; j++) {
                // If characters are the same and the indices are different
                if(str[i-1] == str[j-1] && i != j) {
                    dp[i][j] = dp[i-1][j-1] + 1;
                } else {
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
                }
            }
        }

        // The answer is the value in dp[n][n]
        return dp[n][n];
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
		int ans = obj.LongestRepeatingSubsequence(str);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends