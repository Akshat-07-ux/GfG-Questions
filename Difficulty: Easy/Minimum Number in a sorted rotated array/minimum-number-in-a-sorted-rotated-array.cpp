//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
public:
    // Function to find the minimum element in sorted and rotated array.
    int minNumber(int arr[], int low, int high) {
        while (low < high) {
            int mid = low + (high - low) / 2;
            
            // Check if mid element is greater than the high element.
            if (arr[mid] > arr[high]) {
                // Minimum element must be in the right half.
                low = mid + 1;
            } else {
                // Minimum element is in the left half or at mid.
                high = mid;
            }
        }
        // When low == high, we've found the smallest element.
        return arr[low];
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
		int a[n];
		for(int i=0;i<n;++i)
			cin>>a[i];	
		Solution obj;
		cout << obj.minNumber(a,0,n-1) << endl;
	
cout << "~" << "\n";
}
	return 0;
}
// } Driver Code Ends