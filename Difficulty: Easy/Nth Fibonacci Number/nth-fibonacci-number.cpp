//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    int nthFibonacci(int n) {
        const int MOD = 1000000007;
        
        if (n == 1 || n == 2) {
            return 1; // Since the first Fibonacci number is 1, and the second is also 1
        }
        
        long long a = 1; // F(1)
        long long b = 1; // F(2)
        long long c; // Variable to store the next Fibonacci number
        
        for (int i = 3; i <= n; ++i) {
            c = (a + b) % MOD;
            a = b;
            b = c;
        }
        
        return b; // b holds the nth Fibonacci number
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
        cout << ob.nthFibonacci(n) << endl;
    }
    return 0;
}

// } Driver Code Ends