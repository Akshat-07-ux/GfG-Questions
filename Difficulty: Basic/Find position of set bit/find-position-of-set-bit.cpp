//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
   public:
    int findPosition(int N) {
        // Check if N is 0 or has more than one set bit
        if (N == 0 || (N & (N - 1)) != 0) {
            return -1;
        }

        // Find the position of the single set bit
        int position = 1; // Position starts from 1
        while ((N & 1) == 0) { // Check if the least significant bit is not set
            N >>= 1;           // Right shift N to check the next bit
            position++;        // Increment position
        }
        return position;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;

        cin>>N;

        Solution ob;
        cout << ob.findPosition(N) << endl;
    
cout << "~" << "\n";
}
    return 0;
}
// } Driver Code Ends