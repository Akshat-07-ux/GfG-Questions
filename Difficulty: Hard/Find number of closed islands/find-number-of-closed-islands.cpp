//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

//User function Template for C++

class Solution {
 public:
    int N, M;
    
    // Directions: Up, Right, Down, Left
    int dx[4] = {-1, 0, 1, 0};
    int dy[4] = {0, 1, 0, -1};
    
    // DFS function to mark the whole island as visited
    void dfs(vector<vector<int>>& mat, int x, int y) {
        if (x < 0 || x >= N || y < 0 || y >= M || mat[x][y] == 0) return;
        
        mat[x][y] = 0; // Mark as visited
        
        // Visit all 4 directions
        for (int i = 0; i < 4; i++) {
            dfs(mat, x + dx[i], y + dy[i]);
        }
    }
    
    int closedIslands(vector<vector<int>>& mat, int n, int m) {
        N = n, M = m;
        
        // Step 1: Remove all border islands
        for (int i = 0; i < N; i++) {
            if (mat[i][0] == 1) dfs(mat, i, 0);      // Left border
            if (mat[i][M - 1] == 1) dfs(mat, i, M - 1); // Right border
        }
        for (int j = 0; j < M; j++) {
            if (mat[0][j] == 1) dfs(mat, 0, j);      // Top border
            if (mat[N - 1][j] == 1) dfs(mat, N - 1, j); // Bottom border
        }
        
        // Step 2: Count closed islands in the inner matrix
        int count = 0;
        for (int i = 1; i < N - 1; i++) {
            for (int j = 1; j < M - 1; j++) {
                if (mat[i][j] == 1) {
                    count++;
                    dfs(mat, i, j); // Mark entire island as visited
                }
            }
        }
        
        return count;
    }
};



//{ Driver Code Starts.
int main() {
	int t;
	cin>>t;
	while(t--)
	{
        int N, M;
        cin >> N >> M;
        vector<vector<int>>matrix(N, vector<int>(M, 0));
        for(int i=0; i<N; i++)
            for(int j=0; j<M; j++)
                cin >> matrix[i][j];
                
        Solution obj;
        int ans = obj.closedIslands(matrix, N, M);
        cout << ans << "\n";
    
cout << "~" << "\n";
}
	
	return 0;
	
}


// } Driver Code Ends