//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
 public:
    string oddEven(int n) {
        // If n is divisible by 2, it's even; otherwise, it's odd
        return (n % 2 == 0) ? "even" : "odd";
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        Solution ob;
        cout << ob.oddEven(N) << endl;
    }
    return 0;
}
// } Driver Code Ends