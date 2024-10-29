//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
public:
    vector<string> wordBoggle(vector<vector<char>>& board, vector<string>& dictionary) {
        vector<string> result;
        unordered_set<string> dict(dictionary.begin(), dictionary.end());
        int rows = board.size(), cols = board[0].size();
        
        for (string word : dictionary) {
            bool found = false;
            for (int i = 0; i < rows; i++) {
                for (int j = 0; j < cols; j++) {
                    if (dfs(board, word, i, j, 0)) {
                        result.push_back(word);
                        found = true;
                        break;
                    }
                }
                if (found) break;
            }
        }
        
        sort(result.begin(), result.end());
        return result;
    }
    
private:
    bool dfs(vector<vector<char>>& board, string& word, int i, int j, int idx) {
        int rows = board.size(), cols = board[0].size();
        
        if (idx == word.length()) return true;
        if (i < 0 || i >= rows || j < 0 || j >= cols || board[i][j] != word[idx]) return false;
        
        char temp = board[i][j];
        board[i][j] = '#'; // mark as visited
        
        bool found = dfs(board, word, i-1, j-1, idx+1) ||
                      dfs(board, word, i-1, j,   idx+1) ||
                      dfs(board, word, i-1, j+1, idx+1) ||
                      dfs(board, word, i,   j-1, idx+1) ||
                      dfs(board, word, i,   j+1, idx+1) ||
                      dfs(board, word, i+1, j-1, idx+1) ||
                      dfs(board, word, i+1, j,   idx+1) ||
                      dfs(board, word, i+1, j+1, idx+1);
        
        board[i][j] = temp; // restore the original value
        return found;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        vector<string> dictionary;
        for (int i = 0; i < N; ++i) {
            string s;
            cin >> s;
            dictionary.push_back(s);
        }
        
        int R, C;
        cin >> R >> C;
        vector<vector<char> > board(R);
        for (int i = 0; i < R; i++) {
            board[i].resize(C);
            for (int j = 0; j < C; j++) cin >> board[i][j];
        }
        Solution obj;
        vector<string> output = obj.wordBoggle(board, dictionary);
        if (output.size() == 0)
            cout << "-1";
        else {
            sort(output.begin(), output.end());
            for (int i = 0; i < output.size(); i++) cout << output[i] << " ";
        }
        cout << endl;
    
cout << "~" << "\n";
}
}

// } Driver Code Ends