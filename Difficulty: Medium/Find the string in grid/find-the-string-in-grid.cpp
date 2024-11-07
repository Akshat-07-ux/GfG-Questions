//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    vector<vector<int>> searchWord(vector<vector<char>> &grid, string word) {
        vector<vector<int>> result;
        int n = grid.size();
        int m = grid[0].size();
        int len = word.size();
        
        // Direction vectors for the 8 possible directions
        int dx[] = {0, 0, -1, 1, -1, -1, 1, 1};
        int dy[] = {-1, 1, 0, 0, -1, 1, -1, 1};

        // Function to check if the word can be found starting from (x, y) in direction (dx, dy)
        auto isValid = [&](int x, int y, int dir) {
            for (int k = 0; k < len; k++) {
                int nx = x + k * dx[dir];
                int ny = y + k * dy[dir];
                
                // Check bounds and character match
                if (nx < 0 || ny < 0 || nx >= n || ny >= m || grid[nx][ny] != word[k]) {
                    return false;
                }
            }
            return true;
        };

        // Search for the word in all cells and directions
        set<pair<int, int>> found_positions;
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == word[0]) {
                    for (int dir = 0; dir < 8; dir++) {
                        if (isValid(i, j, dir)) {
                            found_positions.insert({i, j});
                            break; // Only add the starting position once
                        }
                    }
                }
            }
        }

        // Copy positions from set to vector for lexicographically sorted output
        for (auto &pos : found_positions) {
            result.push_back({pos.first, pos.second});
        }

        return result;
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<char>>grid(n, vector<char>(m,'x'));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++)
				cin >> grid[i][j];
		}
		string word;
		cin >> word;
		Solution obj;
		vector<vector<int>>ans = obj.searchWord(grid, word);
		if(ans.size() == 0)
		{
		    cout<<"-1\n";
		}
		else
		{
		    for(auto i: ans){
			for(auto j: i)
				cout << j << " ";
			cout << "\n";
		    }
		}
		
		
	
cout << "~" << "\n";
}
	return 0;
}
// } Driver Code Ends