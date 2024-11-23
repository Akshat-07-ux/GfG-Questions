//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    bool isPossible(int N, int P, vector<pair<int, int>>& prerequisites) {
        // Step 1: Build the graph and in-degree array
        vector<vector<int>> graph(N);
        vector<int> inDegree(N, 0);

        for (const auto& prereq : prerequisites) {
            int u = prereq.second; // prerequisite task
            int v = prereq.first;  // dependent task
            graph[u].push_back(v);
            inDegree[v]++;
        }

        // Step 2: Perform topological sort using Kahn's Algorithm
        queue<int> q;

        // Add all tasks with zero in-degree to the queue
        for (int i = 0; i < N; ++i) {
            if (inDegree[i] == 0) {
                q.push(i);
            }
        }

        int processedTasks = 0;

        while (!q.empty()) {
            int current = q.front();
            q.pop();
            processedTasks++;

            // Reduce the in-degree of neighbors and enqueue if it becomes zero
            for (int neighbor : graph[current]) {
                inDegree[neighbor]--;
                if (inDegree[neighbor] == 0) {
                    q.push(neighbor);
                }
            }
        }

        // Step 3: Check if all tasks were processed
        return processedTasks == N;
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
    	int N, P;
        vector<pair<int, int> > prerequisites;
        cin >> N;
        cin >> P;
        for (int i = 0; i < P; ++i) {
            int x, y;
            cin >> x >> y;
            prerequisites.push_back(make_pair(x, y));
        }
        // string s;
        // cin>>s;
        Solution ob;
        if (ob.isPossible(N,P, prerequisites))
            cout << "Yes";
        else
            cout << "No";
        cout << endl;
	
cout << "~" << "\n";
}
	return 0;
}
// } Driver Code Ends