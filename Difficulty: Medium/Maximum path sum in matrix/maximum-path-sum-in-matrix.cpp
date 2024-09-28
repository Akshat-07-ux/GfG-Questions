//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int maximumPath(int N, vector<vector<int>> Matrix) {
        // Start from the second row and compute the maximum path sum for each cell
        for (int i = 1; i < N; ++i) {
            for (int j = 0; j < N; ++j) {
                // Collect maximum value from the previous row: top, top-left, and top-right
                int top = Matrix[i-1][j]; // Directly above
                
                int top_left = (j > 0) ? Matrix[i-1][j-1] : 0; // Diagonal left
                int top_right = (j < N-1) ? Matrix[i-1][j+1] : 0; // Diagonal right
                
                // Update the current cell with the max of the possible previous positions
                Matrix[i][j] += max({top, top_left, top_right});
            }
        }

        // The maximum value in the last row is the answer
        int result = 0;
        for (int j = 0; j < N; ++j) {
            result = max(result, Matrix[N-1][j]);
        }
        
        return result;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        vector<vector<int>> Matrix(N, vector<int>(N, 0));
        for(int i = 0;i < N*N;i++)
            cin>>Matrix[(i/N)][i%N];
        
        Solution ob;
        cout<<ob.maximumPath(N, Matrix)<<"\n";
    }
    return 0;
}
// } Driver Code Ends