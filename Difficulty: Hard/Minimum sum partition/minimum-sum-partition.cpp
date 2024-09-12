//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
public:
    int minDifference(int arr[], int n) {
        // Calculate the total sum of the array elements
        int totalSum = std::accumulate(arr, arr + n, 0);

        // Initialize a DP array to store subset sums
        std::vector<bool> dp(totalSum / 2 + 1, false);
        dp[0] = true;

        // Fill the DP table
        for (int i = 0; i < n; ++i) {
            for (int j = totalSum / 2; j >= arr[i]; --j) {
                if (dp[j - arr[i]]) {
                    dp[j] = true;
                }
            }
        }

        // Find the largest j for which dp[j] is true
        int subsetSum = 0;
        for (int j = totalSum / 2; j >= 0; --j) {
            if (dp[j]) {
                subsetSum = j;
                break;
            }
        }

        // Compute the minimum difference
        int minDiff = totalSum - 2 * subsetSum;
        return minDiff;
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
	    cout << ob.minDifference(a, n) << "\n";
	     
    }
    return 0;
}
// } Driver Code Ends