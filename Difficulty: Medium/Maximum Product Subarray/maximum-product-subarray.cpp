//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
// User function Template for C++
class Solution {
 public:
    // Function to find the maximum product subarray
    int maxProduct(vector<int> &arr) {
        int n = arr.size();

        // Initialize variables to track the maximum and minimum products up to the current position
        int maxProductSoFar = arr[0];
        int minProduct = arr[0];
        int maxProduct = arr[0];

        for (int i = 1; i < n; i++) {
            // If the current element is negative, swap maxProductSoFar and minProduct
            if (arr[i] < 0) {
                swap(maxProductSoFar, minProduct);
            }

            // Update maxProductSoFar and minProduct
            maxProductSoFar = max(arr[i], maxProductSoFar * arr[i]);
            minProduct = min(arr[i], minProduct * arr[i]);

            // Update the global maximum product
            maxProduct = max(maxProduct, maxProductSoFar);
        }

        return maxProduct;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        // int n, i;
        // cin >> n;
        // vector<int> arr(n);
        // for (i = 0; i < n; i++) {
        //     cin >> arr[i];
        // }

        vector<int> arr;
        string input;

        // Read array
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        Solution ob;
        auto ans = ob.maxProduct(arr);
        cout << ans << "\n";

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends