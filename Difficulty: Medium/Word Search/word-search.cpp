//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
public:
    int n, m;
    
    bool dfs(vector<vector<char>>& mat, string& word, int i, int j, int index, vector<vector<bool>>& visited) {
        if (index == word.length()) return true;
        if (i < 0 || i >= n || j < 0 || j >= m || mat[i][j] != word[index] || visited[i][j]) 
            return false;
        
        visited[i][j] = true;
        
        // Explore 4 possible directions: up, down, left, right
        bool found = dfs(mat, word, i + 1, j, index + 1, visited) ||
                     dfs(mat, word, i - 1, j, index + 1, visited) ||
                     dfs(mat, word, i, j + 1, index + 1, visited) ||
                     dfs(mat, word, i, j - 1, index + 1, visited);
        
        visited[i][j] = false;  // Backtrack
        
        return found;
    }

    bool isWordExist(vector<vector<char>>& mat, string& word) {
        n = mat.size();
        m = mat[0].size();
        
        vector<vector<bool>> visited(n, vector<bool>(m, false));
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (mat[i][j] == word[0] && dfs(mat, word, i, j, 0, visited))
                    return true;
            }
        }
        
        return false;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, m;
        cin >> n >> m;
        vector<vector<char>> mat(n, vector<char>(m, '*'));
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                cin >> mat[i][j];
        string word;
        cin >> word;
        Solution obj;
        bool ans = obj.isWordExist(mat, word);
        if (ans)
            cout << "true\n";
        else
            cout << "false\n";

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends