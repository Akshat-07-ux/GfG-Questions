//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    // Possible moves of a Knight
    vector<pair<int, int>> directions = {
        {-2, -1}, {-2, 1}, {2, -1}, {2, 1},
        {-1, -2}, {-1, 2}, {1, -2}, {1, 2}
    };

    int minStepToReachTarget(vector<int>& KnightPos, vector<int>& TargetPos, int N) {
        // Convert 1-based index to 0-based index
        int startX = KnightPos[0] - 1;
        int startY = KnightPos[1] - 1;
        int targetX = TargetPos[0] - 1;
        int targetY = TargetPos[1] - 1;

        // If Knight is already at the target position
        if (startX == targetX && startY == targetY) return 0;

        // Queue for BFS
        queue<pair<int, int>> q;
        q.push({startX, startY});

        // 2D array to keep track of visited positions
        vector<vector<int>> visited(N, vector<int>(N, 0));
        visited[startX][startY] = 1;

        int steps = 0;

        // BFS Loop
        while (!q.empty()) {
            int size = q.size();
            steps++;

            for (int i = 0; i < size; i++) {
                pair<int, int> front = q.front();  // Fix: Use explicit pair declaration
                q.pop();
                int x = front.first, y = front.second; // Fix: Explicitly extract x and y

                // Explore all 8 possible moves
                for (auto& dir : directions) {
                    int newX = x + dir.first;
                    int newY = y + dir.second;

                    // If inside board and not visited
                    if (newX >= 0 && newY >= 0 && newX < N && newY < N && !visited[newX][newY]) {
                        // If reached target, return steps
                        if (newX == targetX && newY == targetY) return steps;

                        // Mark visited and add to queue
                        visited[newX][newY] = 1;
                        q.push({newX, newY});
                    }
                }
            }
        }

        return -1; // If not reachable
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
	
cout << "~" << "\n";
}
	return 0;
}
// } Driver Code Ends