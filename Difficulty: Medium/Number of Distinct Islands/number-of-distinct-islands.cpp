//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
public:
    void dfs(int i, int j, vector<vector<int>>& grid, vector<pair<int, int>>& shape, int baseI, int baseJ) {
        int n = grid.size();
        int m = grid[0].size();
        
        // Check boundaries and if cell is already visited or water
        if (i < 0 || i >= n || j < 0 || j >= m || grid[i][j] == 0) return;
        
        // Mark the cell as visited
        grid[i][j] = 0;
        
        // Record the relative position of the cell
        shape.push_back({i - baseI, j - baseJ});
        
        // Explore neighbors (up, down, left, right)
        dfs(i + 1, j, grid, shape, baseI, baseJ);
        dfs(i - 1, j, grid, shape, baseI, baseJ);
        dfs(i, j + 1, grid, shape, baseI, baseJ);
        dfs(i, j - 1, grid, shape, baseI, baseJ);
    }
    
    int countDistinctIslands(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        set<vector<pair<int, int>>> uniqueIslands;
        
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (grid[i][j] == 1) {
                    vector<pair<int, int>> shape;
                    dfs(i, j, grid, shape, i, j);
                    uniqueIslands.insert(shape);
                }
            }
        }
        
        // The number of distinct island shapes
        return uniqueIslands.size();
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
        cout << obj.countDistinctIslands(grid) << endl;
    
cout << "~" << "\n";
}
}
// } Driver Code Ends