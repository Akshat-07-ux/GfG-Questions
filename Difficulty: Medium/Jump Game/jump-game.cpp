//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution {
    public:
    int canReach(int A[], int N) {
        int maxReach = 0; // Tracks the farthest index that can be reached
        
        for (int i = 0; i < N; i++) {
            if (i > maxReach) {
                // If we encounter an index that we cannot reach
                return 0;
            }
            maxReach = max(maxReach, i + A[i]);
            if (maxReach >= N - 1) {
                // If we can reach or go beyond the last index
                return 1;
            }
        }
        return 0; // Default return (shouldn't be reached for valid inputs)
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin>>N;
        
        int A[N];
        
        for(int i=0; i<N; i++)
            cin>>A[i];

        Solution ob;
        cout << ob.canReach(A,N) << endl;
    
cout << "~" << "\n";
}
    return 0;
}
// } Driver Code Ends