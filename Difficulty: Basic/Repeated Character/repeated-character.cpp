//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
 public:
    char firstRep(string s) {
        // Frequency array for 26 lowercase English letters
        int freq[26] = {0};

        // Count the frequency of each character
        for (char c : s) {
            freq[c - 'a']++;
        }

        // Find the first character with frequency > 1
        for (char c : s) {
            if (freq[c - 'a'] > 1) {
                return c;
            }
        }

        // No repeating character found
        return '#';
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string s; cin >> s;
        Solution ob;
        char res = ob.firstRep (s);
        if (res == '#') cout << -1 << endl;
        else cout << res << endl;
    
cout << "~" << "\n";
}
    return 0;
}



// } Driver Code Ends