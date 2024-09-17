//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int smallestSubWithSum(int x, vector<int>& arr) {
        int n = arr.size();
        int min_len = n + 1; // Initialize result to a large value (more than possible array size)
        int curr_sum = 0;    // To store the current window sum
        int start = 0;       // Start of the window

        // Loop through each element in the array
        for (int end = 0; end < n; end++) {
            // Add the current element to the window sum
            curr_sum += arr[end];

            // If the current window's sum is greater than `x`, try to shrink the window
            while (curr_sum > x) {
                // Update minimum length if the current window is smaller
                min_len = min(min_len, end - start + 1);
                
                // Remove the starting element from the window and shrink the window
                curr_sum -= arr[start];
                start++;
            }
        }

        // If we didn't find any valid subarray, return 0, otherwise return min_len
        return (min_len == n + 1) ? 0 : min_len;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore(); // Ignore the newline character after t

    while (t--) {
        vector<int> arr;
        int x;

        cin >> x;
        cin.ignore(); // Ignore the newline character after x

        string input;
        getline(cin, input); // Read the entire line for the array elements

        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }

        Solution obj;
        cout << obj.smallestSubWithSum(x, arr) << endl;
    }

    return 0;
}
// } Driver Code Ends