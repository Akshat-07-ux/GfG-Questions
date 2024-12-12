//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends


class Solution {
  public:
    // Function to count number of ways to reach the nth stair
    // when order does not matter.
    long long countWays(int n) {
        // The number of ways to climb n stairs when order doesn't matter
        // is equivalent to the number of partitions of n into 1s and 2s.
        // This is simply the number of 2s that can fit into n plus 1.
        return n / 2 + 1;
    }
};

//{ Driver Code Starts.
int main() {
    // taking count of testcases
    int t;
    cin >> t;

    while (t--) {
        // taking stair count
        int n;
        cin >> n;
        Solution ob;
        cout << ob.countWays(n) << endl; // Print the output from our pre computed array
    
cout << "~" << "\n";
}
    return 0;
}
// } Driver Code Ends