//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
 public:
    int maxLength(string& s) {
        int left = 0, right = 0, maxLength = 0;

        // Left to Right
        for (char c : s) {
            if (c == '(') left++;
            else right++;

            if (left == right) {
                maxLength = max(maxLength, 2 * right);
            } else if (right > left) {
                left = right = 0; // Reset counters
            }
        }

        left = right = 0;

        // Right to Left
        for (int i = s.size() - 1; i >= 0; i--) {
            if (s[i] == ')') right++;
            else left++;

            if (left == right) {
                maxLength = max(maxLength, 2 * left);
            } else if (left > right) {
                left = right = 0;
            }
        }

        return maxLength;
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
        cout << ob.maxLength(S) << "\n";

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends