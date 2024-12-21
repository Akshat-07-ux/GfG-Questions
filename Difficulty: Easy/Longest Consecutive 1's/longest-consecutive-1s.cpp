//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

/*  Function to calculate the longest consecutive ones
*   N: given input to calculate the longest consecutive ones
*/
class Solution
{
public:
    int maxConsecutiveOnes(int N)
    {
        int maxCount = 0; // To store the maximum count of consecutive 1s
        int currentCount = 0; // To track the current streak of 1s

        while (N > 0) {
            if (N & 1) { // Check if the least significant bit is 1
                currentCount++;
                maxCount = max(maxCount, currentCount); // Update maxCount if needed
            } else {
                currentCount = 0; // Reset current count if 0 is encountered
            }
            N = N >> 1; // Right shift N to process the next bit
        }

        return maxCount;
    }
};


//{ Driver Code Starts.

// Driver Code
int main() {
	int t;
	cin>>t;//testcases
	while(t--)
	{
		int n;
		cin>>n;//input n
		Solution obj;
		//calling maxConsecutiveOnes() function
		cout<<obj.maxConsecutiveOnes(n)<<endl;
	
cout << "~" << "\n";
}
	return 0;
}
// } Driver Code Ends