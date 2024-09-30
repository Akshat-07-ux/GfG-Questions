//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
public:
    // Function to find maximum subarray sum using Kadane's algorithm.
    int kadaneMaxSum(const vector<int>& arr) {
        int maxEndingHere = arr[0], maxSoFar = arr[0];
        for (int i = 1; i < arr.size(); ++i) {
            maxEndingHere = max(arr[i], maxEndingHere + arr[i]);
            maxSoFar = max(maxSoFar, maxEndingHere);
        }
        return maxSoFar;
    }

    // Function to find minimum subarray sum using a modified Kadane's algorithm.
    int kadaneMinSum(const vector<int>& arr) {
        int minEndingHere = arr[0], minSoFar = arr[0];
        for (int i = 1; i < arr.size(); ++i) {
            minEndingHere = min(arr[i], minEndingHere + arr[i]);
            minSoFar = min(minSoFar, minEndingHere);
        }
        return minSoFar;
    }

    // Function to find maximum circular subarray sum.
    int circularSubarraySum(vector<int> &arr) {
        int n = arr.size();

        // Step 1: Find the maximum subarray sum using Kadane's algorithm.
        int maxNormalSubarraySum = kadaneMaxSum(arr);

        // If all elements are negative, return the maximum element (Kadane's result).
        if (maxNormalSubarraySum < 0) {
            return maxNormalSubarraySum;
        }

        // Step 2: Find the total sum of the array.
        int totalSum = 0;
        for (int i = 0; i < n; ++i) {
            totalSum += arr[i];
        }

        // Step 3: Find the minimum subarray sum using Kadane's algorithm for minimum sum.
        int minSubarraySum = kadaneMinSum(arr);

        // Step 4: Calculate the maximum circular subarray sum as totalSum - minSubarraySum.
        int maxCircularSubarraySum = totalSum - minSubarraySum;

        // Step 5: Return the maximum of the normal and circular subarray sum.
        return max(maxNormalSubarraySum, maxCircularSubarraySum);
    }
};

//{ Driver Code Starts.

int main() {
    int T;

    // testcases
    cin >> T;

    while (T--) {
        int num;

        // size of array
        cin >> num;
        vector<int> arr(num);

        // inserting elements
        for (int i = 0; i < num; i++)
            cin >> arr[i];

        Solution ob;
        // calling function
        cout << ob.circularSubarraySum(arr) << endl;
    }

    return 0;
}
// } Driver Code Ends