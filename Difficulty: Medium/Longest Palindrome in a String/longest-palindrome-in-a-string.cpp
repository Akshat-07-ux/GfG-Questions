//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
 public:
    string longestPalindrome(string &s) {
        int n = s.size();
        if (n == 0) return "";
        
        int start = 0, maxLength = 1;

        // Function to expand around the center
        auto expandAroundCenter = [&](int left, int right) -> pair<int, int> {
            while (left >= 0 && right < n && s[left] == s[right]) {
                left--;
                right++;
            }
            int length = right - left - 1;
            return make_pair(left + 1, length);
        };
        
        for (int i = 0; i < n; i++) {
            // Odd length palindrome
            pair<int, int> odd = expandAroundCenter(i, i);
            if (odd.second > maxLength) {
                maxLength = odd.second;
                start = odd.first;
            }
            
            // Even length palindrome
            pair<int, int> even = expandAroundCenter(i, i + 1);
            if (even.second > maxLength) {
                maxLength = even.second;
                start = even.first;
            }
        }
        
        return s.substr(start, maxLength);
    }
};



//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string S;
        cin >> S;

        Solution ob;
        cout << ob.longestPalindrome(S) << endl;

        cout << "~"
             << "\n";
    }
}

// } Driver Code Ends