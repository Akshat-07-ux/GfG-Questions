//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
public:
    // Function to return the total number of possible unique BST.
    int numTrees(int N) {
        const int MOD = 1e9 + 7;
        std::vector<long long> dp(N + 1, 0);
        
        // Base case: With 0 nodes, there's 1 unique BST (the empty tree).
        dp[0] = 1;
        
        // Fill dp array using the recursive formula for Catalan numbers.
        for (int nodes = 1; nodes <= N; nodes++) {
            for (int root = 1; root <= nodes; root++) {
                // Calculate the count of left and right subtrees.
                int left = root - 1;
                int right = nodes - root;
                
                // Update dp[nodes] with the product of dp[left] and dp[right].
                dp[nodes] = (dp[nodes] + (dp[left] * dp[right]) % MOD) % MOD;
            }
        }
        
        return dp[N];
    }
};

//{ Driver Code Starts.
#define mod (int)(1e9+7)
int main(){
    
    //taking total testcases
    int t;
    cin>>t;
    while(t--){
        
        //taking total number of elements
        int n;
        cin>>n;
        Solution ob;
        //calling function numTrees()
        cout<<ob.numTrees(n)<<"\n";
    
cout << "~" << "\n";
}
}	
// } Driver Code Ends