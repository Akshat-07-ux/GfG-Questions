//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
 public:
    void dfs(vector<vector<char>>& grid, int x, int y) {
        int n = grid.size();
        int m = grid[0].size();
        
        // Boundary checks and if the current cell is not land
        if (x < 0 || y < 0 || x >= n || y >= m || grid[x][y] == '0')
            return;

        // Mark the current cell as visited by setting it to '0'
        grid[x][y] = '0';

        // Explore all 8 directions
        dfs(grid, x - 1, y);     // Up
        dfs(grid, x + 1, y);     // Down
        dfs(grid, x, y - 1);     // Left
        dfs(grid, x, y + 1);     // Right
        dfs(grid, x - 1, y - 1); // Top-Left Diagonal
        dfs(grid, x - 1, y + 1); // Top-Right Diagonal
        dfs(grid, x + 1, y - 1); // Bottom-Left Diagonal
        dfs(grid, x + 1, y + 1); // Bottom-Right Diagonal
    }
    
    int numIslands(vector<vector<char>>& grid) {
        if (grid.empty()) return 0;
        
        int n = grid.size();
        int m = grid[0].size();
        int islandCount = 0;
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == '1') {
                    // We found an unvisited land, this starts a new island
                    dfs(grid, i, j);
                    islandCount++;
                }
            }
        }
        
        return islandCount;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, m;
        cin >> n >> m;
        vector<vector<char>> grid(n, vector<char>(m, '#'));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        int ans = obj.numIslands(grid);
        cout << ans << '\n';
    }
    return 0;
}
// } Driver Code Ends