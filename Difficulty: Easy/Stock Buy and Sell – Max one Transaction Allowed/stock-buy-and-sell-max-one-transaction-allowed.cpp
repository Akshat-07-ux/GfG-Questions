//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int maximumProfit(vector<int> &prices) {
        int n = prices.size();
        if (n == 0) return 0; // Edge case: empty prices array
        
        int minPrice = INT_MAX; // Initialize the minimum price
        int maxProfit = 0;      // Initialize the maximum profit
        
        // Traverse through the array
        for (int i = 0; i < n; i++) {
            // Update the minimum price seen so far
            minPrice = min(minPrice, prices[i]);
            // Calculate the profit if the stock is sold today
            int profit = prices[i] - minPrice;
            // Update the maximum profit
            maxProfit = max(maxProfit, profit);
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
        vector<int> prices;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            prices.push_back(number);
        }

        Solution ob;
        int ans = ob.maximumProfit(prices);
        cout << ans << endl;
    }
    return 0;
}

// } Driver Code Ends