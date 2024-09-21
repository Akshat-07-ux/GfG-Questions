//{ Driver Code Starts
// driver code

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution
{
  public:
    // Function to check if it's possible to allocate boards among k painters
    bool isPossible(int arr[], int n, int k, long long maxTime) {
        int painters = 1;
        long long currTime = 0;

        for (int i = 0; i < n; i++) {
            if (arr[i] > maxTime) {
                // If a single board is greater than maxTime, allocation is not possible
                return false;
            }

            if (currTime + arr[i] > maxTime) {
                // Assign the board to the next painter
                painters++;
                currTime = arr[i];

                // If the number of painters exceeds k, return false
                if (painters > k) {
                    return false;
                }
            } else {
                // Add the board to the current painter's work
                currTime += arr[i];
            }
        }

        return true;
    }

    // Function to find the minimum time to paint all boards
    long long minTime(int arr[], int n, int k) {
        long long left = 0, right = 0;

        // Calculate the sum of all boards and the maximum length board
        for (int i = 0; i < n; i++) {
            right += arr[i];
            left = max(left, (long long)arr[i]);
        }

        // Binary search on the answer
        long long result = right;
        while (left <= right) {
            long long mid = left + (right - left) / 2;

            // Check if it's possible to paint all boards within `mid` time
            if (isPossible(arr, n, k, mid)) {
                result = mid;
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }

        return result;
    }
};

//{ Driver Code Starts.

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int k,n;
		cin>>k>>n;
		
		int arr[n];
		for(int i=0;i<n;i++)
		    cin>>arr[i];
		Solution obj;
		cout << obj.minTime(arr, n, k) << endl;
	}
	return 0;
}
// } Driver Code Ends