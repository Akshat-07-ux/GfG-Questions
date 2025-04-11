//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    vector<int> longestIncreasingSubsequence(int n, vector<int>& arr) {
        vector<int> dp(n, 1);       // dp[i]: Length of LIS ending at i
        vector<int> parent(n, -1);  // To reconstruct the sequence

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < i; ++j) {
                if (arr[j] < arr[i]) {
                    if (dp[j] + 1 > dp[i]) {
                        dp[i] = dp[j] + 1;
                        parent[i] = j;
                    } 
                    // If same length but earlier index, prefer the one with smaller index to keep lexicographically smallest
                    else if (dp[j] + 1 == dp[i] && parent[i] > j) {
                        parent[i] = j;
                    }
                }
            }
        }

        // Find index of maximum value in dp
        int lisLength = 0;
        int lisEndIndex = 0;
        for (int i = 0; i < n; ++i) {
            if (dp[i] > lisLength) {
                lisLength = dp[i];
                lisEndIndex = i;
            }
        }

        // Reconstruct LIS
        vector<int> lis;
        while (lisEndIndex != -1) {
            lis.push_back(arr[lisEndIndex]);
            lisEndIndex = parent[lisEndIndex];
        }

        reverse(lis.begin(), lis.end());
        return lis;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        vector<int> arr(N);
        for (int i = 0; i < N; i++) {
            cin >> arr[i];
        }
        Solution obj;
        vector<int> res = obj.longestIncreasingSubsequence(N, arr);
        for (auto x : res)
            cout << x << " ";
        cout << "\n";
    
cout << "~" << "\n";
}
    return 0;
}
// } Driver Code Ends