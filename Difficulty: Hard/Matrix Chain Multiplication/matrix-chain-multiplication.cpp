//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int matrixMultiplication(int N, int arr[])
    {
        // Create a 2D DP table to store results of subproblems
        int dp[N][N];
        
        // Initialize the dp array with 0 for single matrix multiplications
        for (int i = 1; i < N; i++) {
            dp[i][i] = 0;
        }

        // Chain length varies from 2 to N-1
        for (int len = 2; len < N; len++) {
            for (int i = 1; i <= N - len; i++) {
                int j = i + len - 1;
                dp[i][j] = INT_MAX; // Initialize to a large value
                
                // Try placing parenthesis at all possible points
                for (int k = i; k < j; k++) {
                    // Calculate the cost
                    int cost = dp[i][k] + dp[k+1][j] + arr[i-1] * arr[k] * arr[j];
                    
                    // Store the minimum cost
                    dp[i][j] = std::min(dp[i][j], cost);
                }
            }
        }
        
        // The result is in dp[1][N-1], which is the minimum cost to multiply matrices from 1 to N-1
        return dp[1][N-1];
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int arr[N];
        for(int i = 0;i < N;i++)
            cin>>arr[i];
        
        Solution ob;
        cout<<ob.matrixMultiplication(N, arr)<<endl;
    }
    return 0;
}
// } Driver Code Ends