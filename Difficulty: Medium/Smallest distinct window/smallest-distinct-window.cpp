//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
public:
    int findSubString(string str) {
        unordered_set<char> uniqueChars;  // To store all unique characters
        for (char c : str) {
            uniqueChars.insert(c);
        }

        int totalUniqueChars = uniqueChars.size();  // Total unique characters
        int left = 0, right = 0;  // Window pointers
        int minLength = INT_MAX;  // Initialize minimum length to a large value
        unordered_map<char, int> charCount;  // Count characters in the current window

        while (right < str.length()) {
            // Expand the right end of the window
            charCount[str[right]]++;
            right++;

            // When we have a valid window
            while (charCount.size() == totalUniqueChars) {
                // Update minimum length
                minLength = min(minLength, right - left);

                // Shrink the left end of the window
                charCount[str[left]]--;
                if (charCount[str[left]] == 0) {
                    charCount.erase(str[left]);  // Remove from count if it reaches 0
                }
                left++;
            }
        }

        return (minLength == INT_MAX) ? 0 : minLength;  // Return 0 if no window found
    }
};

//{ Driver Code Starts.
// Driver code
int main() {
    int t;
    cin >> t;
    while (t--) {

        string str;
        cin >> str;
        Solution ob;
        cout << ob.findSubString(str) << endl;
    }
    return 0;
}
// } Driver Code Ends