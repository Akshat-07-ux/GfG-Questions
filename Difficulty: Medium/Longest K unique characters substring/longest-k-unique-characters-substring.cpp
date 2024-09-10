//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution{
public:
    int longestKSubstr(string s, int k) {
        // Base case: If k is greater than the length of the string, it's impossible
        if (k > s.size()) return -1;

        unordered_map<char, int> charCount;  // To store character frequencies
        int maxLength = -1;                  // To store the maximum length of the substring with exactly K unique characters
        int start = 0;                       // Left pointer of the sliding window

        // Traverse through the string with the right pointer (end)
        for (int end = 0; end < s.size(); ++end) {
            char rightChar = s[end];
            charCount[rightChar]++;  // Add the current character to the map
            
            // If we have more than 'K' unique characters, shrink the window
            while (charCount.size() > k) {
                char leftChar = s[start];
                charCount[leftChar]--;
                
                // If the frequency of a character becomes 0, remove it from the map
                if (charCount[leftChar] == 0) {
                    charCount.erase(leftChar);
                }
                
                // Move the start pointer to shrink the window
                start++;
            }
            
            // Check if we have exactly 'K' unique characters and update maxLength
            if (charCount.size() == k) {
                maxLength = max(maxLength, end - start + 1);
            }
        }

        return maxLength;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        int k;
        cin >> k;
        Solution ob;
        cout << ob.longestKSubstr(s, k) << endl;
    }
}

// } Driver Code Ends