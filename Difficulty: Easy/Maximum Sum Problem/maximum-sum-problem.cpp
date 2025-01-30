//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
  public:
    unordered_map<int, int> dp;  // Memoization to store previously computed results

    int maxSum(int n) {
        if (n == 0) return 0;

        // If already computed, return the stored value
        if (dp.find(n) != dp.end()) return dp[n];

        // Compute the max sum recursively
        int sum = max(n, maxSum(n / 2) + maxSum(n / 3) + maxSum(n / 4));

        // Store the result in dp table
        dp[n] = sum;
        return sum;
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
        Solution ob;
        cout<<ob.maxSum(n)<<"\n";
    
cout << "~" << "\n";
}
    return 0;
}
// } Driver Code Ends