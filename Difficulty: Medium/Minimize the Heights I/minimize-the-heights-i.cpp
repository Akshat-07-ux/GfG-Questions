//{ Driver Code Starts
// Initial template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int getMinDiff(int k, vector<int> &arr) {
        int n = arr.size();
        if (n == 1) return 0; // If there's only one tower, no difference.

        // Step 1: Sort the array
        sort(arr.begin(), arr.end());

        // Step 2: Calculate the initial difference
        int diff = arr[n - 1] - arr[0];

        // Step 3: Iterate through the array and compute minimum difference
        int minHeight, maxHeight;
        for (int i = 0; i < n - 1; i++) {
            // If reducing arr[i+1] - k results in negative height, skip it
            if (arr[i + 1] < k) continue;

            // Calculate the new minimum and maximum heights
            minHeight = min(arr[0] + k, arr[i + 1] - k);
            maxHeight = max(arr[i] + k, arr[n - 1] - k);

            // Update the difference
            diff = min(diff, maxHeight - minHeight);
        }

        return diff;
    }
};

//{ Driver Code Starts.
int main() {
    int t;

    cin >> t;
    cin.ignore();

    while (t--) {
        int k;
        cin >> k;
        cin.ignore();
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        int n = arr.size();
        Solution ob;
        int res = ob.getMinDiff(k, arr);
        cout << res;

        cout << "\n";
        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends