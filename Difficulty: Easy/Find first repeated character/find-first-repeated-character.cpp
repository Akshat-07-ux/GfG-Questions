//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
string firstRepChar(string s);
int main()
 {
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        cout<<firstRepChar(s)<<endl;
    
cout << "~" << "\n";
}
	return 0;
}
// } Driver Code Ends

string firstRepChar(string s) {
    unordered_set<char> seen;  // Set to track characters we've encountered

    for (char c : s) {
        if (seen.find(c) != seen.end()) {
            // Character is already in the set, so it's the first repeated character
            return string(1, c);
        }
        // Add character to the set if it hasn't been seen
        seen.insert(c);
    }

    // If no repeated character is found, return "-1"
    return "-1";
}