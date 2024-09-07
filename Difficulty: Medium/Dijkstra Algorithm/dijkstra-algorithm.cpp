//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
	//Function to find the shortest distance of all the vertices
    //from the source vertex S.
    vector<int> dijkstra(int V, vector<vector<int>> adj[], int S)
    {
        // Initialize distances with infinity (INT_MAX) except for the source node
        vector<int> dist(V, INT_MAX);
        dist[S] = 0;
        
        // Priority queue to store pairs (distance, vertex) with min-heap property
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push({0, S});  // Push the source node with distance 0
        
        while (!pq.empty()) {
            // Extract the node with the smallest distance
            int currentDist = pq.top().first;
            int u = pq.top().second;
            pq.pop();
            
            // Traverse through all the adjacent nodes of u
            for (auto &neighbor : adj[u]) {
                int v = neighbor[0];  // The neighboring vertex
                int weight = neighbor[1];  // The weight of the edge u-v
                
                // If there's a shorter path to v through u
                if (dist[u] + weight < dist[v]) {
                    dist[v] = dist[u] + weight;
                    pq.push({dist[v], v});
                }
            }
        }
        
        // Return the distances from source to all vertices
        return dist;
    }
};

//{ Driver Code Starts.


int main()
{
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj[V];
        int i=0;
        while (i++<E) {
            int u, v, w;
            cin >> u >> v >> w;
            vector<int> t1,t2;
            t1.push_back(v);
            t1.push_back(w);
            adj[u].push_back(t1);
            t2.push_back(u);
            t2.push_back(w);
            adj[v].push_back(t2);
        }
        int S;
        cin>>S;
        
        Solution obj;
    	vector<int> res = obj.dijkstra(V, adj, S);
    	
    	for(int i=0; i<V; i++)
    	    cout<<res[i]<<" ";
    	cout<<endl;
    }

    return 0;
}


// } Driver Code Ends