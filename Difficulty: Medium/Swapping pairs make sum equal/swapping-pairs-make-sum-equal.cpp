//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
public:
    int findSwapValues(int a[], int n, int b[], int m) {
        // Step 1: Calculate the sum of both arrays
        long long sum_a = 0, sum_b = 0;
        for (int i = 0; i < n; i++) sum_a += a[i];
        for (int i = 0; i < m; i++) sum_b += b[i];
        
        // Step 2: Check if the difference is odd
        long long diff = sum_a - sum_b;
        if (diff % 2 != 0) {
            return -1;  // No solution possible if the difference is odd
        }
        
        // Step 3: Calculate the target difference
        long long target_diff = diff / 2;
        
        // Step 4: Sort array b for binary search
        std::sort(b, b + m);
        
        // Step 5: Iterate through array a and search for (a[i] - target_diff) in array b
        for (int i = 0; i < n; i++) {
            int needed_val = a[i] - target_diff;
            if (std::binary_search(b, b + m, needed_val)) {
                return 1;  // Found a pair that satisfies the condition
            }
        }
        
        // If no pair is found, return -1
        return -1;
    }
};

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        int a[n];
        int b[m];
        for (int i = 0; i < n; i++)
            cin >> a[i];
        for (int i = 0; i < m; i++)
            cin >> b[i];

        Solution ob;
        cout << ob.findSwapValues(a, n, b, m);
        cout << "\n";
    }
    return 0;
}

// } Driver Code Ends