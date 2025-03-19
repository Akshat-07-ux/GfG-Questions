//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends


class Solution{
public:
    vector<int> primes;  // To store the list of prime numbers
    vector<bool> isPrime; // Prime sieve

    // Precompute the first 10^6 prime numbers using Sieve of Eratosthenes
    void precompute() {
        int MAX = 1000000; // Large enough limit
        isPrime.assign(MAX + 1, true);
        isPrime[0] = isPrime[1] = false; // 0 and 1 are not prime

        for (int i = 2; i * i <= MAX; i++) {
            if (isPrime[i]) {
                for (int j = i * i; j <= MAX; j += i)
                    isPrime[j] = false;
            }
        }

        // Store prime numbers in an ordered list
        for (int i = 2; i <= MAX; i++) {
            if (isPrime[i])
                primes.push_back(i);
        }
    }

    // DFS function to find connected components
    int dfs(int node, vector<vector<int>>& adj, vector<bool>& visited) {
        stack<int> s;
        s.push(node);
        visited[node] = true;
        int size = 0;

        while (!s.empty()) {
            int curr = s.top();
            s.pop();
            size++;

            for (int neighbor : adj[curr]) {
                if (!visited[neighbor]) {
                    visited[neighbor] = true;
                    s.push(neighbor);
                }
            }
        }
        return size;
    }

    int helpSanta(int n, int m, vector<vector<int>> &g) {
        if (m == 0) return -1; // No connections case

        // Construct adjacency list
        vector<vector<int>> adj(n + 1);
        for (auto& edge : g) {
            int u = edge[0], v = edge[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        // Find the largest connected component
        vector<bool> visited(n + 1, false);
        int largestComponentSize = 0;

        for (int i = 1; i <= n; i++) {
            if (!visited[i] && !adj[i].empty()) {  // Check if the node is not visited
                int size = dfs(i, adj, visited);
                largestComponentSize = max(largestComponentSize, size);
            }
        }

        // Find the K-th prime number
        return primes[largestComponentSize - 1]; // Since primes array is 0-indexed
    }
};


//{ Driver Code Starts.

int main(){
	int t;cin>>t;
	Solution ob;
	ob.precompute();
	while(t--){
        int n,e,u,v;
        cin>>n>>e;
        vector<vector<int>> g;
        
		for(int i = 0; i < e; i++)
		{
			cin>>u>>v;
			g.push_back({u, v});
// 			g[u].push_back(v);
// 			g[v].push_back(u);
		}
		cout << ob.helpSanta(n, e, g) << endl;
		
	
cout << "~" << "\n";
}
}



// } Driver Code Ends