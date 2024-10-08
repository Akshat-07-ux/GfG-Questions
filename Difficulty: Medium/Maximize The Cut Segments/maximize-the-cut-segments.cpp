//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;



// } Driver Code Ends
class Solution{
public:
    // Function to find the maximum number of cuts.
    int maximizeTheCuts(int n, int x, int y, int z) {
        // Create a DP array initialized to -1
        std::vector<int> dp(n + 1, -1);
        
        // Base case: If length is 0, maximum cuts is 0
        dp[0] = 0;
        
        // Loop through all lengths from 1 to n
        for (int i = 1; i <= n; ++i) {
            if (i >= x && dp[i - x] != -1) {
                dp[i] = std::max(dp[i], dp[i - x] + 1);
            }
            if (i >= y && dp[i - y] != -1) {
                dp[i] = std::max(dp[i], dp[i - y] + 1);
            }
            if (i >= z && dp[i - z] != -1) {
                dp[i] = std::max(dp[i], dp[i - z] + 1);
            }
        }
        
        // If no cuts were possible, return 0
        return dp[n] == -1 ? 0 : dp[n];
    }
};

//{ Driver Code Starts.
int main() {
    
    //taking testcases
    int t;
    cin >> t;
    while(t--)
    {
        //taking length of line segment
        int n;
        cin >> n;
        
        //taking types of segments
        int x,y,z;
        cin>>x>>y>>z;
        Solution obj;
        //calling function maximizeTheCuts()
        cout<<obj.maximizeTheCuts(n,x,y,z)<<endl;

    }

	return 0;
}
// } Driver Code Ends