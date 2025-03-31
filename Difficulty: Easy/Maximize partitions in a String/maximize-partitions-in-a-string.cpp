//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
public:
    int maxPartitions(string &s) {
        unordered_map<char, int> lastIndex;
        int n = s.size();
        
        // Store the last occurrence of each character
        for (int i = 0; i < n; i++) {
            lastIndex[s[i]] = i;
        }

        int partitions = 0, end = 0, prev = -1;

        // Iterate and determine partitions
        for (int i = 0; i < n; i++) {
            end = max(end, lastIndex[s[i]]);
            if (i == end) { // If we reach the last occurrence of a character in the partition
                partitions++;
                prev = i;
            }
        }

        return partitions;
    }
};


//{ Driver Code Starts.

int main() {
    int tc;
    cin >> tc;

    for (int i = 0; i < tc; ++i) {
        string s;
        cin >> s;
        Solution obj;
        cout << obj.maxPartitions(s) << endl;
        cout << "~" << endl;
    }

    return 0;
}

// } Driver Code Ends