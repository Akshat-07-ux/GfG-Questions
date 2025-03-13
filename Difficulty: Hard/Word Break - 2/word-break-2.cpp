//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

// User function Template for C++

class Solution {
public:
    unordered_map<string, vector<string>> memo;
    
    vector<string> wordBreakUtil(string s, unordered_set<string>& dict) {
        if (memo.find(s) != memo.end()) return memo[s]; // Return cached results

        vector<string> result;
        if (dict.count(s)) result.push_back(s); // If whole string is a valid word

        for (int i = 1; i < s.size(); i++) {
            string left = s.substr(0, i);
            if (dict.count(left)) {
                vector<string> rightParts = wordBreakUtil(s.substr(i), dict);
                for (string& part : rightParts) {
                    result.push_back(left + " " + part);
                }
            }
        }

        return memo[s] = result;
    }

    vector<string> wordBreak(vector<string>& dict, string s) {
        unordered_set<string> wordDict(dict.begin(), dict.end());
        return wordBreakUtil(s, wordDict);
    }
};



//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<string> dict;
        string s;
        string line;
        getline(cin, line);
        stringstream ss(line);
        while (ss >> s) {
            dict.push_back(s);
        }
        cin >> s;
        cin.ignore();
        Solution ob;
        vector<string> ans = ob.wordBreak(dict, s);
        if (ans.size() == 0)
            cout << "Empty\n";
        else {
            sort(ans.begin(), ans.end());
            for (int i = 0; i < ans.size(); i++)
                cout << "(" << ans[i] << ")";
            cout << endl;
        }
        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends