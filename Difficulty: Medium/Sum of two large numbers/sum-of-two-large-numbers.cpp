//{ Driver Code Starts

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++
class Solution {
public:
    string findSum(string X, string Y) {
        // Ensure X is the longer string, or swap them if Y is longer
        if (X.length() < Y.length())
            swap(X, Y);
        
        // Reverse both strings to make addition easier from least significant digit
        reverse(X.begin(), X.end());
        reverse(Y.begin(), Y.end());
        
        string result = "";  // To store the sum
        int carry = 0;
        
        // Add each digit of Y to corresponding digit of X
        for (int i = 0; i < Y.length(); i++) {
            int sum = (X[i] - '0') + (Y[i] - '0') + carry;
            result.push_back((sum % 10) + '0');  // Store the last digit of sum
            carry = sum / 10;  // Carry forward the rest
        }
        
        // Add remaining digits of X (if X is longer)
        for (int i = Y.length(); i < X.length(); i++) {
            int sum = (X[i] - '0') + carry;
            result.push_back((sum % 10) + '0');  // Store the last digit of sum
            carry = sum / 10;  // Carry forward the rest
        }
        
        // If there's a carry left, append it
        if (carry) {
            result.push_back(carry + '0');
        }
        
        // Reverse the result to get the correct order
        reverse(result.begin(), result.end());
        
        // Remove any leading zeros (but leave at least one '0' if result is zero)
        int pos = 0;
        while (pos < result.length() && result[pos] == '0') {
            pos++;
        }
        if (pos == result.length()) {
            return "0";  // If all zeros, return "0"
        }
        
        return result.substr(pos);
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
        string x, y;
        cin >> x >> y;
        Solution ob;
        cout << ob.findSum(x, y) << "\n";
    }

    return 0;
}
// } Driver Code Ends