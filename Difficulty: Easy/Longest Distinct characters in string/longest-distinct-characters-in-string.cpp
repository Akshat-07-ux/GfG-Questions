//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
int longestSubstrDistinctChars (string S);
int main()
{
    int t; cin >> t;
    while (t--)
    {
        string S; cin >> S;

        cout << longestSubstrDistinctChars (S) << endl;
    }
}

// Contributed By: Pranay Bansal

// } Driver Code Ends


int longestSubstrDistinctChars(string S)
{
    int n = S.length();
    unordered_map<char, int> last_seen;
    int max_len = 0, start = 0;
    
    for (int end = 0; end < n; end++) {
        // If the character has been seen and is within the current window
        if (last_seen.find(S[end]) != last_seen.end() && last_seen[S[end]] >= start) {
            // Move the start of the window to the right of the last seen character
            start = last_seen[S[end]] + 1;
        }
        
        // Update the last seen position of the current character
        last_seen[S[end]] = end;
        
        // Calculate the length of the current window and update max_len
        max_len = max(max_len, end - start + 1);
    }
    
    return max_len;
}