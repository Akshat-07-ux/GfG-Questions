//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
 public:
    int maximumPoints(std::vector<std::vector<int>>& arr, int n) {
        // Initialize dp for the first day with values of arr[0]
        std::vector<int> dp(3);
        dp[0] = arr[0][0];
        dp[1] = arr[0][1];
        dp[2] = arr[0][2];
        
        // Fill dp array for each subsequent day
        for (int i = 1; i < n; ++i) {
            int prev0 = dp[0], prev1 = dp[1], prev2 = dp[2];
            dp[0] = arr[i][0] + std::max(prev1, prev2);  // If Running today
            dp[1] = arr[i][1] + std::max(prev0, prev2);  // If Fighting today
            dp[2] = arr[i][2] + std::max(prev0, prev1);  // If Learning today
        }
        
        // Maximum points on the last day considering all activities
        return std::max({dp[0], dp[1], dp[2]});
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> arr;
        for (int i = 0; i < n; ++i) {
            vector<int> temp;
            for (int j = 0; j < 3; ++j) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            arr.push_back(temp);
        }

        Solution obj;
        cout << obj.maximumPoints(arr, n) << endl;
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends