//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    int countPartitions(int n, int d, vector<int>& arr) {
        const int MOD = 1e9 + 7;
        
        // Calculate the total sum of the array
        int totalSum = 0;
        for (int num : arr) {
            totalSum += num;
        }

        // If (totalSum + d) is odd, it's impossible to partition
        if ((totalSum + d) % 2 != 0) {
            return 0;
        }
        
        // The target sum we are looking for
        int target = (totalSum + d) / 2;

        // If the target is negative or greater than totalSum, no valid partition exists
        if (target < 0 || target > totalSum) {
            return 0;
        }

        // DP array to store the number of ways to achieve each subset sum
        vector<int> dp(target + 1, 0);
        dp[0] = 1; // There's one way to make sum 0 (by taking no elements)

        // Traverse the array and update the dp array
        for (int num : arr) {
            for (int j = target; j >= num; j--) {
                dp[j] = (dp[j] + dp[j - num]) % MOD;
            }
        }

        return dp[target];
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, d;
        cin >> n >> d;
        vector<int> arr;

        for (int i = 0; i < n; ++i) {
            int x;
            cin >> x;
            arr.push_back(x);
        }

        Solution obj;
        cout << obj.countPartitions(n, d, arr) << "\n";
    }
    return 0;
}
// } Driver Code Ends