//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
    public:
    // Function to count the number of ways in which frog can reach the top.
    long long countWays(int n)
    {
        const int MOD = 1000000007;
        
        // Base cases
        if (n == 1) return 1;
        if (n == 2) return 2;
        if (n == 3) return 4;
        
        long long a = 1, b = 2, c = 4;  // Initialize for n=1, n=2, n=3
        long long result = 0;
        
        // Calculate the number of ways for n > 3
        for (int i = 4; i <= n; i++) {
            result = (a + b + c) % MOD;
            a = b;
            b = c;
            c = result;
        }
        
        return result;
    }
};


//{ Driver Code Starts.
int main()
{
    //taking testcases
	int t;
	cin >> t;
	
	while(t--)
	{
	    //taking number of steps in stair
		int n;
		cin>>n;
		Solution ob;
		//calling function countWays()
		cout << ob.countWays(n) << endl;
	}
    
    return 0;
    
}

// } Driver Code Ends