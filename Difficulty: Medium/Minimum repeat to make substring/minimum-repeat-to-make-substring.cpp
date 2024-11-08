//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
 public:
    int minRepeats(string& s1, string& s2) {
        // The minimum number of repetitions required initially
        int repeat = 1;
        string repeatedString = s1;

        // Keep repeating s1 until the length of repeatedString is at least the length of s2
        while (repeatedString.length() < s2.length()) {
            repeatedString += s1;
            repeat++;
        }

        // Check if s2 is a substring of the current repeated string
        if (repeatedString.find(s2) != string::npos) {
            return repeat;
        }

        // Try one more repetition of s1
        repeatedString += s1;
        repeat++;

        // Check again if s2 is a substring
        if (repeatedString.find(s2) != string::npos) {
            return repeat;
        }

        // If s2 is not found, return -1
        return -1;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    scanf("%d ", &t);
    while (t--) {
        string A, B;
        getline(cin, A);
        getline(cin, B);

        Solution ob;
        cout << ob.minRepeats(A, B) << endl;
    }
    return 0;
}
// } Driver Code Ends