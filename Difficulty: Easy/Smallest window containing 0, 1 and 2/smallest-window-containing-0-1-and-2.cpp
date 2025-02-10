//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
public:
    int smallestSubstring(string S) {
        int n = S.length();
        unordered_map<char, int> freq;
        int left = 0, minLength = INT_MAX;
        int count = 0; // To track unique characters

        for (int right = 0; right < n; ++right) {
            char current = S[right];

            // If a new character (0,1,2) is found, increment the count
            if (freq[current] == 0 && (current == '0' || current == '1' || current == '2')) {
                count++;
            }

            // Increase frequency of the current character
            freq[current]++;

            // When all three characters are found, try to shrink the window
            while (count == 3) {
                minLength = min(minLength, right - left + 1);
                freq[S[left]]--;

                // If a character count becomes zero, decrease count
                if (freq[S[left]] == 0 && (S[left] == '0' || S[left] == '1' || S[left] == '2')) {
                    count--;
                }
                left++; // Shrink window from left
            }
        }

        return (minLength == INT_MAX) ? -1 : minLength;
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
        cout << ob.smallestSubstring(S);
        cout << endl;
    
cout << "~" << "\n";
}
}
// } Driver Code Ends