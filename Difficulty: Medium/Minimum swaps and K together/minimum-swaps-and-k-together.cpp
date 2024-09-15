//{ Driver Code Starts
// C++ program to find minimum swaps required
// to club all elements less than or equals
// to k together
#include <bits/stdc++.h>
using namespace std;



// } Driver Code Ends

class Solution
{
public:
    int minSwap(int arr[], int n, int k) {
        // Count elements less than or equal to k
        int count = 0;
        for (int i = 0; i < n; i++) {
            if (arr[i] <= k) {
                count++;
            }
        }

        // Find how many elements greater than k are present in the first 'count' sized window
        int bad = 0;  // 'bad' will count the elements that are greater than k in the current window
        for (int i = 0; i < count; i++) {
            if (arr[i] > k) {
                bad++;
            }
        }

        // Initialize the minimum swaps as the 'bad' elements in the first window
        int minSwaps = bad;

        // Use sliding window technique to find the minimum number of swaps required
        for (int i = 0, j = count; j < n; i++, j++) {
            // Slide the window by removing the first element (arr[i]) and adding the next element (arr[j])
            if (arr[i] > k) {
                bad--;  // Element going out of window is bad
            }
            if (arr[j] > k) {
                bad++;  // Element coming into window is bad
            }
            minSwaps = min(minSwaps, bad);
        }

        return minSwaps;
    }
};


//{ Driver Code Starts.

// Driver code
int main() {

	int t,n,k;
	cin>>t;
	while(t--)
    {
        cin>>n;
        int arr[n];
        for(int i=0;i<n;i++)
            cin>>arr[i];
        cin>>k;
        Solution ob;
        cout << ob.minSwap(arr, n, k) << "\n";
    }
	return 0;
}

// } Driver Code Ends