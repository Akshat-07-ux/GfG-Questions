//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


class Matrix
{
public:
    template <class T>
    static void input(vector<vector<T>> &A,int n,int m)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                scanf("%d ",&A[i][j]);
            }
        }
    }
 
    template <class T>
    static void print(vector<vector<T>> &A)
    {
        for (int i = 0; i < A.size(); i++)
        {
            for (int j = 0; j < A[i].size(); j++)
            {
                cout << A[i][j] << " ";
            }
            cout << endl;
        }
    }
};


// } Driver Code Ends
class Solution {
public:
    bool hasCycle(int node, int parent, vector<vector<int>> &graph, vector<bool> &visited) {
        visited[node] = true;
        for (int neighbor : graph[node]) {
            if (!visited[neighbor]) {
                if (hasCycle(neighbor, node, graph, visited)) return true;
            } else if (neighbor != parent) {
                return true; // Cycle detected
            }
        }
        return false;
    }

    int isTree(int n, int m, vector<vector<int>> &edges) {
        // A tree must have exactly N-1 edges
        if (m != n - 1) return 0;

        // Create adjacency list
        vector<vector<int>> graph(n);
        for (auto &edge : edges) {
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        }

        // Check for cycles and connectivity using DFS
        vector<bool> visited(n, false);
        if (hasCycle(0, -1, graph, visited)) return 0;

        // Check if all nodes are connected (visited)
        for (int i = 0; i < n; i++) {
            if (!visited[i]) return 0;
        }

        return 1; // The graph is a tree
    }
};


//{ Driver Code Starts.

int main(){
    int t;
    scanf("%d ",&t);
    while(t--){
        
        int n; 
        scanf("%d",&n);
        
        
        int m; 
        scanf("%d",&m);
        
        
        vector<vector<int>> edges(m, vector<int>(2));
        Matrix::input(edges,m,2);
        
        Solution obj;
        int res = obj.isTree(n, m, edges);
        
        cout<<res<<endl;
        
    
cout << "~" << "\n";
}
}

// } Driver Code Ends