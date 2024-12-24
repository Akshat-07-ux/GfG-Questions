//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
 public:
    int minRow(vector<vector<int>> &mat) {
        int n = mat.size();      // Number of rows
        int m = mat[0].size();   // Number of columns

        int minCount = m + 1;    // Initialize with maximum possible value
        int minRowIndex = -1;    // Row index with the minimum count of 1's

        for (int i = 0; i < n; i++) {
            int count = 0;       // Count the number of 1's in the current row
            for (int j = 0; j < m; j++) {
                if (mat[i][j] == 1) count++;
            }

            // Update the row with the minimum count of 1's
            if (count < minCount) {
                minCount = count;
                minRowIndex = i + 1; // Convert to 1-based index
            } else if (count == minCount && i + 1 < minRowIndex) {
                minRowIndex = i + 1;
            }
        }

        return minRowIndex;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, M;
        cin >> N >> M;
        vector<vector<int>> mat(N, vector<int>(M));
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                cin >> mat[i][j];
            }
        }
        Solution ob;
        cout << ob.minRow(mat) << "\n";
        cout << "~\n";
    }
}
// } Driver Code Ends