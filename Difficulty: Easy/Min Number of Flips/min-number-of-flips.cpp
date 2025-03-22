//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

int minFlips (string s);
int32_t main()
{
    int t; cin >> t;
    while (t--)
    {
        string s; cin >> s;

        cout << minFlips (s) << endl;
    
cout << "~" << "\n";
}
}
// Contributed By: Pranay Bansal

// } Driver Code Ends


int minFlips(string S) {
    int n = S.size();
    int flips1 = 0, flips2 = 0;

    // Case 1: Starting with '0' (Pattern: 010101...)
    for (int i = 0; i < n; i++) {
        if (i % 2 == 0 && S[i] != '0') flips1++; // Even index should be '0'
        if (i % 2 == 1 && S[i] != '1') flips1++; // Odd index should be '1'
    }

    // Case 2: Starting with '1' (Pattern: 101010...)
    for (int i = 0; i < n; i++) {
        if (i % 2 == 0 && S[i] != '1') flips2++; // Even index should be '1'
        if (i % 2 == 1 && S[i] != '0') flips2++; // Odd index should be '0'
    }

    return min(flips1, flips2);
}