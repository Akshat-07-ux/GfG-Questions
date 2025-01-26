//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
 public:
    long long getCount(int n) {
        // Map of allowed moves for each digit
        vector<vector<int>> moves = {
            {0, 8},       // 0
            {1, 2, 4},    // 1
            {2, 1, 3, 5}, // 2
            {3, 2, 6},    // 3
            {4, 1, 5, 7}, // 4
            {5, 2, 4, 6, 8}, // 5
            {6, 3, 5, 9}, // 6
            {7, 4, 8},    // 7
            {8, 5, 7, 9, 0}, // 8
            {9, 6, 8}     // 9
        };

        // Base case: if n is 1, there are 10 single-digit sequences
        if (n == 1) return 10;

        // DP table to store the count of sequences ending at each digit for each length
        vector<vector<long long>> dp(n, vector<long long>(10, 0));

        // Initialize for sequences of length 1
        for (int i = 0; i < 10; i++) {
            dp[0][i] = 1;
        }

        // Fill the DP table
        for (int len = 1; len < n; len++) {
            for (int digit = 0; digit < 10; digit++) {
                for (int neighbor : moves[digit]) {
                    dp[len][digit] += dp[len - 1][neighbor];
                }
            }
        }

        // Sum up all possible sequences of length n
        long long totalCount = 0;
        for (int i = 0; i < 10; i++) {
            totalCount += dp[n - 1][i];
        }

        return totalCount;
    }
};

//{ Driver Code Starts.
int main() {

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;

        Solution ob;
        cout << ob.getCount(n) << "\n";
    
cout << "~" << "\n";
}
    return 0;
}

// } Driver Code Ends