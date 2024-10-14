//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    int closestNumber(int N , int M) {
        // Find the quotient
        int quotient = N / M;
        
        // First candidate (closest less than or equal to N)
        int n1 = M * quotient;
        
        // Second candidate (closest greater than N)
        int n2 = (N * M > 0) ? M * (quotient + 1) : M * (quotient - 1);
        
        // Compare distances and return the closest
        if (abs(N - n1) < abs(N - n2)) {
            return n1;
        } else if (abs(N - n1) > abs(N - n2)) {
            return n2;
        } else {
            // Return the one with the larger absolute value
            return (abs(n1) > abs(n2)) ? n1 : n2;
        }
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N,M;
        
        cin>>N>>M;

        Solution ob;
        cout << ob.closestNumber(N,M) << endl;
    }
    return 0;
}
// } Driver Code Ends