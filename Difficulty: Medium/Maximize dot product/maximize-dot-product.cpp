//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
		
	public:
	int maxDotProduct(int n, int m, int a[], int b[]) 
{ 
    // Create DP table
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
    
    // Fill DP table
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= min(i, m); j++) {
            // Either don't use current element of b (insert 0)
            dp[i][j] = dp[i-1][j];
            
            // Or use current element of b at current position
            dp[i][j] = max(dp[i][j], 
                          dp[i-1][j-1] + a[i-1] * b[j-1]);
        }
    }
    
    return dp[n][m];
}
};


//{ Driver Code Starts.
int main() 
{
   
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;

        int a[n], b[m];

        for(int i = 0; i < n; i++)
        	cin >> a[i];

        for(int i = 0; i < m; i++)
        	cin >> b[i];

       

	    Solution ob;
	    cout << ob.maxDotProduct(n, m, a, b) << "\n";
	     
    
cout << "~" << "\n";
}
    return 0;
}

// } Driver Code Ends