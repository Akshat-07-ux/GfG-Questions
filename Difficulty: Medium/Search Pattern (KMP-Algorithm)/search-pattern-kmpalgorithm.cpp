//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
 public:
    vector<int> search(string& pat, string& txt) {
        vector<int> result;
        int m = pat.size();
        int n = txt.size();

        // Step 1: Build the LPS (Longest Prefix Suffix) array
        vector<int> lps(m, 0);
        computeLPSArray(pat, m, lps);

        // Step 2: Perform the search
        int i = 0; // index for txt
        int j = 0; // index for pat
        while (i < n) {
            if (pat[j] == txt[i]) {
                i++;
                j++;
            }
            if (j == m) {
                // Found an occurrence of pat in txt
                result.push_back(i - j);
                j = lps[j - 1]; // Prepare for the next potential match
            } else if (i < n && pat[j] != txt[i]) {
                // Mismatch after j matches
                if (j != 0) {
                    j = lps[j - 1];
                } else {
                    i++;
                }
            }
        }
        return result;
    }

private:
    void computeLPSArray(string& pat, int m, vector<int>& lps) {
        int len = 0; // length of the previous longest prefix suffix
        lps[0] = 0; // lps[0] is always 0
        int i = 1;

        while (i < m) {
            if (pat[i] == pat[len]) {
                len++;
                lps[i] = len;
                i++;
            } else {
                if (len != 0) {
                    len = lps[len - 1];
                } else {
                    lps[i] = 0;
                    i++;
                }
            }
        }
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string S, pat;
        cin >> S >> pat;
        Solution ob;
        vector<int> res = ob.search(pat, S);
        if (res.size() == 0)
            cout << "[]" << endl;
        else {
            for (int i : res)
                cout << i << " ";
            cout << endl;
        }
    }
    return 0;
}

// } Driver Code Ends