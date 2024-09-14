//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    int countSquares(int N) {
        // If N is less than or equal to 1, there are no perfect squares less than N
        if (N <= 1) return 0;
        
        // Find the largest integer whose square is less than N
        int count = sqrt(N - 1);
        
        return count;
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
        cout << ob.countSquares(N) << endl;
    }
    return 0;
}
// } Driver Code Ends