//{ Driver Code Starts
#include <bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
class Solution
{
public:
    const int MOD = 1e9 + 7;
    
    int countFriendsPairings(int n) { 
        // Base cases
        if (n == 1) return 1;
        if (n == 2) return 2;
        
        // To store results for previous computations
        long long prev2 = 1; // f(1)
        long long prev1 = 2; // f(2)
        long long curr;
        
        // Iterate from 3 to n and fill the dp table
        for (int i = 3; i <= n; i++) {
            curr = (prev1 + (i - 1) * prev2 % MOD) % MOD;
            // Move forward in the dp array
            prev2 = prev1;
            prev1 = curr;
        }
        
        return prev1;
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
    	cout <<ob.countFriendsPairings(n); 
    	cout<<endl;
    }
} 

// } Driver Code Ends