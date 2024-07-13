//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    // Function is to check whether two strings are anagram of each other or not.
    bool isAnagram(string a, string b) {
        // Step 1: Check if lengths are different
        if (a.length() != b.length()) {
            return false;
        }

        // Step 2: Create frequency arrays for both strings
        vector<int> count(26, 0); // Since there are 26 lowercase English letters

        // Count characters for string a
        for (char ch : a) {
            count[ch - 'a']++;
        }

        // Subtract characters for string b
        for (char ch : b) {
            count[ch - 'a']--;
        }

        // Check if all counts are zero
        for (int i : count) {
            if (i != 0) {
                return false;
            }
        }

        return true;
    }
};

//{ Driver Code Starts.

int main() {
    
    int t;

    cin >> t;

    while(t--){
        string c, d;

        cin >> c >> d;
        Solution obj;
        if(obj.isAnagram(c, d)) cout << "YES" << endl;
        else cout << "NO" << endl;
    }

}

// } Driver Code Ends