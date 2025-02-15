//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
   public:
    // Helper function to check Hamiltonian Path using backtracking
    bool hamiltonianPathUtil(vector<vector<int>> &graph, vector<bool> &visited, int node, int count, int N) {
        if (count == N) return true; // All nodes visited exactly once
        
        for (int neighbor : graph[node]) {
            if (!visited[neighbor]) {
                visited[neighbor] = true;
                if (hamiltonianPathUtil(graph, visited, neighbor, count + 1, N))
                    return true;
                visited[neighbor] = false; // Backtrack
            }
        }
        
        return false;
    }

    // Function to check for Hamiltonian Path
    bool check(int N, int M, vector<vector<int>> Edges) {
        // Create adjacency list
        vector<vector<int>> graph(N + 1);
        for (auto &edge : Edges) {
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        }

        // Try starting from each node
        for (int start = 1; start <= N; start++) {
            vector<bool> visited(N + 1, false);
            visited[start] = true;
            if (hamiltonianPathUtil(graph, visited, start, 1, N)) 
                return true;
        }

        return false;
    }
};

//{ Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--){
    	int N,M,X,Y;
    	cin>>N>>M;
    	vector<vector<int>> Edges;
    	for(int i=0;i<M;i++)
    	{
    		cin>>X>>Y;
    		Edges.push_back({X,Y});
    	}
    	Solution obj;
    	if(obj.check(N,M,Edges)){
    		cout<<"1"<<endl;
    	}
    	else
    	cout<<"0"<<endl;
	
cout << "~" << "\n";
}
}
// } Driver Code Ends