//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends

//Back-end complete function Template for C++
class Solution {
 public:
    void dfs(int node, vector<vector<int>>& graph, vector<bool>& visited, stack<int>& st) {
        visited[node] = true;
        for (int nei : graph[node]) {
            if (!visited[nei])
                dfs(nei, graph, visited, st);
        }
        st.push(node);
    }

    void reverseDfs(int node, vector<vector<int>>& revGraph, vector<bool>& visited, vector<int>& scc, int sccId) {
        visited[node] = true;
        scc[node] = sccId;
        for (int nei : revGraph[node]) {
            if (!visited[nei])
                reverseDfs(nei, revGraph, visited, scc, sccId);
        }
    }

    int captainAmerica(int n, vector<vector<int>>& gates) {
        // Graph and its reverse
        vector<vector<int>> graph(n + 1), revGraph(n + 1);
        for (auto& g : gates) {
            graph[g[0]].push_back(g[1]);
            revGraph[g[1]].push_back(g[0]);
        }

        // Step 1: Order nodes by finish time in original graph (Topological sort)
        vector<bool> visited(n + 1, false);
        stack<int> st;
        for (int i = 1; i <= n; ++i) {
            if (!visited[i])
                dfs(i, graph, visited, st);
        }

        // Step 2: Reverse DFS according to finishing time
        fill(visited.begin(), visited.end(), false);
        vector<int> scc(n + 1, 0);
        int sccCount = 0;

        while (!st.empty()) {
            int node = st.top(); st.pop();
            if (!visited[node]) {
                ++sccCount;
                reverseDfs(node, revGraph, visited, scc, sccCount);
            }
        }

        // Step 3: Build SCC DAG
        vector<int> outDegree(sccCount + 1, 0);
        for (auto& g : gates) {
            int u = scc[g[0]], v = scc[g[1]];
            if (u != v)
                outDegree[u]++;
        }

        // Step 4: Count number of SCCs with zero out-degree
        int sinkSCC = 0, sinkSCCId = -1;
        for (int i = 1; i <= sccCount; ++i) {
            if (outDegree[i] == 0) {
                sinkSCC++;
                sinkSCCId = i;
            }
        }

        if (sinkSCC != 1) return 0;

        // Step 5: Count nodes in the sink SCC
        int count = 0;
        for (int i = 1; i <= n; ++i) {
            if (scc[i] == sinkSCCId)
                count++;
        }
        return count;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> v(m);
        for (int i = 0; i < m; i++) {
            int a, b;
            cin >> a >> b;
            v[i].push_back(a);
            v[i].push_back(b);
        }

        Solution obj;
        cout << obj.captainAmerica(n, v) << endl;
        cout << "~" << endl;
    }
}
// } Driver Code Ends