//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    // Function to find the nth Catalan number.
    int findCatalan(int n) 
    {
        const int MOD = 1e9 + 7;
        vector<int> dp(n + 1, 0);

        // Base case
        dp[0] = 1;

        // Fill the dp array using the DP approach
        for (int i = 1; i <= n; ++i) {
            for (int j = 0; j < i; ++j) {
                dp[i] = (dp[i] + (long long)dp[j] * dp[i - 1 - j]) % MOD;
            }
        }

        return dp[n];
    }
};

//{ Driver Code Starts.
int main() 
{
	int t;
	cin>>t;
	while(t--) {
	    
	    int n;
	    cin>>n;
	    Solution obj;
	    cout<< obj.findCatalan(n) <<"\n";    
	}
	return 0;
}
// } Driver Code Ends