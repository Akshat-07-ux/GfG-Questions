//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
 public:
    int myAtoi(char *s) {
        int i = 0;  // Pointer to traverse the string
        int sign = 1;  // Default sign is positive
        long result = 0;  // Result as a long to handle overflow temporarily
        
        // Step 1: Skip leading whitespaces
        while (s[i] == ' ') {
            i++;
        }

        // Step 2: Check for a sign
        if (s[i] == '-' || s[i] == '+') {
            sign = (s[i] == '-') ? -1 : 1;
            i++;
        }

        // Step 3: Read digits and form the number
        while (s[i] >= '0' && s[i] <= '9') {
            result = result * 10 + (s[i] - '0');

            // Step 4: Check for overflow and underflow
            if (result * sign > INT_MAX) {
                return INT_MAX;
            } 
            if (result * sign < INT_MIN) {
                return INT_MIN;
            }
            i++;
        }

        return (int)(result * sign);
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        char s[20];
        cin >> s;
        Solution ob;
        int ans = ob.myAtoi(s);
        cout << ans << endl;
        cout << "~" << endl;
    }
}
// } Driver Code Ends