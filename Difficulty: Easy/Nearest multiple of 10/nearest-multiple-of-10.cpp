//{ Driver Code Starts
#include <iostream>
using namespace std;


// } Driver Code Ends

class Solution {
 public:
    std::string roundToNearest(std::string str) {
        int n = str.size();
        int lastDigit = str[n-1] - '0';  // Extract the last digit

        if (lastDigit <= 5) {
            // Round down: Set last digit to '0'
            str[n-1] = '0';
        } else {
            // Round up: Set last digit to '0' and add 1 to the preceding part
            str[n-1] = '0';
            int i = n - 2;
            
            // Carry the 1 back through the number, if necessary
            while (i >= 0 && str[i] == '9') {
                str[i] = '0';  // Set current digit to '0'
                i--;
            }
            if (i >= 0) {
                str[i] += 1;  // Increment the digit
            } else {
                str = '1' + str;  // If all digits were 9, prepend '1'
            }
        }

        return str;
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
        cout << ob.roundToNearest(str) << endl;
    }

    return 0;
}
// } Driver Code Ends