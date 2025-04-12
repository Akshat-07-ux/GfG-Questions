//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    void dfs(vector<vector<int>>& image, int x, int y, int originalColor, int newColor) {
        int n = image.size();
        int m = image[0].size();

        // Boundary and color check
        if (x < 0 || x >= n || y < 0 || y >= m || image[x][y] != originalColor)
            return;

        image[x][y] = newColor;

        // Explore 4-directionally: up, down, left, right
        dfs(image, x + 1, y, originalColor, newColor);
        dfs(image, x - 1, y, originalColor, newColor);
        dfs(image, x, y + 1, originalColor, newColor);
        dfs(image, x, y - 1, originalColor, newColor);
    }

    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        int originalColor = image[sr][sc];

        // If the newColor is same as original, no need to flood fill
        if (originalColor != newColor) {
            dfs(image, sr, sc, originalColor, newColor);
        }

        return image;
    }
};


//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> image(n, vector<int>(m, 0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++)
                cin >> image[i][j];
        }
        int sr, sc, newColor;
        cin >> sr >> sc >> newColor;
        Solution obj;
        vector<vector<int>> ans = obj.floodFill(image, sr, sc, newColor);
        for (auto i : ans) {
            for (auto j : i)
                cout << j << " ";
            cout << "\n";
        }

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends