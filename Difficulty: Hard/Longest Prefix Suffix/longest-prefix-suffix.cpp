//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

// User function template for C++

class Solution {
   public:
    int lps(string str) {
        int n = str.size();
        vector<int> lps(n, 0); // LPS array to store the longest prefix suffix values

        int len = 0; // Length of the previous longest prefix suffix
        int i = 1;

        // Loop to calculate lps[i] for i = 1 to n-1
        while (i < n) {
            if (str[i] == str[len]) {
                len++;
                lps[i] = len;
                i++;
            } else {
                if (len != 0) {
                    // Go back to the previous prefix suffix length
                    len = lps[len - 1];
                } else {
                    // If len == 0, set lps[i] to 0 and move forward
                    lps[i] = 0;
                    i++;
                }
            }
        }

        // The longest proper prefix which is also a suffix is given by lps[n-1]
        return lps[n - 1];
    }
};

//{ Driver Code Starts.

int main() {

    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        string str;
        cin >> str;

        Solution ob;

        cout << ob.lps(str) << "\n";
    }

    return 0;
}

// } Driver Code Ends