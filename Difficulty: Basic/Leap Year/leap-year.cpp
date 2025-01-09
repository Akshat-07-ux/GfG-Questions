//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
public:
    bool checkYear(int n) {
        // A year is a leap year if:
        // 1. It is divisible by 4 and not divisible by 100, OR
        // 2. It is divisible by 400
        if ((n % 4 == 0 && n % 100 != 0) || (n % 400 == 0)) {
            return true;
        }
        return false;
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

        if (ob.checkYear(N))
            cout << "true" << endl;
        else
            cout << "false" << endl;

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends