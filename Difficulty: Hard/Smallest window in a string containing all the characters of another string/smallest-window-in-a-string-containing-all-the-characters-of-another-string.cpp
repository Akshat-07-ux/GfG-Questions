//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
  public:
    // Function to find the smallest window in string s consisting of all characters of string p.
    string smallestWindow(string s, string p) {
        int m = s.length();
        int n = p.length();
        
        if (m < n) return "-1"; // If s is smaller than p, no valid window exists.
        
        // Frequency map for string p
        vector<int> pFreq(26, 0);
        for (char ch : p) pFreq[ch - 'a']++;
        
        // Sliding window frequency map for string s
        vector<int> sFreq(26, 0);
        
        int minWindowLen = INT_MAX;
        int start = 0, startIdx = -1;
        int count = 0; // To track how many characters are fully matched
        
        for (int end = 0; end < m; end++) {
            // Include current character in the window
            char endChar = s[end];
            sFreq[endChar - 'a']++;
            
            // If the current character's frequency is less than or equal to the required frequency
            if (pFreq[endChar - 'a'] != 0 && sFreq[endChar - 'a'] <= pFreq[endChar - 'a']) {
                count++;
            }
            
            // Once we have matched all characters
            while (count == n) {
                // Update minimum window if the current window is smaller
                if (end - start + 1 < minWindowLen) {
                    minWindowLen = end - start + 1;
                    startIdx = start;
                }
                
                // Try to shrink the window from the left
                char startChar = s[start];
                sFreq[startChar - 'a']--;
                
                // If the character we are removing is part of p and now its frequency is below requirement
                if (pFreq[startChar - 'a'] != 0 && sFreq[startChar - 'a'] < pFreq[startChar - 'a']) {
                    count--;
                }
                
                start++; // Move the start pointer to shrink the window
            }
        }
        
        // If startIdx was updated, return the substring, otherwise return "-1"
        return startIdx == -1 ? "-1" : s.substr(startIdx, minWindowLen);
    }
};

//{ Driver Code Starts.
int main()
 {
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        string pat;
        cin>>pat;
        Solution obj;
        cout<<obj.smallestWindow(s, pat)<<endl;
        
    }
	return 0;
}
// } Driver Code Ends