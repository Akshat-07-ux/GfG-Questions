//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution {
public:
    string rremove(string s) {
        bool found = false;
        string result = "";
        
        for (int i = 0; i < s.length(); i++) {
            if (i < s.length() - 1 && s[i] == s[i+1]) {
                found = true;
                while (i < s.length() - 1 && s[i] == s[i+1]) {
                    i++;
                }
            } else {
                result += s[i];
            }
        }
        
        if (found) {
            return rremove(result);
        }
        
        return result;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    string tc;
    getline(cin, tc);
    t = stoi(tc);
    while (t--) {
        string s;
        getline(cin, s);
        Solution ob;
        cout << ob.rremove(s) << "\n";
    }
    return 0;
}
// } Driver Code Ends