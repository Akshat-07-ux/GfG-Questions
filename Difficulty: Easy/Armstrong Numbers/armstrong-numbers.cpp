//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++
class Solution {
 public:
    string armstrongNumber(int n) {
        // Extract digits
        int digit1 = n / 100;       // hundreds digit
        int digit2 = (n / 10) % 10; // tens digit
        int digit3 = n % 10;        // units digit
        
        // Calculate the sum of cubes of digits
        int sumOfCubes = digit1 * digit1 * digit1 +
                         digit2 * digit2 * digit2 +
                         digit3 * digit3 * digit3;
        
        // Check if the sum of cubes is equal to the original number
        if (sumOfCubes == n) {
            return "true";
        } else {
            return "false";
        }
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        Solution ob;
        cout << ob.armstrongNumber(n) << endl;
    }
    return 0;
}

// } Driver Code Ends