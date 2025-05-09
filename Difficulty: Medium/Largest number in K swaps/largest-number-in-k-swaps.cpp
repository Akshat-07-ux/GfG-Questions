//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends



class Solution {
 public:
    string maxNum; // global to store the best result
    
    void solve(string &s, int k, int index) {
        if (k == 0) return;

        char maxDigit = s[index];
        for (int i = index + 1; i < s.size(); ++i) {
            if (s[i] > maxDigit) {
                maxDigit = s[i];
            }
        }

        // If no greater digit found, no need to swap
        if (maxDigit != s[index]) {
            k--; // We'll use one swap batch here
        }

        for (int i = index; i < s.size(); ++i) {
            if (s[i] == maxDigit) {
                swap(s[index], s[i]);

                if (s.compare(maxNum) > 0)
                    maxNum = s;

                solve(s, k, index + 1); // continue with next index

                swap(s[index], s[i]); // backtrack
            }
        }
    }

    string findMaximumNum(string &s, int k) {
        maxNum = s;
        solve(s, k, 0);
        return maxNum;
    }
};


//{ Driver Code Starts.

int main() {
    int t, k;
    string str;

    cin >> t;
    while (t--) {
        cin >> k >> str;
        Solution ob;
        cout << ob.findMaximumNum(str, k) << endl;

        cout << "~"
             << "\n";
    }
    return 0;
}

// } Driver Code Ends