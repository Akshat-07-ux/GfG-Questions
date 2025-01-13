//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
public:
    int padovanSequence(int n) {
        const int MOD = 1e9 + 7;

        // Base cases
        if (n == 0 || n == 1 || n == 2) return 1;

        // Variables to store the last three values
        int p0 = 1, p1 = 1, p2 = 1;

        // Iterate from 3 to n to compute the nth Padovan number
        for (int i = 3; i <= n; ++i) {
            int current = (p0 + p1) % MOD;
            // Shift the values
            p0 = p1;
            p1 = p2;
            p2 = current;
        }

        return p2;
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
        cout << ob.padovanSequence(n) << endl;
    
cout << "~" << "\n";
}
    return 0;
}
// } Driver Code Ends