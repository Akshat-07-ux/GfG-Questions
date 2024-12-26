//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int binary_to_decimal(string &b) {
        int decimal = 0; // Initialize decimal value
        int n = b.size(); // Length of the binary string
        
        // Iterate through the binary string
        for (int i = 0; i < n; ++i) {
            if (b[i] == '1') {
                decimal += pow(2, n - i - 1); // Add 2^(position) if the bit is 1
            }
        }
        
        return decimal;
    }
};

//{ Driver Code Starts.
int main() {
    int T;
    cin >> T;
    while (T--) {
        string str;
        cin >> str;
        Solution ob;
        int ans = ob.binary_to_decimal(str);
        cout << ans << "\n";

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends