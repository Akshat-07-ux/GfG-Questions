class Solution {
   public:
    int minTime(vector<pair<int, int>> &dependency, int duration[], int n, int m) {
        vector<vector<int>> adj(n);  // adjacency list
        vector<int> indegree(n, 0);  // to track in-degrees

        // Build the graph
        for (auto &dep : dependency) {
            int u = dep.first;
            int v = dep.second;
            adj[u].push_back(v);
            indegree[v]++;
        }

        // Queue for topological sorting
        queue<int> q;
        vector<int> timeToComplete(n, 0); // Time to reach each module

        // Add all nodes with indegree 0 to queue
        for (int i = 0; i < n; i++) {
            if (indegree[i] == 0) {
                q.push(i);
                timeToComplete[i] = duration[i];
            }
        }

        int processed = 0;
        int maxTime = 0;

        while (!q.empty()) {
            int u = q.front();
            q.pop();
            processed++;

            for (int v : adj[u]) {
                // Relaxation: update the time to complete v
                if (timeToComplete[v] < timeToComplete[u] + duration[v]) {
                    timeToComplete[v] = timeToComplete[u] + duration[v];
                }

                indegree[v]--;
                if (indegree[v] == 0) {
                    q.push(v);
                }
            }
        }

        // If all modules are not processed → cycle exists
        if (processed != n)
            return -1;

        // Get the max time among all modules
        for (int i = 0; i < n; i++) {
            maxTime = max(maxTime, timeToComplete[i]);
        }

        return maxTime;
    }
};