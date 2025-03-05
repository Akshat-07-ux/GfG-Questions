//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
 public:
    static bool compare(string &a, string &b) {
        return a.length() < b.length();
    }
    
    int longestStringChain(vector<string>& words) {
        unordered_map<string, int> dp;
        int maxLength = 1;
        
        // Sort words by length
        sort(words.begin(), words.end(), compare);
        
        for (string word : words) {
            int best = 1;
            
            // Try removing each character to find predecessors
            for (int i = 0; i < word.length(); i++) {
                string prev = word.substr(0, i) + word.substr(i + 1);
                if (dp.find(prev) != dp.end()) {
                    best = max(best, dp[prev] + 1);
                }
            }
            
            dp[word] = best;
            maxLength = max(maxLength, best);
        }
        
        return maxLength;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<string> words;
        string input;
        getline(cin, input);
        stringstream ss(input);
        string number;
        while (ss >> number) {
            words.push_back(number);
        }
        Solution obj;
        cout << obj.longestStringChain(words) << "\n";
        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends