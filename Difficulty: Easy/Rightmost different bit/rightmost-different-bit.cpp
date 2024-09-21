//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;
 

// } Driver Code Ends
//User function Template for C++

class Solution
{
public:
    // Function to find the first position with different bits.
    int posOfRightMostDiffBit(int m, int n) {
        // XOR m and n to get the positions where the bits are different
        int xor_result = m ^ n;

        // If both numbers are the same, return -1
        if (xor_result == 0) {
            return -1;
        }

        // Find the position of the rightmost set bit (1-based index)
        // This expression will give the position of the rightmost set bit in xor_result
        return log2(xor_result & -xor_result) + 1;
    }
};

//{ Driver Code Starts.

// Driver Code
int main()
{   
    int t;
    cin>>t; //input number of testcases
    while(t--)
    {
         int m,n;
         cin>>m>>n; //input m and n
         Solution ob;
         cout << ob.posOfRightMostDiffBit(m, n)<<endl;
    }
    return 0;     
} 
// } Driver Code Ends