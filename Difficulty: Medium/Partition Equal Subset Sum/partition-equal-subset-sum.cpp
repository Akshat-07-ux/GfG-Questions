//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int equalPartition(int N, int arr[]) {
        int sum = 0;
        for (int i = 0; i < N; i++) {
            sum += arr[i];
        }

        // If the sum is odd, it's impossible to partition the array into two equal subsets
        if (sum % 2 != 0) return 0;

        int target = sum / 2;

        // DP array to store if a subset sum of `j` is possible with the first `i` elements
        vector<bool> dp(target + 1, false);
        dp[0] = true; // Sum 0 is always possible

        for (int i = 0; i < N; i++) {
            for (int j = target; j >= arr[i]; j--) {
                dp[j] = dp[j] || dp[j - arr[i]];
            }
        }

        return dp[target] ? 1 : 0;
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
        if(ob.equalPartition(N, arr))
            cout<<"YES\n";
        else
            cout<<"NO\n";
    }
    return 0;
}
// } Driver Code Ends