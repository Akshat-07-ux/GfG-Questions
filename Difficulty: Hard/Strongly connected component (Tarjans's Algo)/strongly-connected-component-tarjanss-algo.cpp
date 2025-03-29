//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

//User function template for C++

class Solution
{
public:
    vector<vector<int>> result;
    vector<int> disc, low, inStack;
    stack<int> st;
    int timer;

    void dfs(int u, vector<int> adj[]) {
        disc[u] = low[u] = ++timer;
        st.push(u);
        inStack[u] = 1;

        for (int v : adj[u]) {
            if (disc[v] == -1) { // If v is not visited
                dfs(v, adj);
                low[u] = min(low[u], low[v]);
            } else if (inStack[v]) { // Back edge found
                low[u] = min(low[u], disc[v]);
            }
        }

        // If u is the head of an SCC
        if (low[u] == disc[u]) {
            vector<int> scc;
            while (true) {
                int v = st.top();
                st.pop();
                inStack[v] = 0;
                scc.push_back(v);
                if (v == u) break;
            }
            sort(scc.begin(), scc.end());
            result.push_back(scc);
        }
    }

    vector<vector<int>> tarjans(int V, vector<int> adj[]) {
        // Initialize
        disc.assign(V, -1);
        low.assign(V, -1);
        inStack.assign(V, 0);
        timer = 0;

        // Run DFS for all unvisited nodes
        for (int i = 0; i < V; i++) {
            if (disc[i] == -1) {
                dfs(i, adj);
            }
        }

        // Sort SCCs lexicographically
        sort(result.begin(), result.end());
        return result;
    }
};



//{ Driver Code Starts.


int main()
{
    
    int t;
    cin >> t;
    while(t--)
    {
        int V, E;
        cin >> V >> E;

        vector<int> adj[V];

        for(int i = 0; i < E; i++)
        {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        vector<vector<int>> ptr = obj.tarjans(V, adj);

        for(int i=0; i<ptr.size(); i++)
        {
            for(int j=0; j<ptr[i].size(); j++)
            {
                if(j==ptr[i].size()-1)
                    cout<<ptr[i][j];
                else
                    cout<<ptr[i][j]<<" ";
            }
            cout<<',';
        }
        cout<<endl;
    
cout << "~" << "\n";
}

    return 0;
}


// } Driver Code Ends