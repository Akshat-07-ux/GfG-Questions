//{ Driver Code Starts
//Initial Template for C++
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

//User function Template for C++
class Solution
{
public:
    long long largestSumCycle(int N, vector<int> Edge) {
        vector<int> inDegree(N, 0);
        
        // Step 1: Compute in-degree for each node
        for (int i = 0; i < N; i++) {
            if (Edge[i] != -1) {
                inDegree[Edge[i]]++;
            }
        }

        // Step 2: Topological Sorting - Remove non-cyclic nodes
        queue<int> q;
        for (int i = 0; i < N; i++) {
            if (inDegree[i] == 0) {
                q.push(i);
            }
        }

        while (!q.empty()) {
            int node = q.front();
            q.pop();
            int next = Edge[node];
            if (next != -1) {
                inDegree[next]--;
                if (inDegree[next] == 0) {
                    q.push(next);
                }
            }
        }

        // Step 3: Find cycle sums in the remaining graph
        long long maxCycleSum = -1;
        vector<bool> visited(N, false);

        for (int i = 0; i < N; i++) {
            if (inDegree[i] > 0) { // If part of a cycle
                long long cycleSum = 0;
                int node = i;

                while (!visited[node]) {
                    visited[node] = true;
                    cycleSum += node;
                    inDegree[node] = 0; // Mark node as processed
                    node = Edge[node];
                }

                maxCycleSum = max(maxCycleSum, cycleSum);
            }
        }

        return maxCycleSum;
    }
};



//{ Driver Code Starts.
signed main(){
   int tc;
   cin >> tc;
   while(tc--){
      int N;
      cin >> N;
      vector<int> Edge(N);
      for(int i=0;i<N;i++){
        cin>>Edge[i];
      }
      Solution obj;
      long long ans=obj.largestSumCycle(N, Edge);
      cout<<ans<<endl;
   
cout << "~" << "\n";
}
   return 0;
}
// } Driver Code Ends