//{ Driver Code Starts
//Initial template for C++
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

//User function template in C++

class Solution
{
 public:
    // Function to find the total number of unique paths.
    int NumberOfPath(int a, int b) {
        // Create a DP table initialized with 1s
        int dp[a][b];
        
        // Fill the DP table
        for (int i = 0; i < a; i++) {
            for (int j = 0; j < b; j++) {
                if (i == 0 || j == 0) {
                    dp[i][j] = 1;  // Only one way to reach any cell in the first row or first column
                } else {
                    dp[i][j] = dp[i - 1][j] + dp[i][j - 1];  // Sum of top and left cell values
                }
            }
        }
        
        return dp[a - 1][b - 1];  // Bottom-right cell contains the final answer
    }
};



//{ Driver Code Starts.
int main()
{
    //taking total testcases
    int t;
    cin>>t;
    while(t--)
    {
        //taking dimensions of the matrix
        int a,b;
        cin>>a>>b;
        Solution ob;
        //calling NumberOfPath() function
        cout << ob.NumberOfPath(a,b) << endl;
    
cout << "~" << "\n";
}
}


// } Driver Code Ends