//{ Driver Code Starts
// Initial template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int getMinDiff(int k, vector<int>& arr) {
        int n = arr.size();
        if (n == 1) return 0; // If there's only one tower, the difference is zero.

        // Sort the array to work with ordered heights
        sort(arr.begin(), arr.end());

        // Initial difference between the largest and smallest towers
        int ans = arr[n - 1] - arr[0];

        int smallest = arr[0] + k;
        int largest = arr[n - 1] - k;

        if (smallest > largest) swap(smallest, largest);

        for (int i = 0; i < n - 1; ++i) {
            int minHeight = min(smallest, arr[i + 1] - k);
            int maxHeight = max(largest, arr[i] + k);
            ans = min(ans, maxHeight - minHeight);
        }

        return ans;
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