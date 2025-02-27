//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

// Function to return Largest Number

class Solution
{
    public:
    // Function to return the largest possible number of n digits
    // with sum equal to given sum.
    string largestNumber(int n, int sum)
    {
        // If the sum is greater than the maximum possible sum with n digits, return -1
        if (sum > 9 * n) return "-1";
        
        string result = "";
        
        // Construct the number greedily, starting from the highest possible digits
        for (int i = 0; i < n; i++) {
            if (sum >= 9) {
                result += '9';
                sum -= 9;
            } else {
                result += ('0' + sum);
                sum = 0;
            }
        }
        
        return result;
    }
};


//{ Driver Code Starts.
int main()
{
    //taking testcases
	int t;
	cin>>t;

	while(t--)
	{
	    //taking n and sum
		int n,sum;
		cin>>n>>sum;
		
        Solution obj;
        //function call
		cout<<obj.largestNumber(n, sum)<<endl;
	
cout << "~" << "\n";
}
	return 0;
}
// } Driver Code Ends