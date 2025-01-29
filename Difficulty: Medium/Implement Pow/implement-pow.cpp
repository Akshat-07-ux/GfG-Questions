//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++
class Solution {
 public:
    double power(double b, int e) {
        if (b == 0) return 0; // Edge case where b is 0
        if (e == 0) return 1; // Any number raised to power 0 is 1
        
        double result = 1.0;
        long long exp = abs((long long)e); // Convert e to long long to handle INT_MIN case
        
        while (exp > 0) {
            if (exp % 2 == 1) {
                result *= b;
            }
            b *= b;
            exp /= 2;
        }
        
        return (e < 0) ? (1.0 / result) : result;
    }
};

//{ Driver Code Starts.

int main() {
    cout << fixed << setprecision(5);
    int t;
    cin >> t;
    while (t--) {
        double b;
        cin >> b;
        int e;
        cin >> e;
        Solution ob;
        cout << ob.power(b, e) << endl;
        cout << "~" << endl;
    }

    return 0;
}
// } Driver Code Ends