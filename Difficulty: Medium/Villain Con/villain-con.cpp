//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

// User function Template for C++

class Solution {
  public:
    int minColour(int N, int M, vector<int> mat[]) {
        vector<vector<int>> adj(N + 1); // adjacency list
        vector<int> indegree(N + 1, 0);

        for (int i = 0; i < M; ++i) {
            int x = mat[i][0];
            int y = mat[i][1];
            // y admires x => edge x → y
            adj[x].push_back(y);
            indegree[y]++;
        }

        // Topological sort (Kahn’s Algorithm)
        queue<int> q;
        for (int i = 1; i <= N; ++i) {
            if (indegree[i] == 0)
                q.push(i);
        }

        vector<int> level(N + 1, 0); // min color (as levels)
        int maxLevel = 0;

        while (!q.empty()) {
            int u = q.front(); q.pop();

            for (int v : adj[u]) {
                level[v] = max(level[v], level[u] + 1);
                maxLevel = max(maxLevel, level[v]);
                indegree[v]--;
                if (indegree[v] == 0)
                    q.push(v);
            }
        }

        return maxLevel + 1; // number of colors needed
    }
};



//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N, M, x, y;
        cin>>N>>M;
        vector<int> mat[M];
        for(int i = 0;i < M;i++){
            cin>>x>>y;
            mat[i].push_back(x);
            mat[i].push_back(y);
        }
        
        Solution ob;
        cout<<ob.minColour(N, M, mat)<<"\n";
    
cout << "~" << "\n";
}
    return 0;
}
// } Driver Code Ends