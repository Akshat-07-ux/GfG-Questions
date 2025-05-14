//{ Driver Code Starts
// Initial template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
 public:
    string countAndSay(int n) {
        // Base case: the first row of the sequence
        string result = "1";

        // Generate the sequence for rows 2 through n
        for (int i = 1; i < n; ++i) {
            string next = "";  // to build the next row in the sequence
            int count = 1;     // initialize the count for the first digit
            char current_char = result[0];  // start with the first character of the previous string
            
            // Traverse the current sequence and count the consecutive digits
            for (int j = 1; j < result.length(); ++j) {
                if (result[j] == current_char) {
                    count++;  // increment count if the character is the same
                } else {
                    // Append the count and the character to the next sequence
                    next += to_string(count) + current_char;
                    current_char = result[j];  // update the current character
                    count = 1;  // reset the count for the new character
                }
            }
            // Don't forget to append the last group of characters
            next += to_string(count) + current_char;
            
            // Update result for the next iteration
            result = next;
        }

        return result;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        Solution obj;
        cout << obj.countAndSay(n) << endl;

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends