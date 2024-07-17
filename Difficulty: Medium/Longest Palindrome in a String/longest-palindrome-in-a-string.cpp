//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
public:
    string longestPalin (string S) {
        int n = S.size();
        if (n == 0) return "";
        
        // Initialize start position and max length of the palindrome substring
        int start = 0, maxLength = 1;
        
        // Helper function to expand around the center
        auto expandAroundCenter = [&](int left, int right) {
            while (left >= 0 && right < n && S[left] == S[right]) {
                left--;
                right++;
            }
            int len = right - left - 1; // Length of the palindrome
            if (len > maxLength) {
                start = left + 1;
                maxLength = len;
            }
        };
        
        for (int i = 0; i < n; ++i) {
            // Check for odd length palindrome centered at i
            expandAroundCenter(i, i);
            // Check for even length palindrome centered at i and i+1
            expandAroundCenter(i, i + 1);
        }
        
        return S.substr(start, maxLength);
    }
};


//{ Driver Code Starts.

int main()
{
    int t; cin >> t;
    while (t--)
    {
        string S; cin >> S;
        
        Solution ob;
        cout << ob.longestPalin (S) << endl;
    }
}
// Contributed By: Pranay Bansal

// } Driver Code Ends