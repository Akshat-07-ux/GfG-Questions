//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
public:
    long long numberOfPath(int n, int k, vector<vector<int>> &arr) {
        vector<vector<vector<long long>>> dp(n, vector<vector<long long>>(n, vector<long long>(k + 1, 0)));

        // Base Case: Start from (0,0)
        if (arr[0][0] <= k) {
            dp[0][0][arr[0][0]] = 1;
        }

        // Fill DP table row-wise
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                for (int sum = 0; sum <= k; sum++) {
                    if (dp[i][j][sum] > 0) {
                        // Move Right
                        if (j + 1 < n && sum + arr[i][j + 1] <= k) {
                            dp[i][j + 1][sum + arr[i][j + 1]] += dp[i][j][sum];
                        }
                        // Move Down
                        if (i + 1 < n && sum + arr[i + 1][j] <= k) {
                            dp[i + 1][j][sum + arr[i + 1][j]] += dp[i][j][sum];
                        }
                    }
                }
            }
        }

        // Return the number of ways to reach bottom-right with exactly k coins
        return dp[n - 1][n - 1][k];
    }
};

//{ Driver Code Starts.

int main()
{
    Solution obj;
    int i,j,k,l,m,n,t;
    cin>>t;
    while(t--)
    {
        cin>>k>>n;
        vector<vector<int>> v(n, vector<int>(n, 0));
        for(i=0;i<n;i++)
            for(j=0;j<n;j++)
                cin>>v[i][j];
        cout << obj.numberOfPath(n, k, v) << endl;
    
cout << "~" << "\n";
}
}
// } Driver Code Ends