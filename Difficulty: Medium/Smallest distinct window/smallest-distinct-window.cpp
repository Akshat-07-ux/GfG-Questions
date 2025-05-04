//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int findSubString(string& str) {
        int n = str.size();
        if (n == 0) return 0;

        // Count distinct characters in the string
        unordered_set<char> unique_chars(str.begin(), str.end());
        int total_unique = unique_chars.size();

        // Map to store frequency of characters in current window
        unordered_map<char, int> window_freq;
        int min_len = INT_MAX;

        int left = 0;
        int count = 0;

        for (int right = 0; right < n; ++right) {
            window_freq[str[right]]++;

            // Count how many unique characters are matched
            if (window_freq[str[right]] == 1) {
                count++;
            }

            // When all unique characters are in the window
            while (count == total_unique) {
                min_len = min(min_len, right - left + 1);

                // Try to shrink from the left
                window_freq[str[left]]--;
                if (window_freq[str[left]] == 0) {
                    count--;
                }
                left++;
            }
        }

        return min_len;
    }
};


//{ Driver Code Starts.
//      Driver code
int main() {
    int t;
    cin >> t;
    while (t--) {

        string str;
        cin >> str;
        Solution ob;
        cout << ob.findSubString(str) << endl;

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends