//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution {
 public:
    int romanToDecimal(string &str) {
        // Map to store the values of Roman symbols
        unordered_map<char, int> roman = {
            {'I', 1}, {'V', 5}, {'X', 10},
            {'L', 50}, {'C', 100}, {'D', 500}, {'M', 1000}
        };
        
        int n = str.size();
        int result = 0;
        
        for (int i = 0; i < n; i++) {
            // If the current value is less than the next value, subtract it
            if (i < n - 1 && roman[str[i]] < roman[str[i + 1]]) {
                result -= roman[str[i]];
            } 
            // Otherwise, add the value
            else {
                result += roman[str[i]];
            }
        }
        
        return result;
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
        cout << ob.romanToDecimal(s) << endl;
    }
}
// } Driver Code Ends