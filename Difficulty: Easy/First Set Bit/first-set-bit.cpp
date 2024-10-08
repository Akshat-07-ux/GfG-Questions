//{ Driver Code Starts
//Initial Template for C++


#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution
{
public:
    // Function to find position of first set bit in the given number.
    unsigned int getFirstSetBit(int n) {
        // If n is 0, return 0 because there is no set bit.
        if (n == 0) return 0;

        // Initialize position to 1 (since we count positions starting from 1).
        unsigned int position = 1;

        // Check each bit from right to left.
        while ((n & 1) == 0) {
            // Shift right to check the next bit.
            n >>= 1;
            position++;
        }

        // Return the position of the first set bit.
        return position;
    }
};

//{ Driver Code Starts.

// Driver code
int main()
{
    int t;
    cin>>t; // testcases
    while(t--)
    {
        int n;
        cin>>n; //input n
        Solution ob;
        printf("%u\n", ob.getFirstSetBit(n)); // function to get answer
    }
	return 0;
}

// } Driver Code Ends