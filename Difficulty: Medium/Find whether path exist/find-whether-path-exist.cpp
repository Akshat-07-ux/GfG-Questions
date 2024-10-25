//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
public:
    // Function to find whether a path exists from the source to destination.
    bool is_Possible(vector<vector<int>>& grid) 
    {
        int n = grid.size();
        int sourceX, sourceY, destX, destY;

        // Find the source (1) and destination (2) coordinates
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    sourceX = i;
                    sourceY = j;
                }
                if (grid[i][j] == 2) {
                    destX = i;
                    destY = j;
                }
            }
        }
        
        // Directions for moving up, down, left, and right
        vector<pair<int, int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        
        // BFS Initialization
        queue<pair<int, int>> q;
        vector<vector<bool>> visited(n, vector<bool>(n, false));
        
        q.push({sourceX, sourceY});
        visited[sourceX][sourceY] = true;

        while (!q.empty()) {
            // Use pair to get the current position
            pair<int, int> current = q.front();
            q.pop();
            int x = current.first;  // Row index
            int y = current.second; // Column index

            // Check if we reached the destination
            if (x == destX && y == destY) {
                return true;
            }

            // Explore all possible directions
            for (auto& direction : directions) {
                int newX = x + direction.first;
                int newY = y + direction.second;

                // Check bounds and if the cell is valid (3 or 2)
                if (newX >= 0 && newX < n && newY >= 0 && newY < n &&
                    !visited[newX][newY] && (grid[newX][newY] == 2 || grid[newX][newY] == 3)) {
                    visited[newX][newY] = true;
                    q.push({newX, newY});
                }
            }
        }

        // If we exhaust the queue without finding the destination
        return false;
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<vector<int>>grid(n, vector<int>(n, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		bool ans = obj.is_Possible(grid);
		cout << ((ans) ? "1\n" : "0\n");
	
cout << "~" << "\n";
}
	return 0;
}
// } Driver Code Ends