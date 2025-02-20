//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
public:
    string oddEven(string s) {
        vector<int> freq(26, 0);

        // Count frequency of each character
        for (char c : s) {
            freq[c - 'a']++;
        }

        int x = 0, y = 0;

        // Iterate through the frequency array
        for (int i = 0; i < 26; i++) {
            if (freq[i] > 0) { // Consider only characters that appear in the string
                int position = i + 1; // Alphabet position (1-based)
                if (position % 2 == 0 && freq[i] % 2 == 0) {
                    x++; // Even position and even frequency
                } 
                else if (position % 2 == 1 && freq[i] % 2 == 1) {
                    y++; // Odd position and odd frequency
                }
            }
        }

        // Check if (x + y) is even or odd
        return (x + y) % 2 == 0 ? "EVEN" : "ODD";
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    scanf("%d ", &t);
    while (t--) {

        string s;
        getline(cin, s);

        Solution obj;
        string res = obj.oddEven(s);

        cout << res << "\n";
        cout << "~\n";
    }
}

// } Driver Code Ends