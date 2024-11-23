//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
public:
    string longest(vector<string>& names) {
        string longestName = ""; // To store the longest name
        int maxLength = 0; // To track the maximum length

        for (const string& name : names) {
            // Update the longestName and maxLength if the current name is longer
            if (name.length() > maxLength) {
                longestName = name;
                maxLength = name.length();
            }
        }

        return longestName;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<string> names;
        string input1;
        getline(cin, input1);
        stringstream ss1(input1);
        string str;
        while (ss1 >> str) {
            names.push_back(str);
        }
        Solution obj;
        string res = obj.longest(names);
        cout << res << "\n~\n";
    }
}

// } Driver Code Ends