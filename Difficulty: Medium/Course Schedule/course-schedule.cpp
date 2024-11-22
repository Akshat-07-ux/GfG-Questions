//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution
{
public:
    vector<int> findOrder(int n, int m, vector<vector<int>> prerequisites) {
        vector<int> adj[n]; // Adjacency list
        vector<int> indegree(n, 0); // Indegree of each task
        vector<int> order; // To store the task order

        // Build the graph
        for (auto& pair : prerequisites) {
            int u = pair[1];
            int v = pair[0];
            adj[u].push_back(v);
            indegree[v]++;
        }

        // Use a queue to perform topological sort
        queue<int> q;

        // Push all tasks with indegree 0
        for (int i = 0; i < n; i++) {
            if (indegree[i] == 0) {
                q.push(i);
            }
        }

        // Perform BFS (Kahn's Algorithm)
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            order.push_back(node);

            // Reduce the indegree of neighbors
            for (int neighbor : adj[node]) {
                indegree[neighbor]--;
                if (indegree[neighbor] == 0) {
                    q.push(neighbor);
                }
            }
        }

        // If the number of tasks in the order is less than n, it means there's a cycle
        if (order.size() < n) return {};

        return order;
    }
};

//{ Driver Code Starts.

int check(int V, vector <int> &res, vector<int> adj[]) {
    vector<int> map(V, -1);
    for (int i = 0; i < V; i++) {
        map[res[i]] = i;
    }
    for (int i = 0; i < V; i++) {
        for (int v : adj[i]) {
            if (map[i] > map[v]) return 0;
        }
    }
    return 1;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        int n, m;
        cin >> n >> m;
        int u, v;

        vector<vector<int>> prerequisites;

        for (int i = 0; i < m; i++) {
            cin >> u >> v;
            prerequisites.push_back({u,v});
        }
        
        vector<int> adj[n];
        for (auto pre : prerequisites)
            adj[pre[1]].push_back(pre[0]);
        
        Solution obj;
        vector <int> res = obj.findOrder(n, m, prerequisites);
        if(!res.size())
            cout<<"No Ordering Possible"<<endl;
        else
            cout << check(n, res, adj) << endl;
    
cout << "~" << "\n";
}
    
    return 0;
}
// } Driver Code Ends