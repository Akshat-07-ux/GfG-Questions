class Solution {
  public:
    string socialNetwork(int arr[], int N) {
        // Build adjacency list representation of the graph
        vector<vector<int>> graph(N + 1);
        
        // arr[i-2] represents who user i befriends (for users 2 to N)
        for (int i = 2; i <= N; i++) {
            int friend_of_i = arr[i - 2];
            graph[i].push_back(friend_of_i);
        }
        
        string result = "";
        
        // For each user from 2 to N
        for (int start = 2; start <= N; start++) {
            // Find shortest path to all users from 1 to start-1 using BFS
            vector<int> distance(N + 1, -1);
            queue<int> q;
            
            q.push(start);
            distance[start] = 0;
            
            while (!q.empty()) {
                int current = q.front();
                q.pop();
                
                // Explore all friends of current user
                for (int friend_user : graph[current]) {
                    if (distance[friend_user] == -1) {
                        distance[friend_user] = distance[current] + 1;
                        q.push(friend_user);
                    }
                }
            }
            
            // Check connections to users 1 to start-1
            for (int target = 1; target < start; target++) {
                if (distance[target] != -1) {
                    result += to_string(start) + " " + to_string(target) + " " + to_string(distance[target]) + " ";
                }
            }
        }
        
        // Remove trailing space if exists
        if (!result.empty() && result.back() == ' ') {
            result.pop_back();
        }
        
        return result;
    }
};