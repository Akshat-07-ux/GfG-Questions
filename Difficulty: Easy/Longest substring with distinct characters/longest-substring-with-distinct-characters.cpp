//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
public:
    int longestUniqueSubstr(string &s) {
        unordered_map<char, int> last_seen;
        int max_length = 0;
        int start = 0;

        for (int end = 0; end < s.size(); ++end) {
            char current_char = s[end];

            // If the character is already in the map, update the start of the window
            if (last_seen.find(current_char) != last_seen.end() && last_seen[current_char] >= start) {
                start = last_seen[current_char] + 1;
            }

            // Update the last seen index of the current character
            last_seen[current_char] = end;

            // Update the maximum length of the substring
            max_length = max(max_length, end - start + 1);
        }

        return max_length;
    }
};


//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {

        Solution obj;
        string s;
        cin >> s;
        cout << obj.longestUniqueSubstr(s) << endl;
        cout << "~"
             << "\n";
    }

    return 0;
}

// } Driver Code Ends