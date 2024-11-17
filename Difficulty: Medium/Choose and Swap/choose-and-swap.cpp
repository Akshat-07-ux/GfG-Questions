//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
public:
    string chooseandswap(string str) {
        int n = str.length();
        set<char> seen;

        // Add all characters to the set to track characters that appear later
        for (char c : str) {
            seen.insert(c);
        }

        // Traverse the string to find the first character that can be swapped
        for (int i = 0; i < n; i++) {
            seen.erase(str[i]); // Remove the current character from the set

            // Check if there's a smaller character later in the string
            for (char c = 'a'; c < str[i]; c++) {
                if (seen.find(c) != seen.end()) {
                    // We found a smaller character 'c' that appears later
                    char to_replace = str[i];
                    char replace_with = c;

                    // Perform the swapping operation in the string
                    for (int j = 0; j < n; j++) {
                        if (str[j] == to_replace) str[j] = replace_with;
                        else if (str[j] == replace_with) str[j] = to_replace;
                    }

                    return str; // Return the modified string
                }
            }
        }

        // If no swap was performed, return the original string
        return str;
    }
};


//{ Driver Code Starts.

int main() {
    Solution obj;
    int t;
    cin >> t;
    while (t--) {
        string a;
        cin >> a;
        cout << obj.chooseandswap(a) << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends