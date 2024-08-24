//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    
    int knapSack(int W, vector<int>& wt, vector<int>& val) {
        int N = wt.size();
        vector<vector<int>> dp(N + 1, vector<int>(W + 1, 0));

        
        for (int i = 1; i <= N; ++i) {
            for (int j = 1; j <= W; ++j) {
                
                if (wt[i-1] > j) {
                    dp[i][j] = dp[i-1][j];
                } else {
                    
                    dp[i][j] = max(dp[i-1][j], dp[i-1][j - wt[i-1]] + val[i-1]);
                }
            }
        }

        return dp[N][W];
    }
};

//{ Driver Code Starts.

int main() {
    // taking total testcases
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        // reading number of elements and weight
        int n, w;
        vector<int> arr, val, wt, drr;
        string ip;
        int number;
        getline(cin, ip);
        stringstream ss(ip);

        while (ss >> number) {
            arr.push_back(number);
        }

        getline(cin, ip);
        ss.clear();
        ss.str(ip);

        while (ss >> number) {
            val.push_back(number);
        }

        w = arr[0];
        n = val.size();
        getline(cin, ip);
        ss.clear();
        ss.str(ip);

        while (ss >> number) {
            wt.push_back(number);
        }
        Solution ob;
        cout << ob.knapSack(w, wt, val) << endl;
    }
    return 0;
}
// } Driver Code Ends