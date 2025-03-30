//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

// User function template for C++
class Solution {
 public:
    string removeVowels(string& s) {
        unordered_set<char> vowels = {'a', 'e', 'i', 'o', 'u'};
        string result;
        
        for (char c : s) {
            if (vowels.find(c) == vowels.end()) { // If the character is not a vowel
                result += c;
            }
        }
        
        return result;
    }
};


//{ Driver Code Starts.

int main() {

    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    string tc;
    getline(cin, tc);
    t = stoi(tc);
    while (t--) {
        string s, ch;

        getline(cin, s);

        Solution ob;
        cout << ob.removeVowels(s) << "\n";

        cout << "~"
             << "\n";
    }

    return 0;
}
// } Driver Code Ends