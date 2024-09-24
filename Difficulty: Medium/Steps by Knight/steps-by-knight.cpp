//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution 
{
   public:
    // Function to find out minimum steps Knight needs to reach target position.
	int minStepToReachTarget(std::vector<int>&KnightPos, std::vector<int>&TargetPos, int N) {
	    // If knight is already at the target position
	    if (KnightPos[0] == TargetPos[0] && KnightPos[1] == TargetPos[1]) {
	        return 0;
	    }
	    
	    // Possible moves for a knight in 8 directions
	    std::vector<std::pair<int, int>> moves = {
	        {2, 1}, {2, -1}, {-2, 1}, {-2, -1},
	        {1, 2}, {1, -2}, {-1, 2}, {-1, -2}
	    };
	    
	    // Create a visited array to mark visited cells
	    std::vector<std::vector<bool>> visited(N + 1, std::vector<bool>(N + 1, false));
	    
	    // BFS queue to store positions and the current number of moves
	    std::queue<std::pair<std::pair<int, int>, int>> q;
	    
	    // Start BFS from the initial knight's position
	    q.push({{KnightPos[0], KnightPos[1]}, 0});
	    visited[KnightPos[0]][KnightPos[1]] = true;
	    
	    while (!q.empty()) {
	        auto current = q.front();
	        q.pop();
	        
	        int x = current.first.first;
	        int y = current.first.second;
	        int dist = current.second;  // Distance (number of moves) so far
	        
	        // Explore all possible moves for the knight
	        for (auto move : moves) {
	            int newX = x + move.first;
	            int newY = y + move.second;
	            
	            // Check if the new position is within the bounds of the chessboard
	            if (newX >= 1 && newX <= N && newY >= 1 && newY <= N && !visited[newX][newY]) {
	                // If we reached the target position, return the number of moves
	                if (newX == TargetPos[0] && newY == TargetPos[1]) {
	                    return dist + 1;
	                }
	                
	                // Otherwise, mark it as visited and push the new position with incremented distance
	                visited[newX][newY] = true;
	                q.push({{newX, newY}, dist + 1});
	            }
	        }
	    }
	    
	    // If we exhaust the search and don't find the target, return -1 (though in this problem, target is always reachable)
	    return -1;
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		vector<int>KnightPos(2);
		vector<int>TargetPos(2);
		int N;
		cin >> N;
		cin >> KnightPos[0] >> KnightPos[1];
		cin >> TargetPos[0] >> TargetPos[1];
		Solution obj;
		int ans = obj.minStepToReachTarget(KnightPos, TargetPos, N);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends