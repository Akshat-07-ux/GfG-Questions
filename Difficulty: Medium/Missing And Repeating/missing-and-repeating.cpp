//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
class Solution {
  public:
    vector<int> findTwoElement(vector<int>& arr) {
        long long n = arr.size();
        long long sumN = (n * (n + 1)) / 2;          // Expected sum of first n natural numbers
        long long sumSqN = (n * (n + 1) * (2 * n + 1)) / 6;  // Expected sum of squares of first n numbers
        
        long long actualSum = 0, actualSumSq = 0;
        
        for (int i = 0; i < n; i++) {
            actualSum += arr[i];
            actualSumSq += (long long)arr[i] * arr[i];
        }
        
        // Let x be the missing number and y be the repeating number
        long long diffSum = sumN - actualSum;         // x - y
        long long diffSumSq = sumSqN - actualSumSq;   // x^2 - y^2
        
        // (x^2 - y^2) = (x - y)(x + y)
        long long sumXY = diffSumSq / diffSum;        // x + y
        
        long long x = (diffSum + sumXY) / 2;          // x = (diffSum + sumXY) / 2
        long long y = sumXY - x;                      // y = sumXY - x
        
        return {(int)y, (int)x};
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        auto ans = ob.findTwoElement(a);
        cout << ans[0] << " " << ans[1] << "\n";
    }
    return 0;
}
// } Driver Code Ends