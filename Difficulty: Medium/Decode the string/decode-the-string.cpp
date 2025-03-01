//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends


class Solution {
 public:
    string decodedString(string &s) {
        stack<int> countStack;
        stack<string> strStack;
        string currStr = "";
        int currNum = 0;

        for (char c : s) {
            if (isdigit(c)) {
                currNum = currNum * 10 + (c - '0'); // Handle multi-digit numbers
            } else if (c == '[') {
                countStack.push(currNum); // Store the repeat count
                strStack.push(currStr);   // Store the current string
                currStr = ""; 
                currNum = 0;
            } else if (c == ']') {
                int repeat = countStack.top();
                countStack.pop();
                string temp = currStr;
                for (int i = 1; i < repeat; i++) {
                    currStr += temp; // Repeat the string
                }
                currStr = strStack.top() + currStr; // Append to previous string
                strStack.pop();
            } else {
                currStr += c; // Append normal characters
            }
        }

        return currStr;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;

        Solution ob;
        cout << ob.decodedString(s) << "\n";

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends