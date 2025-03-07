//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends

/*complete the Function*/

class Solution {
public:
    vector<string> generateIp(string s) {
        vector<string> result;
        string current;
        backtrack(s, 0, 0, current, result);
        return result;
    }

private:
    void backtrack(const string &s, int start, int part, string current, vector<string> &result) {
        // If we have formed 4 parts and used all characters, add to result
        if (part == 4 && start == s.size()) {
            result.push_back(current);
            return;
        }

        // If parts exceed 4 or we run out of characters
        if (part >= 4 || start >= s.size()) return;

        for (int len = 1; len <= 3; len++) {
            if (start + len > s.size()) break; // Out of bounds check

            string segment = s.substr(start, len);
            int value = stoi(segment);

            // Check if the segment is valid
            if ((segment.size() > 1 && segment[0] == '0') || value > 255) continue;

            string newIp = current.empty() ? segment : current + "." + segment;
            backtrack(s, start + len, part + 1, newIp, result);
        }
    }
};

//{ Driver Code Starts.

int main() {
    int T;
    cin >> T;
    while (T--) {
        string s;
        cin >> s;

        /*generating naively*/
        Solution obj;
        vector<string> str = obj.generateIp(s);
        sort(str.begin(), str.end());
        if (str.size() == 0)
            cout << -1 << "\n";
        else {
            for (auto &u : str) {
                cout << u << "\n";
            }
        }

        cout << "~"
             << "\n";
    }
}
// } Driver Code Ends