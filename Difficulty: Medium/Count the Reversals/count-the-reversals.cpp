//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

int countRev (string s);
int main()
{
    int t; cin >> t;
    while (t--)
    {
        string s; cin >> s;
        cout << countRev (s) << '\n';
    
cout << "~" << "\n";
}
}

// Contributed By: Pranay Bansal
// } Driver Code Ends

int countRev(string s) {
    // If length is odd, it's impossible to balance
    if (s.length() % 2 != 0) return -1;
    
    int open = 0, close = 0; // Counts for unmatched opening and closing brackets
    
    for (char c : s) {
        if (c == '{') {
            open++;
        } else { // c == '}'
            if (open > 0) {
                open--; // Match an opening bracket
            } else {
                close++; // No opening bracket to match
            }
        }
    }
    
    // Calculate the minimum reversals required
    int reversals = (open + 1) / 2 + (close + 1) / 2;
    return reversals;
}