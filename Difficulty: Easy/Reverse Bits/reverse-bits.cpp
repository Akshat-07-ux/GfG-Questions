//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
 public:
    long long reversedBits(long long x) {
        long long result = 0; // To store the reversed bits in decimal form

        for (int i = 0; i < 32; i++) { // Loop through all 32 bits
            // Extract the last bit of x and shift it to the corresponding reversed position
            result = (result << 1) | (x & 1);

            // Right shift x to process the next bit
            x >>= 1;
        }

        return result;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        long long X;
        
        cin>>X;

        Solution ob;
        cout << ob.reversedBits(X) << endl;
    
cout << "~" << "\n";
}
    return 0;
}
// } Driver Code Ends