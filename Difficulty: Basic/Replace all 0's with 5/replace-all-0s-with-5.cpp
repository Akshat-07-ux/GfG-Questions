//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

int convertFive(int n);


// } Driver Code Ends
/*you are required to complete this method*/
class Solution {
public:
    int convertFive(int n) {
        // If n is 0, return 5
        if (n == 0) return 5;
        
        // Variable to store the result
        int result = 0;
        
        // Multiplier to place digits in correct position
        int multiplier = 1;
        
        // Process each digit
        while (n > 0) {
            // Extract the current digit
            int digit = n % 10;
            
            // Replace 0 with 5
            if (digit == 0) {
                digit = 5;
            }
            
            // Add the digit to result
            result = digit * multiplier + result;
            
            // Move to next digit
            n /= 10;
            multiplier *= 10;
        }
        
        return result;
    }
};

//{ Driver Code Starts.

int main() {
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        Solution ob;
        cout << ob.convertFive(n) << endl;
    }
}
// } Driver Code Ends