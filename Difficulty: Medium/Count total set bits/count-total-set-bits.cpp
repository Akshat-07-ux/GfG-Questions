//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
 public:
    // Function to return sum of count of set bits in the integers from 1 to n.
    int countSetBits(int n) {
        if (n == 0) {
            return 0;
        }

        // Find the largest power of 2 less than or equal to n
        int x = largestPowerOf2(n);
        
        // Count set bits from 1 to 2^x - 1
        int bitsUpTo2x = x * (1 << (x - 1));
        
        // Count the most significant bit for numbers from 2^x to n
        int msbCount = n - (1 << x) + 1;
        
        // Recur for the remaining part from (2^x + 1) to n
        int rest = countSetBits(n - (1 << x));
        
        return bitsUpTo2x + msbCount + rest;
    }
    
    // Function to find the largest power of 2 less than or equal to n
    int largestPowerOf2(int n) {
        int x = 0;
        while ((1 << (x + 1)) <= n) {
            x++;
        }
        return x;
    }
};

//{ Driver Code Starts.

// Driver code
int main()
{
	 int t;
	 cin>>t;// input testcases
	 while(t--) //while testcases exist
	 {
	       int n;
	       cin>>n; //input n
	       Solution ob;
	       cout << ob.countSetBits(n) << endl;// print the answer
	  }
	  return 0;
}

// } Driver Code Ends