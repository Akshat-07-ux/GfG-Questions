//{ Driver Code Starts
// Initial template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
public:
    int stockBuyAndSell(std::vector<int> &prices) {
        int maxProfit = 0;
        
        // Traverse through the prices array
        for (int i = 1; i < prices.size(); i++) {
            // If there's a rise in price, we add the profit
            if (prices[i] > prices[i - 1]) {
                maxProfit += prices[i] - prices[i - 1];
            }
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
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        int n = arr.size();
        Solution ob;
        int res = ob.stockBuyAndSell(arr);
        cout << res;

        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends