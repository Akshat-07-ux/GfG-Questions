//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
 public:
    // Function to find the first non-repeating character in a string.
    char nonRepeatingChar(string &s) {
        // Step 1: Create a frequency map to count occurrences of each character
        unordered_map<char, int> freq;

        // Step 2: Populate the frequency map
        for (char c : s) {
            freq[c]++;
        }

        // Step 3: Traverse the string to find the first character with frequency 1
        for (char c : s) {
            if (freq[c] == 1) {
                return c; // Return the first non-repeating character
            }
        }

        // Step 4: If no non-repeating character is found, return '$'
        return '$';
    }
};

//{ Driver Code Starts.

int main() {

    int T;
    cin >> T;

    while (T--) {

        string S;
        cin >> S;
        Solution obj;
        char ans = obj.nonRepeatingChar(S);

        if (ans != '$')
            cout << ans;
        else
            cout << "-1";

        cout << endl;

        cout << "~"
             << "\n";
    }

    return 0;
}

// } Driver Code Ends