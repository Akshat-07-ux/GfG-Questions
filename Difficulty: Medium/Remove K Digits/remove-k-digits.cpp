//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
 public:
    string removeKdigits(string S, int K) {
        int n = S.size();
        stack<char> st;

        // Iterate over the digits of S
        for (char digit : S) {
            // Remove digits from the stack if they are greater than the current digit
            // and we still need to remove more digits (K > 0)
            while (!st.empty() && K > 0 && st.top() > digit) {
                st.pop();
                K--;
            }
            // Push the current digit onto the stack
            st.push(digit);
        }

        // If K > 0, remove remaining digits from the end
        while (K > 0 && !st.empty()) {
            st.pop();
            K--;
        }

        // Construct the result from the stack
        string result = "";
        while (!st.empty()) {
            result += st.top();
            st.pop();
        }
        reverse(result.begin(), result.end());

        // Remove leading zeroes
        int start = 0;
        while (start < result.size() && result[start] == '0') {
            start++;
        }
        result = result.substr(start);

        // If the result is empty, return "0"
        return result.empty() ? "0" : result;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string S;
        cin >> S;
        int K;
        cin >> K;
        Solution obj;
        cout << obj.removeKdigits(S, K) << endl;
    
cout << "~" << "\n";
}
    return 0;
}

// } Driver Code Ends