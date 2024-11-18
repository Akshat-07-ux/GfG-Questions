//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
public:
    void dfs(vector<vector<int>>& grid, int i, int j, int n, int m) {
        // Base case: check boundaries and if the current cell is water (0)
        if (i < 0 || j < 0 || i >= n || j >= m || grid[i][j] == 0) return;
        
        // Mark the cell as visited
        grid[i][j] = 0;

        // Explore all 4 possible directions
        dfs(grid, i + 1, j, n, m); // Down
        dfs(grid, i - 1, j, n, m); // Up
        dfs(grid, i, j + 1, n, m); // Right
        dfs(grid, i, j - 1, n, m); // Left
    }

    int numberOfEnclaves(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        // Step 1: Mark all boundary-connected land cells using DFS
        for (int i = 0; i < n; i++) {
            if (grid[i][0] == 1) dfs(grid, i, 0, n, m);          // Left boundary
            if (grid[i][m - 1] == 1) dfs(grid, i, m - 1, n, m);   // Right boundary
        }
        for (int j = 0; j < m; j++) {
            if (grid[0][j] == 1) dfs(grid, 0, j, n, m);           // Top boundary
            if (grid[n - 1][j] == 1) dfs(grid, n - 1, j, n, m);   // Bottom boundary
        }

        // Step 2: Count the remaining land cells
        int count = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 1) count++;
            }
        }

        return count;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid(n, vector<int>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        cout << obj.numberOfEnclaves(grid) << endl;
    
cout << "~" << "\n";
}
}
// } Driver Code Ends