//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

class Matrix {
  public:
    template <class T>
    static void input(vector<vector<T>> &A, int n, int m) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                scanf("%d ", &A[i][j]);
            }
        }
    }

    template <class T>
    static void print(vector<vector<T>> &A) {
        for (int i = 0; i < A.size(); i++) {
            for (int j = 0; j < A[i].size(); j++) {
                cout << A[i][j] << " ";
            }
            cout << endl;
        }
    }
};


// } Driver Code Ends

class Solution {
 public:
    int MinimumEffort(int rows, int columns, vector<vector<int>> &heights) {
        vector<pair<int, int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
        pq.push({0, 0, 0}); // {effort, row, col}

        vector<vector<int>> effort(rows, vector<int>(columns, INT_MAX));
        effort[0][0] = 0;

        while (!pq.empty()) {
            auto current = pq.top();
            pq.pop();
            int currEffort = current[0], r = current[1], c = current[2];

            if (r == rows - 1 && c == columns - 1) return currEffort;

            for (const auto &dir : directions) { // Fix for structured binding error
                int dr = dir.first, dc = dir.second;
                int newRow = r + dr, newCol = c + dc;

                if (newRow >= 0 && newRow < rows && newCol >= 0 && newCol < columns) {
                    int newEffort = max(currEffort, abs(heights[r][c] - heights[newRow][newCol]));
                    if (newEffort < effort[newRow][newCol]) {
                        effort[newRow][newCol] = newEffort;
                        pq.push({newEffort, newRow, newCol});
                    }
                }
            }
        }

        return 0;
    }
};



//{ Driver Code Starts.

int main() {
    int t;
    scanf("%d ", &t);
    while (t--) {

        int rows;
        scanf("%d", &rows);

        int columns;
        scanf("%d", &columns);

        vector<vector<int>> heights(rows, vector<int>(columns));
        Matrix::input(heights, rows, columns);

        Solution obj;
        int res = obj.MinimumEffort(rows, columns, heights);

        cout << res << endl;
    
cout << "~" << "\n";
}
}

// } Driver Code Ends