//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

// User function Template for C++

class Solution {
  public:
    void dfs(int node, int parent, int depth, vector<int> graph[], int &evenCount, int &oddCount) {
        if (depth % 2 == 0) {
            evenCount++;
        } else {
            oddCount++;
        }
        
        for (int neighbor : graph[node]) {
            if (neighbor != parent) {
                dfs(neighbor, node, depth + 1, graph, evenCount, oddCount);
            }
        }
    }
    
    int countOfNodes(vector<int> graph[], int n) {
        int evenCount = 0, oddCount = 0;
        dfs(1, 0, 0, graph, evenCount, oddCount); // Start DFS from node 1, parent is 0 (non-existent)

        // Combination nC2 = n*(n-1)/2
        int evenPairs = evenCount * (evenCount - 1) / 2;
        int oddPairs = oddCount * (oddCount - 1) / 2;

        return evenPairs + oddPairs;
    }
};


//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin >> n;
        vector<int>graph[n+1];
        for(int i=0;i<n-1;i++){
            int u, v;
            cin >> u >> v;
            graph[u].push_back(v);
            graph[v].push_back(u);
        }
        Solution ob;
        cout<<ob.countOfNodes(graph, n)<<endl;
    
cout << "~" << "\n";
}
    return 0;
}
// } Driver Code Ends