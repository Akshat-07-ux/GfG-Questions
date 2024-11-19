//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
public:
    int nthPoint(int n) {
        const int MOD = 1e9 + 7;

        if (n == 1) return 1;
        if (n == 2) return 2;

        // Initialize a DP array to store the number of ways to reach each point
        vector<int> dp(n + 1, 0);

        // Base cases
        dp[1] = 1;
        dp[2] = 2;

        // Fill the DP table
        for (int i = 3; i <= n; i++) {
            dp[i] = (dp[i - 1] + dp[i - 2]) % MOD;
        }

        return dp[n];
    }
};


//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		Solution ob;
		int ans  = ob.nthPoint(n);
		cout << ans <<"\n";
	
cout << "~" << "\n";
}
	return 0;
}
// } Driver Code Ends