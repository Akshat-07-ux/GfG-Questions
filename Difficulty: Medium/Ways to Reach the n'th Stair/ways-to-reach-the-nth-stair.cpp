//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
    public:
    // Function to count the number of ways to reach the nth stair.
    int countWays(int n)
    {
        const int MOD = 1000000007;
        
        // Base cases
        if (n == 1) return 1;
        if (n == 2) return 2;

        int prev2 = 1;  // Ways to reach (n-2)th stair
        int prev1 = 2;  // Ways to reach (n-1)th stair
        int current;

        // Loop to calculate the number of ways for each stair
        for (int i = 3; i <= n; i++) {
            current = (prev1 + prev2) % MOD; // Calculate current ways
            prev2 = prev1;  // Update prev2 to previous prev1
            prev1 = current; // Update prev1 to current
        }

        return prev1; // Return the final count for the nth stair
    }
};


//{ Driver Code Starts.
int main()
{
    //taking total testcases
    int t;
    cin >> t;
    while(t--)
    {
        //taking stair count
        int m;
        cin>>m;
        Solution ob;
        cout<<ob.countWays(m)<<endl; // Print the output from our pre computed array
    }
    return 0;
}

// } Driver Code Ends