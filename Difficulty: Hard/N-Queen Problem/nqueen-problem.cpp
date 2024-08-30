//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    vector<vector<int>> nQueen(int n) {
        vector<vector<int>> solutions;
        vector<int> board(n, 0); // board[i] will represent the row position of the queen in the i-th column
        solveNQueens(n, 0, board, solutions);
        return solutions;
    }
    
private:
    void solveNQueens(int n, int col, vector<int>& board, vector<vector<int>>& solutions) {
        if (col == n) {
            solutions.push_back(board);
            return;
        }
        
        for (int row = 1; row <= n; ++row) {
            if (isSafe(row, col, board)) {
                board[col] = row;
                solveNQueens(n, col + 1, board, solutions);
                board[col] = 0; // backtrack
            }
        }
    }
    
    bool isSafe(int row, int col, const vector<int>& board) {
        for (int i = 0; i < col; ++i) {
            if (board[i] == row || // Check if a queen is in the same row
                abs(board[i] - row) == abs(i - col)) { // Check if a queen is on the same diagonal
                return false;
            }
        }
        return true;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        
        Solution ob;
        vector<vector<int>> ans = ob.nQueen(n);
        if(ans.size() == 0)
            cout<<-1<<"\n";
        else {
            for(int i = 0;i < ans.size();i++){
                cout<<"[";
                for(int u: ans[i])
                    cout<<u<<" ";
                cout<<"] ";
            }
            cout<<endl;
        }
    }
    return 0;
}
// } Driver Code Ends