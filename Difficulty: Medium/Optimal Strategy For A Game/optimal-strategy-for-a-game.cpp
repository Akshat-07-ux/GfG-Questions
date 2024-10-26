//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

//Function to find the maximum possible amount of money we can win.
class Solution{
 public:
    long long maximumAmount(int n, int arr[]){
        // Create a DP table to store the maximum amount the first player can collect
        vector<vector<long long>> dp(n, vector<long long>(n, 0));
        
        // Fill the table for subarrays of length 1 (base case)
        for (int i = 0; i < n; i++) {
            dp[i][i] = arr[i];
        }
        
        // Fill the table for subarrays of length 2 (base case)
        for (int i = 0; i < n - 1; i++) {
            dp[i][i + 1] = max(arr[i], arr[i + 1]);
        }
        
        // Fill the DP table for subarrays of length 3 and more
        for (int len = 3; len <= n; len++) {
            for (int i = 0; i <= n - len; i++) {
                int j = i + len - 1;
                // Choose the coin at the start or the coin at the end
                dp[i][j] = max(arr[i] + min(dp[i + 2][j], dp[i + 1][j - 1]),
                               arr[j] + min(dp[i][j - 2], dp[i + 1][j - 1]));
            }
        }
        
        // The answer is in dp[0][n-1], the maximum amount we can collect from the entire array
        return dp[0][n - 1];
    }
};

//{ Driver Code Starts.
int main() 
{
   
   	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		int a[n];
		for(int i=0;i<n;i++)
		cin>>a[i];
		Solution ob;
		cout<< ob.maximumAmount(n,a)<<endl;
	
cout << "~" << "\n";
}
	return 0;
}
// } Driver Code Ends