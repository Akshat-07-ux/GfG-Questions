//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
   public:
    string smallestWindow(string s, string p) {
        vector<int> freq_p(256, 0), freq_window(256, 0);
        int start = 0, min_length = INT_MAX, count = 0;
        string result = "-1";

        // Count frequency of characters in p
        for (char c : p) {
            freq_p[c]++;
        }

        for (int end = 0; end < s.length(); end++) {
            // Process current character
            if (freq_p[s[end]] > 0 && ++freq_window[s[end]] <= freq_p[s[end]]) {
                count++;
            }

            // If all characters are matched
            if (count == p.length()) {
                // Try to minimize the window
                while (freq_p[s[start]] == 0 || freq_window[s[start]] > freq_p[s[start]]) {
                    if (freq_window[s[start]] > freq_p[s[start]]) {
                        freq_window[s[start]]--;
                    }
                    start++;
                }

                // Update result if current window is smaller
                int window_length = end - start + 1;
                if (window_length < min_length) {
                    min_length = window_length;
                    result = s.substr(start, min_length);
                }
            }
        }

        return result;
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