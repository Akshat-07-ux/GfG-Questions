//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
public:
    // Function to count distinct subsequences of a given string
    int countDistinctSubsequences(string str) {
        int n = str.size();
        vector<int> dp(n + 1, 0);
        dp[0] = 1; // Empty string has one subsequence: ""

        unordered_map<char, int> lastOccurrence;

        for (int i = 1; i <= n; i++) {
            char currentChar = str[i - 1];
            dp[i] = 2 * dp[i - 1];

            // If current character has appeared before, adjust the count
            if (lastOccurrence.find(currentChar) != lastOccurrence.end()) {
                int lastIndex = lastOccurrence[currentChar];
                dp[i] -= dp[lastIndex - 1];
            }
            // Update the last occurrence of the current character
            lastOccurrence[currentChar] = i;
        }

        // Return the count of distinct subsequences for the entire string
        return dp[n];
    }

    // Function to find the better string
    string betterString(string str1, string str2) {
        int count1 = countDistinctSubsequences(str1);
        int count2 = countDistinctSubsequences(str2);

        if (count1 > count2) return str1;
        else if (count2 > count1) return str2;
        else return str1;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string str1, str2;
        cin >> str1 >> str2;
        Solution obj;
        string ans = obj.betterString(str1, str2);
        cout << ans << "\n";
    
cout << "~" << "\n";
}
}

// } Driver Code Ends