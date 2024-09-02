//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution{
public:
    // Direction vectors for moving left, right, up, down
    int dx[4] = {0, 0, -1, 1};
    int dy[4] = {-1, 1, 0, 0};
    
    // Function to return the minimum cost to reach the bottom-right cell from the top-left cell.
    int minimumCostPath(vector<vector<int>>& grid) 
    {
        int n = grid.size();
        // Priority queue to implement Dijkstra's algorithm
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
        
        // Distance matrix to store the minimum cost to reach each cell
        vector<vector<int>> dist(n, vector<int>(n, INT_MAX));
        
        // Start from the top-left cell
        dist[0][0] = grid[0][0];
        pq.push({grid[0][0], {0, 0}});
        
        while (!pq.empty())
        {
            int cost = pq.top().first;
            int x = pq.top().second.first;
            int y = pq.top().second.second;
            pq.pop();
            
            // Explore the four possible directions
            for (int i = 0; i < 4; i++)
            {
                int nx = x + dx[i];
                int ny = y + dy[i];
                
                // Check if the new position is within bounds
                if (nx >= 0 && ny >= 0 && nx < n && ny < n)
                {
                    int newCost = cost + grid[nx][ny];
                    
                    // If the new path offers a lower cost, update the distance and push it to the queue
                    if (newCost < dist[nx][ny])
                    {
                        dist[nx][ny] = newCost;
                        pq.push({newCost, {nx, ny}});
                    }
                }
            }
        }
        
        // The bottom-right cell will have the minimum cost to reach it
        return dist[n-1][n-1];
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
		int ans = obj.minimumCostPath(grid);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends