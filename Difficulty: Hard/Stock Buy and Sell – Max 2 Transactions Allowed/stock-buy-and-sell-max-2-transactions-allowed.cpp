//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
class Solution {
public:
    int maxProfit(vector<int> &arr) {
        int n = arr.size();
        if (n == 0) return 0;

        // Step 1: Calculate maximum profit if we sell at each index
        vector<int> leftProfit(n, 0);
        int minPrice = arr[0];

        for (int i = 1; i < n; i++) {
            minPrice = min(minPrice, arr[i]);
            leftProfit[i] = max(leftProfit[i - 1], arr[i] - minPrice);
        }

        // Step 2: Calculate maximum profit if we buy at each index
        vector<int> rightProfit(n, 0);
        int maxPrice = arr[n - 1];

        for (int i = n - 2; i >= 0; i--) {
            maxPrice = max(maxPrice, arr[i]);
            rightProfit[i] = max(rightProfit[i + 1], maxPrice - arr[i]);
        }

        // Step 3: Combine the two profits to get the maximum result
        int maxProfit = 0;
        for (int i = 0; i < n; i++) {
            maxProfit = max(maxProfit, leftProfit[i] + rightProfit[i]);
        }

        return maxProfit;
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
        int res = ob.maxProfit(arr);

        cout << res << endl << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends