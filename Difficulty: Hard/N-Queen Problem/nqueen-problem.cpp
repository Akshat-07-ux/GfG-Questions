//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    vector<vector<int>> result;

    bool isSafe(vector<int>& board, int row, int col, int n) {
        for (int prevCol = 0; prevCol < col; prevCol++) {
            int prevRow = board[prevCol];
            if (prevRow == row || abs(prevRow - row) == abs(prevCol - col)) {
                return false;
            }
        }
        return true;
    }

    void solve(int col, vector<int>& board, int n) {
        if (col == n) {
            result.push_back(board);
            return;
        }

        for (int row = 1; row <= n; row++) {
            if (isSafe(board, row, col, n)) {
                board[col] = row;
                solve(col + 1, board, n);
            }
        }
    }

    vector<vector<int>> nQueen(int n) {
        vector<int> board(n, 0);
        solve(0, board, n);
        return result;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;

        Solution ob;
        vector<vector<int>> ans = ob.nQueen(n);
        if (ans.size() == 0)
            cout << -1 << "\n";
        else {
            sort(ans.begin(), ans.end());
            for (int i = 0; i < ans.size(); i++) {
                cout << "[";
                for (int u : ans[i])
                    cout << u << " ";
                cout << "] ";
            }
            cout << endl;
        }

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends