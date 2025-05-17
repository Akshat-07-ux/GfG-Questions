//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
    public:
    int minimumNumberOfSwaps(string& s) {
        int open = 0, close = 0, imbalance = 0, swaps = 0;

        for (char c : s) {
            if (c == '[') {
                open++;
                if (imbalance > 0) {
                    swaps += imbalance;
                    imbalance--; // We "use" a pending closing bracket to pair with this
                }
            } else { // c == ']'
                close++;
                imbalance = close - open;
            }
        }

        return swaps;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string S;
        cin >> S;
        Solution ob;
        cout << ob.minimumNumberOfSwaps(S) << endl;

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends