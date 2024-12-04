//{ Driver Code Starts
/* Driver program to test above function */

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
 public:
    int minChar(string& s) {
        string rev = s;
        reverse(rev.begin(), rev.end());
        string temp = s + "#" + rev;

        int n = temp.size();
        vector<int> lps(n, 0);

        for (int i = 1; i < n; ++i) {
            int j = lps[i - 1];
            while (j > 0 && temp[i] != temp[j]) {
                j = lps[j - 1];
            }
            if (temp[i] == temp[j]) {
                ++j;
            }
            lps[i] = j;
        }

        return s.size() - lps.back();
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string str;
        cin >> str;
        Solution ob;
        int ans = ob.minChar(str);
        cout << ans << endl;

        cout << "~"
             << "\n";
    }
    return 0;
}

// } Driver Code Ends