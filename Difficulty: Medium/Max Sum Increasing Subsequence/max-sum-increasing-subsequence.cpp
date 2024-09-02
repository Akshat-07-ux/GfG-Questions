//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
public:
	int maxSumIS(int arr[], int n)  
	{  
	    // Initialize dp array
	    int dp[n];
	    
	    // Initialize dp array with the values of the array itself
	    for (int i = 0; i < n; i++) {
	        dp[i] = arr[i];
	    }
	    
	    // Fill dp array using the relation described above
	    for (int i = 1; i < n; i++) {
	        for (int j = 0; j < i; j++) {
	            if (arr[i] > arr[j] && dp[i] < dp[j] + arr[i]) {
	                dp[i] = dp[j] + arr[i];
	            }
	        }
	    }
	    
	    // Find and return the maximum value in dp array
	    return *max_element(dp, dp + n);
	}  
};


//{ Driver Code Starts.
int main() 
{
   	
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        int a[n];

        for(int i = 0; i < n; i++)
        	cin >> a[i];

      

	    Solution ob;
	    cout << ob.maxSumIS(a, n) << "\n";
	     
    }
    return 0;
}


// } Driver Code Ends