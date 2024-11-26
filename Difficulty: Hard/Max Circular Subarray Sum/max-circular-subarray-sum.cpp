//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
class Solution {
 public:
    // Function to find maximum circular subarray sum.
    int circularSubarraySum(vector<int> &arr) {
        int n = arr.size();

        // Step 1: Find the maximum subarray sum using Kadane's algorithm
        int max_kadane = kadane(arr);

        // Step 2: Find the total sum of the array
        int total_sum = accumulate(arr.begin(), arr.end(), 0);

        // Step 3: Find the minimum subarray sum using Kadane's algorithm for negative elements
        for (int &x : arr) x = -x; // Invert the array
        int min_kadane = kadane(arr);
        for (int &x : arr) x = -x; // Revert the array back to original

        // Handle the edge case where all elements are negative
        if (total_sum + min_kadane == 0) {
            return max_kadane;
        }

        // Step 4: Calculate the maximum circular subarray sum
        int max_circular = total_sum + min_kadane;

        // Step 5: Return the maximum of the two cases
        return max(max_kadane, max_circular);
    }

private:
    // Helper function to implement Kadane's algorithm
    int kadane(const vector<int> &arr) {
        int max_sum = arr[0], current_sum = arr[0];
        for (int i = 1; i < arr.size(); ++i) {
            current_sum = max(arr[i], current_sum + arr[i]);
            max_sum = max(max_sum, current_sum);
        }
        return max_sum;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr;
        string input;

        // Read first array
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }

        Solution ob;
        int res = ob.circularSubarraySum(arr);

        cout << res << endl;
    }
    return 0;
}

// } Driver Code Ends