//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

string merge (string s1, string s2);

int main()
{
    int t; cin >> t;
    while (t--)
    {
        string s1; cin >> s1;
        string s2; cin >> s2;

        cout << merge (s1, s2) << endl;
    
cout << "~" << "\n";
}
}

// Contributed By: Pranay Bansal

// } Driver Code Ends


string merge(string S1, string S2) {
    string result = "";
    int i = 0, j = 0;

    // Merge characters alternately from both strings
    while (i < S1.length() && j < S2.length()) {
        result += S1[i++];
        result += S2[j++];
    }

    // If S1 has remaining characters
    while (i < S1.length()) {
        result += S1[i++];
    }

    // If S2 has remaining characters
    while (j < S2.length()) {
        result += S2[j++];
    }

    return result;
}
