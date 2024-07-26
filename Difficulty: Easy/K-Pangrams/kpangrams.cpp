//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
public:
    bool kPangram(string str, int k) {
        vector<int> charCount(26, 0);
        int uniqueChars = 0;
        int totalChars = 0;
        
        // Count occurrences of each character
        for (char c : str) {
            if (isalpha(c)) {
                int index = c - 'a';
                if (charCount[index] == 0) {
                    uniqueChars++;
                }
                charCount[index]++;
                totalChars++;
            }
        }
        
        // If we don't have enough total characters, return false
        if (totalChars < 26) {
            return false;
        }
        
        // Calculate how many new characters we need to add
        int neededChars = 26 - uniqueChars;
        
        // Check if we have enough operations to make it a pangram
        return (neededChars <= k);
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        cin.ignore();
        string str;
        getline(cin, str);

        int k;
        cin >> k;

        Solution ob;
        bool a = ob.kPangram(str, k);
        if (a)
            cout << "true" << endl;
        else
            cout << "false" << endl;
    }
    return 0;
}
// } Driver Code Ends