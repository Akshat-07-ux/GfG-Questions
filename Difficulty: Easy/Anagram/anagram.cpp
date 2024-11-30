//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
   public:
    // Function to check whether two strings are anagrams of each other or not.
    bool areAnagrams(string& s1, string& s2) {
        // If the lengths are different, they cannot be anagrams.
        if (s1.size() != s2.size()) {
            return false;
        }
        
        // Create a frequency map for the characters in s1.
        unordered_map<char, int> freq;
        
        for (char c : s1) {
            freq[c]++;
        }
        
        // Decrease the frequency for characters in s2.
        for (char c : s2) {
            if (freq.find(c) == freq.end() || freq[c] == 0) {
                return false; // Character in s2 not found in s1 or frequency mismatch.
            }
            freq[c]--;
        }
        
        // If all frequencies are zero, the strings are anagrams.
        return true;
    }
};

//{ Driver Code Starts.

int main() {

    int t;

    cin >> t;

    while (t--) {
        string c, d;

        cin >> c >> d;
        Solution obj;
        if (obj.areAnagrams(c, d))
            cout << "true" << endl;
        else
            cout << "false" << endl;
        cout << "~" << endl;
    }
}

// } Driver Code Ends