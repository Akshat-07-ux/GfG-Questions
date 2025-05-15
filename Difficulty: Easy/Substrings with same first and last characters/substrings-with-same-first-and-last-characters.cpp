//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
 public:
    int countSubstring(string &s) {
        // Frequency map to store count of each character
        unordered_map<char, int> freq;

        for (char ch : s) {
            freq[ch]++;
        }

        int count = 0;

        for (auto &pair : freq) {
            int f = pair.second;
            // Add single characters and combinations
            count += (f * (f + 1)) / 2;
        }

        return count;
    }
};

//{ Driver Code Starts.

int main() {

    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        string str;
        cin >> str;

        Solution ob;

        cout << ob.countSubstring(str) << "\n";

        cout << "~"
             << "\n";
    }

    return 0;
}
// } Driver Code Ends