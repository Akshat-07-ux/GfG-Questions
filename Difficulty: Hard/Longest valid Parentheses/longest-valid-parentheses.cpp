//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
 public:
    int maxLength(string str) {
        // Stack to store indices of '(' and ')'
        stack<int> stk;
        // Initialize result variable to store the maximum length
        int max_len = 0;
        // Initialize base for valid substrings, -1 helps in the case when we find valid parenthesis from the beginning
        stk.push(-1);

        // Iterate through the string
        for (int i = 0; i < str.length(); i++) {
            // If opening parenthesis, push index onto the stack
            if (str[i] == '(') {
                stk.push(i);
            } else {
                // Pop the top of the stack
                stk.pop();
                
                // If stack is not empty, find the length of the current valid substring
                if (!stk.empty()) {
                    int len = i - stk.top();
                    max_len = max(max_len, len);
                } else {
                    // If the stack is empty, push the current index as a base for future valid substrings
                    stk.push(i);
                }
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
        cout << ob.maxLength(S) << "\n";
    }
    return 0;
}
// } Driver Code Ends