//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
	public:
    // Function to return list containing vertices in Topological order.
    vector<int> topoSort(int V, vector<int> adj[]) 
    {
        vector<int> inDegree(V, 0);
        vector<int> topoOrder;
        
        // Step 1: Calculate in-degree for each vertex
        for (int i = 0; i < V; ++i) {
            for (int neighbor : adj[i]) {
                inDegree[neighbor]++;
            }
        }
        
        // Step 2: Push all vertices with in-degree 0 into the queue
        queue<int> q;
        for (int i = 0; i < V; ++i) {
            if (inDegree[i] == 0) {
                q.push(i);
            }
        }
        
        // Step 3: Process the vertices in queue
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            topoOrder.push_back(node);
            
            // Decrease the in-degree of all its neighbors
            for (int neighbor : adj[node]) {
                inDegree[neighbor]--;
                
                // If in-degree becomes 0, add it to the queue
                if (inDegree[neighbor] == 0) {
                    q.push(neighbor);
                }
            }
        }
        
        return topoOrder;
    }
};

//{ Driver Code Starts.

/*  Function to check if elements returned by user
*   contains the elements in topological sorted form
*   V: number of vertices
*   *res: array containing elements in topological sorted form
*   adj[]: graph input
*/
int check(int V, vector <int> &res, vector<int> adj[]) {
    
    if(V!=res.size())
    return 0;
    
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
        int N, E;
        cin >> E >> N;
        int u, v;

        vector<int> adj[N];

        for (int i = 0; i < E; i++) {
            cin >> u >> v;
            adj[u].push_back(v);
        }
        
        Solution obj;
        vector <int> res = obj.topoSort(N, adj);

        cout << check(N, res, adj) << endl;
    }
    
    return 0;
}
// } Driver Code Ends