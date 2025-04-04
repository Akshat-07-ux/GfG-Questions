//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends


class Solution {
public:
    string convert(string& s) {
        int n = s.length();
        if (n == 0) return s; // Handle empty string
        
        if (islower(s[0])) s[0] = toupper(s[0]); // Convert first letter if lowercase
        
        for (int i = 1; i < n; i++) {
            if (s[i] == ' ' && i + 1 < n && islower(s[i + 1])) {
                s[i + 1] = toupper(s[i + 1]); // Convert the first letter of each word
            }
        }
        
        return s;
    }
};



//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        string str;
        getline(cin, str);
        Solution ob;
        cout << ob.convert(str) << endl;

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends