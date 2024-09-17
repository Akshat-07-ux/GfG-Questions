//{ Driver Code Starts
// Initial template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for c++
class Solution {
    public:
    int findMaxLen(string s) {
        int left = 0, right = 0;
        int max_len = 0;
        
        // Traverse from left to right
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == '(') {
                left++;
            } else {
                right++;
            }
            
            if (left == right) {
                max_len = max(max_len, 2 * right); // valid substring length
            } else if (right > left) {
                left = right = 0; // Reset counters if too many ')'
            }
        }
        
        // Reset counters for right-to-left pass
        left = right = 0;
        
        // Traverse from right to left
        for (int i = s.length() - 1; i >= 0; i--) {
            if (s[i] == '(') {
                left++;
            } else {
                right++;
            }
            
            if (left == right) {
                max_len = max(max_len, 2 * left); // valid substring length
            } else if (left > right) {
                left = right = 0; // Reset counters if too many '('
            }
        }
        
        return max_len;
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
        cout << ob.findMaxLen(S) << endl;
    }
    return 0;
}

// } Driver Code Ends