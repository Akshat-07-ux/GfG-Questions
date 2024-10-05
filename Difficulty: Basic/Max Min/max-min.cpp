//{ Driver Code Starts
/* Driver program to test above function */

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution
{
public:
    int findSum(int A[], int N) {
        // Initialize min and max with extreme values
        int minElement = INT_MAX;
        int maxElement = INT_MIN;
        
        // Traverse the array once
        for (int i = 0; i < N; i++) {
            if (A[i] < minElement) {
                minElement = A[i];  // Update min
            }
            if (A[i] > maxElement) {
                maxElement = A[i];  // Update max
            }
        }
        
        // Return the sum of the min and max elements
        return minElement + maxElement;
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
	    int arr[n];
	    for(int i=0;i<n;i++)
	      cin>>arr[i];
	    Solution ob;  
	    int ans=ob.findSum(arr, n);
	    cout<<ans;
	    cout<<"\n";
	}
	return 0;
}

// } Driver Code Ends