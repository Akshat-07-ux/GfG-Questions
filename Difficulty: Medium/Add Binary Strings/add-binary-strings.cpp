//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++
class Solution {
  public:
    string addBinary(string& s1, string& s2) {
        int i = s1.size() - 1;
        int j = s2.size() - 1;
        int carry = 0;
        string result = "";

        // Iterate from the end of both strings
        while (i >= 0 || j >= 0 || carry > 0) {
            int bit1 = (i >= 0) ? s1[i--] - '0' : 0;
            int bit2 = (j >= 0) ? s2[j--] - '0' : 0;
            
            int sum = bit1 + bit2 + carry;
            carry = sum / 2;
            result += (sum % 2) + '0';
        }

        // Reverse the result as we built it backwards
        reverse(result.begin(), result.end());

        // Remove leading zeros if present
        size_t pos = result.find_first_not_of('0');
        return (pos == string::npos) ? "0" : result.substr(pos);
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string A, B;
        cin >> A >> B;
        Solution ob;
        cout << ob.addBinary(A, B);
        cout << "\n";

        cout << "~"
             << "\n";
    }
}

// Contributed By: Pranay Bansal

// } Driver Code Ends