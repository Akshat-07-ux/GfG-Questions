//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {

private:
    int n;
    vector<int> dx = {-1, 1, 0, 0};
    vector<int> dy = {0, 0, -1, 1};
    vector<vector<int>> parent;
    vector<int> size;

    int find(int x) {
        if (parent[x / n][x % n] != x)
            parent[x / n][x % n] = find(parent[x / n][x % n]);
        return parent[x / n][x % n];
    }

    void unite(int x, int y) {
        int px = find(x), py = find(y);
        if (px != py) {
            if (size[px] < size[py])
                swap(px, py);
            parent[py / n][py % n] = px;
            size[px] += size[py];
        }
    }

public:
    int MaxConnection(vector<vector<int>>& grid) {
        n = grid.size();
        parent.resize(n, vector<int>(n));
        size.resize(n * n, 1);

        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                parent[i][j] = i * n + j;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    for (int k = 0; k < 4; k++) {
                        int ni = i + dx[k], nj = j + dy[k];
                        if (ni >= 0 && ni < n && nj >= 0 && nj < n && grid[ni][nj] == 1)
                            unite(i * n + j, ni * n + nj);
                    }
                }
            }
        }

        int maxSize = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 0) {
                    set<int> neighbors;
                    for (int k = 0; k < 4; k++) {
                        int ni = i + dx[k], nj = j + dy[k];
                        if (ni >= 0 && ni < n && nj >= 0 && nj < n && grid[ni][nj] == 1)
                            neighbors.insert(find(ni * n + nj));
                    }
                    int totalSize = 1;
                    for (int neighbor : neighbors)
                        totalSize += size[neighbor];
                    maxSize = max(maxSize, totalSize);
                }
            }
        }

        return maxSize == 0 ? n * n : maxSize;
    }
};


//{ Driver Code Starts.
int main() {

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> grid(n, vector<int>(n));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> grid[i][j];
            }
        }

        Solution obj;
        cout << obj.MaxConnection(grid) << "\n";
    }
}

// } Driver Code Ends