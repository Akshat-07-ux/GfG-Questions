//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int knapSack(int N, int W, int val[], int wt[]) {
        // DP array to store the maximum profit for every weight limit from 0 to W
        vector<int> dp(W + 1, 0);
        
        // Iterate through all items
        for (int i = 0; i < N; i++) {
            // For each weight capacity, try to include the current item
            for (int w = wt[i]; w <= W; w++) {
                // Update the DP value for weight w
                dp[w] = max(dp[w], dp[w - wt[i]] + val[i]);
            }
        }

        // Return the maximum profit for the weight limit W
        return dp[W];
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N, W;
        cin>>N>>W;
        int val[N], wt[N];
        for(int i = 0;i < N;i++)
            cin>>val[i];
        for(int i = 0;i < N;i++)
            cin>>wt[i];
        
        Solution ob;
        cout<<ob.knapSack(N, W, val, wt)<<endl;
    }
    return 0;
}
// } Driver Code Ends