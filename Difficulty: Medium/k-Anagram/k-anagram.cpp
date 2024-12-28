//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution {
   public:
    bool areKAnagrams(string &s1, string &s2, int k) {
        // Condition 1: Both strings must have the same length
        if (s1.size() != s2.size()) {
            return false;
        }

        // Frequency array to count characters in s1 and s2
        vector<int> freq(26, 0);

        // Count frequency of characters in s1
        for (char c : s1) {
            freq[c - 'a']++;
        }

        // Decrease frequency based on characters in s2
        for (char c : s2) {
            freq[c - 'a']--;
        }

        // Count the number of mismatched characters
        int mismatchCount = 0;
        for (int count : freq) {
            if (count > 0) {
                mismatchCount += count;
            }
        }

        // If mismatches can be resolved within k changes, return true
        return mismatchCount <= k;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string str1, str2;
        cin >> str1 >> str2;
        int k;
        cin >> k;
        Solution ob;
        if (ob.areKAnagrams(str1, str2, k) == true)
            cout << "true\n";
        else
            cout << "false\n";
    }
}
// } Driver Code Ends