//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
    public:
    // Function to find a continuous sub-array which adds up to a given number.
    vector<int> subarraySum(vector<int> arr, int n, long long s) {
        long long currentSum = 0;
        int start = 0;

        for (int end = 0; end < n; end++) {
            // Add the current element to the sum
            currentSum += arr[end];

            // If the current sum exceeds the target sum, remove elements from the start
            while (currentSum > s && start < end) {
                currentSum -= arr[start];
                start++;
            }

            // If we found the target sum, return the subarray indices
            if (currentSum == s) {
                return {start + 1, end + 1};  // Adding 1 for 1-based indexing
            }
        }

        // If no subarray is found, return {-1}
        return {-1};
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        long long s;
        cin >> n >> s;
        vector<int> arr(n);
        // int arr[n];
        const int mx = 1e9;
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        vector<int> res;
        res = ob.subarraySum(arr, n, s);

        for (int i = 0; i < res.size(); i++)
            cout << res[i] << " ";
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends